#include "mylargeimage.h"

#include <QPainter>

MyLargeImage::MyLargeImage(MyImage img) : MyImage(img)
{
}

void MyLargeImage::Split()
{
	if (!isNull())
	{
		rows = (height() / 1024);
		cols = (width() / 1024);

		if (height() % 1024 != 0)
			rows++;

		if (width() % 1024 != 0)
			cols++;

		for (int i=0; i < rows; i++)
		{
			for (int j=0; j < cols; j++)
			{
				QImage part;
				part = QImage(QSize(1024,1024), QImage::Format_ARGB32);
				part.fill(qRgba(0, 0, 0, 0));

				QPainter painter(&part);
				painter.drawImage(QRect(QPoint(0,0), QSize(1024, 1024)), *this, QRect(QPoint(j * 1024, i * 1024), QSize(1024, 1024)));
				painter.end();

				ImageList.push_back(part);
			}
		}
	}
}

void MyLargeImage::WriteData(QString fpath, QString ext)
{
	int i = 0;
	int j = 0;

	for (auto img : ImageList)
	{
		img.save(fpath + "/" + Name + "[" + QString::number(i) +"]" + "[" + QString::number(j) + "]" + ext);

		if (i == cols-1)
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
}

void MyLargeImage::PrintXML(QTextStream &xmlFile)
{
	xmlFile << "<LargeImage "
	        << "fileName=\"" << Name << "\""
	        << " rows=" << rows
	        << " cols=" << cols
	        << ">\n";
}
