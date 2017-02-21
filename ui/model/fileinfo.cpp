#include "fileinfo.h"

FileInfo::FileInfo(QObject *parent) :
    QObject(parent)
{
}

/**
* 获取文件标题
*/
QString FileInfo::getFileTitle()
{
    return this->fileTitle;
}

/**
* 设置文件标题
* @fileTitle 文件标题
*/
void FileInfo::setFileTitle(QString fileTitle)
{
    this->fileTitle = fileTitle;
}

/**
* 获取markdown文件名称
*/
QString FileInfo::getMarkdownFileName()
{
    return this->markdownFileName;
}

/**
* 设置markdown文件名称
* @fileName markdown文件名称
*/
void FileInfo::setMarkdownFileName(QString fileName)
{
    this->markdownFileName = fileName;
}

/**
* 获取html文件名称
*/
QString FileInfo::getHtmlFileName()
{
    return this->htmlFileName;
}

/**
* 设置html文件名称
* @fileName HTML文件名称
*/
void FileInfo::setHtmlFileName(QString fileName)
{
    this->htmlFileName = fileName;
}

/**
* 获取markdown全路径名称
*/
QString FileInfo::getMarkdownFileFullName()
{
    return this->markdownFileFullName;
}

/**
* 设置markdown全路径名称
* @fileFullName markdown全路径名称
*/
void FileInfo::setMarkdownFileFullName(QString fileFullName)
{
    this->markdownFileFullName = fileFullName;
}

/**
* 获取html全路径名称
*/
QString FileInfo::getHtmlFileFullName()
{
    return this->htmlFileFullName;
}

/**
* 设置html全路径名称
* @fileFullName HTML全路径名称
*/
void FileInfo::setHtmlFileFullName(QString fileFullName)
{
    this->htmlFileFullName = fileFullName;
}

/**
* 获取markdown文本
*/
QString FileInfo::getMarkdown()
{
    return this->markdown;
}

/**
* 设置markdown文本
* @markdown markdown内容
*/
void FileInfo::setMarkdown(QString markdown)
{
    this->markdown = markdown;
}

/**
* 获取htmlText文本
*/
QString FileInfo::getHtmlText()
{
    return this->htmlText;
}

/**
* 设置htmlText文本
* @htmlText HTML内容
*/
void FileInfo::setHtmlText(QString htmlText)
{
    this->htmlText = htmlText;
}

/**
* 获取保存状态
*/
bool FileInfo::isSaved()
{
    return this->bSaved;
}

/**
* 设置保存状态
* @bSaved 是否保存
*/
void FileInfo::setSaved(bool bSaved)
{
    this->bSaved = bSaved;
}

/**
* 获取设置标题状态
*/
bool FileInfo::isTitled()
{
    return this->bTitled;
}

/**
* 设置标题状体
* @bSaved 是否设置标题
*/
void FileInfo::setTitled(bool bTitle)
{
    this->bTitled = bTitle;
}

/**
* 获取html，不附带CSS
*/
QString FileInfo::getHtml()
{
    return html;
}

/**
* 设置HTML
*/
void FileInfo::setHtml(QString html)
{
    this->html = html;
}

/**
* 获取HTML模板
*/
QString FileInfo::getHtmlTemplete()
{
    // 如果HTML模板为空，则加载HTML模板
    if(htmlTemplate.isNull() || htmlTemplate.isEmpty())
    {
        QFile file(HTML_TEMPLATE_DEFAULT);

        // 打开文件失败
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return "";
        }

        // 读文件
        QTextStream in(&file);
        htmlTemplate = in.readAll();
        file.close();
    }

    return htmlTemplate;
}

/**
* 设置HTML模板
*/
void FileInfo::setHtmlTemplete(QString htmlTemplete)
{
    // 设置HTML模板
    this->htmlTemplate = htmlTemplete;
}
