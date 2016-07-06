#pragma once
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <Mikan.h>
#include "defines.h"
#include "Player.h"

class PlayerBullet {
private:
	texture_t id;
	pixel x;
	pixel y;
	pixel x_previous;
	pixel y_previous;
	pixel v_x;
	pixel v_y;
	pixel w;
	pixel h;
	pixel r;

public:
	PlayerBullet( Player& player ) {
		id = TEXTURE_BULLET;

		x = player.getX();
		y = player.getY();
		x_previous = x;
		y_previous = y;

		w = 16.;
		h = 16.;

		r = w / 2.;

		v_x = 0.;
		v_y = -M_PI*M_PI*M_E*M_E;
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

	inline PlayerBullet& draw() {
		MikanDraw->DrawTexture( id, round( x - w / 2 ), round( y - h / 2 ), 4 * w, 0, w, h );
		return *this;
	}

	inline PlayerBullet& move() {
		x_previous = x;
		y_previous = y;
		x += v_x;
		y += v_y;
		return *this;
	}
};

