#ifndef Perfect_H_INCLUDED
#define Perfect_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
/*
   [Perfect object]
*/
typedef struct _Perfect
{
    ALLEGRO_BITMAP *img;
    int width;
    int height;
    int x, y;
    int v;
} Perfect;
Elements *New_Perfect(int label);
void Perfect_update(Elements *self);
void _Perfect_update_position(Elements *self, int dx, int dy);
void Perfect_interact(Elements *self, Elements *tar);
void Perfect_draw(Elements *self);
void Perfect_destory(Elements *self);

#endif
