#include "boss2.h"
#include "../shapes/Circle.h"
#include <stdlib.h>
#include <allegro5/allegro_primitives.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 672

/*
   [Boss function]
*/
Elements *New_Boss2(int label)
{
    Boss2 *pDerivedObj = (Boss2 *)malloc(sizeof(Boss2));
    Elements *pObj = New_Elements(label);

    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/boss_normal.png");
    pDerivedObj->img_up = al_load_bitmap("assets/image/boss_top.png");
    pDerivedObj->img_down = al_load_bitmap("assets/image/boss_buttom.png");
    pDerivedObj->img_left = al_load_bitmap("assets/image/boss_left.png");
    pDerivedObj->img_right = al_load_bitmap("assets/image/boss_right.png");
    pDerivedObj->img2 = al_load_bitmap("assets/image/hammer_top.png"); // 2 for hammer
    pDerivedObj->img_up2 = al_load_bitmap("assets/image/hammer_top.png");
    pDerivedObj->img_down2 = al_load_bitmap("assets/image/hammer_down.png");
    pDerivedObj->img_left2 = al_load_bitmap("assets/image/hammer_left.png");
    pDerivedObj->img_right2 = al_load_bitmap("assets/image/hammer_right.png");
    pDerivedObj->current_img = pDerivedObj->img;
    pDerivedObj->current_img2 = pDerivedObj->img2;
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->current_img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->current_img);
    pDerivedObj->image_switched = false;
    pDerivedObj->switch_timer = 0;
    pDerivedObj->image_switched2 = false;
    pDerivedObj->switch_timer2 = 0;
    pDerivedObj->id = rand() % 4;
    pDerivedObj->key_pressed = false;
    // Specify the scale factors
    float scale_x = 0.25; // Scale width to 50%
    float scale_y = 0.25; // Scale height to 50%

    // Set initial position to center the image
    pDerivedObj->x = (SCREEN_WIDTH - pDerivedObj->width * scale_x) / 2 - 30;   //-10 normally
    pDerivedObj->y = (SCREEN_HEIGHT - pDerivedObj->height * scale_y) / 2 + 10; //+10 normally
    pDerivedObj->x2 = -400;
    pDerivedObj->y2 = -400;
    // setting the interact object

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Boss2_update;
    pObj->Interact = Boss2_interact;
    pObj->Draw = Boss2_draw;
    pObj->Destroy = Boss2_destroy;

    return pObj;
}

void Boss2_update(Elements *self)
{
    Boss2 *Obj = ((Boss2 *)(self->pDerivedObj));
    //double dt = 0.5;

    // 检查UP键状态
    if (key_state[ALLEGRO_KEY_UP]) {
        if (!Obj->key_pressed) {
            Obj->id = rand() % 4;
            Obj->key_pressed = true;

            if (Obj->id == 0) {
                Obj->current_img = Obj->img_up;
                Obj->current_img2 = Obj->img_up2;
                Obj->x2 = 190;
                Obj->y2 = 100;
            } else if (Obj->id == 1) {
                Obj->current_img = Obj->img_down;
                Obj->current_img2 = Obj->img_down2;
                Obj->x2 = 540;
                Obj->y2 = 340;
            } else if (Obj->id == 2) {
                Obj->current_img = Obj->img_left;
                Obj->current_img2 = Obj->img_left2;
                Obj->x2 = 190;
                Obj->y2 = 340;
            } else if (Obj->id == 3) {
                Obj->current_img = Obj->img_right;
                Obj->current_img2 = Obj->img_right2;
                Obj->x2 = 490;
                Obj->y2 = 120;
            }

            Obj->width = al_get_bitmap_width(Obj->current_img);
            Obj->height = al_get_bitmap_height(Obj->current_img);
            Obj->image_switched = true;
            Obj->switch_timer = 2.0; 
            Obj->image_switched2 = true;
            Obj->switch_timer2 = 2.0;
        }
    } else {
        if (Obj->key_pressed) {
            Obj->current_img = Obj->img; 
            Obj->current_img2 = Obj->img2;
            Obj->width = al_get_bitmap_width(Obj->current_img);
            Obj->height = al_get_bitmap_height(Obj->current_img);
            Obj->key_pressed = false; 
        }
    }

    // if (Obj->image_switched) {
    //     Obj->switch_timer -= dt;
    //     if (Obj->switch_timer <= 0) {
    //         Obj->current_img = Obj->img;
    //         Obj->width = al_get_bitmap_width(Obj->current_img);
    //         Obj->height = al_get_bitmap_height(Obj->current_img);
    //         Obj->image_switched = false;
    //     }
    // }
    // if (Obj->image_switched2) {
    //     Obj->switch_timer2 -= dt;
    //     if (Obj->switch_timer2 <= 0) {
    //         Obj->x2 = -500;
    //         Obj->y2 = -500;
    //         Obj->image_switched2 = false;
    //     }
    // }
}

void _Boss2_update_position(Elements *self, int dx, int dy)
{
}

void Boss2_interact(Elements *self, Elements *tar)
{
}

void Boss2_draw(Elements *self)
{
    Boss2 *Obj = ((Boss2 *)(self->pDerivedObj));

    // Specify the scale factors
    float scale_x = 0.25; // Scale width to 50%
    float scale_y = 0.25; // Scale height to 50%
    float scale_x2 = 1;   // Scale width to 50%
    float scale_y2 = 1;   // Scale height to 50%

    // Calculate new width and height
    float new_width = Obj->width * scale_x;
    float new_height = Obj->height * scale_y;
    float new_width2 = Obj->width * scale_x2;
    float new_height2 = Obj->height * scale_y2;

    al_draw_scaled_bitmap(Obj->current_img,
                          0, 0, Obj->width, Obj->height, // Source bitmap coordinates
                          Obj->x, Obj->y,                // Destination coordinates
                          new_width, new_height,         // Scaled width and height
                          0);                            // Flags
    al_draw_scaled_bitmap(Obj->current_img2,
                          0, 0, Obj->width, Obj->height, // Source bitmap coordinates
                          Obj->x2, Obj->y2,              // Destination coordinates
                          new_width2, new_height2,       // Scaled width and height
                          0);                            // Flags
}

void Boss2_destroy(Elements *self)
{
    Boss2 *Obj = ((Boss2 *)(self->pDerivedObj));
    if (Obj)
    {
        if (Obj->current_img)
        {
            al_destroy_bitmap(Obj->current_img);
        }
        if (Obj->hitbox)
        {
            free(Obj->hitbox);
        }
        free(Obj);
    }
    if (self)
        free(self);
}