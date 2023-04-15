#pragma once
#include "Piece.h"
#include <memory>
#include <vector>
#include "Color.h"
#include "King.h"
#include <qapplication.h>


class Board {
	Q_OBJECT

public:
	Board();
	//Board(const Board& board);
	//Verify if a move is possible without looking for checks
	bool verifyMove(std::shared_ptr<Piece> piece, int x, int y);
	//Return true if the king of the color in parametere is in check
	bool verifyCheck(Color color);
	//Return true if the move is totally legal
	bool verifyMoveWithCheck(std::shared_ptr<Piece> piece, int x, int y);

	void deletePiece(int posX, int posY);
	void addPeice(std::shared_ptr<Piece> piece);
	bool isPieceOnCoordinates(int x, int y);
	std::shared_ptr<Piece> getPieceOnCoordinates(int x, int y);

public slots:
	void receiveClickedCase(int x, int y, std::shared_ptr<Piece> piece) {};

private:
	std::vector<std::shared_ptr<Piece>> pieces_;
};

