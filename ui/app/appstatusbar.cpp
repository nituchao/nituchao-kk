#include "appstatusbar.h"

AppStatusBar::AppStatusBar(QWidget *parent) :
    BaseStatusBar(parent)
{
    initWindowStatus();
}

/**
 *初始化窗口状态
 */
void AppStatusBar::initWindowStatus()
{
    this->setMaximumHeight(APP_STATUS_BAR_FIX_HEIGHT);

    this->setMouseTracking(true);

    this->setAutoFillBackground(true);

    this->setStyleSheet(APP_WINDOW_BACKGROUND_TRANSPARENT);
}
