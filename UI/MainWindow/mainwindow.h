//
// Created by Mircea on 5/30/2023.
//

#ifndef OOP_L7_MAINWINDOW_H
#define OOP_L7_MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
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
        explicit MainWindow(unique_ptr<ScooterController> _scooterCtrl, unique_ptr<UserController> _userCtrl,
                            QWidget *parent = nullptr);

        void TableWidgetDisplay(vector<domain::Scooter> scooterList);

        ~MainWindow() override;


    private:
        Ui::MainWindow *ui;
        QTableWidget *table{};
        unique_ptr<ScooterController> scooterCtrl;
        unique_ptr<UserController> userCtrl;

    };
} // ui

#endif //OOP_L7_MAINWINDOW_H
