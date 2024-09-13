#include "SceneManager.h"


void SceneManager::setCurrentScene(BaseScene* scene)
{
	this->currentScene = scene;
	this->currentScene->on_enter();
}

void SceneManager::switchTO(SceneState state)
{
	currentScene->on_exit();
	switch (state)
	{
	case mainScene:
		currentScene = mnScene;
		break;
	case gameScene:
		currentScene = gmScene;
		break;
	case selectorScene:
		currentScene = SeScene;
		break;
	default:
		break;
	}
	currentScene->on_enter();
}

void SceneManager::on_enter()
{
	currentScene->on_enter();
}
void SceneManager::on_update(int delta)
{
	currentScene->on_update(delta);
}
void SceneManager::on_exit()
{
	currentScene->on_exit();
}
void SceneManager::on_draw()
{
	currentScene->on_draw();
}
void SceneManager::on_input(const ExMessage& msg)
{
	currentScene->on_input(msg);
}
