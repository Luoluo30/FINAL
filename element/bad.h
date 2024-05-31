#ifndef Bad_H_INCLUDED
#define Bad_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
/*
   [Bad object]
*/
typedef struct _Bad
{
    ALLEGRO_BITMAP *img;
    int width;
    int height;
    int x, y;
    int v;
} Bad;
Elements *New_Bad(int label);
void Bad_update(Elements *self);
void _Bad_update_position(Elements *self, int dx, int dy);
void Bad_interact(Elements *self, Elements *tar);
void Bad_draw(Elements *self);
void Bad_destory(Elements *self);

#endif
