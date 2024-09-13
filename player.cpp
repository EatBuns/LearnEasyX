#include "player.h"

void Player::on_enter()
{
	peashooter_idle_right_animation.setAtlas(&peashooter_idle_right);
	peashooter_idle_left_animation.setAtlas(&peashooter_idle_left);
	peashooter_die_right_animation.setAtlas(&peashooter_die_right);
	peashooter_die_left_animation.setAtlas(&peashooter_die_left);
	peashooter_run_right_animation.setAtlas(&peashooter_run_right);
	peashooter_run_left_animation.setAtlas(&peashooter_run_left);

	peashooter_idle_right_animation.setInterval(70);
	peashooter_idle_left_animation.setInterval(70);
	peashooter_die_right_animation.setInterval(70);
	peashooter_die_left_animation.setInterval(70);
	peashooter_run_right_animation.setInterval(70);
	peashooter_run_left_animation.setInterval(70);

	current_Animation = &peashooter_idle_right_animation;
}

void Player::on_update(int delta)
{
	current_Animation->onUpdate(delta);

	switch (direct)
	{
	case DIRECTION::D:
		
		break;
	case DIRECTION::A:
		
		break;
	case DIRECTION::UP:
		if (jumponce)
		{
			
			jumponce = false;
		}
		break;
	}
	
	
	
}

void Player::on_draw(const camera& cm, int x, int y)
{
	float cm_x = cm.getPosition().x;
	float cm_y = cm.getPosition().y;
	current_Animation->onDraw(100 - cm_x, 100 - cm_y);
}

void Player::on_input(const ExMessage& msg)
{
	if(msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case 0x41:
			direct = DIRECTION::A;
			current_Animation = &peashooter_run_left_animation;
			break;
		case 0x44:
			direct = DIRECTION::D;
			current_Animation = &peashooter_run_right_animation;
			break;
		case VK_SPACE:
			direct = DIRECTION::UP;
			//jumponce = true;
			break;
			
		}
	}
	else if(msg.message == WM_KEYUP)
	{
		switch (msg.vkcode)
		{
		case 0x41:
			direct = DIRECTION::NONE;
			current_Animation = &peashooter_idle_left_animation;
			break;
		case 0x44:
			direct = DIRECTION::NONE;
			current_Animation = &peashooter_idle_right_animation;
			break;
		case VK_SPACE:
			direct = DIRECTION::NONE;
			jumponce = true;
			break;
		}
	}
}
