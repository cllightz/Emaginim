#pragma once
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <Mikan.h>
#include "defines.h"
#include "Player.h"

class Enemies;

class PlayerBullet {
protected:
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
	pixel rx;
	pixel ry;

	hp_t damage;

public:
	PlayerBullet() {}

	PlayerBullet( Player& player ) {
		id = TEXTURE_BULLET;

		x = player.getX();
		y = player.getY();
		x_previous = x;
		y_previous = y;

		w = 16.;
		h = 16.;
		rx = 4. * w;
		ry = 0.;

		r = w / 2.;

		v_x = 0.;
		v_y = -M_PI*M_PI*M_E*M_E;

		damage = 1.;
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

	inline PlayerBullet& move() {
		x_previous = x;
		y_previous = y;
		x += v_x;
		y += v_y;
		return *this;
	}

	bool isCollision( Enemies& );

	inline PlayerBullet& draw() {
		MikanDraw->DrawTextureC( id, round( x ), round( y ), rx, ry, w, h );
		return *this;
	}

protected:
	inline bool isReached( pixel X, pixel Y ) {
		if ( x_previous <= x ) {
			if ( y_previous <= y ) {
				return x <= X && y <= Y;
			} else {
				return x <= X && Y <= y;
			}
		} else {
			if ( y_previous <= y ) {
				return X <= x && y <= Y;
			} else {
				return X <= x && Y <= y;
			}
		}
	}
};

