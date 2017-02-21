#include "appscript.h"


AppScript::AppScript()
{
    markedContext = v8::Context::New();
    initEnvironment();
}

void AppScript::initEnvironment()
{
    QString markedJs = loadMarkedJs();
    v8::Context::Scope scope(markedContext);
    v8::Handle<v8::String> markedSource = v8::String::New(markedJs.toLatin1().data());
    v8::Handle<v8::Script> markedScript = v8::Script::Compile(markedSource);
    markedScript->Run();
}

QString AppScript::markdownToHtml(QString markdown)
{
    markdown = filterIllegalChar(markdown);
    v8::TryCatch tryCatch;
    v8::Context::Scope scope(markedContext);
    QString cmd = QString("marked(\"%1\");").arg(markdown);
    v8::Handle<v8::String> source = v8::String::New(cmd.toStdString().data());
    v8::Handle<v8::Script> script = v8::Script::Compile(source);
    v8::Handle<v8::Value> result = script->Run();
    v8::String::Utf8Value str(result);
    return QString(ToCString(str));
}

QString AppScript::htmlToMarkdown(QString html)
{
    return html;
}

const char* AppScript::ToCString(const v8::String::Utf8Value &value)
{
    return *value ? *value : "<string conversion failed>";
}

QString AppScript::filterIllegalChar(QString str)
{
    str.replace("\\", "\\\\");
    str.replace("\"", "\\\"");
    str.replace("\'", "\\\'");
    str.replace("\n", "\\n");
    return str;
}

QString AppScript::loadMarkedJs()
{
    QString js = NULL;
    QFile file( ":/script/marked" );
    if ( file.open(QIODevice::ReadOnly)) {
        QTextStream stream( &file );
        js = stream.readAll();
        file.close();
    }

    return js;
}

