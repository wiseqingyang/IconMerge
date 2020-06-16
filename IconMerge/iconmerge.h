#ifndef ICONMERGE_H
#define ICONMERGE_H

#include <QtWidgets/QMainWindow>
#include "ui_iconmerge.h"

class IconMerge : public QMainWindow
{
	Q_OBJECT

public:
	IconMerge(QWidget *parent = 0);
	~IconMerge();

private:
	Ui::IconMergeClass ui;
	QString srcFilePath;
	void initComboBox();
	QString price;
	QString award;

public slots:
	void selectFile();
	void changePriceText(const QString&);
	void changeAwardText(const QString&);
	void generateFile();

};

#endif // ICONMERGE_H
