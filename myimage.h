#ifndef MyImage_HPP
#define MyImage_HPP

#include <QImage>
#include <QString>
#include <QTextStream>

class MyImage : public QImage
{
public:
	MyImage(QString name, QImage image);
	QString Name;
};

#endif
