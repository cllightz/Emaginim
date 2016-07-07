#pragma once
#include "PlayerBullet.h"

class GatlingBullet : public PlayerBullet {
public:
	GatlingBullet( Player& player, pixel X ) {
		id = TEXTURE_BULLET;

		x = player.getX() + X;
		y = player.getY();
		x_previous = x;
		y_previous = y;

		w = 2.;
		h = 3.;
		rx = 0.;
		ry = 16.;

		r = w / 2.;

		v_x = 0.;
		v_y = -M_PI*M_PI*M_E*M_E;
	}
};