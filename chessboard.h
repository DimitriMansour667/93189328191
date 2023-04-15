#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "Board.h"
#include "chesspiece.h"

class ChessBoard : public QWidget
{
    Q_OBJECT

public:
    ChessBoard(QWidget* parent = nullptr);
    ~ChessBoard();


private:
    Board board_;
    QGridLayout* m_gridLayout;
    ChessPiece* m_boardSquares[8][8];
};
