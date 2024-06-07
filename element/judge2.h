#ifndef JUDGE2_H_INCLUDED
#define JUDGE2_H_INCLUDED
#include "element.h"
#include "../scene/gamescene2.h" // for element label
#include "../shapes/Shape.h"
/*
   [Judge object]
*/
typedef struct _Judge2
{
    int x, y; // the position of image
    int r;    // the radius
    Shape *hitbox_pf, *hitbox_gd, *hitbox_ok; // the hitbox of object
    ALLEGRO_COLOR color;
} Judge2;

Elements *New_Judge2(int label);
void Judge2_update(Elements *self);
void Judge2_interact(Elements *self, Elements *tar);
void Judge2_draw(Elements *self);
void Judge2_destory(Elements *self);

#endif
