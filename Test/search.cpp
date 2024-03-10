#include "search.h"
#include "ui_search.h"
#include "mainwindow.h"
#include "setting.h"
#include "mymap.h"
#include <QDebug>
#include <QPixmap>
#include <QStringList>
#include <QDateTime>
#include <QTimeZone>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Search::Search(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Search)
{
    ui->setupUi(this);

    MainWindow* mainWindow = qobject_cast<MainWindow*>(parent);
    connect(mainWindow  , &MainWindow::currentWeatherDataReceived, this, &Search::currentWeatherDataReceived);
    connect(mainWindow, &MainWindow::fiveDayWeatherDataReceived, this, &Search::fiveDayWeatherDataReceived);

    // Icons for the left widget menu bar in buttons
    ui->Home_button->setIcon(QIcon("/Users/User/Documents/SkyMate/C++/Icons/Home.png"));
    ui->Dashboard_button->setIcon(QIcon("/Users/User/Documents/SkyMate/C++/Icons/dashboard.png"));
    ui->Search_button->setIcon(QIcon("/Users/User/Documents/SkyMate/C++/Icons/search.png"));
    ui->Map_button->setIcon(QIcon("/Users/User/Documents/SkyMate/C++/Icons/map.png"));
    ui->Setting_button->setIcon(QIcon("/Users/User/Documents/SkyMate/C++/Icons/settings.png"));

    // Icons in the middle widget for weathericon indicator
    ui->weathericon_indicator->setPixmap(QPixmap("/Users/User/Documents/SkyMate/C++/Icons/sun_icon.png"));

    // Icons in the right widget
    // today's weather widget
    ui->weathericon_indicator_at_six->setPixmap(QPixmap("/Users/User/Documents/SkyMate/C++/Icons/cloudymightrain_icon.png"));
    ui->weathericon_indicator_at_nine->setPixmap(QPixmap("/Users/User/Documents/SkyMate/C++/Icons/cloudy_icon.png"));
    ui->weathericon_indicator_at_twelve->setPixmap(QPixmap("/Users/User/Documents/SkyMate/C++/Icons/sun_icon.png"));

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

    connect(ui->Home_button, &QPushButton::clicked, this, &Search::Home_button);
    connect(ui->Dashboard_button, &QPushButton::clicked, this, &Search::Dashboard_button);
    connect(ui->Search_button, &QPushButton::clicked, this, &Search::Search_button);
    connect(ui->Map_button, &QPushButton::clicked, this, &Search::Map_button);
    connect(ui->Setting_button, &QPushButton::clicked, this, &Search::Setting_button);

    // Example in MainWindow class
    QJsonObject currentWeatherData;  // Replace with actual data
    currentWeatherDataReceived(currentWeatherData);

    QJsonObject fiveDayWeatherData;  // Replace with actual data
    fiveDayWeatherDataReceived(fiveDayWeatherData);

}

Search::~Search()
{
    delete ui;
}
void Search::Home_button()
{
    qDebug() << "Home-Button-Clicked";
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void Search::Dashboard_button()
{
    qDebug() << "DashBoard-Button-Clicked";
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void Search::Search_button()
{
    qDebug() << "Search-Button-Clicked";
}

void Search::Map_button()
{
    qDebug() << "Map-Button-Clicked";
    hide();
    myMap *mymap = new myMap();
    mymap->show();
}

void Search::Setting_button()
{
    qDebug() << "Setting-Button-Clicked";
    hide();
    Setting *setting = qobject_cast<Setting*>(this->parentWidget());
    if (setting) {
        setting->show();
    }
}
void Search::currentWeatherDataReceived(const QJsonObject & jsonObject)
{
    qDebug() << "Current weather data received:" << jsonObject;
    double temperature = jsonObject["temperature"].toDouble();
    qDebug() << "Temperature: " << temperature;
    double temp_celsius = temperature - 273.15;  // Corrected this line
    qDebug() << "temp_celsius: " << temp_celsius;
    ui->temperature_label->setText(QString::number(temp_celsius, 'f', 0) + "°c");
}


void Search::fiveDayWeatherDataReceived(const QJsonObject & forecastWeatherJsonObject)
{
    qDebug() << "Five-day weather data received:" << forecastWeatherJsonObject;
    // Add your UI update code here
}


void Search::updateUIFromApiResponse(const QJsonObject &data)
{
    // ... code to update UI with the received weather data
    qDebug() << "Received weather data in Search class:" << data;
}
////////////////////////////////////////////////////////////////////////
