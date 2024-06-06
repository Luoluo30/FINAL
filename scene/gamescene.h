#ifndef GAMESCENE_H_INCLUDED
#define GAMESCENE_H_INCLUDED
#include "scene.h"
// #include "../element/element.h"
// #include "../element/charater.h"
// #include "../element/floor.h"
// #include "../element/teleport.h"
// #include "../element/tree.h"
// #include "../element/projectile.h"
#include "../element/judge.h"
#include "../element/beat.h"
#include "../element/timer.h"
#include "../element/boss.h"
#include "../element/star.h"
#include "../element/perfect.h"
#include "../element/good.h"
#include "../element/ok.h"
#include "../element/gun.h"
#include <allegro5/allegro_audio.h>

/*
   [game scene object]
*/
typedef enum EleType
{
    // Floor_L,
    // Teleport_L,
    // Tree_L,
    // Character_L,
    // Projectile_L,
    Judge_L,
    Beat_L,
    Timer_L,
    Boss_L,
    Star_L,
    Perfect_L,
    Good_L,
    Ok_L,
    Bad_L,
    Gun_L
} EleType;
typedef struct _GameScene
{
    ALLEGRO_BITMAP *background;
    ALLEGRO_BITMAP *office;
    ALLEGRO_BITMAP *hell;
    ALLEGRO_SAMPLE *song;
    ALLEGRO_SAMPLE_INSTANCE *sample_instance;
    ALLEGRO_TIMER *t;
} GameScene;
Scene *New_GameScene(int label);
void game_scene_update(Scene *self);
void game_scene_draw(Scene *self);
void game_scene_destroy(Scene *self);

#endif
