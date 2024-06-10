#include "scene.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
/*
   [Menu object]
*/
typedef struct _Menu2
{
    ALLEGRO_FONT *font;
    ALLEGRO_SAMPLE *song;
    ALLEGRO_SAMPLE_INSTANCE *sample_instance;
    ALLEGRO_BITMAP *background;  // 添加背景
    int title_x, title_y;
    //點擊的範圍
    int button1_x, button1_y, button1_width, button1_height;
    int button2_height, button2_width, button2_y, button2_x;
    bool key_state[ALLEGRO_KEY_MAX];
    bool prev_key_state[ALLEGRO_KEY_MAX];

} Menu2;
Scene *New_Menu2(int label);
void menu_update2(Scene *self);
void menu_draw2(Scene *self);
void menu_destroy2(Scene *self);
