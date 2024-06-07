#ifndef SCORE2_H_INCLUDED
#define SCORE2_H_INCLUDED
#include "../scene/gamescene2.h" // for element label
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>
/*
   [Score object]
*/
typedef struct _Score2
{
    int count;
    ALLEGRO_FONT *font;
    int text_x, text_y;
    int text1_x, text1_y;
    char num[10];
} Score2;

Elements *New_Score2(int label);
void Score2_update(Elements *self);
void Score2_interact(Elements *self, Elements *tar);
void Score2_draw(Elements *self);
void Score2_destory(Elements *self);


#endif
