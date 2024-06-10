#include "gamescene2.h"
#include "../element/timer2.h"
/*
   [GameScene function]
*/
Scene *New_GameScene2(int label)
{
    GameScene2 *pDerivedObj = (GameScene2 *)malloc(sizeof(GameScene2));
    Scene *pObj = New_Scene(label);
    // setting derived object member
    pDerivedObj->office = al_load_bitmap("assets/image/office.jpg");
    pDerivedObj->hell = al_load_bitmap("assets/image/hell.jpg");
    pDerivedObj->end_pass = al_load_bitmap("assets/image/end_pass.jpg");
    pDerivedObj->end_fail = al_load_bitmap("assets/image/end_fail.jpg");
    pDerivedObj->background = pDerivedObj->office;
    pObj->pDerivedObj = pDerivedObj;
    pDerivedObj->t = al_create_timer(1.0/60);
    al_start_timer(pDerivedObj->t);
    pDerivedObj->font = al_load_ttf_font("assets/font/vac.otf", 175, 0);
    pDerivedObj->font_x = -400;
    pDerivedObj->font_y = -400;

    // Load sound
    pDerivedObj->song = al_load_sample("assets/sound/idol_chorus.mp3");
    al_reserve_samples(20);
    pDerivedObj->sample_instance = al_create_sample_instance(pDerivedObj->song);
    // Play the song once
    al_set_sample_instance_playmode(pDerivedObj->sample_instance, ALLEGRO_PLAYMODE_ONCE);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(pDerivedObj->sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(pDerivedObj->sample_instance, 0.4);
    al_play_sample_instance(pDerivedObj->sample_instance); // 初始化時播放一次

    // register element
    /*_Register_elements(pObj, New_Floor(Floor_L));
    _Register_elements(pObj, New_Teleport(Teleport_L));
    _Register_elements(pObj, New_Tree(Tree_L));
    _Register_elements(pObj, New_Character(Character_L));*/
    _Register_elements(pObj, New_Judge2(Judge2_L));
    _Register_elements(pObj, New_Beat2(Beat2_L, 1280, 590, -17, al_map_rgb(255, 255, 111)));
    _Register_elements(pObj, New_Beat2(Beat2_L, 1650, 590, -17, al_map_rgb(255, 255, 111)));
    _Register_elements(pObj, New_Beat2(Beat2_L, 1980, 590, -17, al_map_rgb(255, 255, 111)));
    _Register_elements(pObj, New_Beat2(Beat2_L, 2300, 590, -17, al_map_rgb(255, 255, 111)));
    _Register_elements(pObj, New_Beat2(Beat2_L, 2590, 590, -17, al_map_rgb(255, 255, 111)));
     _Register_elements(pObj, New_Beat2(Beat2_L, 2850, 590, -17, al_map_rgb(255, 255, 111)));
     _Register_elements(pObj, New_Beat2(Beat2_L, 3100, 590, -17, al_map_rgb(255, 255, 111)));
     _Register_elements(pObj, New_Beat2(Beat2_L, 3390, 590, -17, al_map_rgb(255, 255, 111)));
    _Register_elements(pObj, New_Timer2(Timer2_L));
    _Register_elements(pObj, New_Boss2(Boss2_L));
    _Register_elements(pObj, New_Star2(Star2_L));
    _Register_elements(pObj, New_Score2(Score2_L));
    // setting derived object function
    pObj->Update = game_scene2_update;
    pObj->Draw = game_scene2_draw;
    pObj->Destroy = game_scene2_destroy;
    return pObj;
}

void game_scene2_update(Scene *self)
{
    GameScene2 *Obj = ((GameScene2 *)(self->pDerivedObj));
    // 获取计时器元素
    Timer2 *time = NULL;
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++) {
        Elements *ele = allEle.arr[i];
        if (ele->label == Timer2_L) {
            time = (Timer2 *)ele->pDerivedObj;
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
    //換背景
    if (time && time->count >= 1405 && time->count < 3012) {
        Obj->background = Obj->hell;
    }
    if (time && time->count >= 3012 && time->count < 6660) {
        Obj->background = Obj->office;
    }
    if (time && time->count >= 6660 && end_score2 >= 100000) {
        Obj->background = Obj->end_pass;
    }
    if (time && time->count == 6660 && end_score2 < 100000) {
        Obj->background = Obj->end_fail;
    }

    if (time && time->count == 6660) {
        Obj->font_x = 450;
        Obj->font_y = 360;
    }
}

void game_scene2_draw(Scene *self)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
    GameScene2 *gs = ((GameScene2 *)(self->pDerivedObj));
    al_draw_bitmap(gs->background, 0, 0, 0);
    ElementVec allEle = _Get_all_elements(self);
    for (int i = 0; i < allEle.len; i++)
    {
        Elements *ele = allEle.arr[i];
        ele->Draw(ele);
    }
    char score_text[10];
    sprintf(score_text, "%d", end_score2);
    al_draw_text(gs->font, al_map_rgb(0, 0, 0), gs->font_x, gs->font_y, ALLEGRO_ALIGN_CENTER, score_text);
}
void game_scene2_destroy(Scene *self)
{
    GameScene2 *Obj = ((GameScene2 *)(self->pDerivedObj));
    ALLEGRO_BITMAP *background = Obj->background;
    al_destroy_bitmap(background);
    al_destroy_sample(Obj->song);
    al_destroy_sample_instance(Obj->sample_instance);
  //  ElementVec allEle = _Get_all_elements(self);
  //  for (int i = 0; i < allEle.len; i++)
  //  {
  //      Elements *ele = allEle.arr[i];
  //      ele->Destroy(ele);
   // }
    free(Obj);
    free(self);
}
