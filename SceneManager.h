#pragma once
#include "baseScene.h"
#include "comm.h"

extern BaseScene* mnScene;
extern BaseScene* gmScene;
extern BaseScene* SeScene;

class SceneManager
{
public:
	SceneManager() = default;
	~SceneManager() = default;

	//设置当前场景
	void setCurrentScene(BaseScene* scene);
	//切换场景
	void switchTO(SceneState state);
	void on_enter();
	void on_update(int delta);
	void on_draw();
	void on_input(const ExMessage& msg);
	void on_exit();

private:
	BaseScene* currentScene = nullptr;
};

