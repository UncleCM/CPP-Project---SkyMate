// weathericon.h
#ifndef WEATHERICON_H
#define WEATHERICON_H

#include <QPixmap>

class WeatherIcon {
public:
    explicit WeatherIcon(const QString& filePath);

    QPixmap getPixmap() const;

private:
    QPixmap pixmap;
};

#endif // WEATHERICON_H
