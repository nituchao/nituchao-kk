#include "messagebox.h"

MessageBox::MessageBox(QWidget *parent) :
    QDialog(parent)
{
}

MessageBox::MessageBox(QWidget *parent, bool isYes, bool isNo, bool isCancel, bool isCheckBox, QString title, QString text, int msgType, QString checkText) :
    QDialog(parent)
{
    initWindowStatus();
    initComponent(isYes, isNo, isCancel, isCheckBox, title, text, msgType, checkText);
}

/**
* 初始化窗口状态
*/
void MessageBox::initWindowStatus()
{
    // 固定高度
    this->setFixedHeight(DIALOG_MESSAGE_BOX_FIX_HEIGHT);

    // 固定宽度
    this->setFixedWidth(DIALOG_MESSAGE_BOX_FIX_WIDTH);

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
* 初始化窗口组件
* @bool isYes
* @bool isNo
* @bool isCancel
* @QString title
* @QString text
* @int msgType
* @QString checkText
*/
void MessageBox::initComponent(bool isYes, bool isNo, bool isCancel, bool isCheckBox, QString title, QString text, int msgType, QString checkText)
{
    mainLayout = new QVBoxLayout();
    mainLayout->setObjectName(DIALOG_MESSAGE_NAME_MAIN_LAYOUT);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    titleLayout = new QHBoxLayout();
    titleLayout->setObjectName(DIALOG_MESSAGE_NAME_TITLE_LAYOUT);
    titleLayout->setMargin(DIALOG_COMMON_MARGIN_WIDTH);
    titleLayout->setSpacing(0);

    bodyLayout = new QHBoxLayout();
    bodyLayout->setObjectName(DIALOG_MESSAGE_NAME_BODY_LAYOUT);
    bodyLayout->setMargin(DIALOG_COMMON_MARGIN_WIDTH);
    bodyLayout->setSpacing(0);
    bodyLayout->setAlignment(Qt::AlignHCenter);

    iconLayout = new QHBoxLayout();
    iconLayout->setObjectName(DIALOG_MESSAGE_NAME_ICON_LAYOUT);
    iconLayout->setMargin(0);
    iconLayout->setSpacing(0);

    checkLayout = new QHBoxLayout();
    checkLayout->setObjectName(DIALOG_MESSAGE_NAME_CHECK_LAYOUT);
    checkLayout->setMargin(0);
    checkLayout->setSpacing(DIALOG_COMMON_SPECING_WIDTH);
    checkLayout->setAlignment(Qt::AlignBottom);

    textLayout = new QHBoxLayout();
    textLayout->setObjectName(DIALGO_MESSAGE_NAME_TEXT_LAYOUT);
    textLayout->setMargin(0);
    textLayout->setSpacing(DIALOG_COMMON_SPECING_WIDTH);
    textLayout->setAlignment(Qt::AlignLeft);
    textLayout->setAlignment(Qt::AlignTop);

    msgLayout = new QVBoxLayout();
    msgLayout->setObjectName(DIALOG_MESSAGE_NAME_MSG_LAYOUT);
    msgLayout->setMargin(0);
    msgLayout->setSpacing(0);
    msgLayout->setAlignment(Qt::AlignJustify);

    btnLayout = new QHBoxLayout();
    btnLayout->setObjectName(DIALOG_MESSAGE_NAME_BUTTON_LAYOUT);
    btnLayout->setMargin(DIALOG_COMMON_MARGIN_WIDTH);
    btnLayout->setSpacing(DIALOG_COMMON_SPECING_WIDTH);

    // 标题标签
    titleLab = new QLabel();
    titleLab->setObjectName(DIALOG_MESSAGE_NAME_TITLE_LABEL);
    titleLab->setText(title);

    // 正文标签
    textLab = new QLabel();
    textLab->setObjectName(DIALOG_MESSAGE_NAME_TEXT_LABEL);
    textLab->setText(text);

    // icon标签
    iconLab = new QLabel();
    iconLab->setObjectName(DIALOG_MESSAGE_NAME_ICON_LABEL);
    iconLab->setFixedHeight(APP_COMMON_SIZE_64);
    iconLab->setFixedWidth(APP_COMMON_SIZE_64);
    // 操作类型为文件
    if(msgType == DIALOG_MSESSAGE_TYPE_FILE)
    {
        iconLab->setPixmap(QPixmap(DIALOG_MESSAGE_BOX_PAGE_OPERATE_ICON));
    }

    // checkBox标签
    checkLab = new QLabel();
    checkLab->setObjectName(DIALOG_MESSAGE_NAME_CHECK_LABEL);
    if(!checkText.isNull() && !checkText.isEmpty())
    {
        checkLab->setText(checkText);
    }

    // checkBox
    checkBox = new QCheckBox();
    checkBox->setObjectName(DIALOG_MESSAGE_NAME_CHECK_BOX);
    checkBox->setChecked(false);

    // 关闭按钮
    closeBtn = new QToolButton();
    closeBtn->setObjectName(DIALOG_MESSAGE_NAME_TITLE_CLOSE_BUTTON);
    closeBtn->setIcon(QIcon(DIALOG_COMMON_TITLE_BAR_ICON_CLOSE_BUTTON));
    closeBtn->setFixedHeight(DIALOG_COMMON_TITLE_BAR_BUTTON_FIX_HEIGHT);
    closeBtn->setFixedWidth(DIALOG_COMMON_TITLE_BAR_BUTTON_FIX_WIDTH);

    // YES按钮
    yesBtn = new QPushButton();
    yesBtn->setObjectName(DIALOG_MESSAGE_NAME_YES_BUTTON);
    yesBtn->setText(DIALOG_COMMON_TEXT_YES);
    yesBtn->setFixedHeight(DIALOG_COMMON_BUTTON_FIX_HEIGHT);
    yesBtn->setFixedWidth(DIALOG_COMMON_BUTTON_FIX_WIDTH);

    // NO按钮
    noBtn = new QPushButton();
    noBtn->setObjectName(DIALOG_MESSAGE_NAME_NO_BUTTON);
    noBtn->setText(DIALOG_COMMON_TEXT_NO);
    noBtn->setFixedHeight(DIALOG_COMMON_BUTTON_FIX_HEIGHT);
    noBtn->setFixedWidth(DIALOG_COMMON_BUTTON_FIX_WIDTH);

    // CANCEL按钮
    cancelBtn = new QPushButton();
    cancelBtn->setObjectName(DIALOG_MESSAGE_NAME_CANCEL_BUTTON);
    cancelBtn->setText(DIALOG_COMMON_TEXT_CANCEL);
    cancelBtn->setFixedHeight(DIALOG_COMMON_BUTTON_FIX_HEIGHT);
    cancelBtn->setFixedWidth(DIALOG_COMMON_BUTTON_FIX_WIDTH);
    cancelBtn->setFocus();

    //控制YES按钮显示
    if(!isYes)
    {
        yesBtn->hide();
    }

    //控制NO按钮显示
    if(!isNo)
    {
        noBtn->hide();
    }

    // 控制Cancel按钮显示
    if(!isCancel)
    {
        cancelBtn->hide();
    }

    // 控制checkBox显示
    if(!isCheckBox)
    {
        checkBox->hide();
        checkLab->hide();
    }

    titleLayout->addWidget(titleLab);
    titleLayout->addStretch();
    titleLayout->addWidget(closeBtn);

    bodyLayout->addStretch();
    bodyLayout->addLayout(iconLayout);
    bodyLayout->addLayout(msgLayout);
    bodyLayout->addStretch();

    msgLayout->addLayout(textLayout);
    msgLayout->addLayout(checkLayout);

    iconLayout->addStretch();
    iconLayout->addWidget(iconLab);
    iconLayout->addStretch();
    textLayout->addStretch();
    textLayout->addWidget(textLab);
    textLayout->addStretch();

    checkLayout->addWidget(checkBox);
    checkLayout->addWidget(checkLab);
    checkLayout->addStretch();

    btnLayout->addStretch();
    btnLayout->addWidget(yesBtn);
    btnLayout->addWidget(noBtn);
    btnLayout->addWidget(cancelBtn);

    mainLayout->addLayout(titleLayout);
    mainLayout->addLayout(bodyLayout);
    mainLayout->addLayout(btnLayout);

    setLayout(mainLayout);

    // 建立连接
    connect(closeBtn, &QToolButton::clicked, this, &QDialog::close);
    connect(yesBtn, &QPushButton::clicked, this, &MessageBox::yesOperate);
    connect(noBtn, &QPushButton::clicked, this, &MessageBox::noOperate);
    connect(cancelBtn, &QPushButton::clicked, this, &MessageBox::cancelOperate);
}

/**
* no按钮操作
*/
void MessageBox::noOperate()
{
    // 用户选择了否
    this->done(DIALOG_MESSAGE_BOX_DONE_NO);
}

/**
* yes按钮操作
*/
void MessageBox::yesOperate()
{
    bool isHidden = checkBox->isHidden();

    // 单选框没有隐藏 && 被选中
    if(!isHidden && checkBox->isChecked())
    {
        this->done(DIALOG_MESSAGE_BOX_DONE_YES_WITH_CHECK);
    }

    // 单选框被隐藏 || 没有被选中
    if(isHidden || !checkBox->isChecked())
    {
        this->done(DIALOG_MESSAGE_BOX_DONE_YES_WITHOUT_CHECK);
    }
}

/**
* cancel按钮操作
*/
void MessageBox::cancelOperate()
{
    // 用户取消操作
    this->done(DIALOG_MESSAGE_BOX_DONE_CANCEL);
}
