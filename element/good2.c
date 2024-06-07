#include "good2.h"
#include "../shapes/Rectangle.h"

/*
   [Good function]
*/
Elements *New_Good2(int label)
{
    Good2 *pDerivedObj = (Good2 *)malloc(sizeof(Good2));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->img = al_load_bitmap("assets/image/good.png");
    pDerivedObj->x = 0;
    pDerivedObj->y = 550;
    pDerivedObj->v = -10;
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);
    pObj->pDerivedObj = pDerivedObj;
    // setting derived object function
    pObj->Draw = Good2_draw;
    pObj->Update = Good2_update;
    pObj->Interact = Good2_interact;
    pObj->Destroy = Good2_destory;
    return pObj;
}
void Good2_update(Elements *self)
{
    Good2 *pf = ((Good2 *)(self->pDerivedObj));
    _Good2_update_position(self, 0, pf->v);
    if(pf->y<200)
        self->dele = true;
}
void _Good2_update_position(Elements *self, int dx, int dy)
{
    Good2 *pf = ((Good2 *)(self->pDerivedObj));
    pf->x += dx;
    pf->y += dy;
}
void Good2_interact(Elements *self, Elements *tar) {}
void Good2_draw(Elements *self)
{
    Good2 *Obj = ((Good2 *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Good2_destory(Elements *self)
{
    Good2 *Obj = ((Good2 *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
