#include "Bad.h"
#include "../shapes/Rectangle.h"

/*
   [Bad function]
*/
Elements *New_Bad(int label)
{
    Bad *pDerivedObj = (Bad *)malloc(sizeof(Bad));
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
    pObj->Draw = Bad_draw;
    pObj->Update = Bad_update;
    pObj->Interact = Bad_interact;
    pObj->Destroy = Bad_destory;
    return pObj;
}
void Bad_update(Elements *self)
{
    Bad *pf = ((Bad *)(self->pDerivedObj));
    _Bad_update_position(self, 0, pf->v);
    if(pf->y<200)
        self->dele = true;
}
void _Bad_update_position(Elements *self, int dx, int dy)
{
    Bad *pf = ((Bad *)(self->pDerivedObj));
    pf->x += dx;
    pf->y += dy;
}
void Bad_interact(Elements *self, Elements *tar) {}
void Bad_draw(Elements *self)
{
    Bad *Obj = ((Bad *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Bad_destory(Elements *self)
{
    Bad *Obj = ((Bad *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
