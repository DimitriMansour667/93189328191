#pragma once
#include "Piece.h"
#include <QLabel>
#include <qapplication.h>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>


class ChessPiece : public QLabel
{
    Q_OBJECT

public:
    ChessPiece(const QString& text, int x, int y, std::shared_ptr<Piece> piece, QWidget* parent = nullptr) : QLabel(text, parent)
    {
        setAlignment(Qt::AlignCenter);
        this->x_ = x;
        this->y_ = y;
        this->piece_ = piece;
    }

    ChessPiece(int x, int y, QWidget* parent = nullptr) : QLabel(parent)
    {
        setAlignment(Qt::AlignCenter);
        this->x_ = x;
        this->y_ = y;
        this->piece_ = nullptr;
    }

public slots :

signals :
    void clickedCase(int x, int y, std::shared_ptr<Piece> piece);

protected:
    void mousePressEvent(QMouseEvent* event) override
    {
        emit clickedCase(x_, y_, piece_);
    }
private:
    int x_;
    int y_;
    std::shared_ptr<Piece> piece_;
};
