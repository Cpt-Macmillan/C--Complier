#include "CComplier.h"
//#include <Windows.h>

CComplier::CComplier(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//connect(this, &CComplier::new_step_finished, this, &CComplier::update_schedule);
	connect(ui.pushButton, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("0 prog-resource")));
	connect(ui.pushButton_2, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("2 prog-clear.txt")));
	connect(ui.pushButton_3, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("3-lexical.txt")));
	connect(ui.pushButton_4, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("4 grammar.txt")));
	connect(ui.pushButton_5, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("5 ll1_grammar.txt")));
	connect(ui.pushButton_6, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("6 ad_grammar.txt")));
	connect(ui.pushButton_7, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("7 vn_vtlist.txt")));
	connect(ui.pushButton_8, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("9 mtable.txt")));
	connect(ui.pushButton_10, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("10 stack_content.txt")));
	connect(ui.pushButton_11, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("11 symbol_table.txt")));
	connect(ui.pushButton_12, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("12 middle_code.txt")));
	connect(ui.pushButton_13, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("13 ad_midcode.txt")));

	connect(ui.pushButton_14, &QPushButton::clicked, this, std::bind(&CComplier::open_source_file,this,QString("debug.txt")));
	connect(ui.pushButton_9, &QPushButton::clicked, this,&CComplier::call_Compiler_Main);

	ui.pushButton->setVisible(0);
	ui.pushButton_2->setVisible(0);
	ui.pushButton_3->setVisible(0);
	ui.pushButton_4->setVisible(0);
	ui.pushButton_5->setVisible(0);
	ui.pushButton_6->setVisible(0);
	ui.pushButton_7->setVisible(0);
	ui.pushButton_8->setVisible(0);
	ui.pushButton_10->setVisible(0);
	ui.pushButton_11->setVisible(0);
	ui.pushButton_12->setVisible(0);
	ui.pushButton_13->setVisible(0);
	ui.pushButton_14->setVisible(0);

	

	this->steps_finished = 0;
	this->update_schedule();
	
}

void CComplier::step_finish(std::string a)
{
	this->steps_finished++;
	this->update_schedule();
	ui.label->setText(QString::fromStdString(a));
}

void CComplier::update_schedule()
{
	ui.progressBar123->setValue(100 * this->steps_finished / 13);
}



void CComplier::call_Compiler_Main()
{
	this->steps_finished = 0;
	this->has_mistake = 1;
	update_schedule();
	this->has_mistake = compiler_main(*this);
	if (!has_mistake) {
		ui.pushButton->setVisible(1);
		ui.pushButton_2->setVisible(1);
		ui.pushButton_3->setVisible(1);
		ui.pushButton_4->setVisible(1);
		ui.pushButton_5->setVisible(1);
		ui.pushButton_6->setVisible(1);
		ui.pushButton_7->setVisible(1);
		ui.pushButton_8->setVisible(1);
		ui.pushButton_10->setVisible(1);
		ui.pushButton_11->setVisible(1);
		ui.pushButton_12->setVisible(1);
		ui.pushButton_13->setVisible(1);
		ui.pushButton_9->setVisible(0);
		
	}
	else {
		//³öÏÖÒì³£
		ui.pushButton_9->setVisible(0);
		ui.label->setText(QObject::tr("<font color = red>%1</font>").arg("Exception occured."));
		
		ui.pushButton_14->setVisible(1);
	}
}

void CComplier::open_source_file(QString & filename) {
	system((std::string("notepad.exe ") + filename.toStdString()).data());
}