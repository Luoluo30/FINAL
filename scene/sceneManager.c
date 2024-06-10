#include "sceneManager.h"
#include "menu.h"
#include "gamescene.h"
#include "gamescene2.h"
#include "menu2.h"
Scene *scene = NULL;
void create_scene(SceneType type)
{
    switch (type)
    {
    case Menu_L:
        scene = New_Menu(Menu_L);
        break;
    case GameScene_L:
        scene = New_GameScene(GameScene_L);
        break;
    case GameScene2_L:
        scene = New_GameScene2(GameScene2_L);
        break;
    case Menu_L2:
        scene = New_Menu2(Menu_L2);
        break;
    default:
        break;
    }
}