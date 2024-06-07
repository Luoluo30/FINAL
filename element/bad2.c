#include "Bad2.h"
#include "../shapes/Rectangle.h"

/*
   [Bad function]
*/
Elements *New_Bad2(int label)
{
    Bad2 *pDerivedObj = (Bad2 *)malloc(sizeof(Bad2));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/bad.png");
    pDerivedObj->x = 0;
    pDerivedObj->y = 550;
    pDerivedObj->v = -10;
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pObj->pDerivedObj = pDerivedObj;
    // setting derived object function
    pObj->Draw = Bad2_draw;
    pObj->Update = Bad2_update;
    pObj->Interact = Bad2_interact;
    pObj->Destroy = Bad2_destory;
    return pObj;
}
void Bad2_update(Elements *self)
{
    Bad2 *pf = ((Bad2 *)(self->pDerivedObj));
    _Bad2_update_position(self, 0, pf->v);
    if(pf->y<200)
        self->dele = true;
}
void _Bad2_update_position(Elements *self, int dx, int dy)
{
    Bad2 *pf = ((Bad2 *)(self->pDerivedObj));
    pf->x += dx;
    pf->y += dy;
}
void Bad2_interact(Elements *self, Elements *tar) {}
void Bad2_draw(Elements *self)
{
    Bad2 *Obj = ((Bad2 *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Bad2_destory(Elements *self)
{
    Bad2 *Obj = ((Bad2 *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
