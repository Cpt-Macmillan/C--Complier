#pragma once

#include <QtWidgets/QMainWindow>
#include <string>
#include "uic/ui_CComplier.h"
#include <algorithm>



class CComplier : public QMainWindow
{
	Q_OBJECT

public:
	CComplier(QWidget *parent = Q_NULLPTR);
	void step_finish(std::string a);
public:
	void update_schedule();
	
public slots:
	void open_source_file(QString &);
	void call_Compiler_Main();
private:
	Ui::CComplierClass ui;
	int steps_finished;
private:
	int has_mistake;
};

//后端函数接口
int compiler_main(CComplier&);