#pragma once
#include <vector>
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

	inline Enemies& shoot() {
		list.push_back( std::shared_ptr<Enemy>( new Enemy() ) );
		return *this;
	}

	inline Enemies& strike( PlayerBullets& playerBullets ) {
		if ( list.size() == 0 ) {
			return *this;
		}

		for ( auto ite = list.begin(); ite < list.end(); ) {
			ite = playerBullets.isCollision( **ite ) ? list.erase( ite ) : ite + 1;
		}

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

		for ( const auto& bullet : list ) {
			if ( sqrt( pow( bullet->getX() - X, 2. ) + pow( bullet->getY() - Y, 2. ) ) < R*.5 + bullet->getR()*.1 ) {
				return true;
			}
		}

		return false;
	}
};

