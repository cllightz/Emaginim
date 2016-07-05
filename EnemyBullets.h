#pragma once
#include <vector>
#include "EnemyBullet.h"
#include "Player.h"

class EnemyBullets {
private:
	std::vector< std::shared_ptr<EnemyBullet> > list;

public:
	inline EnemyBullets() {}

	inline EnemyBullets& init() {
		list = std::vector< std::shared_ptr<EnemyBullet> >();
		return *this;
	}

	inline bool isCollision( Player& player ) {
		if ( list.empty() ) {
			return false;
		}

		pixel pX = player.getX();
		pixel pY = player.getY();
		pixel pR = player.getR();

		pixel bR = list[0]->getR();

		for ( const auto& bullet : list ) {
			if ( sqrt( pow( bullet->getX() - pX, 2. ) + pow( bullet->getY() - pY, 2. ) ) < bR*.8 + pR*.2 ) {
				return true;
			}
		}

		MikanDraw->Printf( FONT_PROMPT, 200, 200, "%f, %f", list[0]->getX(), list[0]->getY() );

		return false;
	}

	inline EnemyBullets& draw() {
		for ( const auto& bullet : list ) {
			bullet->draw();
		}

		return *this;
	}

	inline EnemyBullets& move() {
		if ( rand() % 10 == 0 ) {
			EnemyBullet* bullet = new EnemyBullet();
			list.push_back( std::shared_ptr<EnemyBullet>( bullet ) );
		}

		for ( const auto& bullet : list ) {
			bullet->move();
		}

		return *this;
	}
};

