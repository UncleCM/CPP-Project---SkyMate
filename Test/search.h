#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();


public slots:
    void currentWeatherDataReceived(const QJsonObject &jsonObject);

    void fiveDayWeatherDataReceived(const QJsonObject &forecastWeatherJsonObject);

    void updateUIFromApiResponse(const QJsonObject &jsonObject);

private slots:
    void Map_button();

    void Home_button();

    void Dashboard_button();

    void Search_button();

    void Setting_button();

private:
    Ui::Search *ui;
};



#endif // SEARCH_H
