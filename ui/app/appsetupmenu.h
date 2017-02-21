#ifndef SETUPMENU_H
#define SETUPMENU_H

#include <QtWidgets/QMenu>
#include "../include/transnames.h"

class AppSetupMenu : public QMenu
{
    Q_OBJECT
public:
    explicit AppSetupMenu(QWidget *parent = 0);

    QAction* editPost;
    QAction* prePost;
    QAction* doubleView;
    QAction* pubPost;
    QAction* find;
    QAction* print;
    QAction* open;
    QAction* save;
    QAction* saveAs;
    QAction* saveToHtml;
    QAction* syncPost;
    QAction* setAccount;
    QAction* setAction;
    QAction* about;
    QAction* feedBack;
    QAction* help;
    QAction* exit;
    QAction* asciCodeAction;
    QMenu *codeMenu;


private:
    void initSetMenu();
    void initActions();
    void showEvent(QShowEvent *);
    
signals:
    void setupMenuShowSignal();
    void openFileSignal();
    void saveHtmlSignal();
    void saveMarkdownSignal();
    void saveAsSignal();
    void previewSignal();
    void editViewSignal();
    void doubleViewSignal();
    void helpSignal();
    void aboutSignal();
    void feedBackSignal();
    void exitSignal();

public slots:
    void openFileSlots();
    void saveAsSlots();
    void saveHtmlSlots();
    void saveMarkdownSlots();
    void previewSlots();
    void editViewSlots();
    void doubleViewSlots();
    void helpSlots();
    void aboutSlots();
    void feedBackSlots();
    void exitSlots();
};

#endif // SETUPMENU_H
