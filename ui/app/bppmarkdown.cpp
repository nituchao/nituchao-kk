#include "bppmarkdown.h"

BppMarkDown::BppMarkDown(QWidget *parent) :
    BppMarkDownBase(parent)
{
}

/**
* MarkDown编辑器析构函数
*/
BppMarkDown::~BppMarkDown()
{
    initWindowStatus();
}

/**
* 隐藏事件
*/
void BppMarkDown::hideEvent(QHideEvent *)
{

}

void BppMarkDown::initWindowStatus()
{
    // 设置使用父组件背景
    this->setAutoFillBackground(true);

    // 设置背景透明
    this->setStyleSheet(APP_WINDOW_BACKGROUND_TRANSPARENT);

    // 设置不接受默认的拖拽
    this->setAcceptDrops(false);

    // 设置tab长度
    this->setTabStopWidth(APP_MARKDOWN_EDITOR_TAB_WIDTH);

    // 设置字体
    this->setFont(QFont("Songti SC,SimSun,serif"));
}

/**
* BppMarkDownBase构造函数
* @Qparent
*/
BppMarkDownBase::BppMarkDownBase(QWidget *parent) :
    QPlainTextEdit(parent),
    _border(new BppMarkDownBorder(this))
{
    // 设置markdown编辑器border边框对象名称
    _border->setObjectName(APP_MARKDOWN_BORDER);

    this->updateBorderWidth(0);
    this->hightLightCurrentLine();

    connect( this, &QPlainTextEdit::blockCountChanged, this, &BppMarkDownBase::updateBorderWidth);
    connect( this, &QPlainTextEdit::updateRequest, this, &BppMarkDownBase::updateBorder);
    connect( this, &QPlainTextEdit::cursorPositionChanged, this, &BppMarkDownBase::hightLightCurrentLine);
}

/**
* BppMarkDownBase析构函数
*/
BppMarkDownBase::~BppMarkDownBase()
{

}

/**
* 绘制MarkDown边框, 当BppMarkDownBorder被绘制时调用
* @event 事件
*/
void BppMarkDownBase::borderPaintEvent(QPaintEvent *event)
{
    QPainter painter(_border);

    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int)blockBoundingGeometry(block).translated(contentOffset()).top()+5;
    int bottom = top + (int)blockBoundingRect(block).height();

    while (block.isValid() && top <= event->rect().bottom())
    {
        if (block.isVisible() && bottom >= event->rect().top())
        {
            QString number = QString::number(blockNumber + 1);
            painter.drawText(0, top, _border->width(), fontMetrics().height(), Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}

/**
* 获取边框宽度
*/
int BppMarkDownBase::borderWidth() const
{
    int digits = 2;
    int max = qMax(1, blockCount());;
    while(max >= 10)
    {
        max /= 10;
        ++digits;
    }
    int space = fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

/**
* 更新边框宽度
* @newBlockCount 边框宽度
*/
void BppMarkDownBase::updateBorderWidth(int newBlockCount)
{
    Q_UNUSED(newBlockCount);

    setViewportMargins(borderWidth() + 3, 0, 0, 0);
}

/**
* 更新边框
* @r
* @dy
*/
void BppMarkDownBase::updateBorder(const QRect &r, int dy)
{
    if(dy)
    {
        _border->scroll(0, dy);
    }
    else
    {
        _border->update(0, r.y(), _border->width(), r.height());
    }

    if(r.contains(viewport()->rect()))
    {
        updateBorderWidth(0);
    }
}

/**
* 高亮当前行
*/
void BppMarkDownBase::hightLightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if(!isReadOnly())
    {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(240, 240, 255);
        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);

        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

/**
* 调整大小事件
* @event 事件
*/
void BppMarkDownBase::resizeEvent(QResizeEvent *event)
{
    QPlainTextEdit::resizeEvent(event);

    QRect cr = contentsRect();

    _border->setGeometry(QRect(cr.left(), cr.top(), this->borderWidth(), cr.height()));
}

/**
* BppMarkDownBorder构造函数
* @parent
*/
BppMarkDownBorder::BppMarkDownBorder(BppMarkDownBase *parent) :
    QWidget(parent),
    _base(parent)
{

}

/**
* BppMarkDownBorder析构函数
*/
BppMarkDownBorder::~BppMarkDownBorder()
{

}

/**
* 获取大小
*/
QSize BppMarkDownBorder::sizeHint() const
{
    return QSize(_base->borderWidth(), 0);
}

/**
* 绘图事件
* @event
*/
void BppMarkDownBorder::paintEvent(QPaintEvent *event)
{
    _base->borderPaintEvent(event);
}
