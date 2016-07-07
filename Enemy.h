#pragma once
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
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
	double scale;
	pixel r;
	hp_t hp;
	pixel rx;
	pixel ry;

	pixel center_x;
	pixel center_y;
	radian theta;
	radian delta_theta;
	double k_theta_x;
	double k_theta_y;
	pixel amplitude;

public:
	inline Enemy() {
		id = TEXTURE_ENEMY;

		x = MikanWindow->GetWindowWidth( 1 ) / 2.;
		y = MikanWindow->GetWindowHeight( 1 ) / 2.;

		w = 32.;
		h = 32.;
		rx = 0.;
		ry = 0.;

		scale = 4.;
		r = scale * w / 2.;

		v_x = 0.;
		v_y = 0.;

		hp = 10000;

		center_x = MikanWindow->GetWindowWidth( 1 ) / 2.;
		center_y = MikanWindow->GetWindowHeight( 1 ) / 4.;
		theta = 0.;
		delta_theta = .005;
		k_theta_x = 5.;
		k_theta_y = 6.;
		amplitude = 100.;
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

		MikanDraw->Printf( FONT_PROMPT, 0, 0, "%d", hp );
		return hp <= 0 ||
			x <= L && v_x <= 000 ||
			R <= x && 000 <= v_x ||
			y <= T && v_y <= 000 ||
			B <= y && 000 <= v_y;
	}

	inline Enemy& draw() {
		MikanDraw->DrawTextureScalingC( id, round( x ), round( y ), rx, ry, w, h, scale );
		return *this;
	}

	inline Enemy& move() {
		theta += delta_theta;

		if ( M_PI < theta ) {
			theta - M_PI;
		}

		x = center_x + amplitude * sin( k_theta_x * theta );
		y = center_y + amplitude * sin( k_theta_y * theta );

		MikanDraw->Printf( FONT_PROMPT, 0, 50, "%f %f", x, y );
		return *this;
	}

	inline Enemy& hit( hp_t damage ) {
		hp -= damage;
		return *this;
	}
};

