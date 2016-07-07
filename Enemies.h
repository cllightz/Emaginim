#pragma once
#include <vector>
#include "Enemy.h"
#include "EnemyBullet.h"
#include "Player.h"
#include "PlayerBullets.h"

class Enemies {
private:
	std::vector< std::shared_ptr<Enemy> > list;

public:
	inline Enemies() {
		list = std::vector< std::shared_ptr<Enemy> >();
	}

	inline bool hasEnemy() {
		return !list.empty();
	}

	inline std::shared_ptr<Enemy>& getEnemy() {
		return list.at( 0 );
	}

	inline Enemies& move() {
		if ( list.size() == 0 ) {
			return *this;
		}

		for ( auto ite = list.begin(); ite < list.end(); ) {
			ite = (*ite)->move().isDead() ? list.erase( ite ) : ite + 1;
		}

		MikanDraw->Printf( FONT_PROMPT, 400, 200, "%d", list.size() );

		return *this;
	}

	inline Enemies& spawn() {
		list.push_back( std::shared_ptr<Enemy>( new Enemy() ) );
		return *this;
	}

	inline Enemies& draw() {
		for ( const auto& bullet : list ) {
			bullet->draw();
		}

		return *this;
	}

	inline bool isCollision( Player& player ) {
		pixel X = player.getX();
		pixel Y = player.getY();
		pixel R = player.getR();

		for ( const auto& enemy : list ) {
			if ( sqrt( pow( enemy->getX() - X, 2. ) + pow( enemy->getY() - Y, 2. ) ) < R*.5 + enemy->getR()*.1 ) {
				return true;
			}
		}

		return false;
	}

	inline bool isCollision( pixel X, pixel Y, pixel R, hp_t damage ) {
		for ( const auto& enemy : list ) {
			if ( sqrt( pow( enemy->getX() - X, 2. ) + pow( enemy->getY() - Y, 2. ) ) < R*.9 + enemy->getR()*.9 ) {
				enemy->hit( damage );
				return true;
			}
		}

		return false;
	}
};

