#include "guncircle.h"
#include "../global.h"
#include "../shapes/Circle.h"
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#define SCREEN_WIDTH 900

Elements *New_Guncircle(int label)
{
    Guncircle *pDerivedObj = (Guncircle *)malloc(sizeof(Guncircle));
    Elements *pObj = New_Elements(label);
    pDerivedObj->x = SCREEN_WIDTH / 2;
    pDerivedObj->y = 590;
    pDerivedObj->r = 80;
    pDerivedObj->color = al_map_rgb(255, 255, 255);

    // for shaking
    pDerivedObj->shake_x = 0;
    pDerivedObj->shake_y = 0;
    pDerivedObj->shake_magnitude = 5;
    
    // setting the interact object
    pObj->inter_obj[pObj->inter_len++] = Timer_L;
    /*pObj->inter_obj[pObj->inter_len++] = Tree_L;*/

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Draw = Guncircle_draw;
    pObj->Update = Guncircle_update;
    pObj->Interact = Guncircle_interact;
    pObj->Destroy = Guncircle_destory;
    return pObj;
}

void Guncircle_update(Elements *self)
{
    Guncircle *Obj = ((Guncircle *)(self->pDerivedObj));
    if (key_state[ALLEGRO_KEY_LEFT] || key_state[ALLEGRO_KEY_RIGHT])
    {
        score_increment = 10; 
        Obj->shake_x = (rand() % (2 * Obj->shake_magnitude + 1)) - Obj->shake_magnitude;
        Obj->shake_y = (rand() % (2 * Obj->shake_magnitude + 1)) - Obj->shake_magnitude;
    }
    else
    {
        // 重置震動
        Obj->shake_x = 0;
        Obj->shake_y = 0;
    }
}

void Guncircle_interact(Elements *self, Elements *tar)
{
    if (tar->label == Timer_L)
    {
        Timer *tm = ((Timer *)(tar->pDerivedObj));
        if (tm->count >= 10000)
            self->dele = true;
    }
}

void Guncircle_draw(Elements *self)
{
    Guncircle *Obj = ((Guncircle *)(self->pDerivedObj));
    al_draw_circle(Obj->x + Obj->shake_x, Obj->y + Obj->shake_y, Obj->r, al_map_rgb(0, 0, 0), 6);
    al_draw_filled_circle(Obj->x + Obj->shake_x, Obj->y + Obj->shake_y, Obj->r, Obj->color);
}

void Guncircle_destory(Elements *self)
{
    Guncircle *Obj = ((Guncircle *)(self->pDerivedObj));
    free(Obj);
    free(self);
}
