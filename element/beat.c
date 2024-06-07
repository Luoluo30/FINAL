#include "beat.h"
#include "perfect.h"
#include "good.h"
#include "bad.h"
#include "../global.h"
#include "../shapes/Circle.h"
#include "../scene/sceneManager.h"
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>
#include <stdlib.h>
#include "score.h"

//for the first beat
Elements *New_Beat(int label, int x, int y, int v, ALLEGRO_COLOR c)
{
    Beat *pDerivedObj = (Beat *)malloc(sizeof(Beat));
    Elements *pObj = New_Elements(label);
    pDerivedObj->id = rand() % 4;
    if (pDerivedObj->id == 0) 
        pDerivedObj->img = al_load_bitmap("assets/image/arrow_up.png");
    else if (pDerivedObj->id == 1) 
        pDerivedObj->img = al_load_bitmap("assets/image/arrow_down.png");
    else if (pDerivedObj->id == 2) 
        pDerivedObj->img = al_load_bitmap("assets/image/arrow_left.png");
    else if (pDerivedObj->id == 3) 
        pDerivedObj->img = al_load_bitmap("assets/image/arrow_right.png");
    
    
    pDerivedObj->x = x;
    pDerivedObj->y = y;
    pDerivedObj->r = 53;
    pDerivedObj->v = v;         //-4
    pDerivedObj->color = c;     //al_map_rgb(100, 100, 100)
    pDerivedObj->hitbox = New_Circle(pDerivedObj->x, pDerivedObj->y, 5);
    pDerivedObj->ev = false;    //for evaluating bad
    pDerivedObj->width = al_get_bitmap_width(pDerivedObj->img);
    pDerivedObj->height = al_get_bitmap_height(pDerivedObj->img);

    // setting the interact object
    pObj->inter_obj[pObj->inter_len++] = Judge_L;
    /*pObj->inter_obj[pObj->inter_len++] = Tree_L;*/

    // setting derived object function
    pObj->pDerivedObj = pDerivedObj;
    pObj->Draw = Beat_draw;
    pObj->Update = Beat_update;
    pObj->Interact = Beat_interact;
    pObj->Destroy = Beat_destory;
    return pObj;
}

void Beat_update(Elements *self)
{
    Beat *Obj = ((Beat *)(self->pDerivedObj));
    _Beat_update_position(self, Obj->v, 0);
    if (Obj->x <= 5 && Obj->ev == false)
    {
        //printf("Bad\n");
        Elements *bd = New_Bad(Bad_L);
        _Register_elements(scene, bd);
        Obj->ev = true;
    }
    if (Obj->x < -100)
    {
        self-> dele=true;
    }
}

void _Beat_update_position(Elements *self, int dx, int dy)
{
    Beat *Obj = ((Beat *)(self->pDerivedObj));
    Obj->x += dx;
    Obj->y += dy;
    Shape *hitbox = Obj->hitbox;
    hitbox->update_center_x(hitbox, dx);
    hitbox->update_center_y(hitbox, dy);
}

void Beat_interact(Elements *self, Elements *tar)
{
    Beat *Obj = ((Beat *)(self->pDerivedObj));
    Judge *judge = ((Judge *)(tar->pDerivedObj));   
    if(Obj->ev==false)
    {    
        if (judge->hitbox_pf->overlap(judge->hitbox_pf, Obj->hitbox))
        {
            if(Obj->id==0&&key_state[ALLEGRO_KEY_UP])
            {
                Elements *pf = New_Perfect(Perfect_L);
                _Register_elements(scene, pf);
                self-> dele=true;
                score_increment = 1000; 
            }
            else if((Obj->id==1&&key_state[ALLEGRO_KEY_DOWN]))
            {
                Elements *pf = New_Perfect(Perfect_L);
                _Register_elements(scene, pf);
                self-> dele=true;
                score_increment = 1000;
            }
            else if((Obj->id==2&&key_state[ALLEGRO_KEY_LEFT]))
            {
                Elements *pf = New_Perfect(Perfect_L);
                _Register_elements(scene, pf);
                self-> dele=true;
                score_increment = 1000; 
            }
            else if((Obj->id==3&&key_state[ALLEGRO_KEY_RIGHT]))
            {
                Elements *pf = New_Perfect(Perfect_L);
                _Register_elements(scene, pf);
                self-> dele=true;
                score_increment = 1000; 
            }
        }
        else if (judge->hitbox_gd->overlap(judge->hitbox_gd, Obj->hitbox))
        {
            if(Obj->id==0&&key_state[ALLEGRO_KEY_UP])
            {
                Elements *gd = New_Good(Good_L);
                _Register_elements(scene, gd);
                self-> dele=true;
                score_increment = 700; 
            }
            else if((Obj->id==1&&key_state[ALLEGRO_KEY_DOWN]))
            {
                Elements *gd = New_Good(Good_L);
                _Register_elements(scene, gd);
                self-> dele=true;
                score_increment = 700; 
            }
            else if((Obj->id==2&&key_state[ALLEGRO_KEY_LEFT]))
            {
                Elements *gd = New_Good(Good_L);
                _Register_elements(scene, gd);
                self-> dele=true;
                score_increment = 700; 
            }
            else if((Obj->id==3&&key_state[ALLEGRO_KEY_RIGHT]))
            {
                Elements *gd = New_Good(Good_L);
                _Register_elements(scene, gd);
                self-> dele=true;
                score_increment = 700; 
            }
        }
        else if (judge->hitbox_ok->overlap(judge->hitbox_ok, Obj->hitbox))
        {
            if(Obj->id==0&&key_state[ALLEGRO_KEY_UP])
            {
                Elements *okay = New_Ok(Ok_L);
                _Register_elements(scene, okay);
                self-> dele=true;
                score_increment = 300; 
            }
            else if((Obj->id==1&&key_state[ALLEGRO_KEY_DOWN]))
            {
                Elements *okay = New_Ok(Ok_L);
                _Register_elements(scene, okay);
                self-> dele=true;
                score_increment = 300; 
            }
            else if((Obj->id==2&&key_state[ALLEGRO_KEY_LEFT]))
            {
                Elements *okay = New_Ok(Ok_L);
                _Register_elements(scene, okay);
                self-> dele=true;
                score_increment = 300; 
            }
            else if((Obj->id==3&&key_state[ALLEGRO_KEY_RIGHT]))
            {
                Elements *okay = New_Ok(Ok_L);
                _Register_elements(scene, okay);
                self-> dele=true;
                score_increment = 300; 
            }
        }
    }
}

void Beat_draw(Elements *self)
{
    Beat *Obj = ((Beat *)(self->pDerivedObj));
    al_draw_filled_circle(Obj->x, Obj->y, Obj->r, Obj->color);
    al_draw_circle(Obj->x, Obj->y, Obj->r, al_map_rgb(0, 0, 0), 3);

    float scale_x = 0.33; // Scale width to 50%
    float scale_y = 0.33; // Scale height to 50%
    // Calculate new width and height
    float new_width = Obj->width * scale_x;
    float new_height = Obj->height * scale_y;
    al_draw_scaled_bitmap(Obj->img,
                          0, 0, Obj->width, Obj->height, // Source bitmap coordinates
                          Obj->x - 60, Obj->y - 62, // Destination coordinates
                          new_width, new_height, // Scaled width and height
                          0); // Flags
}

void Beat_destory(Elements *self)
{
    Beat *Obj = ((Beat *)(self->pDerivedObj));
    al_destroy_bitmap(Obj->img);
    free(Obj->hitbox);
    free(Obj);
    free(self);
}
