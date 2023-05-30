//
// Created by Mircea on 5/30/2023.
//

#ifndef OOP_L7_MAINWINDOW_H
#define OOP_L7_MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace ui {
    QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
    QT_END_NAMESPACE

    class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);

        void TableWidgetDisplay();

        ~MainWindow() override;


    private:
        Ui::MainWindow *ui;
        QTableWidget* table;


    };
} // ui

#endif //OOP_L7_MAINWINDOW_H
