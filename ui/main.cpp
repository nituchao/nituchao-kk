#include "app/appui.h"
#include <QDebug>
#include <QTextCodec>
#include <QTranslator>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /**
    * 国际化支持
    */
    QTranslator translator;
    translator.load("lang_zh_CN.qm");
    a.installTranslator(&translator);

    AppUi ui;
    ui.show();

    return a.exec();
}
