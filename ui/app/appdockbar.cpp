#include "appdockbar.h"
#include "QDebug"

AppDockBar::AppDockBar(QWidget *parent) :
    QWidget(parent)
{
    initWindowComponent();
    initWindowStatus();
}

AppDockBar::~AppDockBar()
{

}

/**
* 初始化窗口状态参数
*/
void AppDockBar::initWindowStatus()
{
    // 设置导航栏的固定高度
    this->setFixedHeight(APP_DOCK_FIX_HEIGHT);

    // 设置鼠标跟踪
    this->setMouseTracking(true);

    // 继承父组件背景
    this->setAutoFillBackground(true);

    // 设置北京透明
    this->setStyleSheet(APP_WINDOW_BACKGROUND_TRANSPARENT);
}

/**
* 初始化窗口组件
*/
void AppDockBar::initWindowComponent()
{
    this->setObjectName(APP_DOCK_BAR_NAME_SELF_NAME);

    vLayout = new QVBoxLayout();
    titleLayout = new QHBoxLayout();
    toolsLayout = new QHBoxLayout();

    vLayout->setMargin(0);
    titleLayout->setMargin(5);
    toolsLayout->setMargin(5);

    vLayout->setSpacing(0);
    titleLayout->setSpacing(0);
    toolsLayout->setSpacing(0);

    vLayout->setObjectName(APP_DOCK_BAR_NAME_V_LAYOUT);
    titleLayout->setObjectName(APP_DOCK_BAR_NAME_TITLE_LAYOUT);
    toolsLayout->setObjectName(APP_DOCK_BAR_NAME_TOOLS_LAYOUT);

    closeButton = new QToolButton();
    closeButton->setObjectName(APP_DOCK_BAR_NAME_CLOSE_BUTTON);
    closeButton->setIcon(QIcon(APP_DOCK_BAR_CLOSE_BUTTON));

    maximButton = new QToolButton();
    maximButton->setObjectName(APP_DOCK_BAR_NAME_MAXIM_BUTTON);
    maximButton->setIcon(QIcon(APP_DOCK_BAR_MAXIM_BUTTON));


    minimButton = new QToolButton();
    minimButton->setObjectName(APP_DOCK_BAR_NAME_MINIM_BUTTON);
    minimButton->setIcon(QIcon(APP_DOCK_BAR_MINIM_BUTTON));

    setupButton = new QToolButton();
    setupButton->setObjectName(APP_DOCK_BAR_NAME_SETUP_BUTTON);
    setupButton->setPopupMode(QToolButton::InstantPopup);
    setupButton->setIcon(QIcon(APP_DOCK_BAR_SETUP_BUTTON));

    logoLable = new QLabel();
    logoLable->setPixmap(QPixmap(APP_DOCK_BAR_LOGO_LABEL));
    logoLable->setObjectName(APP_DOCK_BAR_NAME_LOGO_LABEL);

    textLabel = new QLabel();
    textLabel->setObjectName(APP_DOCK_BAR_NAME_TEXT_LABEL);
    textLabel->setText("*" + APP_DOCK_BAR_TRANS_NAMES_TEXT_LABEL + APP_DOCK_BAR_TRANS_NAMES_TITLE_LABEL);

    titleLabel = new QLabel();
    titleLabel->setObjectName(APP_DOCK_BAR_NAME_TITLE_LABEL);
    titleLabel->setText(APP_DOCK_BAR_TRANS_NAMES_BLANK);

    setupMenu = new AppSetupMenu();
    setupMenu->setObjectName(APP_DOCK_BAR_NAME_SETUP_MENU);
    setupButton->setMenu(setupMenu);

    titleLayout->addWidget(this->logoLable);
    titleLayout->addWidget(this->titleLabel);
    titleLayout->addWidget(this->textLabel);
    titleLayout->addStretch();
    titleLayout->addWidget(this->minimButton);
    titleLayout->addWidget(this->maximButton);
    titleLayout->addWidget(this->closeButton);

    toolsLayout->addStretch();
    toolsLayout->addWidget(this->setupButton);

    vLayout->addLayout(titleLayout);
    vLayout->addLayout(toolsLayout);
    setLayout(vLayout);

    // 设置连接
    connect(setupMenu, &AppSetupMenu::setupMenuShowSignal, this, &AppDockBar::setSetupMenuPos);
}

/**
* 设置文本内容
* @content 在标题栏上显示文件名
*/
void AppDockBar::setTextContent(QString fileName)
{
    this->textLabel->setText(fileName);
}

/**
* 获取关闭按钮
*/
QToolButton* AppDockBar::getCloseButton()
{
    return this->closeButton;
}

/**
* 获取最大化按钮
*/
QToolButton* AppDockBar::getMaximButton()
{
    return this->maximButton;
}

/**
* 获取最小化按钮
*/
QToolButton* AppDockBar::getMinimButton()
{
    return this->minimButton;
}

/**
* 设置设置菜单的位置
*/
void AppDockBar::setSetupMenuPos()
{
    QPoint pos = mapToGlobal(setupButton->pos());
    pos.setX(pos.x() + setupButton->width() - setupMenu->width());
    pos.setY(pos.y() + setupButton->height());
    setupMenu->popup(pos);
}

/**
* 获取设置菜单对象
*/
AppSetupMenu* AppDockBar::getSetupMenu()
{
    return setupMenu;
}

/**
* 更换最大化图标
* @maxim 是否最大化状态
*/
void AppDockBar::updateMaximButtonIcon(bool maxim)
{
    // 设置最大化图标
    if(maxim)
    {
        maximButton->setIcon(QIcon(APP_DOCK_BAR_NORMAL_BUTTON));
    }
    else // 设置向下还原图标
    {
        maximButton->setIcon(QIcon(APP_DOCK_BAR_MAXIM_BUTTON));
    }
}

/**
* 更新标题栏内容
* @titleText
* @是否保存
*/
void AppDockBar::updateTitleText(QString titleText, bool isSaved)
{
    if(titleText.isEmpty())
    {
        titleText = APP_DOCK_BAR_TRANS_NAMES_TEXT_LABEL;
    }

    if(isSaved)
    {
        // 保存状态
        this->textLabel->setText(titleText + APP_DOCK_BAR_TRANS_NAMES_TITLE_LABEL);
    }
    else
    {
        // 非保存状态
        this->textLabel->setText("*" + titleText + APP_DOCK_BAR_TRANS_NAMES_TITLE_LABEL);
    }
}
