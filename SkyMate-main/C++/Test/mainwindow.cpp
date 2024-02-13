#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>
#include <QStringList>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Icons for the left widget menu bar in buttons
    ui->Home_button->setIcon(QIcon("/Users/User/Documents/SkyMate-main/C++/Icons/Home.png"));
    ui->Dashboard_button->setIcon(QIcon("/Users/User/Documents/SkyMate-main/C++/Icons/dashboard.png"));
    ui->Search_button->setIcon(QIcon("/Users/User/Documents/SkyMate-main/C++/Icons/search.png"));
    ui->Map_button->setIcon(QIcon("/Users/User/Documents/SkyMate-main/C++/Icons/map.png"));
    ui->Setting_button->setIcon(QIcon("/Users/User/Documents/SkyMate-main/C++/Icons/settings.png"));

    // Icons for the middle widgets in labels
    ui->uvindex_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/uvindex_icon.png"));
    ui->windspeed_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/windspeed_icon.png"));
    ui->humidity_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/humidity_icon.png"));
    ui->visibility_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/visibility_icon.png"));
    ui->feelslike_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/feelslike_icon.png"));
    ui->chanceofrain_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/chanceofrain_icon.png"));
    ui->pressure_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/pressure_icon.png"));
    ui->sunset_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/sunset_icon.png"));

    // Icons in the middle widget for weathericon indicator
    ui->weathericon_indicator->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/sun_icon.png"));

    // Icons in the right widget
    // today's weather widget
    ui->weathericon_indicator_at_six->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/cloudymightrain_icon.png"));
    ui->weathericon_indicator_at_nine->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/cloudy_icon.png"));
    ui->weathericon_indicator_at_twelve->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/sun_icon.png"));

    // 7Day Foorecast
    ui->monday_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/sun_icon.png"));
    ui->tuesday_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/sun_icon.png"));
    ui->wednesday_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/sun_icon.png"));
    ui->thursday_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/cloudy_icon.png"));
    ui->friday_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/cloudy_icon.png"));
    ui->saturday_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/cloudymightrain_icon.png"));
    ui->sunday_icon->setPixmap(QPixmap("/Users/User/Documents/SkyMate-main/C++/Icons/sun_icon.png"));

    // citylist
    QStringList city_names;
    city_names << "Abidjan" << "Abu Dhabi" << "Abuja" << "Accra" << "Addis Ababa" << "Ahmedabad" << "Aleppo" << "Alexandria" << "Algiers" << "Almaty" << "Amman" << "Amsterdam" << "Anchorage" << "Andorra la Vella" << "Ankara" << "Antananarivo" << "Apia" << "Arnold" << "Ashgabat" << "Asmara" << "Asuncion" << "Athens" << "Auckland" << "Avarua" << "Baghdad" << "Baku" << "Bamako" << "Banda Aceh" << "Bandar Seri Begawan" << "Bandung" << "Bangkok" << "Bangui" << "Banjul" << "Barcelona" << "Barranquilla" << "Basrah" << "Basse-Terre" << "Basseterre" << "Beijing" << "Beirut" << "Bekasi" << "Belem" << "Belgrade" << "Belmopan" << "Belo Horizonte" << "Bengaluru" << "Berlin" << "Bern" << "Bishkek" << "Bissau" << "Bogota" << "Brasilia" << "Bratislava" << "Brazzaville" << "Bridgetown" << "Brisbane" << "Brussels" << "Bucharest" << "Budapest" << "Buenos Aires" << "Bujumbura" << "Bursa" << "Busan" <<
        "Cairo" << "Cali" << "California" << "Caloocan" << "Camayenne" << "Canberra" << "Cape Town" << "Caracas" << "Casablanca" << "Castries" << "Cayenne" << "Charlotte Amalie" << "Chengdu" << "Chennai" << "Chicago" << "Chisinau" << "Chittagong" << "Chongqing" << "Colombo" << "Conakry" << "Copenhagen" << "Cordoba" << "Curitiba" <<
        "Daegu" << "Daejeon" << "Dakar" << "Dallas" << "Damascus" << "Dar es Salaam" << "Delhi" << "Denver" << "Dhaka" << "Dili" << "Djibouti" << "Dodoma" << "Doha" << "Dongguan" << "Douala" << "Douglas" << "Dubai" << "Dublin" << "Durban" << "Dushanbe" << "Faisalabad" << "Fort-de-France" << "Fortaleza" << "Freetown" << "Fukuoka" << "Funafuti" << "Gaborone" << "George Town" << "Georgetown" << "Gibraltar" << "Gitega" << "Giza" << "Guadalajara" << "Guangzhou" << "Guatemala City" << "Guayaquil" << "Gujranwala" << "Gustavia" << "Gwangju" <<
        "Hamburg" << "Hanoi" << "Harare" << "Havana" << "Helsinki" << "Ho Chi Minh City" << "Hong Kong" << "Honiara" << "Honolulu" << "Houston" << "Hyderabad" << "Hyderabad" << "Ibadan" << "Incheon" << "Isfahan" << "Islamabad" << "Istanbul" << "Izmir" << "Jaipur" << "Jakarta" << "Jeddah" << "Jerusalem" << "Johannesburg" << "Juarez" << "Juba" <<
        "Kabul" << "Kaduna" << "Kampala" << "Kano" << "Kanpur" << "Kaohsiung" << "Karachi" << "Karaj" << "Kathmandu" << "Kawasaki" << "Kharkiv" << "Khartoum" << "Khulna" << "Kigali" << "Kingsburg" << "Kingston" << "Kingstown" << "Kinshasa" << "Kobe" << "Kolkata" << "Kota Bharu" << "Kowloon" << "Kuala Lumpur" << "Kumasi" << "Kuwait" << "Kyiv" << "Kyoto" <<
        "La Paz" << "Lagos" << "Lahore" << "Libreville" << "Lilongwe" << "Lima" << "Lisbon" << "Ljubljana" << "Lome" << "London" << "Los Angeles" << "Luanda" << "Lubumbashi" << "Lusaka" << "Luxembourg" << "Macau" << "Madrid" << "Majuro" << "Makassar" << "Malabo" << "Male" << "Mamoudzou" << "Managua" << "Manama" << "Manaus" << "Manila" << "Maputo" << "Maracaibo" << "Maracay" << "Mariehamn" << "Marigot" << "Maseru" << "Mashhad" << "Mbabane" << "Mecca" << "Medan" << "Medellin" << "Medina" << "Melbourne" << "Mexico City" << "Miami" << "Minsk" << "Mogadishu" << "Monaco" << "Monrovia" << "Montevideo" << "Montreal" << "Moroni" << "Moscow" << "Mosul" << "Multan" << "Mumbai" << "Muscat" <<
        "N'Djamena" << "Nagoya" << "Nairobi" << "Nanchong" << "Nanjing" << "Nassau" << "Nay Pyi Taw" << "New York" << "Niamey" << "Nicosia" << "Nouakchott" << "Noumea" << "Novosibirsk" << "Nuku'alofa" << "Nur-Sultan" << "Nuuk" << "Oranjestad";
    ui->comboBox->addItems(city_names);

    connect(ui->Home_button, &QPushButton::clicked, this, &MainWindow::Home_button);
    connect(ui->Dashboard_button, &QPushButton::clicked, this, &MainWindow::Dashboard_button);
    connect(ui->Search_button, &QPushButton::clicked, this, &MainWindow::Search_button);
    connect(ui->Map_button, &QPushButton::clicked, this, &MainWindow::Map_button);
    connect(ui->Setting_button, &QPushButton::clicked, this, &MainWindow::Setting_button);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Home_button()
{
    qDebug() << "Home-Button-Clicked";
}

void MainWindow::Dashboard_button()
{
    qDebug() << "DashBoard-Button-Clicked";
}

void MainWindow::Search_button()
{
    qDebug() << "Search-Button-Clicked";
}

void MainWindow::Map_button()
{
    qDebug() << "Map-Button-Clicked";
}

void MainWindow::Setting_button()
{
    qDebug() << "Setting-Button-Clicked";
}

// QNetworkReply* MainWindow::makeApiRequest(const QString &link)
// {
//     QNetworkAccessManager *manager = new QNetworkAccessManager(this);
//     QNetworkRequest request;
//     QUrl url("http://api.openweathermap.org/data/2.5/weather?q=" + link + "&appid=4c2d59ca85c3178d321be386f81a3f5b");
//     request.setUrl(url);

//     QNetworkReply *reply = manager->get(request);

//     // Connect the finished signal to a slot for further processing
//     connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *finishedReply) {
//         // Call the function to update UI when the reply is received
//         updateUIFromApiResponse(finishedReply);

//         // Clean up the network manager and reply
//         finishedReply->deleteLater();
//         manager->deleteLater();
//     });


//     return reply;
// }

// QNetworkReply* MainWindow::makeApiRequest(const QString &link)
// {
//     QNetworkAccessManager *manager = new QNetworkAccessManager(this);
//     QNetworkRequest request;
//     QUrl url("http://api.openweathermap.org/data/2.5/weather?q=" + link + "&appid=4c2d59ca85c3178d321be386f81a3f5b");
//     request.setUrl(url);

//     QNetworkReply *reply = manager->get(request);

//     // Connect the finished signal to a lambda function for further processing
//     connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *finishedReply) {
//         if (finishedReply->error() == QNetworkReply::NoError) {
//             QByteArray data = finishedReply->readAll();
//             QJsonDocument jsonResponse = QJsonDocument::fromJson(data);
//             QJsonObject jsonObject = jsonResponse.object();  // Declare jsonObject here

//             // Call the function to update UI when the reply is received
//             updateUIFromApiResponse(jsonObject);
//         } else {
//             qDebug() << "Error fetching data for City " << link << ": " << finishedReply->errorString();
//         }

//         // Clean up the network manager and reply
//         finishedReply->deleteLater();
//         manager->deleteLater();
//     });

//     return reply;
// }

QNetworkReply* MainWindow::makeApiRequest(const QString &link)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    QUrl url("http://api.openweathermap.org/data/2.5/weather?q=" + link + "&appid=4c2d59ca85c3178d321be386f81a3f5b");
    request.setUrl(url);

    QNetworkReply *reply = manager->get(request);

    // Connect the finished signal to a lambda function for further processing
    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *finishedReply) {
        if (finishedReply->error() == QNetworkReply::NoError) {
            QByteArray data = finishedReply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(data);
            QJsonObject jsonObject = jsonResponse.object();

            // Call the function to update UI when the reply is received
            updateUIFromApiResponse(jsonObject);
        } else {
            qDebug() << "Error fetching data for City " << link << ": " << finishedReply->errorString();
        }

        // Clean up the network manager and reply
        finishedReply->deleteLater();
        manager->deleteLater();
    });

    return reply;
}

void MainWindow::updateUIFromApiResponse(const QJsonObject &jsonObject)
{
    if (!jsonObject.isEmpty()) {
        double windSpeed = jsonObject["wind"].toObject()["speed"].toDouble();
        qDebug() << "Wind Speed:" << windSpeed;
        qDebug() << "Formatted Wind Speed:" << QString::number(windSpeed, 'f', 1) + " m/s";

        // Update the correct UI element (windspeed label in this case)
        ui->windspeed_value->setText(QString::number(windSpeed, 'f', 1) + " m/s");

        // Add code to update other UI elements with relevant weather data if needed
        // For example, update temperature, humidity, etc.
    } else {
        qDebug() << "Empty JSON object received.";
    }
}


// void MainWindow::updateUIFromApiResponse(const QJsonObject &jsonObject)
// {
//     double windSpeed = jsonObject["wind"].toObject()["speed"].toDouble();
//     qDebug() << "Wind Speed:" << windSpeed;
//     qDebug() << "Formatted Wind Speed:" << QString::number(windSpeed, 'f', 1) + " m/s";

//     // Update the correct UI element (windspeed label in this case)
//     ui->windspeed_value->setText(QString::number(windSpeed, 'f', 1) + " m/s");

//     // Add code to update other UI elements with relevant weather data if needed
//     // For example, update temperature, humidity, etc.
// }


// void MainWindow::on_comboBox_currentIndexChanged(int index)
// {
//     QString cityName = ui->comboBox->itemText(index);

//     // Fetch weather data for the selected city
//     QNetworkReply *reply = makeApiRequest(cityName);

//     // Connect the finished signal to a lambda function that processes the API response
//     connect(reply, &QNetworkReply::finished, this, [=]() {
//         if (reply->error() == QNetworkReply::NoError) {
//             QByteArray data = reply->readAll();
//             qDebug() << "API Response for City " << cityName << ":" << data;

//             QJsonDocument jsonResponse = QJsonDocument::fromJson(data);
//             QJsonObject jsonObject = jsonResponse.object();  // Declare jsonObject here

//             // Extract and display relevant information based on the API response
//             updateUIFromApiResponse(jsonObject);

//         } else {
//             qDebug() << "Error fetching data for City " << cityName << ": " << reply->errorString();
//         }

//         // Clean up the network reply
//         reply->deleteLater();
//     });
// }

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QString cityName = ui->comboBox->itemText(index);

    // Reset wind speed label to "N/A"
    ui->windspeed_value->setText("N/A");

    // Fetch weather data for the selected city
    QNetworkReply *reply = makeApiRequest(cityName);

    // Connect the finished signal to a lambda function that updates the windspeed label
    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(data);
            QJsonObject jsonObject = jsonResponse.object();

            // Extract and display relevant information based on the API response
            updateUIFromApiResponse(jsonObject);

        } else {
            qDebug() << "Error fetching data for City " << cityName << ": " << reply->errorString();
            // Reset wind speed label to "N/A" in case of an error
            ui->windspeed_value->setText("N/A");
        }

        // Clean up the network reply
        reply->deleteLater();
    });
}

void MainWindow::updateWindspeedLabel(double windSpeed)
{
    if (windSpeed > 0) {
        ui->windspeed_value->setText(QString::number(windSpeed, 'f', 1) + " m/s");
    } else {
        ui->windspeed_value->setText("N/A");
    }
}


void MainWindow::on_windspeed_value_linkActivated(const QString &link)
{
    qDebug() << "Link Activated for City: " << link;

    QNetworkReply *reply = makeApiRequest(link);

    // Connect the finished signal to a lambda function that updates the windspeed label
    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(data);
            QJsonObject jsonObject = jsonResponse.object();

            double windSpeed = jsonObject["wind"].toObject()["speed"].toDouble();

            // Call the updateWindspeedLabel function with the wind speed
            qDebug() << "Wind Speed for City " << link << ": " << windSpeed;
            updateWindspeedLabel(windSpeed);
        } else {
            qDebug() << "Error fetching data for City " << link << ": " << reply->errorString();
        }

        // Clean up the network reply
        reply->deleteLater();
    });
}

void MainWindow::on_uvindex_value_linkActivated(const QString &link)
{

}

