#include "PlayerBullets.h"
#include "Enemy.h"
#include "Enemies.h"

PlayerBullets& PlayerBullets::shoot( Player& player, Enemies& enemies, int counter ) {
	list.push_back( std::shared_ptr<PlayerBullet>( new GatlingBullet( player, +3. ) ) );
	list.push_back( std::shared_ptr<PlayerBullet>( new GatlingBullet( player, +3. ) ) );
	list.push_back( std::shared_ptr<PlayerBullet>( new GatlingBullet( player, -3. ) ) );
	list.push_back( std::shared_ptr<PlayerBullet>( new GatlingBullet( player, -3. ) ) );

	if ( counter % 5 == 0 ) {
		list.push_back( std::shared_ptr<PlayerBullet>( new GunpodBullet( player, +9., 2. ) ) );
		list.push_back( std::shared_ptr<PlayerBullet>( new GunpodBullet( player, -9., 2. ) ) );
		list.push_back( std::shared_ptr<PlayerBullet>( new GunpodBullet( player, +17., 4. ) ) );
		list.push_back( std::shared_ptr<PlayerBullet>( new GunpodBullet( player, -17., 4. ) ) );
	}

	if ( counter % 11 == 0 ) {
		list.push_back( std::shared_ptr<PlayerBullet>( new RocketpodBullet( player, +13., 3. ) ) );
		list.push_back( std::shared_ptr<PlayerBullet>( new RocketpodBullet( player, -13., 3. ) ) );
		list.push_back( std::shared_ptr<PlayerBullet>( new RocketpodBullet( player, +21., 5. ) ) );
		list.push_back( std::shared_ptr<PlayerBullet>( new RocketpodBullet( player, -21., 5. ) ) );
	}

	if ( counter % 51 == 0 ) {
		if ( enemies.hasEnemy() ) {
			list.push_back( std::shared_ptr<PlayerBullet>( new MissileBullet( player, enemies.getEnemy() ) ) );
			MikanDraw->Printf( FONT_PROMPT, 0, 80, "%f %f", list.back()->getX(), list.back()->getY() );
		}
	}

	return *this;
}