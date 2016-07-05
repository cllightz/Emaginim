#pragma once
#include <cmath>
#include <vector>
#include <Mikan.h>
#include "defines.h"

class EnemyBullet {
private:
	texture_t id;
	pixel x;
	pixel y;
	pixel v_x;
	pixel v_y;
	pixel w;
	pixel h;
	pixel r;

public:
	inline EnemyBullet() {
		id = TEXTURE_BULLET;
		MikanDraw->CreateTexture( id, "bullet.png", TRC_ZERO );

		x = MikanWindow->GetWindowWidth() / 2.;
		y = -50;

		w = 16.;
		h = 16.;

		r = w / 2.;

		v_x = double( rand() ) / double( RAND_MAX ) - .5;
		v_y = double( rand() ) / double( RAND_MAX ) + .5;
	}

	inline pixel getX() {
		return x;
	}

	inline pixel getY() {
		return y;
	}

	inline pixel getR() {
		return r;
	}

	inline EnemyBullet& draw() {
		MikanDraw->DrawTexture( id, round( x - w / 2 ), round( y - h / 2 ), 0, 0, w, h );
		return *this;
	}

	inline EnemyBullet& move() {
		x += v_x;
		y += v_y;
		return *this;
	}
};

