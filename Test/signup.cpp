#include "signup.h"
#include "ui_signup.h"
#include "login.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>


Signup::Signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Signup)
{
    ui->setupUi(this);

    ui->signup_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate/Icons/signup_icon.png"));

    connect(ui->signup_Button, &QPushButton::clicked, this, &Signup::signup_Button);
    connect(ui->login_Button, &QPushButton::clicked, this, &Signup::login_Button);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::signup_Button()
{
    qDebug() << "Sign-Up-Button-Clicked";

    // Check if the policy_checkBox is checked
    if (!ui->policy_checkBox->isChecked())
    {
        qDebug() << "User must agree to policies to sign up.";
        // Display a warning message to the user using QMessageBox
        QMessageBox::warning(this, "Sign Up Failed", "Please agree to the policies to sign up.");
        return;
    }

    // Get user data from QLineEdit boxes
    QString full_name = ui->full_name_box->text();
    QString email = ui->email_box->text();
    QString username = ui->username_box->text();
    QString password = ui->password_box->text();

    // Check if any of the input fields are empty
    if (full_name.isEmpty() || email.isEmpty() || username.isEmpty() || password.isEmpty())
    {
        qDebug() << "One or more fields are empty.";
        // Display a warning message to the user using QMessageBox
        QMessageBox::warning(this, "Sign Up Failed", "Please fill in all fields.");
        return;
    }

    // Open the file to check if the user already exists
    QFile file(QDir(QCoreApplication::applicationDirPath()).filePath("userAccount.txt"));
    if (!file.exists())
    {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            file.close();
        }
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error opening the file: " << file.errorString();
        return;
    }

    QTextStream in(&file);

    bool userExists = false;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList userData = line.split(",");
        if (userData.length() == 4)
        {
            QString storedUsername = userData[2].trimmed();
            QString storedFullName = userData[0].trimmed();
            QString storedEmail = userData[1].trimmed();
            QString storedPassword = userData[3].trimmed();

            // Check if any of the fields match the entered values
            if (username == storedUsername || full_name == storedFullName ||
                email == storedEmail || password == storedPassword)
            {
                userExists = true;
                break;
            }
        }
    }

    file.close();

    if (userExists)
    {
        qDebug() << "User with the same username, full name, email, or password already exists.";
        // Display a warning message to the user using QMessageBox
        QMessageBox::warning(this, "Sign Up Failed", "User with the same username, full name, email, or password already exists.");
    }
    else
    {
        // Open the file in append mode to add new user data
        if (file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream stream(&file);

            // Write user data to the file in CSV-like format
            stream << full_name << "," << email << "," << username << "," << password << "\n";

            file.close();
            qDebug() << "User data successfully added to file.";

            hide();
            login *Login = new login();
            Login->show();
        }
        else
        {
            qDebug() << "Error creating the file!";
        }
    }
}



void Signup::login_Button()
{
    qDebug() << "Log-In-Button-Clicked";
    hide();
    login *Login = new login();
    Login->show();
}

