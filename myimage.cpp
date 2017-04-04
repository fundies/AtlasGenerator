#include "myimage.h"

MyImage::MyImage(QString name, QImage image) : QImage(image)
{
	Name = name;
}
