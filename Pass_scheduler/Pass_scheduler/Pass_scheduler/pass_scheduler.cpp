#include "pass_scheduler.h"

Pass_scheduler::Pass_scheduler(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	flag2=0;
	flag3=0;
	flag4=0;
	h="1";

	QWidget *centralWidget = new QWidget(this);
	QVBoxLayout *layout = new QVBoxLayout(centralWidget);

	readfromfile();//parsing and storing from Antenna Schedule

	resize(570,330);

	QWidget *bwidget = new QWidget(centralWidget);
	QHBoxLayout *blayout = new QHBoxLayout(bwidget);

	QPushButton *quitButton = new QPushButton(bwidget);
	quitButton->setText("Quit");
	quitButton->setFixedSize(100,20);
	QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(window()));

	blayout->addWidget(quitButton);

	layout->addWidget(&label);
	layout->addWidget(&table);
	layout->addWidget(bwidget);

	setCentralWidget(centralWidget);
	QIcon icon("C:\\Data_files\\a.png");
	QIcon icon2("C:\\Data_files\\b.png");
	setWindowIcon(icon);
	w.setWindowIcon(icon2);
	w.setWindowTitle("Data Acquisition");

}

Pass_scheduler::~Pass_scheduler()
{

}

void Pass_scheduler::showtime()
{	
	QString line;
	
	
	QTime qtime = QTime::currentTime();
	QString Str = "  TIME: ";

	label.setText(Str.append(qtime.toString()).append("                                                                                                       ").append("DATE : ").append(date_));

	flag = -1;//current pass index for accessing

	QString time;

	w.resize(200,100);// dummy module size

	for(int i=0;i<ID.size();i++)
	{ // scheduling loop
		bool ok;
		int AOS_time_hour=SPS_on.at(i).mid(0,2).toInt(&ok,10);
		int AOS_time_minute = SPS_on.at(i).mid(2,2).toInt(&ok,10);
		int AOS_time_second = SPS_on.at(i).mid(4,2).toInt(&ok,10);
		int LOS_time_hour = SPS_off.at(i).mid(0,2).toInt(&ok,10);
		int LOS_time_minute = SPS_off.at(i).mid(2,2).toInt(&ok,10);
		int LOS_time_second = SPS_off.at(i).mid(4,2).toInt(&ok,10);
		if(AOS_time_hour>qtime.hour()||((AOS_time_hour==qtime.hour())&&(AOS_time_minute>qtime.minute()))||((AOS_time_hour==qtime.hour()) && (AOS_time_minute==qtime.minute()) && (AOS_time_second>qtime.second()))||((AOS_time_hour==qtime.hour()) && (AOS_time_minute==qtime.minute()) && (AOS_time_second==qtime.second())))
		{
			if(((AOS_time_hour==qtime.hour())&&(AOS_time_minute==qtime.minute()+3)&&(AOS_time_second<=qtime.second()))||((AOS_time_hour==qtime.hour())&&(AOS_time_minute<qtime.minute()+3))&&flag2==0)
			{
				
				QLabel *lab = new QLabel("Data acquisition starts");
				lab->setAlignment(Qt::AlignCenter);
				w.setCentralWidget(lab);
				w.show();
				flag2=1;// flag2 is for data acquisition starting
			}

			if(flag==-1)
			{
				flag = i;
				if(AOS_time_minute-qtime.minute()>=0)
				{
					if(AOS_time_second-qtime.second()>=0)
					{
						time = QString::number(AOS_time_hour-qtime.hour()).append(":").append(QString::number(AOS_time_minute-qtime.minute())).append(":").append(QString::number(AOS_time_second-qtime.second())).append(" to AOS");
					}
					else
					{
						time = QString::number(AOS_time_hour-qtime.hour()).append(":").append(QString::number(AOS_time_minute-qtime.minute()-1)).append(":").append(QString::number(AOS_time_second-qtime.second()+60)).append(" to AOS");
					}
				}
				else
				{
					if(AOS_time_second-qtime.second()>=0)
					{
						time = QString::number(AOS_time_hour-qtime.hour()-1).append(":").append(QString::number(AOS_time_minute-qtime.minute()+60)).append(":").append(QString::number(AOS_time_second-qtime.second())).append(" to AOS");
					}
					else
					{
						time = QString::number(AOS_time_hour-qtime.hour()-1).append(":").append(QString::number(AOS_time_minute-qtime.minute()+60-1)).append(":").append(QString::number(AOS_time_second-qtime.second()+60)).append(" to AOS");
					}
				}
			}
		}
		else
		{
			if(LOS_time_hour>qtime.hour()||((LOS_time_hour==qtime.hour())&&(LOS_time_minute>qtime.minute()))||((LOS_time_hour==qtime.hour()) && (LOS_time_minute==qtime.minute()) && (LOS_time_second>qtime.second()))||((LOS_time_hour==qtime.hour()) && (LOS_time_minute==qtime.minute()) && (LOS_time_second==qtime.second())))
		{
			
	
				if(flag==-1)
				{
				flag = i;
				if(LOS_time_minute-qtime.minute()>=0)
				{
					if(LOS_time_second-qtime.second()>=0)
					{
						time = QString::number(LOS_time_hour-qtime.hour()).append(":").append(QString::number(LOS_time_minute-qtime.minute())).append(":").append(QString::number(LOS_time_second-qtime.second())).append(" to LOS");
					}
					else
					{
						time = QString::number(LOS_time_hour-qtime.hour()).append(":").append(QString::number(LOS_time_minute-qtime.minute()-1)).append(":").append(QString::number(LOS_time_second-qtime.second()+60)).append(" to LOS");
					}
				}
				else
				{
					if(LOS_time_second-qtime.second()>=0)
					{
						time = QString::number(LOS_time_hour-qtime.hour()-1).append(":").append(QString::number(LOS_time_minute-qtime.minute()+60)).append(":").append(QString::number(LOS_time_second-qtime.second())).append(" to LOS");
					}
					else
					{
						time = QString::number(LOS_time_hour-qtime.hour()-1).append(":").append(QString::number(LOS_time_minute-qtime.minute()+60-1)).append(":").append(QString::number(LOS_time_second-qtime.second()+60)).append(" to LOS");
					}
				}
				}
				
				if(LOS_time_hour==qtime.hour()&&LOS_time_minute==qtime.minute()&&LOS_time_second==qtime.second()&&flag2==1)
				{
					w.close();//widget close 
					flag2=0;//los crossed 
					//if(flag2!=1)
					//{
					QFile file(p);
					file.open(QFile::ReadOnly);
					QTextStream in(&file);
					QString pf;
					pf = in.readLine();
					QChar m('1');
					pf.replace(flag,1,m);
					file.close();
					file.open(QFile::WriteOnly);
					QTextStream out(&file);
					out<<pf;
					file.close();
					//}
				}
				else if(LOS_time_hour==qtime.hour()&&LOS_time_minute<=qtime.minute()+2&&flag2==0&&flag4==0)
				{
					QMessageBox msg;
					QIcon icon3("C:\\Data_files\\c.png");
					msg.setWindowIcon(icon3);
					msg.setWindowTitle("Warning");
					msg.setText("Only 2 minutes left for SPS OFF time.Do you still want to start data acquisition?");
					msg.addButton(QMessageBox::Ok);
					msg.addButton(QMessageBox::Cancel);
					int status = msg.exec();
					switch(status)
					{
					case QMessageBox::Ok:
						w.show();
						flag2=1;
						break;
					case QMessageBox::Cancel:
						flag4=1;
						break;
					}
				}


				else if(flag4!=1)
				{
					QLabel *lab = new QLabel("Data acquisition starts");
					lab->setAlignment(Qt::AlignCenter);
					w.setCentralWidget(lab);
					w.show();
					flag2=1;					
				}
				else
				{
					}

			}
			else
			{
			}
		}
	}

	table.clearContents();
	table.setRowCount(ID.size());
	table.setColumnCount(5);
	table.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	table.setHorizontalHeaderLabels(QString("Satellite ID;Orbit Number;SPS on;SPS off;Status").split(";")); 
	for(int m=0;m<ID.size();m++)
	{
			table.setItem(m,0,new QTableWidgetItem(ID.at(m)));
			table.setItem(m,1,new QTableWidgetItem(Orbitnumber.at(m)));
			table.setItem(m,2,new QTableWidgetItem(SPS_on.at(m)));
			table.setItem(m,3,new QTableWidgetItem(SPS_off.at(m)));
			if(m==flag)
			{
				table.setItem(m,4,new QTableWidgetItem(time));
				for(int k=0;k<5;k++)
				{
					table.item(m,k)->setData(Qt::BackgroundRole,Qt::green);
				}
			}
			else if(m>flag)
			{
				table.setItem(m,4,new QTableWidgetItem("Awaited"));
			}
			else
			{
				QFile op(p);
				op.open(QFile::ReadOnly);
				QTextStream inh(&op);
				QString kl = inh.readLine();
				if(kl.at(m)=='1')
				{
					table.setItem(m,4,new QTableWidgetItem("Pass Over"));
					for(int k=0;k<5;k++)
					{
						table.item(m,k)->setData(Qt::BackgroundRole,Qt::gray);
					}
				}
				else
				{
					table.setItem(m,4,new QTableWidgetItem("Pass Skipped"));
					for(int k=0;k<5;k++)
					{
						table.item(m,k)->setData(Qt::BackgroundColorRole,Qt::yellow);
					}
				}
				op.close();
			}
	}
	QTableWidgetItem *item = table.item(flag,4);
	if(flag3==0)
	{
		table.scrollToItem(item,QAbstractItemView::PositionAtTop);
		flag3=1;
	}
}

void Pass_scheduler::readfromfile()
{
	path="C:\\Data_files\\Antenna-A02_Sch_";
	
	QDate date = QDate::currentDate();
	QString part1 = date.toString("dd");
	QString part2 = date.toString("MMM").toUpper();
	QString part3 = date.toString("yyyy");
	QString part4 =".psh";
	p = path.append(part1).append(part2).append(part3);
	p.append("_memory").append(part4);

	date_ = date.toString("dd.MM.yyyy");
	QFile data(path.append(part4));
	QString line;
	QList<QString> list;
	if(data.open(QFile::ReadOnly))
	{
		QTextStream in(&data);
		do
		{
			line = in.readLine();
			list.append(line);
		}while(!line.isNull());
	}
	else
	{
		QMessageBox msgbox;
		QIcon icon4("C:\\Data_files\\c.png");
		msgbox.setWindowIcon(icon4);
		msgbox.resize(400,200);
		msgbox.setText("file is not found");
		msgbox.exec();
		
	}
	for(int i=1;i<list.size()-1;i++)
	{
		ID.append(list.at(i).mid(3,3));
		Orbitnumber.append(list.at(i).mid(6,6));
		AOS.append(list.at(i).mid(12,6));
		LOS.append(list.at(i).mid(18,6));
		SPS_availability.append(list.at(i).mid(66,1));
		SPS_on.append(list.at(i).mid(67,6));
		SPS_off.append(list.at(i).mid(73,6));
	}

	QFile memory(p);
	if(!memory.exists())
	{
		memory.open(QFile::ReadWrite);
		QTextStream out(&memory);
		for(int i=0;i<ID.size();i++)
		{
			out<<"0";
		}
	}
	QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showtime()));// countdown, AOS,LOS,SYSTEM TIME
    timer->start(1000);

	showtime();
}

void Pass_scheduler::window()
{
	QMessageBox msg;
	QIcon icon5("C:\\Data_files\\c.png");
	msg.setWindowIcon(icon5);
	msg.setWindowTitle("Prompt");
	msg.setText("Are you sure you want to quit?");
	msg.addButton(QMessageBox::Ok);
	msg.addButton(QMessageBox::Cancel);
	int status = msg.exec();
	switch(status)
	{
	case QMessageBox::Ok:
		qApp->quit();
		break;
	case QMessageBox::Cancel:
		//readfromfile();
		break;
	}
}





