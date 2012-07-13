#ifndef PASS_SCHEDULER_H
#define PASS_SCHEDULER_H

#include <QtGui/QMainWindow>
#include "ui_pass_scheduler.h"
#include <QFile>
#include <QList>
#include <QTextStream>
#include <QTableWidget>
#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidgetItem>
#include <QDateTime>
#include <QTabWidget>
#include <QDialog>
#include <QMessageBox>

class Pass_scheduler : public QMainWindow
{
	Q_OBJECT

public:
	Pass_scheduler(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Pass_scheduler();

private:
	int flag;
	//int skipflag;
	int flag2;
	int flag3;
	int flag4;
	//int flag5;
	QString sys_time;
	QList<QString> ID;
	QList<QString> Orbitnumber;
	QList<QString> AOS;
	QList<QString> LOS;
	QList<QString> SPS_availability;
	QList<QString> SPS_on;
	QList<QString> SPS_off;
	QList<QString> memory;
	QList<QString> data;
	QTableWidget table;
	//QTableWidget pass_table;
	QString path;
	QString p;
	QString date_;
	QString h;
	QMainWindow w;
	QLabel label;
	QLabel lab;
	//Ui::Pass_schedulerClass ui;

public slots:
	void showtime();
	void readfromfile();
	void window();
	//void changeflag();
};

#endif // PASS_SCHEDULER_H





