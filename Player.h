#pragma once
#include <cmath>
#include <vector>
#include <Mikan.h>
#include "defines.h"
#include "EnemyBullet.h"

class Player {
private:
	texture_t id;
	pixel x;
	pixel y;
	pixel w;
	pixel h;
	pixel r;

public:
	inline Player() {}

	inline Player( pixel X, pixel Y ) {
		id = TEXTURE_PLAYER;

		x = X;
		y = Y;
		w = 32.;
		h = 32.;

		r = w / 2.;
	}

	inline Player& move() {
		// ©«ª¨
		char S = MikanInput->GetKeyNum( K_LSHIFT ) ? 0b10000 : 0;
		char L = MikanInput->GetKeyNum( K_LEFT   ) ? 0b01000 : 0;
		char D = MikanInput->GetKeyNum( K_DOWN   ) ? 0b00100 : 0;
		char U = MikanInput->GetKeyNum( K_UP     ) ? 0b00010 : 0;
		char R = MikanInput->GetKeyNum( K_RIGHT  ) ? 0b00001 : 0;
		char K = S | L | D | U | R;

		pixel v_fast   = 4.5;
		pixel v_fast_s = v_fast * sqrt( .5 );
		pixel v_slow   = 1.5;
		pixel v_slow_s = v_slow * sqrt( .5 );

		switch ( K ) {
			case 0b00010:
			case 0b01011:
				y -= v_fast;
				break;

			case 0b01010:
				y -= v_fast_s;
				x -= v_fast_s;
				break;

			case 0b01000:
			case 0b01110:
				x -= v_fast;
				break;

			case 0b01100:
				y += v_fast_s;
				x -= v_fast_s;
				break;

			case 0b00100:
			case 0b01101:
				y += v_fast;
				break;

			case 0b00101:
				y += v_fast_s;
				x += v_fast_s;
				break;

			case 0b00001:
			case 0b00111:
				x += v_fast;
				break;

			case 0b00011:
				y -= v_fast_s;
				x += v_fast_s;
				break;

			case 0b10010:
			case 0b11011:
				y -= v_slow;
				break;

			case 0b11010:
				y -= v_slow_s;
				x -= v_slow_s;
				break;

			case 0b11000:
			case 0b11110:
				x -= v_slow;
				break;

			case 0b11100:
				y += v_slow_s;
				x -= v_slow_s;
				break;

			case 0b10100:
			case 0b11101:
				y += v_slow;
				break;

			case 0b10101:
				y += v_slow_s;
				x += v_slow_s;
				break;

			case 0b10001:
			case 0b10111:
				x += v_slow;
				break;

			case 0b10011:
				y -= v_slow_s;
				x += v_slow_s;
				break;


		}

		if ( y < 0. ) {
			y = 0.;
		}

		if ( MikanWindow->GetWindowHeight( 1 ) - 1. < y ) {
			y = MikanWindow->GetWindowHeight( 1 ) - 1.;
		}

		if ( x < 0. ) {
			x = 0.;
		}

		if ( MikanWindow->GetWindowWidth( 1 ) - 1. < x ) {
			x = MikanWindow->GetWindowWidth( 1 ) - 1.;
		}
		return *this;
	}

	inline Player& draw() {
		MikanDraw->DrawTexture( id, round( x - w / 2. ), round( y - h / 2. ), 0, 0, w, h );
		return *this;
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
};

