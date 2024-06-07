#ifndef BAD_H_INCLUDED
#define BAD_H_INCLUDED
#include "element.h"
#include "../scene/gamescene2.h" // for element label
#include "../shapes/Shape.h"
/*
   [Bad object]
*/
typedef struct _Bad2
{
    ALLEGRO_BITMAP *img;
    int width;
    int height;
    int x, y;
    int v;
} Bad2;
Elements *New_Bad2(int label);
void Bad2_update(Elements *self);
void _Bad2_update_position(Elements *self, int dx, int dy);
void Bad2_interact(Elements *self, Elements *tar);
void Bad2_draw(Elements *self);
void Bad2_destory(Elements *self);

#endif
