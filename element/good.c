#include "Good.h"
#include "../shapes/Rectangle.h"

/*
   [Good function]
*/
Elements *New_Good(int label)
{
    Good *pDerivedObj = (Good *)malloc(sizeof(Good));
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
    pObj->Draw = Good_draw;
    pObj->Update = Good_update;
    pObj->Interact = Good_interact;
    pObj->Destroy = Good_destory;
    return pObj;
}
void Good_update(Elements *self)
{
    Good *pf = ((Good *)(self->pDerivedObj));
    _Good_update_position(self, 0, pf->v);
    if(pf->y<200)
        self->dele = true;
}
void _Good_update_position(Elements *self, int dx, int dy)
{
    Good *pf = ((Good *)(self->pDerivedObj));
    pf->x += dx;
    pf->y += dy;
}
void Good_interact(Elements *self, Elements *tar) {}
void Good_draw(Elements *self)
{
    Good *Obj = ((Good *)(self->pDerivedObj));
    al_draw_bitmap(Obj->img, Obj->x, Obj->y, 0);
}
void Good_destory(Elements *self)
{
    Good *Obj = ((Good *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj);
    free(self);
}
