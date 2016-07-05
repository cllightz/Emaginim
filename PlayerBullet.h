#pragma once
#include <cmath>
#include <vector>
#include <Mikan.h>
#include "defines.h"
#include "Player.h"

class PlayerBullet {
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
	PlayerBullet( Player& player ) {
		id = TEXTURE_BULLET;
		MikanDraw->CreateTexture( id, "bullet.png", TRC_ZERO );

		x = player.getX();
		y = player.getY();

		w = 16.;
		h = 16.;

		r = w / 2.;

		v_x = 0.;
		v_y = -sqrt( 3. );
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

	inline PlayerBullet& draw() {
		MikanDraw->DrawTexture( id, round( x - w / 2 ), round( y - h / 2 ), 4 * w, 0, w, h );
		return *this;
	}

	inline PlayerBullet& move() {
		x += v_x;
		y += v_y;
		return *this;
	}
};

