#ifndef PERFECT2_H_INCLUDED
#define PERFECT2_H_INCLUDED
#include "element.h"
#include "../scene/gamescene2.h" // for element label
#include "../shapes/Shape.h"
/*
   [Perfect object]
*/
typedef struct _Perfect2
{
    ALLEGRO_BITMAP *img;
    int width;
    int height;
    int x, y;
    int v;
} Perfect2;
Elements *New_Perfect2(int label);
void Perfect2_update(Elements *self);
void _Perfect2_update_position(Elements *self, int dx, int dy);
void Perfect2_interact(Elements *self, Elements *tar);
void Perfect2_draw(Elements *self);
void Perfect2_destory(Elements *self);

#endif
