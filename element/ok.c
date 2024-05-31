#include "Ok.h"
#include "../shapes/Rectangle.h"

/*
   [Ok function]
*/
Elements *New_Ok(int label)
{
    Ok *pDerivedObj = (Ok *)malloc(sizeof(Ok));
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
    pObj->Draw = Ok_draw;
    pObj->Update = Ok_update;
    pObj->Interact = Ok_interact;
    pObj->Destroy = Ok_destory;
    return pObj;
}
void Ok_update(Elements *self)
{
    Ok *pf = ((Ok *)(self->pDerivedObj));
    _Ok_update_position(self, 0, pf->v);
    if(pf->y<200)
        self->dele = true;
}
void _Ok_update_position(Elements *self, int dx, int dy)
{
    Ok *pf = ((Ok *)(self->pDerivedObj));
    pf->x += dx;
    pf->y += dy;
}
void Ok_interact(Elements *self, Elements *tar) {}
void Ok_draw(Elements *self)
{
    Ok *Obj = ((Ok *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Ok_destory(Elements *self)
{
    Ok *Obj = ((Ok *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
