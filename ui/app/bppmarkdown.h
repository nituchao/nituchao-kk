#ifndef BPPMARKDOWN_H
#define BPPMARKDOWN_H

#include <QPoint>
#include <QtWidgets/QWidget>
#include <QPainter>
#include <QtWidgets/QTextBrowser>
#include <QTextBlock>
#include <QtWidgets/QPlainTextEdit>
#include "../include/appparam.h"
#include "../include/buildnames.h"

class BppMarkDown;
class BppMarkDownBase;
class BppMarkDownBorder;

class BppMarkDownBase : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit BppMarkDownBase(QWidget *parent = 0);
    virtual ~BppMarkDownBase();

    void borderPaintEvent(QPaintEvent *);
    int borderWidth() const;

protected:
    void resizeEvent(QResizeEvent *);

private slots:
    void updateBorderWidth(int);
    void updateBorder(const QRect &, int);
    void hightLightCurrentLine();

private:
    BppMarkDownBorder* _border;

};

class BppMarkDownBorder : public QWidget
{
    Q_OBJECT
public:
    explicit BppMarkDownBorder(BppMarkDownBase* base);
    virtual ~BppMarkDownBorder();

    QSize sizeHint() const;

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    BppMarkDownBase* _base;
};

class BppMarkDown : public BppMarkDownBase
{
    Q_OBJECT
public:
    explicit BppMarkDown(QWidget *parent = 0);
    ~BppMarkDown();

protected:
    virtual void hideEvent(QHideEvent *);

signals:

public slots:

private:
    void initWindowStatus();

};

#endif // BPPMARKDOWN_H
