#include "ok2.h"
#include "../shapes/Rectangle.h"

/*
   [Ok function]
*/
Elements *New_Ok2(int label)
{
    Ok2 *pDerivedObj = (Ok2 *)malloc(sizeof(Ok2));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/Ok.png");
    pDerivedObj->x = -10;
    pDerivedObj->y = 550;
    pDerivedObj->v = -10;
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pObj->pDerivedObj = pDerivedObj;
    // setting derived object function
    pObj->Draw = Ok2_draw;
    pObj->Update = Ok2_update;
    pObj->Interact = Ok2_interact;
    pObj->Destroy = Ok2_destory;
    return pObj;
}
void Ok2_update(Elements *self)
{
    Ok2 *pf = ((Ok2 *)(self->pDerivedObj));
    _Ok2_update_position(self, 0, pf->v);
    if(pf->y<200)
        self->dele = true;
}
void _Ok2_update_position(Elements *self, int dx, int dy)
{
    Ok2 *pf = ((Ok2 *)(self->pDerivedObj));
    pf->x += dx;
    pf->y += dy;
}
void Ok2_interact(Elements *self, Elements *tar) {}
void Ok2_draw(Elements *self)
{
    Ok2 *Obj = ((Ok2 *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Ok2_destory(Elements *self)
{
    Ok2 *Obj = ((Ok2 *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
