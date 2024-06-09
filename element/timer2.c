#include "timer2.h"
#include "../scene/sceneManager.h"
#include <stdbool.h>
#include <allegro5/allegro_primitives.h>
// count the time when the game starts
/*
   [Timer function]
*/
Elements *New_Timer2(int label)
{
    Timer2 *pDerivedObj = (Timer2 *)malloc(sizeof(Timer2));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->t = al_create_timer(1.0/60);
    al_start_timer(pDerivedObj->t);
    pDerivedObj->count = 0;
    pDerivedObj->last = 0;
    pDerivedObj->x = -WIDTH;
    pDerivedObj->y = 10;
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Timer2_update;
    pObj->Interact = Timer2_interact;
    pObj->Draw = Timer2_draw;
    pObj->Destroy = Timer2_destory;
    return pObj;
}
void Timer2_update(Elements *self)
{
    Timer2 *Obj = ((Timer2 *)(self->pDerivedObj));
    _Timer2_update_position(self, Obj->count, 0);
    Obj->count = al_get_timer_count(Obj->t);
    //if(key_state[ALLEGRO_KEY_SPACE])
         //printf("%d\n", Obj->count);
    //-90
    // 143, 167, 185, 206, 225, 300, 317, 337, 357, 377, 
    int count[10000] = {416, 451, 471, 491, 511};
    for(int i=0; i<10000; i++)
    {
        if(Obj->count==count[i] && Obj->count!=Obj->last)
        {
            if(Obj->count<=1000)
            {
                Elements *bt = New_Beat2(Beat2_L, 1000, 590, -17, al_map_rgb(255, 255, 111));
                _Register_elements(scene, bt);
            }
            Obj->last = Obj->count;
        }
    }
    if(Obj->count == 9000) //9000
    {
        Elements *gun = New_Gun2(Gun2_L);
        _Register_elements(scene, gun);
    }
    if(Obj->count == 10000) //10000
    {
        Elements *gun = New_Gun2(Gun2_L);
        _Remove_elements(scene, gun);
    }
    if(key_state[ALLEGRO_KEY_SPACE]){
        //printf("%d\n", Obj->count);
    }
}
void _Timer2_update_position(Elements *self, int dx, int dy)
{
    Timer2 *Obj = ((Timer2 *)(self->pDerivedObj));
    Obj->x = -WIDTH + WIDTH*dx/6660;
    Obj->y += dy;
}
void Timer2_interact(Elements *self, Elements *tar)
{

}
void Timer2_draw(Elements *self)
{
    Timer2 *Obj = ((Timer2*)(self->pDerivedObj));
    al_draw_filled_rectangle(Obj->x, 0, Obj->x+WIDTH, Obj->y, al_map_rgb(255, 0, 0));
}
void Timer2_destory(Elements *self)
{
    Timer2 *Obj = ((Timer2 *)(self->pDerivedObj));
    al_destroy_timer(Obj->t);
    free(Obj);
    free(self);
}

