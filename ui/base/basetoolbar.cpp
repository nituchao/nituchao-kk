#include "basetoolbar.h"

BaseToolBar::BaseToolBar(QWidget *parent) :
    QToolBar(parent)
{
    this->init();
}

/**
* 初始化ToolBar
*/
void BaseToolBar::init()
{
    // 鼠标跟踪
    this->setMouseTracking(true);

    // 不可移动
    this->setMovable(false);
}
