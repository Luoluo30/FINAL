#ifndef Ok_H_INCLUDED
#define Ok_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
/*
   [Ok object]
*/
typedef struct _Ok
{
    ALLEGRO_BITMAP *img;
    int width;
    int height;
    int x, y;
    int v;
} Ok;
Elements *New_Ok(int label);
void Ok_update(Elements *self);
void _Ok_update_position(Elements *self, int dx, int dy);
void Ok_interact(Elements *self, Elements *tar);
void Ok_draw(Elements *self);
void Ok_destory(Elements *self);

#endif
