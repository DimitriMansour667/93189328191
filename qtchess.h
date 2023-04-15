#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtchess.h"

class qtchess : public QMainWindow
{
    Q_OBJECT

public:
    qtchess(QWidget *parent = nullptr);
    ~qtchess();

private:
    Ui::qtchessClass ui;
};
