#include "Util.h"

using namespace Sweet;

/**
* Returns T/F if rectangles overlap
* 
* @author Ian Coleman
* @param Potential collidable rectangle
* @param Rectangle that may collide with first @param
*/
bool Util::AABBRectIntersect(seRect *rect1, seRect *rect2)
{	
	return !( rect1->getBottomRight().Y() < rect2->getTopLeft().Y() ||
			rect1->getTopLeft().Y() > rect2->getBottomRight().Y() ||
			rect1->getBottomRight().X() < rect2->getTopLeft().X() ||
			rect1->getTopLeft().X() > rect2->getBottomRight().X() );			
}