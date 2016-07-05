#pragma once
#include <cassert>
#include <vector>
#include "EnemyBullet.h"
#include "Player.h"
#include "PlayerBullets.h"

class EnemyBullets {
private:
	std::vector< std::shared_ptr<EnemyBullet> > list;

public:
	inline EnemyBullets() {}

	inline EnemyBullets& init() {
		list = std::vector< std::shared_ptr<EnemyBullet> >();
		return *this;
	}

	inline EnemyBullets& move() {
		for ( const auto& bullet : list ) {
			bullet->move();
		}

		return *this;
	}

	inline EnemyBullets& shoot() {
		list.push_back( std::shared_ptr<EnemyBullet>( new EnemyBullet() ) );
		return *this;
	}

	inline EnemyBullets& strike( PlayerBullets& playerBullets ) {
		if ( list.size() == 0 ) {
			return *this;
		}

		for ( auto ite = list.begin(); ite < list.end(); ) {
			ite = playerBullets.isCollision( **ite ) ? list.erase( ite ) : ite + 1;
		}

		return *this;
	}

	inline EnemyBullets& draw() {
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
			if ( sqrt( pow( bullet->getX() - X, 2. ) + pow( bullet->getY() - Y, 2. ) ) < R*.8 + bullet->getR()*.2 ) {
				return true;
			}
		}

		return false;
	}
};

