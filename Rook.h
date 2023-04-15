#pragma once
#include "Piece.h"

class Rook : virtual public Piece {
public:
	Rook(int x, int y, Color color) : Piece(x, y, color) {}
	~Rook() {}

	virtual bool verifyPseudoLegalMove(int x, int y) const override;
	virtual std::string getPNG() const override;
private:
};
