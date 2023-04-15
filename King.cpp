#include "King.h"

bool King::verifyPseudoLegalMove(int x, int y) const
{
	if (x > positionX_ + 1 || x < positionX_ - 1)
		return false;

	if (y > positionY_ + 1 || y < positionY_ - 1)
		return false;

	return true;
}

std::string King::getPNG() const
{
	if (color_ == white)
		return "kingw.png";
	return "kingb.png";
}
