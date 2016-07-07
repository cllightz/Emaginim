#include <Mikan.h>
#include <memory>
#include <vector>
#include "defines.h"
#include "Enemy.h"
#include "Enemies.h"
#include "EnemyBullet.h"
#include "EnemyBullets.h"
#include "Player.h"
#include "PlayerBullets.h"

namespace {
	Player player;
	Enemies enemies;
	PlayerBullets playerBullets;
	EnemyBullets enemyBullets;
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

	player = Player( MikanDraw->GetScreenWidth( 1 ) / 2., MikanDraw->GetScreenHeight( 1 ) * 3 / 4. );
	enemies = Enemies();
	playerBullets = PlayerBullets();
	enemyBullets = EnemyBullets();

	counter = 0;
}

int MainLoop() {
	MikanDraw->ClearScreen();

	if ( counter == 0 ) {
		enemies.spawn();
	}

	player.move();

	if ( MikanInput->GetKeyNum( K_Z ) ) {
		playerBullets.shoot( player, enemies, counter );
	}

	playerBullets.move();
	enemies.move();

	if ( enemies.hasEnemy() ) {
		enemyBullets.shoot( *(enemies.getEnemy()), counter );
	}
	
	enemyBullets.move();

	playerBullets.strike( enemies );

	enemies.draw();
	playerBullets.draw();
	player.draw();

	if ( MikanInput->GetKeyNum( K_LSHIFT ) ) {
		MikanDraw->DrawCircleC( player.getX(), player.getY(), player.getR() * .1 );
	}

	enemyBullets.draw();

	if ( enemies.isCollision( player ) ) {
		return 1;
	}

	if ( enemyBullets.isCollision( player ) ) {
		return 1;
	}

	counter++;

	return 0;
}

void CleanUp() {
}
