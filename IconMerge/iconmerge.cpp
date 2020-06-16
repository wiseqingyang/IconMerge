#include "iconmerge.h"
#include "QDebug"
#include "QFileDialog"
#include "QMessageBox"

#include "iostream"

#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

void genTicketIcon(string srcIconName, string priceVal, string awardVal, string destIconName);

IconMerge::IconMerge(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->initComboBox();
	connect(ui.btn_select, &QPushButton::clicked, this, &IconMerge::selectFile);
	connect(ui.combo_price, &QComboBox::currentTextChanged, this, &IconMerge::changePriceText);
	connect(ui.combo_award, &QComboBox::currentTextChanged, this, &IconMerge::changeAwardText);
	connect(ui.btn_gen, &QPushButton::clicked, this, &IconMerge::generateFile);
}

IconMerge::~IconMerge()
{

}

void IconMerge::initComboBox()
{
	QDir dir("./price");
	QFileInfoList list = dir.entryInfoList();
	for (QFileInfoList::iterator ite = list.begin(); ite != list.end(); ite++)
	{
		if (ite->fileName() != "." &&  ite->fileName() != ".." && !ite->isDir()) {
			if (price.size() == 0) 
			{
				price = ite->fileName();
			}
			qDebug() << ite->fileName();
			ui.combo_price->addItem(ite->fileName());
		}
	}

	QDir awardDir("./award");
	QFileInfoList awardList = awardDir.entryInfoList();
	for (QFileInfoList::iterator ite = awardList.begin(); ite != awardList.end(); ite++)
	{
		if (ite->fileName() != "." &&  ite->fileName() != ".." && !ite->isDir()) {
			if (award.size() == 0)
			{
				award = ite->fileName();
			}
			qDebug() << ite->fileName();
			ui.combo_award->addItem(ite->fileName());
		}
	}
}

void IconMerge::selectFile() 
{
	srcFilePath = QFileDialog::getOpenFileName(this, tr("open file"), "/");
	ui.lineEdit->setText(srcFilePath);
	qDebug() << "choose dic " << srcFilePath;	
}

void IconMerge::changePriceText(const QString& text)
{
	qDebug() << "select indexx " << text;
	price = text;
}

void IconMerge::changeAwardText(const QString& text)
{
	qDebug() << "select indexx " << text;
	award = text;
}

void IconMerge::generateFile()
{
	qDebug() << "price " << price;
	qDebug() << "award" << award;
	if (srcFilePath.size() == 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("源文件不能为空"), NULL, NULL);
		return;
	}

	if (price.size() == 0 || award.size() == 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("面值或奖金不能为空"), NULL, NULL);
		return;
	}

	QDir dir(srcFilePath);

	QString fileName = dir.dirName();
	QString prefixPath = dir.path()
							.remove(QRegularExpression(QString("%1$").arg(dir.dirName())));
	QString destPath = QString("%1de_%2").arg(prefixPath).arg(fileName);

	
	genTicketIcon(srcFilePath.toLocal8Bit().toStdString(),
		price.toLocal8Bit().toStdString(),
		award.toLocal8Bit().toStdString(),
		destPath.toLocal8Bit().toStdString());
}

/*
* @param
* @frontArray 前景图片
* @backArray 后景图片
* 后景图片将会修改
*/

void mergeTwoSameImg(Mat frontArray, Mat backArray)
{
	std::vector<Mat> src_channels;
	std::vector<Mat> desc_channels;

	split(frontArray, src_channels);
	split(backArray, desc_channels);

	if (src_channels.size() == 3)
	{
		src_channels.push_back(Mat::zeros(src_channels[0].size(), src_channels[0].type()));
		src_channels[3] = 255;
	}

	if (desc_channels.size() == 3)
	{
		desc_channels.push_back(Mat::zeros(desc_channels[0].size(), desc_channels[0].type()));
		desc_channels[3] = 255;
	}

	CV_Assert(src_channels.size() == 4 && desc_channels.size() == 4);

	for (int i = 0; i < 3; i++)
	{
		// Mat tmp = desc_channels[i].mul(desc_channels[3], 1 / 255.0).mul(255.0 - desc_channels[3], 1.0 / 255.0) + src_channels[i].mul(src_channels[3], 1.0 / 255.0);
		// desc_channels[i] = tmp / (alpha / 255.0);
		desc_channels[i] = desc_channels[i].mul(255.0 - src_channels[3], 1 / 255.0); // 按透明度稀释
		desc_channels[i] += src_channels[i].mul(src_channels[3], 1.0 / 255.0);
	}
	if (backArray.channels() == 3)
	{
		desc_channels.pop_back();
	}
	merge(desc_channels, backArray);
}

void genTicketIcon(string srcIconName, string priceVal, string awardVal, string destIconName) {
	string srcPath = srcIconName;
	string pricePath = string("./price/") + priceVal;
	string awardPath = string("./award/") + awardVal;
	string destPath = destIconName;

	string rightTopBk = "./Resources/rightTopBk.png";
	string rightBottomBk = "./Resources/rightBottomBk.png";


	Mat descIcon = imread(srcPath, CV_LOAD_IMAGE_UNCHANGED);
	Mat price = imread(pricePath, CV_LOAD_IMAGE_UNCHANGED);
	Mat award = imread(awardPath, CV_LOAD_IMAGE_UNCHANGED);

	Mat rightTop = imread(rightTopBk, CV_LOAD_IMAGE_UNCHANGED);
	Mat rightBottom = imread(rightBottomBk, CV_LOAD_IMAGE_UNCHANGED);

	Mat rightTopROI = descIcon(Rect(descIcon.cols - rightTop.cols, 0, rightTop.cols, rightTop.rows));
	Mat rightBottomROI = descIcon(Rect(descIcon.cols - rightBottom.cols, descIcon.rows - rightBottom.rows, rightBottom.cols, rightBottom.rows));
	mergeTwoSameImg(rightTop, rightTopROI);
	mergeTwoSameImg(rightBottom, rightBottomROI);

	Mat priceROI = descIcon(Rect(descIcon.cols - price.cols, 0, price.cols, price.rows));
	Mat awardROI = descIcon(Rect(descIcon.cols - award.cols, descIcon.rows - award.rows, award.cols, award.rows));

	mergeTwoSameImg(price, priceROI);
	mergeTwoSameImg(award, awardROI);
	imwrite(destPath, descIcon);
	printf("compelete\n");
}
