#pragma once
#include "Piece.h"

class Bishop : virtual public Piece
{
public:
	Bishop(int x, int y, Color color) : Piece(x, y, color) {}
	~Bishop() {}

	virtual bool verifyPseudoLegalMove(int x, int y) const override;
	virtual std::string getPNG() const override;
};
