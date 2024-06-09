#ifndef GUNCIRCLE2_H_INCLUDED
#define GUNCIRCLE2_H_INCLUDED
#include "element.h"
#include "../scene/gamescene2.h" // for element label
#include "../shapes/Shape.h"
/*
   [Guncircle1 object]
*/
typedef struct _Guncircle2
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
} Guncircle2;

Elements *New_Guncircle2(int label);
void Guncircle2_update(Elements *self);
void _Guncircle2_update_position(Elements *self, int dx, int dy);
void Guncircle2_interact(Elements *self, Elements *tar);
void Guncircle2_draw(Elements *self);
void Guncircle2_destory(Elements *self);

#endif

