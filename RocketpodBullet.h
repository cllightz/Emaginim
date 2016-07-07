#pragma once
#include "PlayerBullet.h"
#include <random>

class RocketpodBullet : public PlayerBullet {
public:
	RocketpodBullet( Player& player, pixel X = 0., pixel Y = 0., pixel A = 0., double sigma_angle = M_PI_4 / 1000., hp_t DAMAGE = 11. ) {
		id = TEXTURE_BULLET;

		x = player.getX() + X;
		y = player.getY() + Y;

		w = 6.;
		h = 32.;
		rx = 6.;
		ry = 16.;

		r = w / 2.;

		damage = DAMAGE;

		v_x = 0.;
		v_y = 0.;

		std::random_device rnd;
		std::mt19937 mt( rnd() );
		std::normal_distribution<> normal_acceleration( A, .01 );
		pixel a = normal_acceleration( mt );
		std::normal_distribution<> normal_angle( -M_PI_2, sigma_angle );
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