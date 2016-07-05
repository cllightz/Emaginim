#include <Mikan.h>
#include <memory>
#include <vector>
#include "defines.h"
#include "EnemyBullet.h"
#include "EnemyBullets.h"
#include "Player.h"

namespace {
	Player player;
	EnemyBullets enemyBullets;
	PlayerBullets playerBullets;
	unsigned long long int counter;
}

void SystemInit() {
	MikanWindow->SetWindowName( "Emaginim" );
	MikanWindow->SetWindowIcon( "GAME_ICON" );
}

void UserInit() {
	player = Player().init();
	enemyBullets = EnemyBullets().init();

	MikanDraw->CreateFont( FONT_PROMPT, "Meiryo UI", 24, 0xFFFFFFFF );

	counter = 0;
}

int MainLoop() {
	MikanDraw->ClearScreen();

	player.move();
	playerBullets.move();
	enemyBullets.move();

	playerBullets.shoot( player );
	enemyBullets.shoot();

	enemyBullets.strike( playerBullets );

	player.draw();
	playerBullets.draw();
	enemyBullets.draw();

	if ( enemyBullets.isCollision( player ) ) {
		return 1;
	}

	return 0;
}

void CleanUp() {
}
