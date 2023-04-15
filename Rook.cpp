#include "Rook.h"

bool Rook::verifyPseudoLegalMove(int x, int y) const
{
	if (positionX_ != x && positionY_ != y)
		return false;

	return true;
}

std::string Rook::getPNG() const
{
	if (color_ == white)
		return "rookw.png";
	return "rookb.png";
}