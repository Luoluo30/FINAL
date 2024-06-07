#include "score.h"
#include "../scene/sceneManager.h"
#include <stdbool.h>
#include <allegro5/allegro_primitives.h>
#include <string.h>
// count the time when the game starts
/*
   [Score function]
*/
Elements *New_Score(int label)
{
    Score *pDerivedObj = (Score *)malloc(sizeof(Score));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->count = 0;
    pDerivedObj->text_x = 775;
    pDerivedObj->text_y = 50;
    pDerivedObj->text1_x = 860;
    pDerivedObj->text1_y = 100;
    //strcpy(pDerivedObj->num, pDerivedObj->count);
    pDerivedObj->font = al_load_ttf_font("assets/font/vac.otf", 50, 0);
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Score_update;
    pObj->Interact = Score_interact;
    pObj->Draw = Score_draw;
    pObj->Destroy = Score_destory;
    return pObj;
}

void Score_update(Elements *self)
{
    Score *Obj = ((Score*)(self->pDerivedObj));
    if (score_increment != 0)
    {
        Obj->count += score_increment;
        score_increment = 0; // 重置增量
    }
}

void Score_interact(Elements *self, Elements *tar)
{

}
void Score_draw(Elements *self)
{
    Score *Obj = ((Score*)(self->pDerivedObj));
    char score_text[10];
    sprintf(score_text, "%d", Obj->count);
    al_draw_text(Obj->font, al_map_rgb(0, 0, 0), Obj->text_x, Obj->text_y, ALLEGRO_ALIGN_RIGHT, "Score");
    al_draw_text(Obj->font, al_map_rgb(0, 0, 0), Obj->text1_x, Obj->text1_y, ALLEGRO_ALIGN_RIGHT, score_text);
}
void Score_destory(Elements *self)
{
    Score *Obj = ((Score *)(self->pDerivedObj));
    al_destroy_font(Obj->font);
    free(Obj);
    free(self);
}

