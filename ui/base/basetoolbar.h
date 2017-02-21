#ifndef BASETOOLBAR_H
#define BASETOOLBAR_H

#include <QtWidgets/QToolBar>

/**
* 自定义工具栏基类
*/
class BaseToolBar : public QToolBar
{
    Q_OBJECT
public:
    explicit BaseToolBar(QWidget *parent = 0);

signals:

public slots:

protected:
    void init();

};

#endif // BASETOOLBAR_H
