#ifndef Gun_H_INCLUDED
#define Gun_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
#define MAX_BLOODS 3
/*
   [Gun object]
*/
typedef struct {
    float x, y;
    double start_time;
} Blood;

typedef struct {
    ALLEGRO_BITMAP *gl;
    ALLEGRO_BITMAP *gr;
    ALLEGRO_BITMAP *gol;
    ALLEGRO_BITMAP *gor;
    ALLEGRO_BITMAP *current_img;
    ALLEGRO_BITMAP *current_img2;
    ALLEGRO_BITMAP *blood;
    int width;
    int height;
    float x, y, x2, y2;
    Shape *hitbox;
    double switch_timer;
    bool image_switched;
    double switch_timer2;
    bool image_switched2;
    bool show_blood;
    int blood_x, blood_y;
    Blood bloods[MAX_BLOODS];
} Gun;

Elements *New_Gun(int label);
void Gun_update(Elements *self);
void Gun_interact(Elements *self, Elements *tar);
void Gun_draw(Elements *self);
void Gun_destroy(Elements *self);
void handle_key_down(Elements *gun, int keycode);
#endif