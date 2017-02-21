#ifndef APPSTATUSBAR_H
#define APPSTATUSBAR_H

#include "../include/appparam.h"
#include "../base/basestatusbar.h"

/**
* 系统状态栏，在窗体最底部
*/

class AppStatusBar : public BaseStatusBar
{
    Q_OBJECT
public:
    explicit AppStatusBar(QWidget *parent = 0);

signals:

public slots:

private:
    void initWindowStatus();

};

#endif // APPSTATUSBAR_H
