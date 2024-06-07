#ifndef STAR_H_INCLUDED
#define STAR_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
/*
   [star object]
*/
typedef struct _Star
{
    int x, y, x2, y2;          // the position of image
    int width, height; // the width and height of image
    ALLEGRO_BITMAP *img;
    double switch_timer;
    bool image_switched;
} Star;
Elements *New_Star(int label);
void Star_update(Elements *self);
void Star_interact(Elements *self, Elements *tar);
void Star_draw(Elements *self);
void Star_destory(Elements *self);

#endif
