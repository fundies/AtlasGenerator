#include "atlas.h"

#include <QDebug>
#include <QPainter>

const QSize textureSize(1024, 1024);

PositionInfo::PositionInfo(QString name, QRect rect)
{
	Name = name;
	Rect = rect;
}

Atlas::Atlas(QString name) : MyImage(name, QImage(textureSize, QImage::Format_ARGB32))
{
	fill(qRgba(0, 0, 0, 0));
}

bool Atlas::AddImage(MyImage image)
{
	QPoint pos;
	QRect p;
	bool success = true;

	if (mPoints.empty() && mRects.empty())
	{
		pos = QPoint(0,0);
		mPoints.append(QPoint(image.width()+1, 0));
		mPoints.append(QPoint(0, image.height()+1));
		p = QRect(pos, image.size());
	}
	else
	{
		for (auto point : mPoints)
		{
			p = QRect(point.rx(), point.ry(), image.width(), image.height());
			success = true;

			for (auto rect : mRects)
			{
				if (rect.intersects(p) || p.right() > textureSize.width() || p.bottom() > textureSize.height())
				{
					success = false;
					break;
				}
			}

			if (success)
			{
				pos = point;
				break;
			}
		}
	}

	if (success)
	{
		mRects.append(p);

		if (p.right()+1 < textureSize.width())
			mPoints.append(QPoint(p.right()+1, p.top()));

		if (p.left()+1 < textureSize.height())
			mPoints.append(QPoint(p.left(), p.bottom()+1));


		mInfo.append(PositionInfo(image.Name, p));

		QPainter painter(this);
		painter.drawImage(pos, image);
		painter.end();
	}

	for (auto rect : mRects)
	{
		QList<QPoint>::iterator it = mPoints.begin();

		while (it != mPoints.end())
		{
			if (rect.contains(*it, false))
				it = mPoints.erase(it);
			else
				++it;
		}
	}

	return success;
}

void Atlas::WriteData(QString fpath, QString ext)
{
	save(fpath + "/" + Name + ext);
}

void Atlas::PrintXML(QTextStream &out)
{
	out << "<Atlas fileName=\"" << Name << "\">\n";

	for (auto info : mInfo)
	{
		out << "	<image "
		    << "fileName=\"" << info.Name << "\""
		    << " x=" << info.Rect.left()
		    << " y=" << info.Rect.top()
		    << " width=" << info.Rect.width()
		    << " height=" << info.Rect.width()
		    << ">\n";
	}

	out << "</Atlas>\n";
}
