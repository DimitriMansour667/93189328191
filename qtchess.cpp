#include "qtchess.h"
#include "ChessBoard.h"
#include <QHBoxLayout>

qtchess::qtchess(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QHBoxLayout* layout = new QHBoxLayout(this);
    ChessBoard* board = new ChessBoard(this);
    layout->addWidget(board);
    setCentralWidget(board);
}

qtchess::~qtchess()
{}
