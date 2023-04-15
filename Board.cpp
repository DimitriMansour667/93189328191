#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include <memory>

Board::Board() {

	//création des pieces noires
	std::shared_ptr<King> KB = std::make_shared<King>(4, 7, black);
	pieces_.push_back((KB));

	std::shared_ptr<Rook> RB1 = std::make_shared<Rook>(0, 7, black);
	pieces_.push_back((RB1));
	std::shared_ptr<Rook> RB2 = std::make_shared<Rook>(7, 7, black);
	pieces_.push_back((RB2));

	std::shared_ptr<Bishop> BB1 = std::make_shared<Bishop>(2, 7, black);
	pieces_.push_back((BB1));
	std::shared_ptr<Bishop> BB2 = std::make_shared<Bishop>(5, 7, black);
	pieces_.push_back((BB2));

	//création des pieces blanches
	std::shared_ptr<King> KW = std::make_shared<King>(4, 0, white);
	pieces_.push_back((KW));

	std::shared_ptr<Rook> RW1 = std::make_shared<Rook>(0, 0, white);
	pieces_.push_back((RW1));
	std::shared_ptr<Rook> RW2 = std::make_shared<Rook>(7, 0, white);
	pieces_.push_back((RW2));

	std::shared_ptr<Bishop> BW1 = std::make_shared<Bishop>(2, 0, white);
	pieces_.push_back((BW1));
	std::shared_ptr<Bishop> BW2 = std::make_shared<Bishop>(5, 0, white);

	pieces_.push_back((BW2));
}

void Board::deletePiece(int posX, int posY)
{
	for (int i = 0; i < pieces_.size(); i++)
	{
		if (pieces_[i]->getPositionX() == posX && pieces_[i]->getPositionY() == posY)
		{
			pieces_[i] = nullptr;
		}
	}
}

void Board::addPeice(std::shared_ptr<Piece> piece)
{
	pieces_.push_back((piece));
}

bool Board::isPieceOnCoordinates(int x, int y)
{
	for (auto& piece : pieces_)
		if (piece->getPositionX() == x && piece->getPositionY() == y)
			return true;
	return false;
}

bool Board::verifyMove(std::shared_ptr<Piece> piece, int x, int y)
{
	if (piece->verifyPseudoLegalMove(x, y) == false)
		return false;

	//Return false if a piece of the same color is at the end position of the move
	for (auto& piece2 : pieces_)
	{
		if (piece2->getPositionX() == x && piece2->getPositionY() == y && piece2->getColor() == piece->getColor())
			return false;
	}

	//Return false if a piece is on the way of the rook if the piece is a rook
	if (auto&& rook = dynamic_cast<Rook*>(piece.get()))
	{
		if (x > rook->getPositionX())
		{
			for (int i = rook->getPositionX() + 1; i < x; i++)
				if (isPieceOnCoordinates(i, rook->getPositionY()) == true)
					return false;
		}

		if (x < rook->getPositionX())
		{
			for (int i = rook->getPositionX() - 1; i > x; i--)
				if (isPieceOnCoordinates(i, rook->getPositionY()) == true)
					return false;
		}

		if (y > rook->getPositionY())
		{
			for (int i = rook->getPositionY() + 1; i < y; i++)
				if (isPieceOnCoordinates(rook->getPositionX(), i) == true)
					return false;
		}

		if (y < rook->getPositionY())
		{
			for (int i = rook->getPositionX() - 1; i > y; i--)
				if (isPieceOnCoordinates(rook->getPositionX(), i) == true)
					return false;
		}
	}

	//Return false if a piece is on the way of the bishop if the piece is a bishop
	if (auto&& bishop = dynamic_cast<Bishop*>(piece.get()))
	{
		if (x > bishop->getPositionX() && y > bishop->getPositionY())
		{
			for (int i = 1; i <= 8; i++)
				if (isPieceOnCoordinates(bishop->getPositionX() + i, bishop->getPositionY() + i) == true)
					return false;
		}

		if (x < bishop->getPositionX() && y > bishop->getPositionY())
		{
			for (int i = 1; i <= 8; i++)
				if (isPieceOnCoordinates(bishop->getPositionX() - i, bishop->getPositionY() + i) == true)
					return false;
		}

		if (x > bishop->getPositionX() && y < bishop->getPositionY())
		{
			for (int i = 1; i <= 8; i++)
				if (isPieceOnCoordinates(bishop->getPositionX() + i, bishop->getPositionY() - i) == true)
					return false;
		}

		if (x < bishop->getPositionX() && y < bishop->getPositionY())
		{
			for (int i = 1; i <= 8; i++)
				if (isPieceOnCoordinates(bishop->getPositionX() - i, bishop->getPositionY() - i) == true)
					return false;
		}
	}

	return true;
}

bool Board::verifyCheck(Color color)
{
	int kingX = -1;
	int kingY = -1;

	//find coordinates of the king of the right color
	for (auto& piece : pieces_)
		if (auto&& king = dynamic_cast<King*>(piece.get()))
			if (king->getColor() == color)
			{
				kingX = king->getPositionX();
				kingY = king->getPositionY();
			}

	for (auto& piece : pieces_)
		if (piece->getColor() != color)
			if (verifyMove(piece, kingX, kingY) == true)
				return true;

	return false;
}

bool Board::verifyMoveWithCheck(std::shared_ptr<Piece> piece, int x, int y)
{
	int initialX = piece->getPositionX();
	int initialY = piece->getPositionY();

	if (verifyMove(piece, x, y) == false)
		return false;

	piece->setPosition(x, y);

	//Return false if, after the move, the king of the piece's color is still in check
	//and puts the piece back at its place
	if (verifyCheck(piece->getColor()) == true)
	{
		piece->setPosition(initialX, initialY);
		return false;
	}

	piece->setPosition(initialX, initialY);

	return true;
}

std::shared_ptr<Piece> Board::getPieceOnCoordinates(int x, int y)
{
	if (isPieceOnCoordinates(x, y) == false)
		return nullptr;
	for (auto& piece : pieces_)
	{
		if (piece->getPositionX() == x && piece->getPositionY() == y)
			return piece;
	}
}
