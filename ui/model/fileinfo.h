#ifndef FILEINFO_H
#define FILEINFO_H

#include <QFile>
#include <QObject>
#include <QTextStream>
#include "../include/appparam.h"

class FileInfo : public QObject
{
    Q_OBJECT
public:
    explicit FileInfo(QObject *parent = 0);
    QString getFileTitle();
    QString getMarkdownFileName();
    QString getHtmlTemplete();
    QString getHtmlFileName();
    QString getMarkdownFileFullName();
    QString getHtmlFileFullName();
    QString getMarkdown();
    QString getHtmlText();
    QString getHtml();
    bool isSaved();
    bool isTitled();
    void setFileTitle(QString);
    void setHtmlTemplete(QString);
    void setMarkdownFileName(QString);
    void setHtmlFileName(QString);
    void setMarkdownFileFullName(QString);
    void setHtmlFileFullName(QString);
    void setMarkdown(QString);
    void setHtmlText(QString);
    void setHtml(QString);
    void setFileStatus(int);
    void setSaved(bool);
    void setTitled(bool);

signals:

public slots:

private:
    QString fileTitle;
    QString markdownFileName;
    QString htmlFileName;
    QString markdownFileFullName;
    QString htmlFileFullName;
    QString markdown;
    QString html;
    QString htmlText;
    QString htmlTemplate;
    bool bSaved;
    bool bTitled;

private:
    bool loadHtmlTemplate();

};

#endif // FILEINFO_H
