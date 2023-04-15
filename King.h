#pragma once
#include "Piece.h"

class King : virtual public Piece {
public:
	King(int x, int y, Color color) : Piece(x, y, color)
	{
		kingContainer_[kingPosCounter_] = 1; //catch le overflow ici si 3 rois
		kingPosCounter_++;
	};
	~King() {}

	virtual bool verifyPseudoLegalMove(int x, int y) const override;
	virtual std::string getPNG() const override;
private:
	int kingContainer_[2];
	int kingPosCounter_ = 0;
};
