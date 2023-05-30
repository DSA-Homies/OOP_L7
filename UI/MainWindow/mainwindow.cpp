//
// Created by Mircea on 5/30/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <QHeaderView>
#include "../../Utils/utils.h"
#include "../TableWidgetItems/TablewidgetItems.h"

namespace ui {
    using namespace domain;


    MainWindow::MainWindow(unique_ptr<ScooterController> _scooterCtrl, unique_ptr<UserController> _userCtrl,
                           QWidget *parent) :
            QMainWindow(parent), ui(new Ui::MainWindow) {
        ui->setupUi(this);
        scooterCtrl = std::move(_scooterCtrl);
        userCtrl = std::move(_userCtrl);

        TableWidgetDisplay(scooterCtrl->getAll());
    }


    MainWindow::~MainWindow() {
        delete ui;
    }

    void MainWindow::TableWidgetDisplay(vector<Scooter> scooterList) {
        table = new QTableWidget(this);
        table->setRowCount((int) scooterList.size());
        table->setColumnCount(6);

        QStringList hLabels;
        hLabels << "ID" << "Model" << "Commissioning Date" << "Kilometers" << "Location" << "Status";
        table->setHorizontalHeaderLabels(hLabels);


        // Add data
        for (int i = 0; i < table->rowCount(); i++) {
            QTableWidgetItem *item;
            for (int j = 0; j < table->columnCount(); j++) {

                if (j == 0)
                    item = new QTableWidgetItem(QString::fromStdString(scooterList[i].getId()));
                if (j == 1)
                    item = new QTableWidgetItem(QString::fromStdString(scooterList[i].getModel()));
                if (j == 2)
                    item = new DateTableWidgetItem(
                            QString::fromStdString(scooterList[i].getCommissioningDateStr()));
                if (j == 3)
                    item = new FloatTableWidgetItem(QString::fromStdString(scooterList[i].getKilometerStr()));
                if (j == 4)
                    item = new QTableWidgetItem(QString::fromStdString(scooterList[i].getLocation()));
                if (j == 5)
                    item = new QTableWidgetItem(QString::fromStdString(scooterList[i].getStatusStr()));

                table->setItem(i, j, item);
            }
        }

        table->setSortingEnabled(true);


        table->setStyleSheet("QTableWidget{"
                             "background-color: #C0C0C0;"
                             "alternate-background-color: #606060;"
                             "selection-background-color: #282828;"
                             "}");
        table->setAlternatingRowColors(true);

        // cell items properties
        table->setSelectionMode(QAbstractItemView::SingleSelection);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setTextElideMode(Qt::ElideRight);


        // Table properties
        table->setShowGrid(true);
        table->setGridStyle(Qt::DotLine);
        table->setSortingEnabled(true);
        table->setCornerButtonEnabled(true);

        // Header properties
        table->horizontalHeader()->setVisible(true);
        table->horizontalHeader()->setDefaultSectionSize(150);
        table->horizontalHeader()->setStretchLastSection(true);


        setCentralWidget(table);


    }
} // ui
