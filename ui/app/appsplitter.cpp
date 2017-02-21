#include "appsplitter.h"
#include "QDebug"

AppSplitter::AppSplitter(QWidget *parent) :
    QSplitter(parent)
{
    initWindowStatus();
    initComponet();
}

/**
* 初始化窗口状态
*/
void AppSplitter::initWindowStatus()
{
    // 设置鼠标跟踪
    this->setMouseTracking(true);

    // 设置继承父类背景
    this->setAutoFillBackground(true);

    // 设置允许拖拽
    this->setAcceptDrops(true);
}

/**
* 初始化窗口组件
*/
void AppSplitter::initComponet()
{
    markDown = new BppMarkDown();
    markDown->setObjectName(APP_SPLITTER_MARDOWN);

    browser = new QWebView();
    browser->setObjectName(APP_SPLITTER_BROWSER);

    this->addWidget(markDown);
    this->addWidget(browser);
    this->setHandleWidth(1);

    // 平分窗口
    QList<int> splitterSizes;
    splitterSizes.append(this->width() / 2);
    splitterSizes.append(this->width() / 2);
    this->setSizes(splitterSizes);

    // 禁止拖拽分隔条
    this->handle(1)->setDisabled(true);

    // 禁止编辑器拖拽
    markDown->setAcceptDrops(false);

    // 禁止浏览器拖拽
    browser->setAcceptDrops(false);

    // 建立信号槽连接
    connect(markDown, &BppMarkDown::textChanged, this, &AppSplitter::textChangedSlots);
}

/**
* 预览模式
*/
void AppSplitter::setPrevewMode()
{
    markDown->hide();
    browser->show();
}

/**
* 编辑模式
*/
void AppSplitter::setEditMode()
{
    markDown->show();
    browser->hide();
}

/**
* 双栏模式
*/
void AppSplitter::setDoubleMode()
{

    markDown->show();
    browser->show();

    // 平分窗口
    QList<int> splitterSizes;
    splitterSizes.append(this->width() / 2);
    splitterSizes.append(this->width() / 2);
    setSizes(splitterSizes);
}

/*******************************************拖拽实现***********************************************/
/**
* 拖动文件事件
*/
void AppSplitter::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/uri-list"))
    {
        event->acceptProposedAction();
    }
}

/**
* 放下文件事件
* @event 事件
*/
void AppSplitter::dropEvent(QDropEvent *event)
{
    // 加载拖拽文件
    QList<QUrl> urls = event->mimeData()->urls();

    if(urls.isEmpty())
    {
        return;
    }

    // 获取拖动文件中的第一个
    QString fileFullName = urls.first().toLocalFile();

   // 激发dropMarkdownSignal信号
    emit dropMarkdownSignal(fileFullName);
}

/*******************************************拖拽实现***********************************************/

/**
* 编辑器内容发生变化槽
*/
void AppSplitter::textChangedSlots()
{
    emit textChangedSignal();
}

/**
* 对外提供markdown文本
*/
QString AppSplitter::getMarkdown()
{
    return markDown->toPlainText();
}

/**
* 设置编辑器的markdown文本
* @text
*/
void AppSplitter::setMarkdown(QString text)
{
    markDown->setPlainText(text);
}

/**
* 设置浏览器html内容
* @html
*/
void AppSplitter::setBrowserHtml(QString html)
{
    browser->setHtml(html);
}
