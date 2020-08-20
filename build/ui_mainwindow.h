/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *bt_load;
    QPushButton *bt_save;
    QLineEdit *in_filename;
    QLabel *label_inputsizewh;
    QLabel *label_w;
    QLabel *label_h;
    QLabel *label_xmultiple;
    QPushButton *bt_filter;
    QLineEdit *in_filter;
    QPushButton *bt_alignmajor;
    QLabel *label_pointsize;
    QLabel *label_filteredpointsize;
    QPushButton *bt_resetcam;
    QPushButton *bt_viewup;
    QPushButton *bt_viewdown;
    QPushButton *bt_viewleft;
    QLabel *label_camera;
    QPushButton *bt_viewright;
    QPushButton *bt_alignmiddle;
    QPushButton *bt_alignminor;
    QLabel *label_major0;
    QLabel *label_major1;
    QLabel *label_major2;
    QLabel *label_middle1;
    QLabel *label_middle0;
    QLabel *label_middle2;
    QLabel *label_minor1;
    QLabel *label_minor0;
    QLabel *label_minor2;
    QPushButton *bt_boundingbox;
    QLineEdit *in_x_rot;
    QLineEdit *in_y_rot;
    QLineEdit *in_z_rot;
    QCheckBox *checkBox_voxel;
    QPushButton *bt_xrot;
    QPushButton *bt_yrot;
    QPushButton *bt_zrot;
    QLabel *label_bb_xsize;
    QLabel *label_bb_zsize;
    QLabel *label_bb_ysize;
    QLabel *label_bbx;
    QLabel *label_bby;
    QLabel *label_bbz;
    QPushButton *bt_pca;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(442, 421);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        bt_load = new QPushButton(centralWidget);
        bt_load->setObjectName(QStringLiteral("bt_load"));
        bt_load->setGeometry(QRect(20, 10, 71, 25));
        bt_save = new QPushButton(centralWidget);
        bt_save->setObjectName(QStringLiteral("bt_save"));
        bt_save->setGeometry(QRect(360, 10, 71, 25));
        in_filename = new QLineEdit(centralWidget);
        in_filename->setObjectName(QStringLiteral("in_filename"));
        in_filename->setGeometry(QRect(100, 10, 251, 25));
        label_inputsizewh = new QLabel(centralWidget);
        label_inputsizewh->setObjectName(QStringLiteral("label_inputsizewh"));
        label_inputsizewh->setGeometry(QRect(135, 40, 111, 17));
        label_w = new QLabel(centralWidget);
        label_w->setObjectName(QStringLiteral("label_w"));
        label_w->setGeometry(QRect(250, 40, 91, 17));
        label_h = new QLabel(centralWidget);
        label_h->setObjectName(QStringLiteral("label_h"));
        label_h->setGeometry(QRect(370, 40, 101, 20));
        label_xmultiple = new QLabel(centralWidget);
        label_xmultiple->setObjectName(QStringLiteral("label_xmultiple"));
        label_xmultiple->setGeometry(QRect(350, 40, 16, 17));
        bt_filter = new QPushButton(centralWidget);
        bt_filter->setObjectName(QStringLiteral("bt_filter"));
        bt_filter->setGeometry(QRect(70, 60, 89, 25));
        in_filter = new QLineEdit(centralWidget);
        in_filter->setObjectName(QStringLiteral("in_filter"));
        in_filter->setGeometry(QRect(20, 60, 41, 25));
        bt_alignmajor = new QPushButton(centralWidget);
        bt_alignmajor->setObjectName(QStringLiteral("bt_alignmajor"));
        bt_alignmajor->setGeometry(QRect(140, 220, 89, 31));
        label_pointsize = new QLabel(centralWidget);
        label_pointsize->setObjectName(QStringLiteral("label_pointsize"));
        label_pointsize->setGeometry(QRect(170, 65, 71, 17));
        label_filteredpointsize = new QLabel(centralWidget);
        label_filteredpointsize->setObjectName(QStringLiteral("label_filteredpointsize"));
        label_filteredpointsize->setGeometry(QRect(250, 65, 101, 17));
        bt_resetcam = new QPushButton(centralWidget);
        bt_resetcam->setObjectName(QStringLiteral("bt_resetcam"));
        bt_resetcam->setGeometry(QRect(290, 180, 141, 31));
        bt_viewup = new QPushButton(centralWidget);
        bt_viewup->setObjectName(QStringLiteral("bt_viewup"));
        bt_viewup->setGeometry(QRect(140, 110, 89, 25));
        bt_viewdown = new QPushButton(centralWidget);
        bt_viewdown->setObjectName(QStringLiteral("bt_viewdown"));
        bt_viewdown->setGeometry(QRect(140, 170, 89, 25));
        bt_viewleft = new QPushButton(centralWidget);
        bt_viewleft->setObjectName(QStringLiteral("bt_viewleft"));
        bt_viewleft->setGeometry(QRect(40, 140, 89, 25));
        label_camera = new QLabel(centralWidget);
        label_camera->setObjectName(QStringLiteral("label_camera"));
        label_camera->setGeometry(QRect(140, 140, 101, 20));
        bt_viewright = new QPushButton(centralWidget);
        bt_viewright->setObjectName(QStringLiteral("bt_viewright"));
        bt_viewright->setGeometry(QRect(240, 140, 89, 25));
        bt_alignmiddle = new QPushButton(centralWidget);
        bt_alignmiddle->setObjectName(QStringLiteral("bt_alignmiddle"));
        bt_alignmiddle->setGeometry(QRect(240, 220, 89, 31));
        bt_alignminor = new QPushButton(centralWidget);
        bt_alignminor->setObjectName(QStringLiteral("bt_alignminor"));
        bt_alignminor->setGeometry(QRect(340, 220, 89, 31));
        label_major0 = new QLabel(centralWidget);
        label_major0->setObjectName(QStringLiteral("label_major0"));
        label_major0->setGeometry(QRect(150, 260, 67, 17));
        label_major1 = new QLabel(centralWidget);
        label_major1->setObjectName(QStringLiteral("label_major1"));
        label_major1->setGeometry(QRect(150, 280, 67, 17));
        label_major2 = new QLabel(centralWidget);
        label_major2->setObjectName(QStringLiteral("label_major2"));
        label_major2->setGeometry(QRect(150, 300, 67, 17));
        label_middle1 = new QLabel(centralWidget);
        label_middle1->setObjectName(QStringLiteral("label_middle1"));
        label_middle1->setGeometry(QRect(250, 280, 67, 17));
        label_middle0 = new QLabel(centralWidget);
        label_middle0->setObjectName(QStringLiteral("label_middle0"));
        label_middle0->setGeometry(QRect(250, 260, 67, 17));
        label_middle2 = new QLabel(centralWidget);
        label_middle2->setObjectName(QStringLiteral("label_middle2"));
        label_middle2->setGeometry(QRect(250, 300, 67, 17));
        label_minor1 = new QLabel(centralWidget);
        label_minor1->setObjectName(QStringLiteral("label_minor1"));
        label_minor1->setGeometry(QRect(350, 280, 67, 17));
        label_minor0 = new QLabel(centralWidget);
        label_minor0->setObjectName(QStringLiteral("label_minor0"));
        label_minor0->setGeometry(QRect(350, 260, 67, 17));
        label_minor2 = new QLabel(centralWidget);
        label_minor2->setObjectName(QStringLiteral("label_minor2"));
        label_minor2->setGeometry(QRect(350, 300, 67, 17));
        bt_boundingbox = new QPushButton(centralWidget);
        bt_boundingbox->setObjectName(QStringLiteral("bt_boundingbox"));
        bt_boundingbox->setGeometry(QRect(20, 250, 101, 31));
        in_x_rot = new QLineEdit(centralWidget);
        in_x_rot->setObjectName(QStringLiteral("in_x_rot"));
        in_x_rot->setGeometry(QRect(190, 320, 31, 25));
        in_y_rot = new QLineEdit(centralWidget);
        in_y_rot->setObjectName(QStringLiteral("in_y_rot"));
        in_y_rot->setGeometry(QRect(290, 320, 31, 25));
        in_z_rot = new QLineEdit(centralWidget);
        in_z_rot->setObjectName(QStringLiteral("in_z_rot"));
        in_z_rot->setGeometry(QRect(390, 320, 31, 25));
        checkBox_voxel = new QCheckBox(centralWidget);
        checkBox_voxel->setObjectName(QStringLiteral("checkBox_voxel"));
        checkBox_voxel->setGeometry(QRect(20, 37, 141, 23));
        checkBox_voxel->setChecked(true);
        bt_xrot = new QPushButton(centralWidget);
        bt_xrot->setObjectName(QStringLiteral("bt_xrot"));
        bt_xrot->setGeometry(QRect(140, 320, 51, 25));
        bt_yrot = new QPushButton(centralWidget);
        bt_yrot->setObjectName(QStringLiteral("bt_yrot"));
        bt_yrot->setGeometry(QRect(240, 320, 51, 25));
        bt_zrot = new QPushButton(centralWidget);
        bt_zrot->setObjectName(QStringLiteral("bt_zrot"));
        bt_zrot->setGeometry(QRect(340, 320, 51, 25));
        label_bb_xsize = new QLabel(centralWidget);
        label_bb_xsize->setObjectName(QStringLiteral("label_bb_xsize"));
        label_bb_xsize->setGeometry(QRect(50, 290, 67, 17));
        label_bb_zsize = new QLabel(centralWidget);
        label_bb_zsize->setObjectName(QStringLiteral("label_bb_zsize"));
        label_bb_zsize->setGeometry(QRect(50, 330, 67, 17));
        label_bb_ysize = new QLabel(centralWidget);
        label_bb_ysize->setObjectName(QStringLiteral("label_bb_ysize"));
        label_bb_ysize->setGeometry(QRect(50, 310, 67, 17));
        label_bbx = new QLabel(centralWidget);
        label_bbx->setObjectName(QStringLiteral("label_bbx"));
        label_bbx->setGeometry(QRect(30, 290, 21, 17));
        label_bby = new QLabel(centralWidget);
        label_bby->setObjectName(QStringLiteral("label_bby"));
        label_bby->setGeometry(QRect(30, 310, 21, 17));
        label_bbz = new QLabel(centralWidget);
        label_bbz->setObjectName(QStringLiteral("label_bbz"));
        label_bbz->setGeometry(QRect(30, 330, 21, 17));
        bt_pca = new QPushButton(centralWidget);
        bt_pca->setObjectName(QStringLiteral("bt_pca"));
        bt_pca->setGeometry(QRect(20, 210, 101, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 442, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        bt_load->setText(QApplication::translate("MainWindow", "Load PLY", Q_NULLPTR));
        bt_save->setText(QApplication::translate("MainWindow", "Save PLY", Q_NULLPTR));
        label_inputsizewh->setText(QApplication::translate("MainWindow", "Input size W*H:", Q_NULLPTR));
        label_w->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_h->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_xmultiple->setText(QApplication::translate("MainWindow", "x", Q_NULLPTR));
        bt_filter->setText(QApplication::translate("MainWindow", "Filter points", Q_NULLPTR));
        in_filter->setText(QApplication::translate("MainWindow", "0.01", Q_NULLPTR));
        bt_alignmajor->setText(QApplication::translate("MainWindow", "Align major", Q_NULLPTR));
        label_pointsize->setText(QApplication::translate("MainWindow", "Point size:", Q_NULLPTR));
        label_filteredpointsize->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        bt_resetcam->setText(QApplication::translate("MainWindow", "Reset Camera View", Q_NULLPTR));
        bt_viewup->setText(QApplication::translate("MainWindow", "Up", Q_NULLPTR));
        bt_viewdown->setText(QApplication::translate("MainWindow", "Down", Q_NULLPTR));
        bt_viewleft->setText(QApplication::translate("MainWindow", "Left", Q_NULLPTR));
        label_camera->setText(QApplication::translate("MainWindow", "Camera View", Q_NULLPTR));
        bt_viewright->setText(QApplication::translate("MainWindow", "Right", Q_NULLPTR));
        bt_alignmiddle->setText(QApplication::translate("MainWindow", "Align middle", Q_NULLPTR));
        bt_alignminor->setText(QApplication::translate("MainWindow", "Align minor", Q_NULLPTR));
        label_major0->setText(QApplication::translate("MainWindow", "major0", Q_NULLPTR));
        label_major1->setText(QApplication::translate("MainWindow", "major1", Q_NULLPTR));
        label_major2->setText(QApplication::translate("MainWindow", "major2", Q_NULLPTR));
        label_middle1->setText(QApplication::translate("MainWindow", "middle1", Q_NULLPTR));
        label_middle0->setText(QApplication::translate("MainWindow", "middle0", Q_NULLPTR));
        label_middle2->setText(QApplication::translate("MainWindow", "middle2", Q_NULLPTR));
        label_minor1->setText(QApplication::translate("MainWindow", "minor1", Q_NULLPTR));
        label_minor0->setText(QApplication::translate("MainWindow", "minor0", Q_NULLPTR));
        label_minor2->setText(QApplication::translate("MainWindow", "minor2", Q_NULLPTR));
        bt_boundingbox->setText(QApplication::translate("MainWindow", "Bounding Box", Q_NULLPTR));
        in_x_rot->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        in_y_rot->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        in_z_rot->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        checkBox_voxel->setText(QApplication::translate("MainWindow", "Apply Voxel", Q_NULLPTR));
        bt_xrot->setText(QApplication::translate("MainWindow", "X-rot", Q_NULLPTR));
        bt_yrot->setText(QApplication::translate("MainWindow", "Y-rot", Q_NULLPTR));
        bt_zrot->setText(QApplication::translate("MainWindow", "Z-rot", Q_NULLPTR));
        label_bb_xsize->setText(QApplication::translate("MainWindow", "x size", Q_NULLPTR));
        label_bb_zsize->setText(QApplication::translate("MainWindow", "z size", Q_NULLPTR));
        label_bb_ysize->setText(QApplication::translate("MainWindow", "y size", Q_NULLPTR));
        label_bbx->setText(QApplication::translate("MainWindow", "x:", Q_NULLPTR));
        label_bby->setText(QApplication::translate("MainWindow", "y:", Q_NULLPTR));
        label_bbz->setText(QApplication::translate("MainWindow", "z:", Q_NULLPTR));
        bt_pca->setText(QApplication::translate("MainWindow", "PCA calculate", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
