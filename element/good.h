#ifndef Good_H_INCLUDED
#define Good_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
/*
   [Good object]
*/
typedef struct _Good
{
    ALLEGRO_BITMAP *img;
    int width;
    int height;
    int x, y;
    int v;
} Good;
Elements *New_Good(int label);
void Good_update(Elements *self);
void _Good_update_position(Elements *self, int dx, int dy);
void Good_interact(Elements *self, Elements *tar);
void Good_draw(Elements *self);
void Good_destory(Elements *self);

#endif
