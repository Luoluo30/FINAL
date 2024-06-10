#ifndef JUDGE_H_INCLUDED
#define JUDGE_H_INCLUDED
#include "element.h"
#include "../scene/gamescene.h" // for element label
#include "../shapes/Shape.h"
#include <stdbool.h>
/*
   [Judge object]
*/
typedef struct _Judge
{
    int x, y; // the position of image
    int r;    // the radius
    Shape *hitbox_pf, *hitbox_gd, *hitbox_ok; // the hitbox of object
    ALLEGRO_COLOR color;
    bool b;
} Judge;

Elements *New_Judge(int label);
void Judge_update(Elements *self);
void Judge_interact(Elements *self, Elements *tar);
void Judge_draw(Elements *self);
void Judge_destory(Elements *self);

#endif
