#ifndef APPSCRIPT_H
#define APPSCRIPT_H

#include <QFile>
#include <QString>
#include <QTextStream>
#include "v8/v8.h"

class AppScript
{

public:
    AppScript();
    QString markdownToHtml(QString markdown);
    QString htmlToMarkdown(QString html);

private:
    v8::HandleScope handleScope;
    v8::Persistent<v8::Context> markedContext;
    void initEnvironment();
    const char* ToCString(const v8::String::Utf8Value& value);
    QString filterIllegalChar(QString);
    QString loadMarkedJs();
};

#endif // APPSCRIPT_H
