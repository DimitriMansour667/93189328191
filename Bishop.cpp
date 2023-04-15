#include "Bishop.h"

bool Bishop::verifyPseudoLegalMove(int x, int y) const
{
	if (positionX_ - x != positionY_ - y)
		return false;

	return true;
}

std::string Bishop::getPNG() const
{
	if (color_ == white)
		return "bishopw.png";
	return "bishopb.png";
}
