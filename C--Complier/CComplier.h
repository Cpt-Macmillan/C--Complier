#pragma once

#include <QtWidgets/QMainWindow>
#include <string>
#include "uic/ui_CComplier.h"
#include <algorithm>
#include<fstream>


class CComplier : public QMainWindow
{
	Q_OBJECT

public:
	CComplier(QWidget *parent = Q_NULLPTR);
	void step_finish(std::string a);
public:
	void update_schedule();
	void set_visible_buttons(int i);
private:
	void set_buttons_visible();
public slots:
	void open_source_file(QString &);
	void call_Compiler_Main();
	void open_debug_file(QString& filename);
	
private:
	Ui::CComplierClass ui;
	int steps_finished;
	int visible_buttons;
private:
	int has_mistake;
};

//后端函数接口
int compiler_main(CComplier&);