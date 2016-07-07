#include "PlayerBullet.h"
#include <Mikan.h>
#include <memory>
#include <vector>
#include "Enemies.h"

bool PlayerBullet::isCollision( Enemies& enemies ) {
	radian theta = atan2( y - y_previous, x - x_previous );
	pixel step_x = cos( theta ) * r;
	pixel step_y = sin( theta ) * r;
	pixel x_tmp = x_previous;
	pixel y_tmp = y_previous;

	while ( !isReached( x_tmp, y_tmp ) ) {
		if ( enemies.isCollision( x_tmp, y_tmp, r ) ) {
			return true;
		}

		x_tmp += step_x;
		y_tmp += step_y;
	}

	return false;
}