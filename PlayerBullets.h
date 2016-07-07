#pragma once
#include <vector>
#include "Enemies.h"
#include "GatlingBullet.h"
#include "GunpodBullet.h"
#include "MissileBullet.h"
#include "PlayerBullet.h"
#include "Player.h"
#include "RocketpodBullet.h"

class Enemies;

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

		return *this;
	}

	PlayerBullets& shoot( Player&, Enemies&, int );

	inline PlayerBullets& strike( Enemies& enemies ) {
		for ( std::vector< std::shared_ptr<PlayerBullet> >::iterator ite = list.begin(); ite != list.end(); ) {
			ite = (*ite)->isCollision( enemies ) ? list.erase( ite ) : ite + 1;
		}

		return *this;
	}

	inline PlayerBullets& draw() {
		for ( const auto& bullet : list ) {
			bullet->draw();
		}

		return *this;
	}
};

