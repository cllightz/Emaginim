#pragma once
#include <vector>
#include "Enemy.h"
#include "GatlingBullet.h"
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
		list.push_back( std::shared_ptr<PlayerBullet>( new GatlingBullet( player, +3. ) ) );
		list.push_back( std::shared_ptr<PlayerBullet>( new GatlingBullet( player, -3. ) ) );
		return *this;
	}

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

