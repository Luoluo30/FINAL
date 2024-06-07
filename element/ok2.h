#ifndef OK2_H_INCLUDED
#define OK2_H_INCLUDED
#include "element.h"
#include "../scene/gamescene2.h" // for element label
#include "../shapes/Shape.h"
/*
   [Ok object]
*/
typedef struct _Ok2
{
    ALLEGRO_BITMAP *img;
    int width;
    int height;
    int x, y;
    int v;
} Ok2;
Elements *New_Ok2(int label);
void Ok2_update(Elements *self);
void _Ok2_update_position(Elements *self, int dx, int dy);
void Ok2_interact(Elements *self, Elements *tar);
void Ok2_draw(Elements *self);
void Ok2_destory(Elements *self);

#endif
