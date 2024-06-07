#ifndef STAR2_H_INCLUDED
#define STAR2_H_INCLUDED
#include "element.h"
#include "../scene/gamescene2.h" // for element label
#include "../shapes/Shape.h"
/*
   [star object]
*/
typedef struct _Star2
{
    int x, y, x2, y2;          // the position of image
    int width, height; // the width and height of image
    ALLEGRO_BITMAP *img;
    double switch_timer;
    bool image_switched;
} Star2;
Elements *New_Star2(int label);
void Star2_update(Elements *self);
void Star2_interact(Elements *self, Elements *tar);
void Star2_draw(Elements *self);
void Star2_destory(Elements *self);

#endif
