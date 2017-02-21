#ifndef BASESTATUSBAR_H
#define BASESTATUSBAR_H

#include <QtWidgets/QStatusBar>

/**
* 自定义状态栏
*/

class BaseStatusBar : public QStatusBar
{
    Q_OBJECT
public:
    explicit BaseStatusBar(QWidget *parent = 0);

signals:

public slots:

};

#endif // BASESTATUSBAR_H
