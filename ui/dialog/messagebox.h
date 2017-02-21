#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QLabel>
#include <QDialog>
#include <QCheckBox>
#include <QToolButton>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../include/appparam.h"
#include "../include/transnames.h"
#include "../include/buildnames.h"

class MessageBox : public QDialog
{
    Q_OBJECT
public:
    explicit MessageBox(QWidget *parent = 0);
    MessageBox(QWidget *parent = 0, bool isYes = true, bool isNo = true, bool isCancel = true, bool isCheckBox = true, QString title = NULL, QString text = NULL, int msgType = 0, QString checkText = NULL);

private:
    QLabel* titleLab;
    QLabel* textLab;
    QLabel* iconLab;
    QLabel* checkLab;
    QCheckBox* checkBox;
    QToolButton* closeBtn;
    QPushButton* noBtn;
    QPushButton* yesBtn;
    QPushButton* cancelBtn;
    QVBoxLayout* mainLayout;
    QHBoxLayout* titleLayout;
    QHBoxLayout* bodyLayout;
    QHBoxLayout* iconLayout;
    QVBoxLayout* msgLayout;
    QHBoxLayout* textLayout;
    QHBoxLayout* checkLayout;
    QHBoxLayout* btnLayout;

signals:

public slots:
    void noOperate();
    void yesOperate();
    void cancelOperate();

private:
    void initWindowStatus();
    void initComponent(bool isYes, bool isNo, bool isCancel, bool isCheckBox, QString title, QString text, int msgType, QString checkText);
};

#endif // MESSAGEBOX_H
