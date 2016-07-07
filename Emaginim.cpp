#include <Mikan.h>
#include <memory>
#include <vector>
#include "defines.h"
#include "Enemy.h"
#include "Enemies.h"
#include "EnemyBullet.h"
#include "EnemyBullets.h"
#include "Player.h"

namespace {
	Player player;
	Enemies enemies;
	PlayerBullets playerBullets;
	unsigned long long int counter;
}

void SystemInit() {
	MikanWindow->SetWindowName( "Emaginim" );
	MikanWindow->SetWindowIcon( "GAME_ICON" );
}

void UserInit() {
	MikanDraw->CreateTexture( TEXTURE_PLAYER, "player.png", TRC_ZERO );
	MikanDraw->CreateTexture( TEXTURE_ENEMY, "xchu.png", TRC_ZERO );
	MikanDraw->CreateTexture( TEXTURE_BULLET, "bullet.png", TRC_ZERO );
	MikanDraw->CreateFont( FONT_PROMPT, "Meiryo UI", 24, 0xFFFFFFFF );

	player = Player( MikanDraw->GetScreenWidth( 1 ) / 2., MikanDraw->GetScreenHeight( 1 ) / 2. );
	enemies = Enemies();

	counter = 0;
}

int MainLoop() {
	MikanDraw->ClearScreen();

	if ( MikanInput->GetKeyNum( K_Z ) ) {
		playerBullets.shoot( player );
	}

	if ( counter % 2 == 0 ) {
		enemies.shoot();
	}

	player.move();
	playerBullets.move();
	enemies.move();

	playerBullets.strike( enemies );

	player.draw();
	playerBullets.draw();
	enemies.draw();

	if ( enemies.isCollision( player ) ) {
		return 1;
	}

	counter++;

	return 0;
}

void CleanUp() {
}
