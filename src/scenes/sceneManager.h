#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene.h"

void initSceneManager(void);
void changeScene(SceneType newScene);
void updateCurrentScene(void);
void drawCurrentScene(void);
void unloadCurrentScene(void);
SceneType getCurrentScene(void);

#endif // SCENE_MANAGER_H 