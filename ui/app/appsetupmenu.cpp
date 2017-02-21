#include "appsetupmenu.h"
#include "QDebug"

AppSetupMenu::AppSetupMenu(QWidget *parent) :
    QMenu(parent)
{
    initSetMenu();
    initActions();
}

void AppSetupMenu::initSetMenu()
{
    setMinimumWidth(400);
    setMaximumWidth(400);
}

void AppSetupMenu::initActions()
{
    editPost = new QAction(APP_SETUP_MENU_EDIT_POST, this);
    editPost->setShortcut(APP_SHOT_CUT_EDIT_POST);
    prePost = new QAction(APP_SETUP_MENU_PRE_POST, this);
    prePost->setShortcut(APP_SHOT_CUT_PREVIEW_VIEW);
    doubleView = new QAction(APP_SETUP_MENU_DOUBLE_VIEW, this);
    doubleView->setShortcut(APP_SHOT_CUT_DOUBLE_VIEW);
    pubPost = new QAction(APP_SETUP_MENU_PUB_POST, this);
    pubPost->setShortcut(APP_SHOT_CUT_PUBLISH_POST);
    find = new QAction(APP_SETUP_MENU_FIND, this);
    find->setShortcut(APP_SHOT_CUT_FIND);
    print = new QAction(APP_SETUP_MENU_PRINT, this);
    print->setShortcut(APP_SHOT_CUT_PRINT);
    open = new QAction(APP_SETUP_MENU_OPEN, this);
    open->setShortcut(APP_SHOT_CUT_OPEN);
    save = new QAction(APP_SETUP_MENU_SAVE, this);
    save->setShortcut(APP_SHOT_CUT_SAVE);
    saveAs = new QAction(APP_SETUP_MENU_SAVE_AS, this);
    saveToHtml = new QAction(APP_SETUP_MENU_TO_HTML, this);
    saveToHtml->setShortcut(APP_SHOT_CUT_SAVE_TO_HTML);
    syncPost = new QAction(APP_SETUP_MENU_SYNC_POST, this);
    setAccount = new QAction(APP_SETUP_MENU_SET_ACCOUNT, this);
    setAction = new QAction(APP_SETUP_MENU_SET_ACTION, this);
    about = new QAction(APP_SETUP_MENU_ABOUT, this);
    feedBack = new QAction(APP_SETUP_MENU_FEED_BACK, this);
    help = new QAction(APP_SETUP_MENU_HELP, this);
    exit = new QAction(APP_SETUP_MENU_EXIT, this);
    exit->setShortcut(APP_SHOT_CUT_EXIT);

    addAction(doubleView);
    addAction(editPost);
    addAction(prePost);
    //addAction(pubPost);
    addSeparator();
    //addAction(find);
    //addAction(print);
    addAction(open);
    addAction(save);
    addAction(saveAs);
    addAction(saveToHtml);
    //addSeparator();
    //addAction(syncPost);
    //addAction(setAccount);
    addSeparator();
    addAction(about);
    addAction(feedBack);
    //addAction(help);
    addSeparator();
    addAction(exit);

    // 构建信号槽连接
    connect(prePost, &QAction::triggered, this, &AppSetupMenu::previewSlots);
    connect(editPost, &QAction::triggered, this, &AppSetupMenu::editViewSlots);
    connect(doubleView, &QAction::triggered, this, &AppSetupMenu::doubleViewSlots);
    connect(open, &QAction::triggered, this, &AppSetupMenu::openFileSlots);
    connect(save, &QAction::triggered, this, &AppSetupMenu::saveMarkdownSlots);
    connect(saveAs, &QAction::triggered, this, &AppSetupMenu::saveAsSlots);
    connect(saveToHtml, &QAction::triggered, this, &AppSetupMenu::saveHtmlSlots);
    connect(about, &QAction::triggered, this, &AppSetupMenu::aboutSlots);
    connect(feedBack, &QAction::triggered, this, &AppSetupMenu::feedBackSlots);
    connect(help, &QAction::triggered, this, &AppSetupMenu::helpSlots);
    connect(exit, &QAction::triggered, this, &AppSetupMenu::exitSlots);
}

/**
* 菜单显示事件
*/
void AppSetupMenu::showEvent(QShowEvent *)
{
    emit setupMenuShowSignal();
}

/**
* 打开文件
*/
void AppSetupMenu::openFileSlots()
{
    emit openFileSignal();
}

/**
* 保存成html格式
*/
void AppSetupMenu::saveHtmlSlots()
{
    emit saveHtmlSignal();
}

/**
* 另存为
*/
void AppSetupMenu::saveAsSlots()
{
    emit saveAsSignal();
}

/**
* 保存成markdown格式
*/
void AppSetupMenu::saveMarkdownSlots()
{
    emit saveMarkdownSignal();
}

/**
* 预览模式
*/
void AppSetupMenu::previewSlots()
{
    emit previewSignal();
}

/**
* 编辑模式
*/
void AppSetupMenu::editViewSlots()
{
    emit editViewSignal();
}

/**
* 双栏视图
*/
void AppSetupMenu::doubleViewSlots()
{
    emit doubleViewSignal();
}

/**
* 关于程序
*/
void AppSetupMenu::aboutSlots()
{
    emit aboutSignal();
}


/**
* 帮助
*/
void AppSetupMenu::helpSlots()
{
    emit helpSignal();
}

/**
* 反馈
*/
void AppSetupMenu::feedBackSlots()
{
    emit feedBackSignal();
}

/**
* 退出程序
*/
void AppSetupMenu::exitSlots()
{
    emit exitSignal();
}

