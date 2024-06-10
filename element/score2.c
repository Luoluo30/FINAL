#include "score2.h"
#include "../scene/sceneManager.h"
#include <stdbool.h>
#include <allegro5/allegro_primitives.h>
#include <string.h>
// count the time when the game starts
/*
   [Score function]
*/
Elements *New_Score2(int label)
{
    Score2 *pDerivedObj = (Score2 *)malloc(sizeof(Score2));
    Elements *pObj = New_Elements(label);
    // setting derived object member
    pDerivedObj->count = 0;
    pDerivedObj->text_x = 775;
    pDerivedObj->text_y = 50;
    pDerivedObj->text1_x = 860;
    pDerivedObj->text1_y = 100;
    //interect
    pObj->inter_obj[pObj->inter_len++] = Timer2_L;

    pDerivedObj->font = al_load_ttf_font("assets/font/vac.otf", 50, 0);
    pObj->pDerivedObj = pDerivedObj;
    pObj->Update = Score2_update;
    pObj->Interact = Score2_interact;
    pObj->Draw = Score2_draw;
    pObj->Destroy = Score2_destory;
    return pObj;
}

void Score2_update(Elements *self)
{
    Score2 *Obj = ((Score2*)(self->pDerivedObj));
    if (score_increment != 0)
    {
        Obj->count += score_increment;
        score_increment = 0; // 重置增量
    }
    end_score2 = Obj->count;
}

void Score2_interact(Elements *self, Elements *tar)
{
    if (tar->label == Timer2_L)
    {
        Timer2 *tm = ((Timer2 *)(tar->pDerivedObj));
        if (tm->count >= 6660)
            self->dele = true;
    }
}
void Score2_draw(Elements *self)
{
    Score2 *Obj = ((Score2*)(self->pDerivedObj));
    char score_text[10];
    sprintf(score_text, "%d", Obj->count);
    al_draw_text(Obj->font, al_map_rgb(0, 0, 0), Obj->text_x, Obj->text_y, ALLEGRO_ALIGN_RIGHT, "Score");
    al_draw_text(Obj->font, al_map_rgb(0, 0, 0), Obj->text1_x, Obj->text1_y, ALLEGRO_ALIGN_RIGHT, score_text);
}
void Score2_destory(Elements *self)
{
    Score2 *Obj = ((Score2 *)(self->pDerivedObj));
    al_destroy_font(Obj->font);
    free(Obj);
    free(self);
}

