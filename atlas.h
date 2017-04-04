#ifndef Atlas_HPP
#define Atlas_HPP

#include "myimage.h"

class PositionInfo
{
public:
	PositionInfo(QString name, QRect rect);
	QString Name;
	QRect Rect;
};

class Atlas : MyImage
{
public:
	Atlas(QString name);
	bool AddImage(MyImage image);
	void WriteData(QString fpath, QString ext);
	void PrintXML(QTextStream &xmlFile);

private:
	QList<QPoint> mPoints;
	QList<QRect> mRects;
	QList<PositionInfo> mInfo;
};

#endif
