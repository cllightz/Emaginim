#pragma once
#include "PlayerBullet.h"
#include <random>

class RocketpodBullet : public PlayerBullet {
public:
	inline RocketpodBullet( Player& player, pixel X, pixel Y ) {
		id = TEXTURE_BULLET;

		x = player.getX() + X;
		y = player.getY() + Y;

		w = 6.;
		h = 32.;
		rx = 6.;
		ry = 16.;

		r = w / 2.;

		damage = 240;

		v_x = 0.;
		v_y = 0.;

		std::random_device rnd;
		std::mt19937 mt( rnd() );
		std::normal_distribution<> normal_acceleration( 2.5, .01 );
		pixel a = normal_acceleration( mt );
		std::normal_distribution<> normal_angle( -M_PI_2, M_PI_4 / 50 );
		radian theta = normal_angle( mt );
		a_x = cos( theta ) * a;
		a_y = sin( theta ) * a;
		std::normal_distribution<> normal_gap( -.5, .5 );
		radian gap = normal_gap( mt );
		x -= v_x * gap;
		y -= v_y * gap;

		x_previous = x;
		y_previous = y;
	}
};