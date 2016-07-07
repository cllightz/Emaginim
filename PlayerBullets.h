#pragma once
#include <vector>
#include "Enemy.h"
#include "GatlingBullet.h"
#include "GunpodBullet.h"
#include "PlayerBullet.h"
#include "Player.h"
#include "RocketpodBullet.h"

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

	inline PlayerBullets& shoot( Player& player, int counter ) {
		list.push_back( std::shared_ptr<PlayerBullet>( new GatlingBullet( player, +3. ) ) );
		list.push_back( std::shared_ptr<PlayerBullet>( new GatlingBullet( player, -3. ) ) );

		if ( counter % 5 == 0 ) {
			list.push_back( std::shared_ptr<PlayerBullet>( new GunpodBullet( player, + 9., 2., 30., M_PI_4 / 100, 45 ) ) );
			list.push_back( std::shared_ptr<PlayerBullet>( new GunpodBullet( player, - 9., 2., 30., M_PI_4 / 100, 45 ) ) );
			list.push_back( std::shared_ptr<PlayerBullet>( new GunpodBullet( player, +17., 4., 30., M_PI_4 / 100, 45 ) ) );
			list.push_back( std::shared_ptr<PlayerBullet>( new GunpodBullet( player, -17., 4., 30., M_PI_4 / 100, 45 ) ) );
		}

		if ( counter % 11 == 0 ) {
			list.push_back( std::shared_ptr<PlayerBullet>( new RocketpodBullet( player, +13., 2., 2.5, M_PI_4 / 50, 240 ) ) );
			list.push_back( std::shared_ptr<PlayerBullet>( new RocketpodBullet( player, -13., 2., 2.5, M_PI_4 / 50, 240 ) ) );
			list.push_back( std::shared_ptr<PlayerBullet>( new RocketpodBullet( player, +21., 4., 2.5, M_PI_4 / 50, 240 ) ) );
			list.push_back( std::shared_ptr<PlayerBullet>( new RocketpodBullet( player, -21., 4., 2.5, M_PI_4 / 50, 240 ) ) );
		}
		
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

