#include "timer.h"
#include "../scene/sceneManager.h"
#include <stdbool.h>
#include <allegro5/allegro_primitives.h>
// count the time when the game starts
/*
   [Timer function]
*/
Elements *New_Timer(int label)
{
    Timer *pDerivedObj = (Timer *)malloc(sizeof(Timer));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->t = al_create_timer(1.0/60);
    al_start_timer(pDerivedObj->t);
    pDerivedObj->count = 0;
    pDerivedObj->last = 0;
    pDerivedObj->x = -WIDTH;
    pDerivedObj->y = 10;
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Timer_update;
    pObj->Interact = Timer_interact;
    pObj->Draw = Timer_draw;
    pObj->Destroy = Timer_destory;
    return pObj;
}
void Timer_update(Elements *self)
{
    Timer *Obj = ((Timer *)(self->pDerivedObj));
    _Timer_update_position(self, Obj->count, 0);
    Obj->count = al_get_timer_count(Obj->t);
    //97, 159, 221, 304, 1111, 1180, 1282
    int count[1000] = {312, 352, 372, 392, 472, 552, 582, 622, 672, 702, 782, 812, 862, 912, 942, 1002, 1022, 1082, 1102, 1152, 1182, 1232, 1262, 1292, 1352, 1402, 1422, 1472, 1512, 1562, 1582, 1632, 1652, 1672, 1722, 1742, 1792, 1832, 1852, 1872, 1902, 1952, 1972, 1992, 2042, 2062, 2112, 2152, 2202, 2222, 2362, 2382, 2432, 2452, 2512, 2542, 2592, 2672, 2702, 2782, 2832, 2862, 2912, 2992, 3022, 3082, 3102, 3162, 3182, 3212, 3232, 3302, 3512, 3592, 3612, 3652, 3672, 3732, 3792, 3812, 3832, 3872, 3912, 3992, 4042, 4062, 4112, 4132, 4152, 4232, 4252, 4312, 4362, 4382, 4432, 4452, 4472, 4552, 4572, 4612, 4632, 4682, 4702, 4752, 4772, 4802, 4862, 4912, 4962, 5640, 5690, 5710, 5760, 5800, 5850, 5870, 5920, 5940, 5960, 6010, 6030, 6080, 6120, 6140, 6160, 6190, 6240, 6260, 6280, 6330, 6350, 6400, 6440, 6490, 6510, 6540, 6600, 6650, 6670, 6720, 6740, 6760, 6800, 6830, 6880, 6960, 7050, 7070, 7110, 7130, 7190, 7250, 7270, 7290, 7330, 7370, 7450, 7500, 7520, 7570, 7590, 7610, 7690, 7710, 7770, 7820, 7840, 7890, 7910, 7930, 8010, 8030, 8070, 8090, 8140, 8160, 8210, 8230, 8600, 8660, 8680, 8720, 8740, 8760, 8800, 8830, 8880, 8900, 8920, 10120, 10150, 10180, 10200, 10240, 10280, 10310, 10360, 10400, 10440, 10480, 10520, 10550, 10590, 10620, 10640, 10660, 10720, 10740, 10780, 10820, 10860, 10900, 10930, 10980, 11020, 11040, 11060, 11100, 11140, 11180, 11200, 11220, 11260, 11280, 11300, 11340, 11360, 11380, 11430, 11460, 11600, 11640, 11670, 11700, 11740, 11760, 11800, 11830, 11860, 11920, 11980, 12000, 12020, 12040, 12070, 12100, 12120, 12150, 12190, 12220, 12240, 12280, 12310, 12340, 12380, 12400, 12420, 12440, 12470, 12510, 12560, 12600, 12630, 12700, 12720, 12740, 12760, 12790, 12810, 12830, 12860, 12880, 12900, 12920, 12990, 13050, 13070, 13100, 13150, 13180, 13200, 13230, 13260, 13280, 13310, 13350, 13370, 13390, 13420, 13450, 13470, 13500, 13530, 13550, 13580, 13600, 13630, 13660, 13690, 13710};
    for(int i=0; i<1000; i++)
    {
        if(Obj->count==count[i] && Obj->count!=Obj->last)
        {
            Elements *bt = New_Beat(Beat_L, 1000, 590, -6, al_map_rgb(255, 255, 255));
            _Register_elements(scene, bt);
            Obj->last = Obj->count;
        }
    }
    if(Obj->count == 9000) //9000
    {
        Elements *gun = New_Gun(Gun_L);
        _Register_elements(scene, gun);
    }
    if(Obj->count == 10000) //10000
    {
        Elements *gun = New_Gun(Gun_L);
        _Remove_elements(scene, gun);
    }
}
void _Timer_update_position(Elements *self, int dx, int dy)
{
    Timer *Obj = ((Timer *)(self->pDerivedObj));
    Obj->x = -WIDTH + WIDTH*dx/14220;
    Obj->y += dy;
}
void Timer_interact(Elements *self, Elements *tar)
{

}
void Timer_draw(Elements *self)
{
    Timer *Obj = ((Timer*)(self->pDerivedObj));
    al_draw_filled_rectangle(Obj->x, 0, Obj->x+WIDTH, Obj->y, al_map_rgb(255, 0, 0));
}
void Timer_destory(Elements *self)
{
    Timer *Obj = ((Timer *)(self->pDerivedObj));
    al_destroy_timer(Obj->t);
    free(Obj);
    free(self);
}

