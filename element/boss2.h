#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED
#include "element.h"
#include "../scene/gamescene2.h" // for element label
#include "../shapes/Shape.h"
/*
   [Boss object]
*/
typedef enum {
    NORMAL2,
    UP2,
    DOWN2,
    LEFT2,
    RIGHT2,
    SPACE2
} BossState2;

typedef struct {
    ALLEGRO_BITMAP *img;
    ALLEGRO_BITMAP *img_up;
    ALLEGRO_BITMAP *img_down;
    ALLEGRO_BITMAP *img_left;
    ALLEGRO_BITMAP *img_right;
    ALLEGRO_BITMAP *current_img;
    ALLEGRO_BITMAP *img2;
    ALLEGRO_BITMAP *img_up2;
    ALLEGRO_BITMAP *img_down2;
    ALLEGRO_BITMAP *img_left2;
    ALLEGRO_BITMAP *img_right2;
    ALLEGRO_BITMAP *current_img2;
    int width;
    int height;
    float x, y, x2, y2;
    Shape *hitbox;
    double switch_timer;
    bool image_switched;
    double switch_timer2;
    bool image_switched2;
    int id;
    bool key_pressed;
} Boss2;

Elements *New_Boss2(int label);
void Boss2_update(Elements *self);
void Boss2_interact(Elements *self, Elements *tar);
void Boss2_draw(Elements *self);
void Boss2_destroy(Elements *self);
void handle_key_down(Elements *boss2, int keycode);
#endif