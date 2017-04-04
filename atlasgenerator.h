#ifndef AtlasGenerator_HPP
#define AtlasGenerator_HPP

#include "mylargeimage.h"
#include "atlas.h"

#include <QFile>

class AtlasGenerator
{
public:
	AtlasGenerator(QString inputDir, QString inputExt, QString outputDir, QString outputExt);
	void LoadImagesInDir(QString path, QString ext);
	void GenerateAtlases();
	void SplitLargeImages();

private:
	QString mOutputDir;
	QString mOutputExt;

	QList<Atlas> mAtlas;
	QList<MyImage> mImages;
	QList<MyLargeImage> mLargeImages;

	QFile xmlFile;
	QTextStream* xmlStream;
};

#endif
