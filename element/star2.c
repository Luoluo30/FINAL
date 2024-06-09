#include "star2.h"
#include "../shapes/Rectangle.h"
#include <stdlib.h>

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 672

/*
   [Star function]
*/
Elements *New_Star2(int label)
{
    Star2 *pDerivedObj = (Star2 *)malloc(sizeof(Star2));
    Elements *pObj = New_Elements(label);

    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/star.png");
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pDerivedObj->x = -400;
    pDerivedObj->y = -400;
    pDerivedObj->id = 0;
    pDerivedObj->key_pressed = false; 

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Star2_update;
    pObj->Interact = Star2_interact;
    pObj->Draw = Star2_draw;
    pObj->Destroy = Star2_destory;

    return pObj;
}

void Star2_update(Elements *self)
{
    Star2 *Obj = ((Star2 *)(self->pDerivedObj));
    
    int positions[4][2] = {
        {240, 190},
        {350, 290},
        {270, 230},
        {430, 190}
    };

    if (key_state[ALLEGRO_KEY_SPACE]) {
        if (!Obj->key_pressed) {
            Obj->id = rand() % 4; 
            Obj->x = positions[Obj->id][0];
            Obj->y = positions[Obj->id][1];
            Obj->key_pressed = true;
        }
    } else {
        Obj->x = -400; 
        Obj->y = -400; 
        Obj->key_pressed = false; 
    }
}

void Star2_interact(Elements *self, Elements *tar) {}

void Star2_draw(Elements *self)
{
    Star2 *Obj = ((Star2 *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}

void Star2_destory(Elements *self)
{
    Star2 *Obj = ((Star2 *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
