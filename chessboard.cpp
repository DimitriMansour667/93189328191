#include "chessboard.h"
#include "chesspiece.h"
#include "Board.h"
#include "Piece.h"
#include "Bishop.h"
#include "King.h"
#include "Rook.h"
#include "qobject.h"

ChessBoard::ChessBoard(QWidget* parent)
    : QWidget(parent)
{
    m_gridLayout = new QGridLayout(this);

    // pieces noires
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (auto piece = board_.getPieceOnCoordinates(j, i)) {
                if (auto&& bishop = dynamic_cast<Bishop*>(piece.get())) {
                    if (bishop->getColor() == white) {
                        m_boardSquares[i][j] = new ChessPiece("Bw", i, j, piece, this);
                        QObject::connect(m_boardSquares[i][j], &ChessPiece::clickedCase, &board_, &Board::receiveClickedCase);
                    }
                    else {
                        m_boardSquares[i][j] = new ChessPiece("Bb", i, j, piece, this);
                        QObject::connect(m_boardSquares[i][j], &ChessPiece::clickedCase, &board_, &Board::receiveClickedCase);
                    }
                    
                }
                if (auto&& king = dynamic_cast<King*>(piece.get())) {
                    if (king->getColor() == white) {
                        m_boardSquares[i][j] = new ChessPiece("Kw", i, j, piece, this);
                        QObject::connect(m_boardSquares[i][j], &ChessPiece::clickedCase, &board_, &Board::receiveClickedCase);
                    }
                    else {
                        m_boardSquares[i][j] = new ChessPiece("Kb", i, j, piece, this);
                        QObject::connect(m_boardSquares[i][j], &ChessPiece::clickedCase, &board_, &Board::receiveClickedCase);
                    }
                }
                if (auto&& rook = dynamic_cast<Rook*>(piece.get())) {
                    if (rook->getColor() == white) {
                        m_boardSquares[i][j] = new ChessPiece("Rw", i, j, piece, this);
                        QObject::connect(m_boardSquares[i][j], &ChessPiece::clickedCase, &board_, &Board::receiveClickedCase);
                    }
                    else {
                        m_boardSquares[i][j] = new ChessPiece("Rb", i, j, piece, this);
                        QObject::connect(m_boardSquares[i][j], &ChessPiece::clickedCase, &board_, &Board::receiveClickedCase);
                    }
                }
                
            } 
            else {
                m_boardSquares[i][j] = new ChessPiece(i, j, this);
                QObject::connect(m_boardSquares[i][j], &ChessPiece::clickedCase, &board_, &Board::receiveClickedCase);
            }

        }
    }


    // couleur des cases
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                m_boardSquares[i][j]->setStyleSheet("background-color: white;");
            }
            else {
                m_boardSquares[i][j]->setStyleSheet("background-color: gray;");
            }
        }
    }

    // ajout sur le layout
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            m_gridLayout->addWidget(m_boardSquares[i][j], i, j);
        }
    }

    setLayout(m_gridLayout);
}



ChessBoard::~ChessBoard()
{}
