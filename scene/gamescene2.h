#ifndef GAMESCENE2_H_INCLUDED
#define GAMESCENE2_H_INCLUDED
#include "scene.h"
// #include "../element/element.h"
// #include "../element/charater.h"
// #include "../element/floor.h"
// #include "../element/teleport.h"
// #include "../element/tree.h"
// #include "../element/projectile.h"
#include "../element/judge2.h"
#include "../element/beat2.h"
#include "../element/timer2.h"
#include "../element/boss2.h"
#include "../element/star2.h"
#include "../element/perfect2.h"
#include "../element/good2.h"
#include "../element/ok2.h"
#include "../element/gun2.h"
#include "../element/score2.h"
#include <allegro5/allegro_audio.h>

/*
   [game scene object]
*/
typedef enum EleType2
{
    // Floor_L,
    // Teleport_L,
    // Tree_L,
    // Character_L,
    // Projectile_L,
    Judge2_L,
    Beat2_L,
    Timer2_L,
    Boss2_L,
    Star2_L,
    Perfect2_L,
    Good2_L,
    Ok2_L,
    Bad2_L,
    Gun2_L,
    Score2_L
} EleType2;
typedef struct _GameScene2
{
    ALLEGRO_BITMAP *background;
    ALLEGRO_BITMAP *office;
    ALLEGRO_BITMAP *hell;
    ALLEGRO_SAMPLE *song;
    ALLEGRO_SAMPLE_INSTANCE *sample_instance;
    ALLEGRO_TIMER *t;
} GameScene2;
Scene *New_GameScene2(int label);
void game_scene2_update(Scene *self);
void game_scene2_draw(Scene *self);
void game_scene2_destroy(Scene *self);

#endif
