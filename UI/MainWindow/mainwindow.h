//
// Created by Mircea on 5/30/2023.
//

#ifndef OOP_L7_MAINWINDOW_H
#define OOP_L7_MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QToolButton>
#include <QToolBar>
#include "../../Domain/Scooter.h"
#include "../../Controller/ScooterController.h"
#include "../../Controller/UserController.h"

using namespace ctrl;

namespace ui {
    QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
    QT_END_NAMESPACE

    class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(unique_ptr<ScooterController> _scooterCtrl, shared_ptr<UserController> _userCtrl,
                            QWidget *parent = nullptr);

        void TableWidgetDisplay(vector<domain::Scooter> scooterList);

        void initToolBar();

        ~MainWindow() override;


    private:
        Ui::MainWindow *ui;
        QToolBar *toolBar{};
        QMenu *fileMenu{};
        QAction *loadAction{};
        QToolButton *fileButton{};
        QTableWidget *table{};
        unique_ptr<ScooterController> scooterCtrl;
        shared_ptr<UserController> userCtrl;

    };
} // ui

#endif //OOP_L7_MAINWINDOW_H
