#include "setting.h"
#include "ui_setting.h"
Setting::Setting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Setting),
    selectedWidth(0),
    selectedHeight(0)
{
    ui->setupUi(this);

    connect(ui->FullScreen_checkBox, &QCheckBox::stateChanged, this, &Setting::on_FullScreen_checkBox_stateChanged);
    connect(this, &Setting::CelsiusCheckBoxStateChanged, this, &Setting::celsius_checkBox_stateChanged);


    // Icons for the left widget menu bar in buttons

    ui->Home_button->setIcon(QIcon("/Users/User/Documents/SkyMate/Icons/Home.png"));
    ui->Dashboard_button->setIcon(QIcon("/Users/User/Documents/SkyMate/Icons/dashboard.png"));
    ui->Setting_button->setIcon(QIcon("/Users/User/Documents/SkyMate/Icons/settings.png"));
    ui->Exit_button->setIcon(QIcon("/Users/User/Documents/SkyMate/Icons/Exit_icon.png"));

    // citylist
    QStringList city_names;
    city_names << "Abidjan" << "Abu Dhabi" << "Abuja" << "Accra" << "Addis Ababa" << "Ahmedabad" << "Aleppo" << "Alexandria" << "Algiers" << "Almaty" << "Amman" << "Amsterdam" << "Anchorage" << "Andorra la Vella" << "Ankara" << "Antananarivo" << "Apia" << "Arnold" << "Ashgabat" << "Asmara" << "Asuncion" << "Athens" << "Auckland" << "Avarua" << "Baghdad" << "Baku" << "Bamako" << "Banda Aceh" << "Bandar Seri Begawan" << "Bandung" << "Bangkok" << "Bangui" << "Banjul" << "Barcelona" << "Barranquilla" << "Basrah" << "Basse-Terre" << "Basseterre" << "Beijing" << "Beirut" << "Bekasi" << "Belem" << "Belgrade" << "Belmopan" << "Belo Horizonte" << "Bengaluru" << "Berlin" << "Bern" << "Bishkek" << "Bissau" << "Bogota" << "Brasilia" << "Bratislava" << "Brazzaville" << "Bridgetown" << "Brisbane" << "Brussels" << "Bucharest" << "Budapest" << "Buenos Aires" << "Bujumbura" << "Bursa" << "Busan" <<
        "Cairo" << "Cali" << "California" << "Caloocan" << "Camayenne" << "Canberra" << "Cape Town" << "Caracas" << "Casablanca" << "Castries" << "Cayenne" << "Charlotte Amalie" << "Chengdu" << "Chennai" << "Chicago" << "Chisinau" << "Chittagong" << "Chongqing" << "Colombo" << "Conakry" << "Copenhagen" << "Cordoba" << "Curitiba" <<
        "Daegu" << "Daejeon" << "Dakar" << "Dallas" << "Damascus" << "Dar es Salaam" << "Delhi" << "Denver" << "Dhaka" << "Dili" << "Djibouti" << "Dodoma" << "Doha" << "Dongguan" << "Douala" << "Douglas" << "Dubai" << "Dublin" << "Durban" << "Dushanbe" << "Faisalabad" << "Fort-de-France" << "Fortaleza" << "Freetown" << "Fukuoka" << "Funafuti" << "Gaborone" << "George Town" << "Georgetown" << "Gibraltar" << "Gitega" << "Giza" << "Guadalajara" << "Guangzhou" << "Guatemala City" << "Guayaquil" << "Gujranwala" << "Gustavia" << "Gwangju" <<
        "Hamburg" << "Hanoi" << "Harare" << "Havana" << "Helsinki" << "Ho Chi Minh City" << "Hong Kong" << "Honiara" << "Honolulu" << "Houston" << "Hyderabad" << "Hyderabad" << "Ibadan" << "Incheon" << "Isfahan" << "Islamabad" << "Istanbul" << "Izmir" << "Jaipur" << "Jakarta" << "Jeddah" << "Jerusalem" << "Johannesburg" << "Juarez" << "Juba" <<
        "Kabul" << "Kaduna" << "Kampala" << "Kano" << "Kanpur" << "Kaohsiung" << "Karachi" << "Karaj" << "Kathmandu" << "Kawasaki" << "Kharkiv" << "Khartoum" << "Khulna" << "Kigali" << "Kingsburg" << "Kingston" << "Kingstown" << "Kinshasa" << "Kobe" << "Kolkata" << "Kota Bharu" << "Kowloon" << "Kuala Lumpur" << "Kumasi" << "Kuwait" << "Kyiv" << "Kyoto" <<
        "La Paz" << "Lagos" << "Lahore" << "Libreville" << "Lilongwe" << "Lima" << "Lisbon" << "Ljubljana" << "Lome" << "London" << "Los Angeles" << "Luanda" << "Lubumbashi" << "Lusaka" << "Luxembourg" << "Macau" << "Madrid" << "Majuro" << "Makassar" << "Malabo" << "Male" << "Mamoudzou" << "Managua" << "Manama" << "Manaus" << "Manila" << "Maputo" << "Maracaibo" << "Maracay" << "Mariehamn" << "Marigot" << "Maseru" << "Mashhad" << "Mbabane" << "Mecca" << "Medan" << "Medellin" << "Medina" << "Melbourne" << "Mexico City" << "Miami" << "Minsk" << "Mogadishu" << "Monaco" << "Monrovia" << "Montevideo" << "Montreal" << "Moroni" << "Moscow" << "Mosul" << "Multan" << "Mumbai" << "Muscat" <<
        "N'Djamena" << "Nagoya" << "Nairobi" << "Nanchong" << "Nanjing" << "Nassau" << "Nay Pyi Taw" << "New York" << "Niamey" << "Nicosia" << "Nouakchott" << "Noumea" << "Novosibirsk" << "Nuku'alofa" << "Nur-Sultan" << "Nuuk" << "Oranjestad";
    // ui->comboBox->addItems(city_names);

    connect(ui->Home_button, &QPushButton::clicked, this, &Setting::Home_button);
    connect(ui->Dashboard_button, &QPushButton::clicked, this, &Setting::Dashboard_button);
    connect(ui->Setting_button, &QPushButton::clicked, this, &Setting::Setting_button);
    connect(ui->Exit_button, &QPushButton::clicked, this, &Setting::Exit_button);


    QStringList resolutionList = {"1064 x 640", "1280 x 720", "1366 x 768", "1600 x 900", "1920 x 1080"};

    ui->comboBox->addItems(resolutionList);

    // Connect the signal to the slot
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_currentIndexChanged(int)));
}
Setting::~Setting()
{
    delete ui;
}
void Setting::Home_button()
{
    qDebug() << "Home-Button-Clicked";
    hide();
}

void Setting::Dashboard_button()
{
    qDebug() << "DashBoard-Button-Clicked";
    hide();

    // Emit signals to inform MainWindow about changes

    if (ui->FullScreen_checkBox->isChecked())
    {
        emit fullScreenStateChanged(true);
    }
    else
    {
        emit resolutionChanged(selectedWidth, selectedHeight);
        emit fullScreenStateChanged(false);
    }
    // emit CelsiusCheckBoxStateChanged(Qt::Checked);
    emit showMainWindow();

    if (ui->TempUnit_checkBox->isChecked()){
        emit CelsiusCheckBoxStateChanged(Qt::Checked);
    }
    else{
        emit CelsiusCheckBoxStateChanged(Qt::Unchecked);
    }

    // if (ui->TimeFormat->isChecked()){
    //     emit TimeFormatChanged(Qt::Checked);
    // }
    // else{
    //     emit TimeFormatChanged(Qt::Unchecked);
    // }

    // if (ui->DistanceFormat->isChecked()){
    //     emit DistanceFormatChanged(Qt::Checked);
    // }
    // else{
    //     emit DistanceFormatChanged(Qt::Unchecked);
    // }
}

void Setting::Exit_button(){
    exit(0);
}

////////////////////////////////////////////////////////////////////////////////////

void Setting::Setting_button()
{
    qDebug() << "Setting-Button-Clicked";
}

void Setting::on_comboBox_currentIndexChanged(int index)
{
    QString resolutionString = ui->comboBox->itemText(index);

    QStringList resolutionList = resolutionString.split("x", Qt::SkipEmptyParts);

    if (resolutionList.size() == 2) {
        // Convert the width and height to integers
        selectedWidth = resolutionList[0].trimmed().toInt();
        selectedHeight = resolutionList[1].trimmed().toInt();

        //emit resolutionChanged(selectedWidth, selectedHeight);
        setFixedSize(selectedWidth, selectedHeight);
        // Print the selected resolution to the console
        qDebug() << "Selected Resolution: " << selectedWidth << "x" << selectedHeight;
    }
    else {
        qDebug() << "Invalid resolution format!";
    }
}

void Setting::on_FullScreen_checkBox_stateChanged(int arg1)
{
    //emit fullScreenStateChanged(arg1 == Qt::Checked);

    if (arg1 == Qt::Checked)
    {
        // Set the window to fullscreen
        setWindowState(windowState() | Qt::WindowFullScreen);
        qDebug() << "Checked";
    }
    else
    {
        // Restore the window to its normal state
        setWindowState(windowState() & ~Qt::WindowFullScreen);
        qDebug() << "no Checked";
    }
}

void Setting::celsius_checkBox_stateChanged(int arg1)
{
    //emit CelsiusCheckBoxStateChanged(arg1 == Qt::Checked);
    qDebug() << "CelsiusCheckBoxStateChanged emitted with value: " << (arg1 == Qt::Checked);
}


void Setting::on_TimeFormat_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        //emit TimeFormatChanged(Qt::Checked);
        qDebug() << "Time Format: " << (arg1 == Qt::Checked);
    }
    else{
        //emit TimeFormatChanged(Qt::Unchecked);
        qDebug() << "Time Format: " << (arg1 == Qt::Unchecked);
    }

}

