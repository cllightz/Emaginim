#pragma once
#include <vector>
#include "Enemy.h"
#include "PlayerBullet.h"
#include "Player.h"

class PlayerBullets {
private:
	std::vector< std::shared_ptr<PlayerBullet> > list;

public:
	inline PlayerBullets() {
		list = std::vector< std::shared_ptr<PlayerBullet> >();
	}

	inline PlayerBullets& move() {
		if ( list.size() == 0 ) {
			return *this;
		}

		for ( auto ite = list.begin(); ite < list.end(); ) {
			ite = (*ite)->move().isDead() ? list.erase( ite ) : ite + 1;
		}

		MikanDraw->Printf( FONT_PROMPT, 200, 200, "%d", list.size() );

		return *this;
	}

	inline PlayerBullets& shoot( Player& player ) {
		list.push_back( std::shared_ptr<PlayerBullet>( new PlayerBullet( player ) ) );
		return *this;
	}

	inline bool isCollision( Enemy& enemy ) {
		pixel X = enemy.getX();
		pixel Y = enemy.getY();
		pixel R = enemy.getR();

		for ( const auto& bullet : list ) {
			if ( sqrt( pow( bullet->getX() - X, 2. ) + pow( bullet->getY() - Y, 2. ) ) < R*.8 + bullet->getR()*.2 ) {
				return true;
			}
		}

		return false;
	}

	inline PlayerBullets& draw() {
		for ( const auto& bullet : list ) {
			bullet->draw();
		}

		return *this;
	}
};

