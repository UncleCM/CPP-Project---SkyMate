#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

private slots:
    void Map_button();

    void Home_button();

    void Dashboard_button();

    void Search_button();

    void Setting_button();

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
