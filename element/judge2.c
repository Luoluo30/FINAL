#include "judge2.h"
#include "../global.h"
#include "../shapes/Circle.h"
#include <allegro5/allegro_primitives.h>
Elements *New_Judge2(int label)
{
    Judge2 *pDerivedObj = (Judge2 *)malloc(sizeof(Judge2));
    Elements *pObj = New_Elements(label);
    pDerivedObj->x = 85;
    pDerivedObj->y = 590;
    pDerivedObj->r = 53;
    pDerivedObj->color = al_map_rgb(166, 255, 166);
    pDerivedObj->hitbox_pf = New_Circle(pDerivedObj->x,  pDerivedObj->y, 5);
    pDerivedObj->hitbox_gd = New_Circle(pDerivedObj->x,  pDerivedObj->y, 30);
    pDerivedObj->hitbox_ok = New_Circle(pDerivedObj->x,  pDerivedObj->y, 50);
    
    // setting the interact object
    pObj->inter_obj[pObj->inter_len++] = Beat2_L;
    pObj->inter_obj[pObj->inter_len++] = Timer2_L;
    /*pObj->inter_obj[pObj->inter_len++] = Tree_L;*/

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Draw = Judge2_draw;
    pObj->Update = Judge2_update;
    pObj->Interact = Judge2_interact;
    pObj->Destroy = Judge2_destory;
    return pObj;
}
void Judge2_update(Elements *self)
{
    //Judge *Obj = ((Judge *)(self->pDerivedObj));
    // if(key_state[ALLEGRO_KEY_SPACE])
    // {
    //     Obj->color = al_map_rgb(0, 0, 0);
    // }
    // else
    // {
    //     Obj->color = al_map_rgb(153, 204, 51);
    // }
}
void Judge2_interact(Elements *self, Elements *tar)
{
    if (tar->label == Timer2_L)
    {
        Timer2 *tm = ((Timer2 *)(tar->pDerivedObj));
        if (tm->count == 1405)
            self->dele = true;
    }
}
void Judge2_draw(Elements *self)
{
    Judge2 *Obj = ((Judge2 *)(self->pDerivedObj));
    al_draw_circle(Obj->x, Obj->y, Obj->r, al_map_rgb(0, 0, 0), 6);
    al_draw_filled_circle(Obj->x, Obj->y, Obj->r, Obj->color);
}
void Judge2_destory(Elements *self)
{
    Judge2 *Obj = ((Judge2 *)(self->pDerivedObj));
    free(Obj->hitbox_pf);
    free(Obj->hitbox_gd);
    free(Obj);
    free(self);
}