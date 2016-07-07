#pragma once
#include "PlayerBullet.h"
#include <random>

class GatlingBullet : public PlayerBullet {
public:
	inline GatlingBullet( Player& player, pixel X ) {
		id = TEXTURE_BULLET;

		x = player.getX() + X;
		y = player.getY();

		w = 2.;
		h = 4.;
		rx = 0.;
		ry = 16.;

		r = w / 2.;

		damage = 15;

		std::random_device rnd;
		std::mt19937 mt( rnd() );
		std::normal_distribution<> normal_velocity( 75., 1. );
		pixel v =  normal_velocity( mt );
		std::normal_distribution<> normal_angle( -M_PI_2, M_PI_4 / 1000. );
		radian theta = normal_angle( mt );
		v_x = cos( theta ) * v;
		v_y = sin( theta ) * v;
		std::normal_distribution<> normal_gap( -.5, .5 );
		radian gap = normal_gap( mt );
		x -= v_x * gap;
		y -= v_y * gap;

		x_previous = x;
		y_previous = y;

		a_x = 0.;
		a_y = 0.;
	}
};