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
    pDerivedObj->b = true;
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
    if(key_state[ALLEGRO_KEY_SPACE])
        printf("%d\n", Obj->count);
    //-90
    int count[10000] = {143, 167, 185, 206, 225, 243, 262, 277, 297, 317, 337, 357, 380,416, 442, 462, 486, 511, 531, 551, 576, 591, 616, 635, 679, 704, 725, 752, 779, 800, 823, 847, 876, 899, 920, 940, 961, 984, 1006, 1035, 1055, 1076, 1099, 1127, 1150, 1178, 1205, 1227, 1250, 1278, 1301, 1322, 1336, 2991, 3004, 3018, 3036, 3050, 3069, 3090, 3112, 3127, 3141, 3175, 3190, 3222, 3235, 3248, 3265, 3278, 3292, 3305, 3318, 3334, 3353, 3368, 3369, 3381, 3399, 3413, 3433, 3453, 3474, 3490, 3502, 3519, 3540, 3557, 3579, 3598, 3623, 3641, 3663, 3682, 3697, 3795, 3813, 3826, 3848, 3871, 3891, 3906, 3927, 3941, 3960, 3982, 3999, 4021, 4041, 4062, 4079, 4097, 4112, 4125, 4141, 4159, 4178, 4197, 4218, 4239, 4253, 4273, 4286, 4305, 4327, 4348, 4368, 4389, 4409, 4427, 4447, 4464, 4481, 4503, 4523, 4545, 4564, 4585, 4606, 4631, 4653, 4674, 4695, 4718, 4739, 4762, 4782, 4802, 4823, 4845, 4867, 4891, 4911, 4931, 4949, 4971, 4994, 5015, 5036, 5057, 5079, 5099, 5120, 5142, 5163, 5176, 5203, 5226, 5246, 5266, 5288, 5308, 5329, 5350, 5372, 5394, 5415, 5436, 5458, 5478, 5502, 5521};
    for(int i=0; i<10000; i++)
    {
        if(Obj->count==count[i] && Obj->count!=Obj->last)
        {
            if(Obj->count<=1500)
            {
                Elements *bt = New_Beat2(Beat2_L, 1000, 590, -17, al_map_rgb(255, 255, 111));
                _Register_elements(scene, bt);
            }
            else if(Obj->count<=6000)
            {
                Elements *bt = New_Beat2(Beat2_L, 1000, 590, -17, al_map_rgb(255, 96, 175));
                _Register_elements(scene, bt);
            }
            Obj->last = Obj->count;
        }
    }
    if(Obj->count >= 1405 && Obj->b == true) 
    {
        Obj->b = false;
        Elements *gun = New_Gun2(Gun2_L);
        _Register_elements(scene, gun);
        Elements *gunc = New_Guncircle2(Guncircle2_L);
        _Register_elements(scene, gunc);
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

