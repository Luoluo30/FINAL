#ifndef GOOD2_H_INCLUDED
#define GOOD2_H_INCLUDED
#include "element.h"
#include "../scene/gamescene2.h" // for element label
#include "../shapes/Shape.h"
/*
   [Good object]
*/
typedef struct _Good2
{
    ALLEGRO_BITMAP *img;
    int width;
    int height;
    int x, y;
    int v;
} Good2;
Elements *New_Good2(int label);
void Good2_update(Elements *self);
void _Good2_update_position(Elements *self, int dx, int dy);
void Good2_interact(Elements *self, Elements *tar);
void Good2_draw(Elements *self);
void Good2_destory(Elements *self);

#endif
