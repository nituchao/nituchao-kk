#ifndef APPDOCKBAR_H
#define APPDOCKBAR_H

#include <QtWidgets/QLabel>
#include <QPixmap>
#include <QIcon>
#include <QtWidgets/QWidget>
#include <QString>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include "../app/appsetupmenu.h"
#include "../include/appparam.h"
#include "../include/transnames.h"
#include "../include/buildnames.h"

/**
* 系统导航栏，在窗口最顶部
*/

class AppDockBar : public QWidget
{
    Q_OBJECT
public:
    explicit AppDockBar(QWidget *parent = 0);
    virtual ~AppDockBar();
    AppSetupMenu* getSetupMenu();

    QToolButton* getCloseButton();
    QToolButton* getMaximButton();
    QToolButton* getMinimButton();
    void updateTitleText(QString, bool);
    void updateMaximButtonIcon(bool);

private:
    void initWindowComponent();
    void initWindowStatus();

private:
    QVBoxLayout* vLayout;
    QHBoxLayout* titleLayout;
    QHBoxLayout* toolsLayout;
    QToolButton* closeButton;
    QToolButton* maximButton;
    QToolButton* minimButton;
    QToolButton* setupButton;
    QLabel* logoLable;
    QLabel* textLabel;
    QLabel* titleLabel;
    AppSetupMenu* setupMenu;

signals:

public slots:
    void setTextContent(QString content);
    void setSetupMenuPos();

};

#endif // APPDOCKBAR_H
