#include <allegro5/allegro_primitives.h>
#include "menu2.h"
#include <stdbool.h>
/*
   [Menu function]
*/
Scene *New_Menu2(int label)
{
    Menu2 *pDerivedObj = (Menu2 *)malloc(sizeof(Menu2));
    Scene *pObj = New_Scene(label);

    // setting derived object member
    pDerivedObj->font = al_load_ttf_font("assets/font/vac.otf", 50, 0);

    // Load sound
    pDerivedObj->song = al_load_sample("assets/sound/wings of piano.mp3");
    al_reserve_samples(20);
    pDerivedObj->sample_instance = al_create_sample_instance(pDerivedObj->song);

    // background image
    pDerivedObj->background = al_load_bitmap("assets/image/menu2.png"); 
   
    pDerivedObj->title_x = WIDTH / 2;
    pDerivedObj->title_y = HEIGHT / 2;

    //Loop the song until the display closes
    al_set_sample_instance_playmode(pDerivedObj->sample_instance, ALLEGRO_PLAYMODE_ONCE);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(pDerivedObj->sample_instance, al_get_default_mixer());

    //set the volume of instance
    al_set_sample_instance_gain(pDerivedObj->sample_instance, 0.1);
    pObj->pDerivedObj = pDerivedObj;

    // set the button
    pDerivedObj->button1_x = WIDTH / 2 -363 ;
    pDerivedObj->button1_y = HEIGHT / 2 -130 ; 
    pDerivedObj->button1_width = 250;
    pDerivedObj->button1_height = 85;

    pDerivedObj->button2_x = WIDTH / 2 - 363;
    pDerivedObj->button2_y = HEIGHT / 2 + 200; 
    pDerivedObj->button2_width = 250;
    pDerivedObj->button2_height = 85;

    // Initialize key states
    memset(pDerivedObj->key_state, 0, sizeof(pDerivedObj->key_state));
    memset(pDerivedObj->prev_key_state, 0, sizeof(pDerivedObj->prev_key_state));

    // setting derived object function
    pObj->Update = menu_update2;
    pObj->Draw = menu_draw2;
    pObj->Destroy = menu_destroy2;
    return pObj;
}
void menu_update2(Scene *self)
{
    Menu2 *Obj = ((Menu2 *)(self->pDerivedObj));

    // 更新鍵盤狀態
    ALLEGRO_KEYBOARD_STATE keyState;
    al_get_keyboard_state(&keyState);
    for (int i = 0; i < ALLEGRO_KEY_MAX; i++) {
        Obj->key_state[i] = al_key_down(&keyState, i);
    }

    // 檢查是否剛被按下
    if (!Obj->prev_key_state[ALLEGRO_KEY_ESCAPE] && Obj->key_state[ALLEGRO_KEY_ESCAPE]) {
        self->scene_end = true;
        window = 0;  // shift to menu
    }

    // 更新 prev_key_state
    memcpy(Obj->prev_key_state, Obj->key_state, sizeof(Obj->key_state));
}

void menu_draw2(Scene *self)
{
    Menu2 *Obj = ((Menu2 *)(self->pDerivedObj));
    if (Obj->background){
    int bg_width = al_get_bitmap_width(Obj->background);
    int bg_height = al_get_bitmap_height(Obj->background);
    int bg_x = (WIDTH - bg_width) / 2;
    int bg_y = (HEIGHT - bg_height) / 2;
    al_draw_bitmap(Obj->background, bg_x, bg_y, 0);}



    //check the mouse 
    ALLEGRO_MOUSE_STATE mouse_state;
    al_get_mouse_state(&mouse_state);
    if (mouse_state.buttons & 1) {
        int mouse_x = mouse_state.x;
        int mouse_y = mouse_state.y;
        if (mouse_x >= Obj->button1_x && mouse_x <= Obj->button1_x + Obj->button1_width &&
            mouse_y >= Obj->button1_y && mouse_y <= Obj->button1_y + Obj->button1_height) {
            self->scene_end = true;
            window = 1;  //shift to window1
            al_stop_sample_instance(Obj->sample_instance);
        }
        else if (mouse_x >= Obj->button2_x && mouse_x <= Obj->button2_x + Obj->button2_width &&
                 mouse_y >= Obj->button2_y && mouse_y <= Obj->button2_y + Obj->button2_height) {
            self->scene_end = true;
            window = 2;  //shift to window2
            al_stop_sample_instance(Obj->sample_instance);
        }

        al_play_sample_instance(Obj->sample_instance);
    }
    al_play_sample_instance(Obj->sample_instance);

}

void menu_destroy2(Scene *self)
{
    Menu2 *Obj = ((Menu2 *)(self->pDerivedObj));
    al_destroy_font(Obj->font);
    al_destroy_sample(Obj->song);
    al_destroy_sample_instance(Obj->sample_instance);
    al_destroy_bitmap(Obj->background);
    free(Obj);
    free(self);
}