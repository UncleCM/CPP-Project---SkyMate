#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include "setting.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:

    void handleFullScreenState(bool checked);

    void handleTempCheckBox(bool checked);

    void handleResolutionChange(int width, int height);

    void ShowDashBoard();

    // void handleTimeFormat(bool checked);

    // void handleDistanceFormat(bool checked);

    // void updateDistanceFormat(bool useKilometers);

    // void updateTimeFormat(const QString& timeFormat);

    ///////////////////////////////////////////////////////////

    void updateUIFromApiResponse(const QJsonObject &jsonObject);

    void updateUIFromHourlyForecast(QJsonObject forecastWeatherJsonObject);

    void updateUIFromFiveDayForecast(QJsonObject forecastWeatherJsonObject);

    void updateUIAirQuality(QJsonObject AirQalityJsonObject);

    double celsiusToFahrenheit(double celsius);

private slots:

    void Home_button();

    void Dashboard_button();

    void Setting_button();

    void on_comboBox_currentIndexChanged(int index);

    void Exit_button();

private:
    Ui::MainWindow *ui;
    QSize newSize;
    QStringList city_names;
    QNetworkReply* makeApiRequest(const QString &link);
    Setting* setting;
    bool useFahrenheit;
    QJsonObject currentWeatherData;

    QDateTime sunriseDateTime;
    QDateTime sunsetDateTime;
    double visibility;
};
#endif // MAINWINDOW_H
