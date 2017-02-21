#include "aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent)
{
    initWindowState();
    initComponent();
}

/**
* 初始化窗口组件
*/
void AboutDialog::initWindowState()
{
    // 固定高度
    this->setFixedHeight(DIALOG_ABOUT_FIX_HEIGHT);

    // 固定宽度
    this->setFixedWidth(DIALOG_ABOUT_FIX_WIDTH);

    // 设置无边框|任务栏系统菜单
    this->setWindowFlags( Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

    // 设置鼠标跟踪
    this->setMouseTracking(true);

    // 设置不继承父窗口背景
    this->setAutoFillBackground(true);

    // 设置窗口为有模式对话框
    this->setWindowModality(Qt::ApplicationModal);

}

/**
* 初始化窗口状态
*/
void AboutDialog::initComponent()
{
    mainLayout = new QVBoxLayout();
    mainLayout->setObjectName(DIALOG_ABOUT_NAME_MAIN_LAYOUT);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    titleLayout = new QHBoxLayout();
    titleLayout->setObjectName(DIALOG_ABOUT_NAME_TITLE_LAYOUT);
    titleLayout->setMargin(10);
    titleLayout->setSpacing(0);

    bodyLayout = new QHBoxLayout();
    bodyLayout->setObjectName(DIALOG_ABOUT_NAME_BODY_LAYOUT);
    bodyLayout->setMargin(10);
    bodyLayout->setSpacing(15);

    btnLayout = new QHBoxLayout();
    btnLayout->setObjectName(DIALOG_ABOUT_NAME_BUTTON_LAYOUT);
    btnLayout->setMargin(10);
    btnLayout->setSpacing(0);

    iconLayout = new QVBoxLayout();
    iconLayout->setObjectName(DIALOG_ABOUT_NAME_ICON_LABEL_LAYOUT);
    iconLayout->setMargin(0);
    iconLayout->setSpacing(0);

    textLayout= new QVBoxLayout();
    textLayout->setObjectName(DIALOG_ABOUT_NAME_TEXT_LABEL_LAYOUT);
    textLayout->setMargin(0);
    textLayout->setSpacing(0);

    // 对话框标题
    titleLab = new QLabel();
    titleLab->setObjectName(DIALOG_ABOUT_NAME_TITLE_LABEL);
    titleLab->setText(DIALOG_ABOUT_TITLE_TEXT);

    // 对话框图标
    iconLab = new QLabel();
    iconLab->setPixmap(QPixmap(DIALOG_ABOUT_ICON_LABEL_ICON));
    iconLab->setObjectName(DIALOG_ABOUT_NAME_ICON_LABEL);
    iconLab->setFixedWidth(DIALOG_ABOUT_ICON_LABEL_FIX_WIDTH);
    iconLab->setFixedHeight(DIALOG_ABOUT_ICON_LABEL_FIX_HEIGHT);

    // 对话框正文标题
    headTextLab = new QLabel();
    headTextLab->setObjectName(DIALOG_ABOUT_NAME_HEAD_TEXT_LABEL);
    headTextLab->setText(DIALOG_ABOUT_HEAD_TEXT);
    headTextLab->setFixedHeight(DIALOG_ABOUT_HEAD_TEXT_FIX_HEIGHT);

    // 对话框更新内容
    updateTextLab = new QLabel();
    updateTextLab->setObjectName(DIALOG_ABOUT_NAME_VERSION_INFO_LABEL);
    updateTextLab->setText(DIALOG_ABOUT_VERSION_INFO);
    updateTextLab->setFixedHeight(DIALOG_ABOUT_UPDATE_TEXT_FIX_HEIGHT);

    // 对话框正文
    contentTextLab = new QLabel();
    contentTextLab->setObjectName(DIALOG_ABOUT_NAME_CONTENT_TEXT_LABEL);
    contentTextLab->setText(DIALOG_ABOUT_CONTENT_TEXT);
    contentTextLab->setOpenExternalLinks(true);
    contentTextLab->setAlignment(Qt::AlignBottom);
    contentTextLab->setWordWrap(true);

    // 对话框OK按钮
    okBtn = new QPushButton();
    okBtn->setText(DIALOG_COMMON_TEXT_OK);
    okBtn->setObjectName(DIALOG_ABOUT_NAME_OK_BUTTON);
    okBtn->setFixedHeight(DIALOG_COMMON_BUTTON_FIX_HEIGHT);
    okBtn->setFixedWidth(DIALOG_COMMON_BUTTON_FIX_WIDTH);

    // 对话框关闭按钮
    closeBtn = new QToolButton();
    closeBtn->setIcon(QIcon(DIALOG_COMMON_TITLE_BAR_ICON_CLOSE_BUTTON));
    closeBtn->setObjectName(DIALOG_ABOUT_NAME_CLOSE_BUTTON);
    closeBtn->setFixedWidth(DIALOG_COMMON_TITLE_BAR_BUTTON_FIX_WIDTH);
    closeBtn->setFixedHeight(DIALOG_COMMON_TITLE_BAR_BUTTON_FIX_HEIGHT);

    // 横线
    hLine = new QFrame();
    hLine->setObjectName(DIALOG_ABOUT_NAME_HORIZONTAL_LINE);
    hLine->setFrameShadow(QFrame::Sunken);
    hLine->setFrameShape(QFrame::HLine);

    // 标题栏组件
    titleLayout->addWidget(titleLab);
    titleLayout->addStretch();
    titleLayout->addWidget(closeBtn);

    // 内容区组件
    textLayout->addWidget(headTextLab);
    textLayout->addWidget(updateTextLab);
    textLayout->addWidget(contentTextLab);
    iconLayout->addWidget(iconLab);
    bodyLayout->addLayout(iconLayout);
    bodyLayout->addLayout(textLayout);

    // 按钮区组件
    btnLayout->addStretch();
    btnLayout->addWidget(okBtn);

    // 添加布局
    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(bodyLayout);
    //mainLayout->addWidget(hLine);
    mainLayout->addLayout(btnLayout);

    this->setLayout(mainLayout);

    // 建立连接
    connect(okBtn, &QPushButton::clicked, this, &AboutDialog::close);
    connect(closeBtn, &QToolButton::clicked, this, &AboutDialog::close);
}
