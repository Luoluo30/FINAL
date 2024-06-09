#ifndef GUNCIRCLE_H_INCLUDED
#define GUNCIRCLE_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
/*
   [Guncircle1 object]
*/
typedef struct _Guncircle
{
    int x, y; // the position of image
    int r;    // the radius
    ALLEGRO_COLOR color;
    int width, height;
    bool ev;
    int id;
    int shake_x;
    int shake_y;
    int shake_magnitude;
} Guncircle;

Elements *New_Guncircle(int label);
void Guncircle_update(Elements *self);
void _Guncircle_update_position(Elements *self, int dx, int dy);
void Guncircle_interact(Elements *self, Elements *tar);
void Guncircle_draw(Elements *self);
void Guncircle_destory(Elements *self);

#endif

