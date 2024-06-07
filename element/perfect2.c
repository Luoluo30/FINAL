#include "perfect2.h"
#include "../shapes/Rectangle.h"

/*
   [Perfect function]
*/
Elements *New_Perfect2(int label)
{
    Perfect2 *pDerivedObj = (Perfect2 *)malloc(sizeof(Perfect2));
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
    pObj->Draw = Perfect2_draw;
    pObj->Update = Perfect2_update;
    pObj->Interact = Perfect2_interact;
    pObj->Destroy = Perfect2_destory;
    return pObj;
}
void Perfect2_update(Elements *self)
{
    Perfect2 *pf = ((Perfect2 *)(self->pDerivedObj));
    _Perfect2_update_position(self, 0, pf->v);
    if(pf->y<200)
        self->dele = true;
}
void _Perfect2_update_position(Elements *self, int dx, int dy)
{
    Perfect2 *pf = ((Perfect2 *)(self->pDerivedObj));
    pf->x += dx;
    pf->y += dy;
}
void Perfect2_interact(Elements *self, Elements *tar) {}
void Perfect2_draw(Elements *self)
{
    Perfect2 *Obj = ((Perfect2 *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Perfect2_destory(Elements *self)
{
    Perfect2 *Obj = ((Perfect2 *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
