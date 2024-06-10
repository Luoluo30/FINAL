#include "gamescene.h"
#include "../element/timer.h"
#include <allegro5/allegro_audio.h>

/*
   [GameScene function]
*/
Scene *New_GameScene(int label)
{
    GameScene *pDerivedObj = (GameScene *)malloc(sizeof(GameScene));
    Scene *pObj = New_Scene(label);
    // setting derived object member
    pDerivedObj->office = al_load_bitmap("assets/image/office.jpg");
    pDerivedObj->hell = al_load_bitmap("assets/image/hell.jpg");
    pDerivedObj->background = pDerivedObj->office;
    pObj->pDerivedObj = pDerivedObj;
    pDerivedObj->t = al_create_timer(1.0/60);
    al_start_timer(pDerivedObj->t);

    // Load sound
    pDerivedObj->song = al_load_sample("assets/sound/bokuwa.mp3");
    al_reserve_samples(20);
    pDerivedObj->sample_instance = al_create_sample_instance(pDerivedObj->song);
    // Play the song once
    al_set_sample_instance_playmode(pDerivedObj->sample_instance, ALLEGRO_PLAYMODE_ONCE);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(pDerivedObj->sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(pDerivedObj->sample_instance, 0.4);

    // register element
    _Register_elements(pObj, New_Judge(Judge_L));
    _Register_elements(pObj, New_Beat(Beat_L, 505, 590, -6, al_map_rgb(255,255, 255)));
    _Register_elements(pObj, New_Beat(Beat_L, 890, 590, -6, al_map_rgb(255,255, 255)));
    _Register_elements(pObj, New_Beat(Beat_L, 1111, 590, -6, al_map_rgb(255,255, 255)));
    _Register_elements(pObj, New_Timer(Timer_L));
    _Register_elements(pObj, New_Boss(Boss_L));
    _Register_elements(pObj, New_Star(Star_L));
    _Register_elements(pObj, New_Score(Score_L));
    // setting derived object function
    pObj->Update = game_scene_update;
    pObj->Draw = game_scene_draw;
    pObj->Destroy = game_scene_destroy;
    return pObj;
}

void game_scene_update(Scene *self)
{
    GameScene *Obj = ((GameScene *)(self->pDerivedObj));
    // 抓計時器元素
    Timer *time = NULL;
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++) {
        Elements *ele = allEle.arr[i];
        if (ele->label == Timer_L) {
            time = (Timer *)ele->pDerivedObj;
            break;
        }
    }

    // update every element
    for (int i = 0; i < allEle.len; i++) {
        allEle.arr[i]->Update(allEle.arr[i]);
    }

    // run interact for every element
    for (int i = 0; i < allEle.len; i++) {
        Elements *ele = allEle.arr[i];
        // run every interact object
        for (int j = 0; j < ele->inter_len; j++) {
            int inter_label = ele->inter_obj[j];
            ElementVec labelEle = _Get_label_elements(self, inter_label);
            for (int k = 0; k < labelEle.len; k++) {
                ele->Interact(ele, labelEle.arr[k]);
            }
        }
    }
    // remove element
    for (int i = 0; i < allEle.len; i++) {
        Elements *ele = allEle.arr[i];
        if (ele->dele) {
            _Remove_elements(self, ele);
        }
    }

    if (key_state[ALLEGRO_KEY_ESCAPE]) {
        self->scene_end = true;
        window = 3;
        return;
    }

    // 時間加速
    if (key_state[ALLEGRO_KEY_P]) {
        int64_t ticks_to_add = 2 * 60; //加速2秒 
        if (time) {
            al_set_timer_count(time->t, al_get_timer_count(time->t) + ticks_to_add);
            time->count = al_get_timer_count(time->t); 
        }

        unsigned int samples_to_add = 2 * al_get_sample_instance_frequency(Obj->sample_instance);
        unsigned int new_position = al_get_sample_instance_position(Obj->sample_instance) + samples_to_add;
        al_set_sample_instance_position(Obj->sample_instance, new_position);
    }

    // 換背景
    if (time && time->count == 9050) {
        Obj->background = Obj->hell;
    }
    if (time && time->count == 10000) {
        Obj->background = Obj->office;
    }
}

void game_scene_draw(Scene *self)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    GameScene *gs = ((GameScene *)(self->pDerivedObj));
    al_draw_bitmap(gs->background, 0, 0, 0);
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        ele->Draw(ele);
    }
    al_play_sample_instance(gs->sample_instance);
}

void game_scene_destroy(Scene *self)
{
    GameScene *Obj = ((GameScene *)(self->pDerivedObj));
    ALLEGRO_BITMAP *background = Obj->background;
    al_destroy_bitmap(background);
    al_destroy_sample(Obj->song);
    al_destroy_sample_instance(Obj->sample_instance);
   // ElementVec allEle = _Get_all_elements(self);
   // for (int i = 0; i < allEle.len; i++)
   // {
  //      Elements *ele = allEle.arr[i];
   //     ele->Destroy(ele);
   // }
    free(Obj);
    free(self);
}
