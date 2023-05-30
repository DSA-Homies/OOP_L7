//
// Created by Mircea on 5/30/2023.
//

#ifndef OOP_L7_TABLEWIDGETITEMS_H
#define OOP_L7_TABLEWIDGETITEMS_H

#include <QTableWidgetItem>
#include "../../Utils/utils.h"

/**
 * @brief Helper classes to sort the table by date and float
 */
namespace ui {
    class DateTableWidgetItem : public QTableWidgetItem {
    public:
        explicit DateTableWidgetItem(const QString &text) : QTableWidgetItem(text) {}

        bool operator<(const QTableWidgetItem &other) const override {
            time_t t1 = strToTime(text().toStdString());
            time_t t2 = strToTime(other.text().toStdString());
            return t1 < t2;
        }
    };

    class FloatTableWidgetItem : public QTableWidgetItem {
    public:
        explicit FloatTableWidgetItem(const QString &text) : QTableWidgetItem(text) {}

        bool operator<(const QTableWidgetItem &other) const override {
            float f1 = text().toFloat();
            float f2 = other.text().toFloat();
            return f1 < f2;
        }
    };
}
#endif //OOP_L7_TABLEWIDGETITEMS_H
