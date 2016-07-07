#include "PlayerBullet.h"
#include <Mikan.h>
#include <cassert>
#include <memory>
#include <vector>
#include "Enemies.h"

bool PlayerBullet::isCollision( Enemies& enemies ) {
	radian theta = atan2( y - y_previous, x - x_previous );
	pixel step_x = cos( theta ) * r;
	pixel step_y = sin( theta ) * r;
	pixel x_tmp = x_previous;
	pixel y_tmp = y_previous;
	assert( theta < 0 );

	MikanDraw->Printf( FONT_PROMPT, 0, 400, "x%f xp%f sx%f vx%f\ny%f yp%f sy%f vy%f", x, x_previous, step_x, v_x, y, y_previous, step_y, v_y );

	while ( !isReached( x_tmp, y_tmp ) ) {
		if ( enemies.isCollision( x_tmp, y_tmp, r ) ) {
			return true;
		}

		x_tmp += step_x;
		y_tmp += step_y;
	}

	return false;
}