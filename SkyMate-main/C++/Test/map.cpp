#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>
#include <QStringList>
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

