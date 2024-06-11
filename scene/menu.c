#include <allegro5/allegro_primitives.h>
#include "menu.h"
#include <stdbool.h>
/*
   [Menu function]
*/
Scene *New_Menu(int label)
{
    Menu *pDerivedObj = (Menu *)malloc(sizeof(Menu));
    Scene *pObj = New_Scene(label);

    // setting derived object member
    pDerivedObj->font = al_load_ttf_font("assets/font/vac.otf", 50, 0);

    // Load sound
    pDerivedObj->song = al_load_sample("assets/sound/wings of piano.mp3");
    al_reserve_samples(20);
    pDerivedObj->sample_instance = al_create_sample_instance(pDerivedObj->song);

    // background image
    pDerivedObj->background = al_load_bitmap("assets/image/osu.png"); 
    pDerivedObj->background2 = al_load_bitmap("assets/image/gameinfo.png");
    pDerivedObj->background3 = al_load_bitmap("assets/image/gamebackground.png");
    pDerivedObj->background0 = al_load_bitmap("assets/image/cover.png");
    pDerivedObj->title_x = WIDTH / 2;
    pDerivedObj->title_y = HEIGHT / 2;

    //Loop the song until the display closes
    al_set_sample_instance_playmode(pDerivedObj->sample_instance, ALLEGRO_PLAYMODE_ONCE);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(pDerivedObj->sample_instance, al_get_default_mixer());

    //set the volume of instance
    al_set_sample_instance_gain(pDerivedObj->sample_instance, 0.1);
    pObj->pDerivedObj = pDerivedObj;

    pDerivedObj->circle1_x = WIDTH / 2 - 179;  // circle1(choose songs)
    pDerivedObj->circle1_y = HEIGHT / 2;
    pDerivedObj->circle1_radius = 50; 
    pDerivedObj->circle2_x = WIDTH / 2 -57;  // circle2(gamebackground)
    pDerivedObj->circle2_y = HEIGHT / 2;
    pDerivedObj->circle2_radius = 50;
    pDerivedObj->circle3_x = WIDTH / 2 + 61;  // circle3(set info)
    pDerivedObj->circle3_y = HEIGHT / 2;
    pDerivedObj->circle3_radius = 50;      
    pDerivedObj->circle4_x = WIDTH / 2 + 181;  // circlr4(exit)
    pDerivedObj->circle4_y = HEIGHT / 2;
    pDerivedObj->circle4_radius = 50;
    pDerivedObj->show_background0 = true;
    // setting derived object function
    pObj->Update = menu_update;
    pObj->Draw = menu_draw;
    pObj->Destroy = menu_destroy;
    return pObj;
}
void menu_update(Scene *self)
{
    Menu *Obj = ((Menu *)(self->pDerivedObj));
    //check the keyboard situation
    ALLEGRO_KEYBOARD_STATE keyState;
    al_get_keyboard_state(&keyState);

    //check Enter
    if (al_key_down(&keyState, ALLEGRO_KEY_ENTER)) {
        Obj->show_background0 = false; 
    } 

}

void menu_draw(Scene *self)
{
    Menu *Obj = ((Menu *)(self->pDerivedObj));
    if (Obj->show_background0) {
        if (Obj->background0) {
            int bg_width = al_get_bitmap_width(Obj->background0);
            int bg_height = al_get_bitmap_height(Obj->background0);
            int bg_x = (WIDTH - bg_width) / 2;
            int bg_y = (HEIGHT - bg_height) / 2;
            al_draw_bitmap(Obj->background0, bg_x, bg_y, 0);
            
        }
    } else {
        if (Obj->background) {
            int bg_width = al_get_bitmap_width(Obj->background);
            int bg_height = al_get_bitmap_height(Obj->background);
            int bg_x = (WIDTH - bg_width) / 2;
            int bg_y = (HEIGHT - bg_height) / 2;
            al_draw_bitmap(Obj->background, bg_x, bg_y, 0);
        }
    }
    // check the left mouse
    ALLEGRO_MOUSE_STATE mouse_state;
    al_get_mouse_state(&mouse_state);
    if (mouse_state.buttons & 1) {
        int mouse_x = mouse_state.x;
        int mouse_y = mouse_state.y;
        // check the position of mouse(circle1)
        if ((mouse_x - Obj->circle1_x) * (mouse_x - Obj->circle1_x) + (mouse_y - Obj->circle1_y) * (mouse_y - Obj->circle1_y) <= Obj->circle1_radius * Obj->circle1_radius) {
            self->scene_end = true;
            window = 3;  // shift to gamewindow3
            al_stop_sample_instance(Obj->sample_instance);
        }
        // check the position of mouse(circle2)
        else if ((mouse_x - Obj->circle2_x) * (mouse_x - Obj->circle2_x) + (mouse_y - Obj->circle2_y) * (mouse_y - Obj->circle2_y) <= Obj->circle2_radius * Obj->circle2_radius) {
            int bg_width = al_get_bitmap_width(Obj->background3);
            int bg_height = al_get_bitmap_height(Obj->background3);
            int bg_x = (WIDTH - bg_width) / 2;
            int bg_y = (HEIGHT - bg_height) / 2;
            al_draw_bitmap(Obj->background3, bg_x, bg_y, 0);
        }
        // check the position of mouse(circle3)
        else if ((mouse_x - Obj->circle3_x) * (mouse_x - Obj->circle3_x) + (mouse_y - Obj->circle3_y) * (mouse_y - Obj->circle3_y) <= Obj->circle3_radius * Obj->circle3_radius) {
            //self->scene_end = true;
            int bg_width = al_get_bitmap_width(Obj->background2);
            int bg_height = al_get_bitmap_height(Obj->background2);
            int bg_x = (WIDTH - bg_width) / 2;
            int bg_y = (HEIGHT - bg_height) / 2;
            al_draw_bitmap(Obj->background2, bg_x, bg_y, 0);
        }
        // check the position of mouse(circle4)
        else if ((mouse_x - Obj->circle4_x) * (mouse_x - Obj->circle4_x) + (mouse_y - Obj->circle4_y) * (mouse_y - Obj->circle4_y) <= Obj->circle4_radius * Obj->circle4_radius) {
            self->scene_end = true;
            window = -1;  // exit
            al_stop_sample_instance(Obj->sample_instance);
        }
    }
    al_play_sample_instance(Obj->sample_instance);
}

void menu_destroy(Scene *self)
{
    Menu *Obj = ((Menu *)(self->pDerivedObj));
    al_destroy_font(Obj->font);
    al_destroy_sample(Obj->song);
    al_destroy_sample_instance(Obj->sample_instance);
    al_destroy_bitmap(Obj->background);
    al_destroy_bitmap(Obj->background2);
    al_destroy_bitmap(Obj->background0);
    free(Obj);
    free(self);
}
