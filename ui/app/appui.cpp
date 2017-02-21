#include "appui.h"
#include "QDebug"

QVBoxLayout* AppUi::layout;         // 主窗体布局
AppDockBar* AppUi::dockBar;         // 主窗体导航栏
AppSplitter* AppUi::splitter;       // 主窗体工作区
AppStatusBar* AppUi::statusBar;     // 主窗体状态栏

AppUi::AppUi(QWidget *parent) :
    QWidget(parent)
{
    // 初始化组件
    AppUi::initComponent();

    // 初始化窗口状态
    this->initWindowState();

    // 初始化样式(默认样式)
    this->setupStyleSheet(APP_WINDOW_DEFAULT_STYLE_SHEET);
}

/**
* 初始化组件，单例模式
*/
void AppUi::initComponent()
{
    if(NULL == layout)
    {
        layout = new QVBoxLayout();
        layout->setObjectName(APP_WINDOW_NAME_LAYOUT);
        layout->setMargin(1);
        layout->setSpacing(0);
    }

    if(NULL == dockBar)
    {
        dockBar = new AppDockBar();
        dockBar->setObjectName(APP_WINDOW_NAME_DOCK_BAR);
    }

    if(NULL == splitter)
    {
        splitter = new AppSplitter();
        splitter->setObjectName(APP_WINDOW_NAME_SPLITTER);
    }

    if(NULL == statusBar)
    {
        qDebug() << "ssssssssss";
        statusBar = new AppStatusBar();
        statusBar->setObjectName(APP_WINDOW_NAME_STATUS_BAR);
    }

    proxy = new AppProxy(dockBar, splitter, statusBar);

    // 添加导航栏
    this->layout->addWidget(dockBar);

    // 添加工作区
    this->layout->addWidget(splitter);

    // 添加状态栏
    this->layout->addWidget(statusBar);

    // 设置布局
    this->setLayout(layout);

    // 设置当前窗口对象名称
    this->setObjectName(APP_WINDOW_NAME_SELF_NAME);

    // 建立连接
    connect(dockBar->getMaximButton(), &QToolButton::clicked, this, &AppUi::showMaxRestore);
    connect(dockBar->getMinimButton(), &QToolButton::clicked, this, &AppUi::showMinimized);
    connect(dockBar->getCloseButton(), &QToolButton::clicked, proxy, &AppProxy::exitSlots);
    connect(dockBar->getSetupMenu(), &AppSetupMenu::openFileSignal, proxy, &AppProxy::openFileSlots);
    connect(dockBar->getSetupMenu(), &AppSetupMenu::saveHtmlSignal, proxy, &AppProxy::saveHtmlSlots);
    connect(dockBar->getSetupMenu(), &AppSetupMenu::saveAsSignal, proxy, &AppProxy::saveAsSlots);
    connect(dockBar->getSetupMenu(), &AppSetupMenu::saveMarkdownSignal, proxy, &AppProxy::saveMarkdownSlots);
    connect(dockBar->getSetupMenu(), &AppSetupMenu::previewSignal, proxy, &AppProxy::previewSlots);
    connect(dockBar->getSetupMenu(), &AppSetupMenu::editViewSignal, proxy, &AppProxy::editViewSlots);
    connect(dockBar->getSetupMenu(), &AppSetupMenu::doubleViewSignal, proxy, &AppProxy::doubleViewSlots);
    connect(dockBar->getSetupMenu(), &AppSetupMenu::helpSignal, proxy, &AppProxy::helpSlots);
    connect(dockBar->getSetupMenu(), &AppSetupMenu::aboutSignal, proxy, &AppProxy::aboutSlots);
    connect(dockBar->getSetupMenu(), &AppSetupMenu::feedBackSignal, proxy, &AppProxy::feedBackSlots);
    connect(dockBar->getSetupMenu(), &AppSetupMenu::exitSignal, proxy, &AppProxy::exitSlots);
    connect(splitter, &AppSplitter::textChangedSignal, proxy, &AppProxy::textChangeSlots);
    connect(splitter, &AppSplitter::dropMarkdownSignal, proxy, &AppProxy::dropMarkdownSlots);
    connect(this, &AppUi::exitSignals, proxy, &AppProxy::exitSlots);
    connect(proxy, &AppProxy::exitSignals, this, &AppUi::exitSlots);
}

/**
* 添加组件
*/
void AppUi::initWindowState()
{
    // 设置鼠标跟踪
    this->setMouseTracking(true);

    // 初始状态栏不可调整大小
    AppUi::statusBar->setSizeGripEnabled(false);

    // 设置无边框|任务栏系统菜单
    this->setWindowFlags( Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

    // 设置鼠标跟踪
    this->setMouseTracking(true);

    // 设置不继承父窗口背景
    this->setAutoFillBackground(true);

    // 初始化时为不允许关闭窗口
    this->allowClose = false;

    // 初始化为最大化窗口
    this->bIsMaxAble = true;

    // 最大化窗体
    this->setGeometry(qApp->desktop()->availableGeometry());

    // 左键状态
    bLeftPressed = false;

    // 是否正在移动
    bIsMoving = false;

    // 是否正在调整大小
    bIsResizing = false;

    // 调节大小的光标方向
    eDirection = enum_Direction(eNone);

    // 保存非最大化时窗体尺寸
    rRestoreWindow = QRect(APP_WINDOW_INIT_TOP_LEFT_X, APP_WINDOW_INIT_TOP_LEFT_Y, APP_WINDOW_INIT_WIDTH, APP_WINDOW_INIT_HEIGHT);
}

/**
* 初始化样式
* @stypeFile 样式文件
*/
void AppUi::setupStyleSheet(QString styleFile)
{
    QString qss;
    QFile qssFile(styleFile);
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
    }

    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(APP_DOCK_BAR_BACKGROUND_IMAGE)));
    this->setPalette(palette);
}



/**
* 获取导航栏dockBar单例对象
*/
AppDockBar* AppUi::getDockBar()
{
    // 如果此时没有初始化docBar，则先初始化
    if(NULL == dockBar)
    {
        dockBar = new AppDockBar();
    }

    return AppUi::dockBar;
}

/**
* 获取状态栏statusBar单例对象
*/
AppStatusBar* AppUi::getStatusBar()
{
    // 如果此时没有初始化statusBar，则先初始化
    if(NULL == statusBar)
    {
        statusBar = new AppStatusBar();
    }

    return AppUi::statusBar;
}

/**
* 获取工作区workSpace单例对象
*/
AppSplitter* AppUi::getSplitter()
{
    // 如果此时没有初始化workSpace，则先初始化
    if(NULL == splitter)
    {
        statusBar = new AppStatusBar();
    }

    return AppUi::splitter;
}

/*******************************************窗口事件定义****************************************************/
/**
* 鼠标双击事件
* @event 事件
*/
void AppUi::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton
            && event->y() <= APP_WINDOW_ZOOM_CLICK
            && event->y() > APP_WINDOW_ZOOM_PADDING)
    {
        showMaxRestore();
    }
}

/**
* 鼠标移动事件
* @event 事件
*/
void AppUi::mouseMoveEvent(QMouseEvent *event)
{
    if(!this->bIsMaxAble)
    {
        // 左键按下&&非最大化&&正在移动
        if(this->bLeftPressed && this->bIsMoving)
        {
            // 移动窗体
            this->move(this->pos() + event->globalPos() - this->pPressPoint);

            // 更新按下的点
            this->pPressPoint = event->globalPos();

            // 关闭调整大小，防止串扰
            this->bIsResizing = false;

            // 设置光标样式为普通
            setCursorStyle(enum_Direction(eNone));

            return;
        }

        // 左键没有按下 && 没有在调节大小
        if(!this->bLeftPressed && this->resizeValid(event->x(), event->y()))
        {
            // 设置光标样式
            setCursorStyle(this->eDirection);

            return;
        }

        // 左键按下&&正在调节大小&&没有超出限制，则调节大小
        if(this->bLeftPressed && this->bIsResizing)
        {
            setDrayMove(event->globalX(), event->globalY(), this->eDirection);
            this->pPressPoint = event->globalPos();

            return;
        }

        // 设置光标样式为普通
        setCursorStyle(enum_Direction(eNone));
    }
}

/**
* 鼠标按下事件
* @event 事件
*/
void AppUi::mousePressEvent(QMouseEvent *event)
{
    // 设置左键按下标志有效
    if(event->button() == Qt::LeftButton)
    {
        this->bLeftPressed = true;
    }

    // 如果当前窗口非最大化，则记录点击位置
    if(!this->bIsMaxAble && event->button() == Qt::LeftButton)
    {
        this->pPressPoint = event->globalPos();
    }

    // 设置正在移动标志
    if(event->x() > APP_WINDOW_ZOOM_PADDING
            && event->x() < this->width() - APP_WINDOW_ZOOM_PADDING
            && event->y() > APP_WINDOW_ZOOM_PADDING
            && event->y() < APP_WINDOW_ZOOM_CLICK)
    {
        this->bIsMoving = true;
    }

    // 设置光标方向
    if(this->resizeValid(event->x(), event->y()))
    {
        // 设置光标样式
        this->setCursorStyle(this->eDirection);

        // 设置正在调整大小
        this->bIsResizing = true;
    }
}

/**
* 鼠标释放事件
* @event 事件
*/
void AppUi::mouseReleaseEvent(QMouseEvent *event)
{
    // 设置左键释放标志
    if(event->button() == Qt::LeftButton)
    {
        // 左键按下标志释放
        this->bLeftPressed = false;

        // 正在移动标志置否
        this->bIsMoving = false;

        // 缩放方向标志置0
        this->eDirection = enum_Direction(eNone);

        this->setCursorStyle(this->eDirection);
    }
}

/**
* 设置光标样式
* @direction 方向枚举
*/
void AppUi::setCursorStyle(enum_Direction direction)
{
    //设置上下左右以及右上、右下、左上、坐下的鼠标形状
    switch(direction)
    {
        case eTop:
        case eBottom:
            setCursor(Qt::SizeVerCursor);
            break;
        case eRight:
            setCursor(Qt::SizeHorCursor);
            break;
        case eLeft:
            setCursor(Qt::SizeHorCursor);
            break;
        case eTopRight:
        case eBottomLeft:
            setCursor(Qt::SizeBDiagCursor);
            break;
        case eRightBottom:
        case eLeftTop:
            setCursor(Qt::SizeFDiagCursor);
            break;
        default:
            setCursor(Qt::ArrowCursor);
            break;
    }
}

/**
* 调节窗口大小
* @nXGlobale X全局坐标
* @nYGlobale Y全局坐标
* @direction 方向枚举
*/
void AppUi::setDrayMove(int nXGlobal, int nYGlobal, enum_Direction direction)
{
    //计算偏差
    int ndX = nXGlobal - this->pPressPoint.x();
    int ndY = nYGlobal - this->pPressPoint.y();

    //获得主窗口位置信息
    QRect rectWindow = geometry();

    //判别方向
    if(direction & eTop)
    {
        rectWindow.setTop(rectWindow.top()+ndY);
    }
    if(direction & eRight)
    {
        rectWindow.setRight(rectWindow.right()+ndX);
    }
    if(direction & eBottom)
    {
        rectWindow.setBottom(rectWindow.bottom()+ndY);
    }
    if(direction & eLeft)
    {
        rectWindow.setLeft(rectWindow.left()+ndX);
    }
    // 小于最小尺寸，或大于最大尺寸，直接返回
    if(rectWindow.width() < APP_WINDOW_INIT_WIDTH
            || rectWindow.height() < APP_WINDOW_INIT_HEIGHT
            || rectWindow.width() > qApp->desktop()->availableGeometry().width()
            || rectWindow.height() > qApp->desktop()->availableGeometry().height())
    {
        this->bIsResizing = false;
        this->setCursorStyle(enum_Direction(eNone));
        return;
    }

    // 重新设置窗口位置为新位置信息
    setGeometry(rectWindow);
}

/**
* 设置光标方向
* @xXRelative X方向相对坐标
* @nYRelative Y方向相对坐标
*/
enum_Direction AppUi::resizeValid(int nXRelative, int nYRelative)
{
    int nTop = qAbs(nYRelative) < APP_WINDOW_ZOOM_PADDING ? eTop:eNone;
    int nRight = qAbs(nXRelative-rect().right())< APP_WINDOW_ZOOM_PADDING + 2 ? eRight:eNone;
    int nBottom = qAbs(nYRelative-rect().bottom())< APP_WINDOW_ZOOM_PADDING + 2 ? eBottom:eNone;
    int nLeft = qAbs(nXRelative) < APP_WINDOW_ZOOM_PADDING + 2 ? eLeft:eNone;

    this->eDirection = enum_Direction(nTop + nRight + nBottom + nLeft);

    return this->eDirection;
}

/**
* 处理窗口最大化问题
*/
void AppUi::showMaxRestore()
{
    // 如果不是最大化状态，则最大化
    if(!this->bIsMaxAble)
    {
        // 保存窗口状态
        this->rRestoreWindow = this->geometry();

        // 最大化窗体
        this->setGeometry(qApp->desktop()->availableGeometry());

        // 设置最大化标志
        this->bIsMaxAble = true;

        // 更新最大化按钮图标
        this->dockBar->updateMaximButtonIcon(true);
    }
    // 如果是最大化状态，则恢复到之前的大小
    else
    {
        // 恢复窗体
        setGeometry(this->rRestoreWindow);

        // 设置最大化标志
        this->bIsMaxAble = false;

        // 更新最大化按钮图标
        this->dockBar->updateMaximButtonIcon(false);
    }
}

/**
* 窗口关闭事件
* 当窗口关闭时，发送关闭信号
*/
void AppUi::closeEvent(QCloseEvent* event)
{
    // 如果当前不允许关闭窗口，则忽略该事件
    emit exitSignals();
    event->ignore();
}

/*******************************************窗口事件定义****************************************************/

/**
* 关闭窗口槽函数
*/
void AppUi::exitSlots(bool exit)
{
    qDebug() << exit;
    if(exit)
    {
        qApp->exit(0);
    }
}
