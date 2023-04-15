#pragma once
#include "Color.h"
#include <string>

class Piece {
public:
	Piece(int x, int y, Color color) :
		color_(color),
		positionX_(x),
		positionY_(y) {}
	virtual ~Piece() = 0;

	virtual void setPosition(int x, int y)
	{
		positionX_ = x;
		positionY_ = y;
	}
	//Return true if the movement could be done on this piece on an empty board
	virtual bool verifyPseudoLegalMove(int x, int y) const = 0;
	virtual std::string getPNG() const = 0;

	virtual int getPositionX() const { return positionX_; }
	virtual int getPositionY() const { return positionY_; }
	virtual Color getColor() const { return color_; }

protected:
	Color color_;
	int positionX_ = -1;
	int positionY_ = -1;
};
