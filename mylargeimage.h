#ifndef MyLargeImage_HPP
#define MyLargeImage_HPP

#include "myimage.h"

#include <QVector>
#include <QImage>

class MyLargeImage : public MyImage
{
public:
	MyLargeImage(MyImage img);
	QVector<QImage> ImageList;
	void Split();
	void WriteData(QString fpath, QString ext);
	void PrintXML(QTextStream &xmlFile);

	int cols;
	int rows;
};

#endif
