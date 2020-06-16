/********************************************************************************
** Form generated from reading UI file 'iconmerge.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ICONMERGE_H
#define UI_ICONMERGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IconMergeClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *btn_select;
    QComboBox *combo_price;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *combo_award;
    QPushButton *btn_gen;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IconMergeClass)
    {
        if (IconMergeClass->objectName().isEmpty())
            IconMergeClass->setObjectName(QStringLiteral("IconMergeClass"));
        IconMergeClass->resize(600, 400);
        centralWidget = new QWidget(IconMergeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 90, 54, 18));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(120, 90, 200, 20));
        btn_select = new QPushButton(centralWidget);
        btn_select->setObjectName(QStringLiteral("btn_select"));
        btn_select->setGeometry(QRect(330, 90, 30, 23));
        combo_price = new QComboBox(centralWidget);
        combo_price->setObjectName(QStringLiteral("combo_price"));
        combo_price->setGeometry(QRect(120, 150, 69, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 150, 54, 18));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 210, 54, 18));
        combo_award = new QComboBox(centralWidget);
        combo_award->setObjectName(QStringLiteral("combo_award"));
        combo_award->setGeometry(QRect(120, 210, 100, 22));
        btn_gen = new QPushButton(centralWidget);
        btn_gen->setObjectName(QStringLiteral("btn_gen"));
        btn_gen->setGeometry(QRect(240, 270, 75, 23));
        IconMergeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(IconMergeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        IconMergeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IconMergeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        IconMergeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(IconMergeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        IconMergeClass->setStatusBar(statusBar);

        retranslateUi(IconMergeClass);

        QMetaObject::connectSlotsByName(IconMergeClass);
    } // setupUi

    void retranslateUi(QMainWindow *IconMergeClass)
    {
        IconMergeClass->setWindowTitle(QApplication::translate("IconMergeClass", "IconMerge", Q_NULLPTR));
        label->setText(QApplication::translate("IconMergeClass", "\346\272\220\346\226\207\344\273\266", Q_NULLPTR));
        btn_select->setText(QApplication::translate("IconMergeClass", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("IconMergeClass", "\351\235\242\345\200\274", Q_NULLPTR));
        label_3->setText(QApplication::translate("IconMergeClass", "\345\245\226\351\207\221", Q_NULLPTR));
        btn_gen->setText(QApplication::translate("IconMergeClass", "\347\224\237\346\210\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class IconMergeClass: public Ui_IconMergeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ICONMERGE_H
