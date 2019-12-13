#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplicationtest.h"

class QtGuiApplicationtest : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplicationtest(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiApplicationtestClass ui;
};
