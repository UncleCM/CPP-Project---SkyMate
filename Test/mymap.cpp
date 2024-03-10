#include "mymap.h"
#include "ui_mymap.h"
#include "search.h"
#include "mainwindow.h"
#include "setting.h"

myMap::myMap(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::myMap)
{
    ui->setupUi(this);
    // Icons for the left widget menu bar in buttons
    ui->Home_button->setIcon(QIcon("/Users/spoofch/Documents/Project/C++/Icons/Home.png"));
    ui->Dashboard_button->setIcon(QIcon("/Users/spoofch/Documents/Project/C++/Icons/dashboard.png"));
    ui->Search_button->setIcon(QIcon("/Users/spoofch/Documents/Project/C++/Icons/search.png"));
    ui->Map_button->setIcon(QIcon("/Users/spoofch/Documents/Project/C++/Icons/map.png"));
    ui->Setting_button->setIcon(QIcon("/Users/spoofch/Documents/Project/C++/Icons/settings.png"));

    // Icons for the middle widgets in labels
    // ui->uvindex_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/uvindex_icon.png"));
    // ui->windspeed_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/windspeed_icon.png"));
    // ui->humidity_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/humidity_icon.png"));
    // ui->visibility_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/visibility_icon.png"));
    // ui->feelslike_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/feelslike_icon.png"));
    // ui->sunrise_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/chanceofrain_icon.png"));
    // ui->pressure_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/pressure_icon.png"));
    // ui->sunset_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/sunset_icon.png"));

    // Icons in the middle widget for weathericon indicator
    // ui->weathericon_indicator->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/sun_icon.png"));

    // Icons in the right widget
    // today's weather widget
    // ui->weathericon_indicator_at_six->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/cloudymightrain_icon.png"));
    // ui->weathericon_indicator_at_nine->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/cloudy_icon.png"));
    // ui->weathericon_indicator_at_twelve->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/sun_icon.png"));

    // 7Day Foorecast
    // ui->monday_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/sun_icon.png"));
    // ui->tuesday_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/sun_icon.png"));
    // ui->wednesday_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/sun_icon.png"));
    // ui->thursday_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/cloudy_icon.png"));
    // ui->friday_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/cloudy_icon.png"));
    // ui->saturday_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/cloudymightrain_icon.png"));
    // ui->sunday_icon->setPixmap(QPixmap("/Users/spoofch/Documents/Project/C++/Icons/sun_icon.png"));

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

    connect(ui->Home_button, &QPushButton::clicked, this, &myMap::Home_button);
    connect(ui->Dashboard_button, &QPushButton::clicked, this, &myMap::Dashboard_button);
    connect(ui->Search_button, &QPushButton::clicked, this, &myMap::Search_button);
    connect(ui->Map_button, &QPushButton::clicked, this, &myMap::Map_button);
    connect(ui->Setting_button, &QPushButton::clicked, this, &myMap::Setting_button);
}

myMap::~myMap()
{
    delete ui;
}
void myMap::Home_button()
{
    qDebug() << "Home-Button-Clicked";
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void myMap::Dashboard_button()
{
    qDebug() << "DashBoard-Button-Clicked";
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

void myMap::Search_button()
{
    qDebug() << "Search-Button-Clicked";
    hide();
    Search *search = new Search();
    search->show();
}

void myMap::Map_button()
{
    qDebug() << "Map-Button-Clicked";
}

void myMap::Setting_button()
{
    qDebug() << "Setting-Button-Clicked";
    hide();
    Setting *setting = new Setting();
    setting->show();
}

