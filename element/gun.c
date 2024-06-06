#include "gun.h"
#include "../shapes/Circle.h"
#include <stdlib.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 672

/*
   [Gun function]
*/
Elements *New_Gun(int label)
{
    Gun *pDerivedObj = (Gun *)malloc(sizeof(Gun));
    Elements *pObj = New_Elements(label);

    // setting derived object member
    pDerivedObj->gl = al_load_bitmap("assets/image/gun_left.png");
    pDerivedObj->gr = al_load_bitmap("assets/image/gun_right.png");
    pDerivedObj->gol = al_load_bitmap("assets/image/gun_on_left.png");
    pDerivedObj->gor = al_load_bitmap("assets/image/gun_on_right.png");
    pDerivedObj->blood = al_load_bitmap("assets/image/blood.png");
    pDerivedObj->current_img = pDerivedObj->gl;
    pDerivedObj->current_img2 = pDerivedObj->gr;
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->current_img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->current_img);
    pDerivedObj->image_switched = false;
    pDerivedObj->image_switched2 = false;
    pDerivedObj->switch_timer = 0;
    pDerivedObj->switch_timer2 = 0;

    // Initialize bloods array
    for (int i = 0; i < MAX_BLOODS; i++) {
        pDerivedObj->bloods[i].start_time = -1; // -1 indicates not active
    }

    // Specify the scale factors
    float scale_x = 0.25; // Scale width to 50%
    float scale_y = 0.25; // Scale height to 50%

    // Set initial position to center the image
    pDerivedObj->x = (SCREEN_WIDTH - pDerivedObj->width * scale_x) / 2 - 460; //-10 normally
    pDerivedObj->y = (SCREEN_HEIGHT - pDerivedObj->height * scale_y) / 2 + 100; //+10 normally
    pDerivedObj->x2 = (SCREEN_WIDTH - pDerivedObj->width * scale_x) / 2 + 120; //-10 normally
    pDerivedObj->y2 = (SCREEN_HEIGHT - pDerivedObj->height * scale_y) / 2 + 100; //+10 normally

    // setting the interact object
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Gun_update;
    pObj->Interact = Gun_interact;
    pObj->Draw = Gun_draw;
    pObj->Destroy = Gun_destroy;

    return pObj;
}


void Gun_update(Elements *self)
{
    Gun *Obj = ((Gun *)(self->pDerivedObj));
    double dt = 0.5;
    double current_time = al_get_time();

    if (key_state[ALLEGRO_KEY_LEFT]) {
        Obj->current_img = Obj->gol;
        Obj->width = al_get_bitmap_width(Obj->current_img);
        Obj->height = al_get_bitmap_height(Obj->current_img);
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 

        // random position blood
        for (int i = 0; i < MAX_BLOODS; i++) {
            if (Obj->bloods[i].start_time == -1) {
                Obj->bloods[i].x = rand() % (SCREEN_WIDTH - al_get_bitmap_width(Obj->blood));
                Obj->bloods[i].y = rand() % (SCREEN_HEIGHT - al_get_bitmap_height(Obj->blood));
                Obj->bloods[i].start_time = current_time;
                break;
            }
        }
    }

    if (key_state[ALLEGRO_KEY_RIGHT]) {
        Obj->current_img2 = Obj->gor;
        Obj->width = al_get_bitmap_width(Obj->current_img2);
        Obj->height = al_get_bitmap_height(Obj->current_img2);
        Obj->image_switched2 = true;
        Obj->switch_timer2 = 2.0; 

        // random position blood
        for (int i = 0; i < MAX_BLOODS; i++) {
            if (Obj->bloods[i].start_time == -1) {
                Obj->bloods[i].x = rand() % (SCREEN_WIDTH - al_get_bitmap_width(Obj->blood));
                Obj->bloods[i].y = rand() % (SCREEN_HEIGHT - al_get_bitmap_height(Obj->blood));
                Obj->bloods[i].start_time = current_time;
                break;
            }
        }
    }

    if (Obj->image_switched) {
        Obj->switch_timer -= dt;
        if (Obj->switch_timer <= 0) {
            Obj->current_img = Obj->gl;
            Obj->width = al_get_bitmap_width(Obj->current_img);
            Obj->height = al_get_bitmap_height(Obj->current_img);
            Obj->image_switched = false;
        }
    }

    if (Obj->image_switched2) {
        Obj->switch_timer2 -= dt;
        if (Obj->switch_timer2 <= 0) {
            Obj->current_img2 = Obj->gr;
            Obj->width = al_get_bitmap_width(Obj->current_img2);
            Obj->height = al_get_bitmap_height(Obj->current_img2);
            Obj->image_switched2 = false;
        }
    }

    for (int i = 0; i < MAX_BLOODS; i++) {
        if (Obj->bloods[i].start_time != -1 && (current_time - Obj->bloods[i].start_time) > 0.5) { //這裡設定血液消失時間
            Obj->bloods[i].start_time = -1; 
        }
    }
}



void _Gun_update_position(Elements *self, int dx, int dy)
{
}

void Gun_interact(Elements *self, Elements *tar)
{
}

void Gun_draw(Elements *self)
{
    Gun *Obj = ((Gun *)(self->pDerivedObj));

    // Specify the scale factors
    float scale_x = 0.9; // Scale width to 50%
    float scale_y = 0.9; // Scale height to 50%

    // Calculate new width and height
    float new_width = Obj->width * scale_x;
    float new_height = Obj->height * scale_y;

    al_draw_scaled_bitmap(Obj->current_img,
                          0, 0, Obj->width, Obj->height, // Source bitmap coordinates
                          Obj->x, Obj->y, // Destination coordinates
                          new_width, new_height, // Scaled width and height
                          0); // Flag
    al_draw_scaled_bitmap(Obj->current_img2,
                          0, 0, Obj->width, Obj->height, // Source bitmap coordinates
                          Obj->x2, Obj->y2, // Destination coordinates
                          new_width, new_height, // Scaled width and height
                          0); // Flags

    for (int i = 0; i < MAX_BLOODS; i++) {
        if (Obj->bloods[i].start_time != -1) {
            al_draw_bitmap(Obj->blood, Obj->bloods[i].x, Obj->bloods[i].y, 0);
        }
    }
}


void Gun_destroy(Elements *self)
{
    Gun *Obj = ((Gun *)(self->pDerivedObj));
    if (Obj) {
        if (Obj->current_img) {
            al_destroy_bitmap(Obj->current_img);
        }
        if (Obj->current_img2) {
            al_destroy_bitmap(Obj->current_img2);
        }
        if (Obj->hitbox) {
            free(Obj->hitbox);
        }
        free(Obj);
    }
    if (self) 
        free(self);
    }

