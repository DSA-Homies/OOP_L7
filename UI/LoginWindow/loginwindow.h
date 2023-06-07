#ifndef OOP_L7_LOGINWINDOW_H
#define OOP_L7_LOGINWINDOW_H

#include <QDialog>

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include "../../Controller/UserController.h"
#include "../../Domain/User.h"

using namespace ctrl;

class LoginWindow : public QDialog {
Q_OBJECT

public:
    explicit LoginWindow(shared_ptr<UserController> _userCtrl, QWidget *parent = nullptr) : QDialog(parent) {
        userCtrl = std::move(_userCtrl);
        setWindowTitle("Login");

        // Create UI elements
        auto *usernameLabel = new QLabel("Username:");
        auto *passwordLabel = new QLabel("Password:");
        auto *usernameLineEdit = new QLineEdit;
        usernameLineEdit->setObjectName("usernameLineEdit");
        auto *passwordLineEdit = new QLineEdit;
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        auto *loginButton = new QPushButton("Login");
        auto *cancelButton = new QPushButton("Cancel");

        // Connect the login button to the login() slot
        connect(loginButton, &QPushButton::clicked, this, &LoginWindow::login);

        // Connect the cancel button to the reject() slot
        connect(cancelButton, &QPushButton::clicked, this, &LoginWindow::reject);

        // Create a layout and add UI elements to it
        auto *layout = new QVBoxLayout;
        layout->addWidget(usernameLabel);
        layout->addWidget(usernameLineEdit);
        layout->addWidget(passwordLabel);
        layout->addWidget(passwordLineEdit);
        layout->addWidget(loginButton);
        layout->addWidget(cancelButton);

        // Set the layout for the dialog
        setLayout(layout);
    }

    User getCurrentUser() {
        return currentUser;
    }

private slots:

    void login() {
        // Get the entered username and password
        auto *usernameLineEdit = findChild<QLineEdit *>("usernameLineEdit"); // Assuming it's the first child
        auto *passwordLineEdit = findChild<QLineEdit *>("passwordLineEdit");

        QString username = usernameLineEdit->text();
        QString password = passwordLineEdit->text();

        // Perform login validation
        if (validateLogin(username, password)) {
            // Login successful, accept the dialog
            accept();
        } else {
            // Login failed, display an error message
            QMessageBox::warning(this, "Login Failed", "Invalid username or password. Please try again.");
        }
    }

private:
    shared_ptr<UserController> userCtrl;
    User currentUser;

    bool validateLogin(const QString &username, const QString &password) {
        return userCtrl->validate(username.toStdString(), password.toStdString(), currentUser);
    }

};


#endif //OOP_L7_LOGINWINDOW_H
