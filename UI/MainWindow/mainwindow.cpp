//
// Created by Mircea on 5/30/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <QHeaderView>
#include "../../Domain/Scooter.h"
#include "../../Utils/utils.h"
#include "../TableWidgetItems/TablewidgetItems.h"

namespace ui {
    using namespace domain;

    MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent), ui(new Ui::MainWindow) {
        ui->setupUi(this);
        TableWidgetDisplay();
    }

    MainWindow::~MainWindow() {
        delete ui;
    }

    void MainWindow::TableWidgetDisplay() {
        vector<Scooter> initList{
                Scooter("aaa", "Bolt 4", strToTime("16-05-2023"), 10.0, "Str. Blaga", Status::PARKED),
                Scooter("bbb", "Bolt 4", strToTime("20-03-2022"), 15.0, "Str. Eminescu", Status::IN_USE),
                Scooter("ccc", "Bolt 5", strToTime("15-06-2022"), 20.0, "Str. Enescu", Status::AWAITING),
                Scooter("ddd", "Bolt 5", strToTime("10-07-2023"), 22.2, "Str. Bacovia", Status::DECOMMISSIONED),
                Scooter("eee", "Bolt 5", strToTime("06-03-2023"), 30.7, "Str. Caragiale", Status::RESERVED),
                Scooter("fff", "Bolt 5", strToTime("07-01-2022"), 100.20, "Str. Rebreanu", Status::PARKED),
                Scooter("ggg", "Bolt 3", strToTime("12-02-2020"), 76.5, "Str. Racovita", Status::IN_USE),
                Scooter("hhh", "Bolt 3", strToTime("03-10-2020"), 14.0, "Str. Ipsilanti", Status::PARKED),
                Scooter("iii", "Bolt 3", strToTime("19-12-2020"), 35.3, "Str. Arghezi", Status::AWAITING),
                Scooter("jjj", "Bolt 3", strToTime("28-11-2020"), 44.8, "Str. Eliade", Status::DECOMMISSIONED),
        };

        table = new QTableWidget(this);
        table->setRowCount((int) initList.size());
        table->setColumnCount(6);

        QStringList hLabels;
        hLabels << "ID" << "Model" << "Commissioning Date" << "Kilometers" << "Location" << "Status";
        table->setHorizontalHeaderLabels(hLabels);


        // Add data
        for (int i = 0; i < table->rowCount(); i++) {
            QTableWidgetItem *item;
            for (int j = 0; j < table->columnCount(); j++) {

                if (j == 0)
                    item = new QTableWidgetItem(QString::fromStdString(initList[i].getId()));
                if (j == 1)
                    item = new QTableWidgetItem(QString::fromStdString(initList[i].getModel()));
                if (j == 2)
                    item = new DateTableWidgetItem(QString::fromStdString(initList[i].getCommissioningDateStr()));
                if (j == 3)
                    item = new FloatTableWidgetItem(QString::fromStdString(initList[i].getKilometerStr()));
                if (j == 4)
                    item = new QTableWidgetItem(QString::fromStdString(initList[i].getLocation()));
                if (j == 5)
                    item = new QTableWidgetItem(QString::fromStdString(initList[i].getStatusStr()));

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
