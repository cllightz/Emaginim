#pragma once
#include <vector>
#include "EnemyBullet.h"
#include "PlayerBullet.h"
#include "Player.h"

class PlayerBullets {
private:
	std::vector< std::shared_ptr<PlayerBullet> > list;

public:
	inline PlayerBullets() {}

	inline PlayerBullets& init() {
		list = std::vector< std::shared_ptr<PlayerBullet> >();
		return *this;
	}

	inline bool isCollision( EnemyBullet& enemyBullet ) {
		if ( list.empty() ) {
			return false;
		}

		pixel ebX = enemyBullet.getX();
		pixel ebY = enemyBullet.getY();
		pixel ebR = enemyBullet.getR();

		pixel pbR = list[0]->getR();

		for ( const auto& bullet : list ) {
			if ( sqrt( pow( bullet->getX() - ebX, 2. ) + pow( bullet->getY() - ebY, 2. ) ) < ebR*.8 + pbR*.2 ) {
				return true;
			}
		}

		MikanDraw->Printf( FONT_PROMPT, 200, 200, "%f, %f", list[0]->getX(), list[0]->getY() );

		return false;
	}

	inline PlayerBullets& move() {
		for ( const auto& bullet : list ) {
			bullet->move();
		}

		return *this;
	}

	inline PlayerBullets& shoot( Player& player ) {
		list.push_back( std::shared_ptr<PlayerBullet>( new PlayerBullet( player ) ) );
		return *this;
	}

	inline PlayerBullets& draw() {
		for ( const auto& bullet : list ) {
			bullet->draw();
		}

		return *this;
	}
};

