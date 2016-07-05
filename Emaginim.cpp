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
}

void SystemInit() {
	MikanWindow->SetWindowName( "Emaginim" );
	MikanWindow->SetWindowIcon( "GAME_ICON" );
}

void UserInit() {
	player = Player().init();
	enemyBullets = EnemyBullets().init();

	MikanDraw->CreateFont( FONT_PROMPT, "Meiryo UI", 24, 0xFFFFFFFF );
}

int MainLoop() {
	MikanDraw->ClearScreen();

	player.move().draw();

	if ( enemyBullets.move().draw().isCollision( player ) ) {
		std::abort();
	}

	return 0;
}

void CleanUp() {
}
