#include <QCoreApplication>
#include <QElapsedTimer>
#include <QDebug>
#include <QCommandLineParser>

#include "atlasgenerator.h"


struct Arguments
{
	Arguments() {}
	Arguments(QString inputDir, QString inputExt, QString outputDir, QString outputExt) : inputDir(inputDir), inputExt(inputExt), outputDir(outputDir), outputExt(outputExt) {}

	QString inputDir;
	QString inputExt;
	QString outputDir;
	QString outputExt;
};

enum CommandLineParseResult
{
    CommandLineOk,
    CommandLineError,
    CommandLineVersionRequested,
    CommandLineHelpRequested
};

CommandLineParseResult parseCommandLine(QCommandLineParser &parser, Arguments *args, QString *errorMessage)
{
	parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
	const QCommandLineOption inputOption("i", "Directory holding images", "input");
	parser.addOption(inputOption);

	const QCommandLineOption outputOption("o", "Atlas output directoty", "output");
	parser.addOption(outputOption);
	parser.addPositionalArgument("name", "The name to look up.");

	const QCommandLineOption helpOption = parser.addHelpOption();
	const QCommandLineOption versionOption = parser.addVersionOption();

	if (!parser.parse(QCoreApplication::arguments()))
	{
		*errorMessage = parser.errorText();
		return CommandLineError;
	}

	if (parser.isSet(versionOption))
		return CommandLineVersionRequested;

	if (parser.isSet(helpOption))
		return CommandLineHelpRequested;

	if (parser.isSet(inputOption) && parser.isSet(outputOption))
	{
		args->inputDir = parser.value(inputOption);
		args->outputDir = parser.value(outputOption);
		args->inputExt = "*.png";
		args->outputExt = ".png";
	}


	return CommandLineOk;

}

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	QCoreApplication::setApplicationName("AtlasGen");
	QCoreApplication::setApplicationVersion("1.0");

	QCommandLineParser parser;

	parser.setApplicationDescription(QCoreApplication::translate("QDnsLookupExample", "An example demonstrating the class QDnsLookup."));
	Arguments args;
	QString errorMessage;

	switch (parseCommandLine(parser, &args, &errorMessage))
	{
	case CommandLineOk:
	{
		qDebug() << "Generating Atlases, Please wait..." << endl;
		AtlasGenerator generator(args.inputDir, args.inputExt, args.outputDir, args.outputExt);
		generator.GenerateAtlases();
		generator.SplitLargeImages();
		qDebug() << "Operation Complete" << endl;
		break;
	}

	case CommandLineError:
		fputs(qPrintable(errorMessage), stderr);
		fputs("\n\n", stderr);
		fputs(qPrintable(parser.helpText()), stderr);
		return 1;

	case CommandLineVersionRequested:
		printf("%s %s\n", qPrintable(QCoreApplication::applicationName()),
		       qPrintable(QCoreApplication::applicationVersion()));
		return 0;

	case CommandLineHelpRequested:
		parser.showHelp();
		Q_UNREACHABLE();
	}

	return 0;

}
