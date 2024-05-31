#include "perfect.h"
#include "../shapes/Rectangle.h"

/*
   [Perfect function]
*/
Elements *New_Perfect(int label)
{
    Perfect *pDerivedObj = (Perfect *)malloc(sizeof(Perfect));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/perfect.png");
    pDerivedObj->x = 10;
    pDerivedObj->y = 550;
    pDerivedObj->v = -10;
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pObj->pDerivedObj = pDerivedObj;
    // setting derived object function
    pObj->Draw = Perfect_draw;
    pObj->Update = Perfect_update;
    pObj->Interact = Perfect_interact;
    pObj->Destroy = Perfect_destory;
    return pObj;
}
void Perfect_update(Elements *self)
{
    Perfect *pf = ((Perfect *)(self->pDerivedObj));
    _Perfect_update_position(self, 0, pf->v);
    if(pf->y<200)
        self->dele = true;
}
void _Perfect_update_position(Elements *self, int dx, int dy)
{
    Perfect *pf = ((Perfect *)(self->pDerivedObj));
    pf->x += dx;
    pf->y += dy;
}
void Perfect_interact(Elements *self, Elements *tar) {}
void Perfect_draw(Elements *self)
{
    Perfect *Obj = ((Perfect *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Perfect_destory(Elements *self)
{
    Perfect *Obj = ((Perfect *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
