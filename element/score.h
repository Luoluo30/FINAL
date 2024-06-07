#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include "../scene/gamescene.h" // for element label
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>
/*
   [Score object]
*/
typedef struct _Score
{
    int count;
    ALLEGRO_FONT *font;
    int text_x, text_y;
    int text1_x, text1_y;
    char num[10];
} Score;

Elements *New_Score(int label);
void Score_update(Elements *self);
void Score_interact(Elements *self, Elements *tar);
void Score_draw(Elements *self);
void Score_destory(Elements *self);


#endif
