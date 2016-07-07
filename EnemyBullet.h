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
	inline EnemyBullet( pixel X, pixel Y, pixel V_X, pixel V_Y ) {
		id = TEXTURE_BULLET;

		x = X;
		y = Y;

		w = 16.;
		h = 16.;

		r = w / 2.;

		v_x = V_X;
		v_y = V_Y;
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
		pixel L = 0 - w;
		pixel R = W + w;
		pixel T = 0 - h;
		pixel B = H + h;

		return
			x <= L && v_x <= 000 ||
			R <= x && 000 <= v_x ||
			y <= T && v_y <= 000 ||
			B <= y && 000 <= v_y;
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

