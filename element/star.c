#include "star.h"
#include "../shapes/Rectangle.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 672
/*
   [Star function]
*/
Elements *New_Star(int label)
{
    Star *pDerivedObj = (Star *)malloc(sizeof(Star));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/star.png");
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pDerivedObj->x = -400;
    pDerivedObj->y = -400;
    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Star_update;
    pObj->Interact = Star_interact;
    pObj->Draw = Star_draw;
    pObj->Destroy = Star_destory;
    return pObj;
}
void Star_update(Elements *self)
{
    Star *Obj = ((Star *)(self->pDerivedObj));
    double dt=0.5;
    if (key_state[ALLEGRO_KEY_UP]) {
        Obj->x = 240;
        Obj->y = 190;
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }
    else if (key_state[ALLEGRO_KEY_DOWN]) {
        Obj->x = 350;
        Obj->y = 290;
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }
    else if (key_state[ALLEGRO_KEY_LEFT]) {
        Obj->x = 270;
        Obj->y = 230;
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }
    else if (key_state[ALLEGRO_KEY_RIGHT]) {
        Obj->x = 430;
        Obj->y = 190;
        Obj->image_switched = true;
        Obj->switch_timer = 2.0; 
    }

    if (Obj->image_switched) {
        Obj->switch_timer -= dt;
        if (Obj->switch_timer <= 0) {
            Obj->x = -500;
            Obj->y = -500;
            Obj->image_switched = false;
        }
    }
}

void Star_interact(Elements *self, Elements *tar) {}
void Star_draw(Elements *self)
{
    Star *Obj = ((Star *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Star_destory(Elements *self)
{
    Star *Obj = ((Star *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
