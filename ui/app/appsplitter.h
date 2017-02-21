#ifndef APPSPLITTER_H
#define APPSPLITTER_H

#include <QUrl>
#include <QList>
#include <QFileInfo>
#include <QMimeData>
#include <QTextStream>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtWebKitWidgets/QWebView>
#include "../app/bppmarkdown.h"
#include "../model/fileinfo.h"
#include "../include/appparam.h"
#include "../include/buildnames.h"
#include "../include/transnames.h"
#include "../script/appscript.h"

class AppSplitter : public QSplitter
{
    Q_OBJECT
public:
    explicit AppSplitter(QWidget *parent = 0);

    void setMarkdown(QString);
    void setBrowserHtml(QString);
    void setPrevewMode();
    void setEditMode();
    void setDoubleMode();
    QString getMarkdown();

private:
    QWebView* browser;       // 预览窗口
    BppMarkDown* markDown;   // Markdown编辑器

signals:
    void textChangedSignal();           // 编辑器内容发生变化，参数为文件title
    void dropMarkdownSignal(QString);   // 放下markdown文件，参数为文件名

public slots:
    void textChangedSlots();

private:
    void initWindowStatus();
    void initComponet();

protected:
    void dragEnterEvent(QDragEnterEvent*);
    void dropEvent(QDropEvent*);

};

#endif // APPSPLITTER_H
