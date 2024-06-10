#include "guncircle2.h"
#include "../global.h"
#include "../shapes/Circle.h"
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#define SCREEN_WIDTH 900

Elements *New_Guncircle2(int label)
{
    Guncircle2 *pDerivedObj = (Guncircle2 *)malloc(sizeof(Guncircle2));
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
    pObj->inter_obj[pObj->inter_len++] = Timer2_L;
    /*pObj->inter_obj[pObj->inter_len++] = Tree_L;*/

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Draw = Guncircle2_draw;
    pObj->Update = Guncircle2_update;
    pObj->Interact = Guncircle2_interact;
    pObj->Destroy = Guncircle2_destory;
    return pObj;
}

void Guncircle2_update(Elements *self)
{
    Guncircle2 *Obj = ((Guncircle2 *)(self->pDerivedObj));
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

void Guncircle2_interact(Elements *self, Elements *tar)
{
    if (tar->label == Timer2_L)
    {
        Timer2 *tm = ((Timer2 *)(tar->pDerivedObj));
        if (tm->count >= 3012)
            self->dele = true;
    }
}

void Guncircle2_draw(Elements *self)
{
    Guncircle2 *Obj = ((Guncircle2 *)(self->pDerivedObj));
    al_draw_circle(Obj->x + Obj->shake_x, Obj->y + Obj->shake_y, Obj->r, al_map_rgb(0, 0, 0), 6);
    al_draw_filled_circle(Obj->x + Obj->shake_x, Obj->y + Obj->shake_y, Obj->r, Obj->color);
}

void Guncircle2_destory(Elements *self)
{
    Guncircle2 *Obj = ((Guncircle2 *)(self->pDerivedObj));
    free(Obj);
    free(self);
}
