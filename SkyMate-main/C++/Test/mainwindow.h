#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

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
    void updateUIFromApiResponse(const QJsonObject &jsonObject);

    void updateWindspeedLabel(double windSpeed);

private slots:
    void Map_button();

    void Home_button();

    void Dashboard_button();

    void Search_button();

    void Setting_button();

    void on_windspeed_value_linkActivated(const QString &link);

    void on_comboBox_currentIndexChanged(int index);

    void on_uvindex_value_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
    QStringList city_names;
    QNetworkReply* makeApiRequest(const QString &link);
    // void updateUIFromApiResponse(QNetworkReply* reply);

};
#endif // MAINWINDOW_H
