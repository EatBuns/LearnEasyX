#pragma once
#include "comm.h"
#include "Atlas.h"
#include "Animation.h"
#include "camera.h"
#include  "physical_sim.h"
extern Atlas peashooter_idle_right;
extern Atlas peashooter_idle_left;
extern Atlas peashooter_die_right;
extern Atlas peashooter_die_left;
extern Atlas peashooter_run_right;
extern Atlas peashooter_run_left;

class Player
{
public:
	Player() = default;
	~Player() = default;

	void on_enter();
	void on_update(int delta);
	void on_draw(const camera& cm, int x, int y);
	void on_input(const ExMessage& msg);
private:
	Animation peashooter_idle_right_animation;
	Animation peashooter_idle_left_animation;
	Animation peashooter_die_right_animation;
	Animation peashooter_die_left_animation;
	Animation peashooter_run_right_animation;
	Animation peashooter_run_left_animation;
	Animation* current_Animation = nullptr;


	physical_sim phy;
	DIRECTION direct;
	bool jumponce = true;
};

