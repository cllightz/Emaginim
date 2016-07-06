#pragma once
#include <cmath>
#include <vector>
#include <Mikan.h>
#include "defines.h"

class Enemy {
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
	inline Enemy() {
		id = TEXTURE_ENEMY;

		x = MikanWindow->GetWindowWidth() / 2.;
		y = -50;

		w = 32.;
		h = 32.;

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

	inline bool isDead() {
		pixel W = MikanWindow->GetWindowWidth( 1 );
		pixel H = MikanWindow->GetWindowHeight( 1 );
		pixel L = -W;
		pixel R = 2 * W;
		pixel T = -H;
		pixel B = 2 * H;

		return
			x <= L && v_x <= 000 ||
			R <= x && 000 <= v_x ||
			y <= T && v_y <= 000 ||
			B <= y && 000 <= v_y;
	}

	inline Enemy& draw() {
		MikanDraw->DrawTexture( id, round( x - w / 2 ), round( y - h / 2 ), 0, 0, w, h );
		return *this;
	}

	inline Enemy& move() {
		x += v_x;
		y += v_y;
		return *this;
	}
};
