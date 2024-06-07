#ifndef BEAT2_H_INCLUDED
#define BEAT2_H_INCLUDED
#include "element.h"
#include "../scene/gamescene2.h" // for element label
#include "../shapes/Shape.h"
/*
   [Beat1 object]
*/
typedef struct _Beat2
{
    int x, y; // the position of image
    int r;    // the radius
    double v;             // the velocity of projectile
    Shape *hitbox; // the hitbox of object
    ALLEGRO_COLOR color;
    int width, height;
    //ALLEGRO_BITMAP *img;
    ALLEGRO_BITMAP *evaluation_img;
    bool ev;
    int id;
} Beat2;

Elements *New_Beat2(int label, int x, int y, int v, ALLEGRO_COLOR c);
void Beat2_update(Elements *self);
void _Beat2_update_position(Elements *self, int dx, int dy);
void Beat2_interact(Elements *self, Elements *tar);
void Beat2_draw(Elements *self);
void Beat2_destory(Elements *self);

#endif

