#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QLabel>
#include <QDialog>
#include <QPixmap>
#include <QFrame>
#include <QPushButton>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../include/buildnames.h"
#include "../include/transnames.h"
#include "../include/appparam.h"

class AboutDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AboutDialog(QWidget *parent = 0);

signals:

public slots:


private:
    QFrame* hLine;
    QLabel* titleLab;
    QLabel* iconLab;
    QLabel* headTextLab;
    QLabel* updateTextLab;
    QLabel* contentTextLab;
    QPushButton* okBtn;
    QToolButton* closeBtn;
    QVBoxLayout* mainLayout;
    QHBoxLayout* titleLayout;
    QHBoxLayout* bodyLayout;
    QVBoxLayout* iconLayout;
    QVBoxLayout* textLayout;
    QHBoxLayout* btnLayout;

private:
    void initWindowState();
    void initComponent();


};

#endif // ABOUTDIALOG_H
