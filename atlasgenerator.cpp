#include <QPainter>
#include <QDebug>
#include <QDir>
#include <QFile>

#include "atlasgenerator.h"

AtlasGenerator::AtlasGenerator(QString inputDir, QString inputExt, QString outputDir, QString outputExt) :
	mOutputDir(outputDir), mOutputExt(outputExt), xmlFile(outputDir + "/AtlasInfo.xml")
{
	if (xmlFile.open(QFile::WriteOnly | QFile::Truncate))
		xmlStream = new QTextStream(&xmlFile);

	LoadImagesInDir(inputDir, inputExt);
	mAtlas.append(Atlas("0"));
}

void AtlasGenerator::LoadImagesInDir(QString path, QString ext)
{
	QDir dir(path);
	QStringList files = dir.entryList(QStringList(ext), QDir::Files | QDir::NoSymLinks);

	for (auto f : files)
	{
		QImage img(path + f);

		QString name = f.split(".",QString::SkipEmptyParts).at(0);

		if (img.width() > 1024 || img.height() > 1024)
			mLargeImages.push_back(MyImage(name, img));
		else
			mImages.push_back(MyImage(name, img));
	}
}

void AtlasGenerator::GenerateAtlases()
{
	*xmlStream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";

	int atlasNum = 0;

	for (auto image : mImages)
	{
		if (!image.isNull())
		{
			while(!mAtlas[atlasNum].AddImage(image))
			{
				atlasNum += 1;

				if (atlasNum >= mAtlas.size())
					mAtlas.append(Atlas(QString::number(mAtlas.size())));
			}

			atlasNum = 0;
		}
	}

	for (auto atlas : mAtlas)
	{
		atlas.WriteData(mOutputDir, mOutputExt);
		atlas.PrintXML(*xmlStream);
	}
}

void AtlasGenerator::SplitLargeImages()
{
	for (auto image : mLargeImages)
	{
		image.Split();
		image.WriteData(mOutputDir, mOutputExt);
		image.PrintXML(*xmlStream);
	}
}
