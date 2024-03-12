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

signals:
    void fullScreenStateChanged(bool checked);

    void CelsiusCheckBoxStateChanged(bool checked);

    void resolutionChanged(int width, int height);

    void showMainWindow();

    // void TimeFormatChanged(bool checked);

    // void DistanceFormatChanged(bool checked);

public slots:

    void on_comboBox_currentIndexChanged(int index);

    void on_FullScreen_checkBox_stateChanged(int arg1);

    void celsius_checkBox_stateChanged(int argl);

private slots:

    void Home_button();

    void Dashboard_button();

    void Setting_button();

    void Exit_button();


    void on_TimeFormat_stateChanged(int arg1);

private:
    Ui::Setting *ui;
    int selectedWidth;
    int selectedHeight;
};

#endif // SETTING_H
