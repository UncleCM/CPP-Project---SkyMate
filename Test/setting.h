#ifndef SETTING_H
#define SETTING_H

#include <QDialog>

namespace Ui {
class Setting;
}

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();

public slots:
   // void updateUIFromApiResponse(const QJsonObject &jsonObject);

    // void updateUIFromHourlyForecast(QJsonObject forecastWeatherJsonObject);

    // void updateUIFromFiveDayForecast(QJsonObject forecastWeatherJsonObject);

    // void updateUIFromUVIndex(QJsonObject UVindexJsonObject);

    // void updateLocationLabel(QString LocationText);

    // void updateWindspeedLabel(double windSpeed);

    // void updateHumidityLabel(double humidity);

private slots:
    void Map_button();

    void Home_button();

    void Dashboard_button();

    void Search_button();

    void Setting_button();

    // void on_comboBox_currentIndexChanged(int index);

    // void on_windspeed_value_linkActivated(const QString &link);

    // void on_location_label_linkActivated(const QString &link);

    // void on_humidity_value_linkActivated(const QString &link);


private:
    Ui::Setting *ui;
};

#endif // SETTING_H
