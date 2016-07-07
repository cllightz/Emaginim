#pragma once
#include "PlayerBullet.h"
#include <random>
#include "Enemy.h"

class MissileBullet : public PlayerBullet {
protected:
	pixel v;
	pixel a;
	radian theta;
	radian omega;
	radian omega_max;
	radian delta_omega;
	std::shared_ptr<Enemy>& enemy = std::shared_ptr<Enemy>();
	int counter;
	int start;

public:
	inline MissileBullet( Player& player, std::shared_ptr<Enemy>& ENEMY ) {
		id = TEXTURE_BULLET;

		x = player.getX();
		y = player.getY();
		x_previous = x;
		y_previous = y;

		w = 10.;
		h = 48.;
		rx = 12.;
		ry = 16.;

		r = w / 2.;

		damage = 1250;

		v_x = 0.;
		v_y = 0.;
		a_x = 0.;
		a_y = 0.;

		v = 0.;
		a = 0.5;

		theta = -M_PI_2;
		omega = 0.;
		omega_max = M_PI / 100;
		delta_omega = 0.001;

		player = player;
		enemy = ENEMY;

		counter = 0;
		start = 50;
	}

	inline PlayerBullet& move() {
		x_previous = x;
		y_previous = y;

		if ( counter < start ) {
			y += .5;
		} else {
			if ( omega < omega_max ) {
				omega += delta_omega;
			}

			v += a;

			radian enemy_direction = theta;

			if ( &enemy != NULL ) {
				enemy_direction = atan2( enemy->getY() - y, enemy->getX() - x );
			}

			if ( -M_PI_4 < enemy_direction - theta && enemy_direction - theta < M_PI_4 ) {
				if ( enemy_direction - theta > +omega ) {
					theta += omega;
				} else if ( enemy_direction - theta < -omega ) {
					theta -= omega;
				} else {
					theta = enemy_direction;
				}
			}

			x += v * cos( theta );
			y += v * sin( theta );
		}

		counter++;
		return *this;
	}

	inline PlayerBullet& draw() {
		MikanDraw->DrawTextureRotationC( id, round( x ), round( y ), rx, ry, w, h, theta + M_PI_2 );
		return *this;
	}
};