#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "scene.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
/*
   [Menu object]
*/
typedef struct _Menu
{
    ALLEGRO_FONT *font;
    ALLEGRO_SAMPLE *song;
    ALLEGRO_SAMPLE_INSTANCE *sample_instance;
    ALLEGRO_BITMAP *background;  // 添加背景
    ALLEGRO_BITMAP *background2;
    ALLEGRO_BITMAP *background3;    
    ALLEGRO_BITMAP *background0;
    int title_x, title_y;
    //點擊的範圍
    int circle1_x, circle1_y, circle1_radius;
    int circle2_x, circle2_y, circle2_radius;
    int circle3_x, circle3_y, circle3_radius;
    int circle4_x, circle4_y, circle4_radius;
    bool key_state[ALLEGRO_KEY_MAX];
    bool prev_key_state[ALLEGRO_KEY_MAX];
    bool show_background0;
} Menu;
Scene *New_Menu(int label);
void menu_update(Scene *self);
void menu_draw(Scene *self);
void menu_destroy(Scene *self);    


#endif
