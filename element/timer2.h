#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED
#include "element.h"
#include "beat2.h"
#include "../scene/gamescene2.h" // for element label
#include <stdbool.h>
/*
   [TIMER object]
*/
typedef struct _Timer2
{
    ALLEGRO_TIMER *t;
    int count;
    int last;
    int x, y;
} Timer2;

Elements *New_Timer2(int label);
void Timer2_update(Elements *self);
void _Timer2_update_position(Elements *self, int dx, int dy);
void Timer2_interact(Elements *self, Elements *tar);
void Timer2_draw(Elements *self);
void Timer2_destory(Elements *self);


#endif
