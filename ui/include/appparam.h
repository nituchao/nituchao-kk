#ifndef APPPARAM_H
#define APPPARAM_H

// 主窗体缩放枚举定义
enum enum_Direction
{
   eNone,
   eTop = 1,
   eRight =2 ,
   eBottom =4,
   eLeft = 8,
   eTopRight = eTop + eRight,
   eRightBottom = eRight + eBottom,
   eBottomLeft = eBottom + eLeft,
   eLeftTop = eLeft + eTop
};

// 公共尺寸定义
#define APP_COMMON_SIZE_16 16
#define APP_COMMON_SIZE_24 24
#define APP_COMMON_SIZE_32 32
#define APP_COMMON_SIZE_64 64
#define APP_COMMON_SIZE_128 128
#define APP_COMMON_SIZE_256 256


// 主窗体移动,拖动区域定义
#define APP_WINDOW_DRAG_TOP_HEIGHT 100
#define APP_WINDOW_ZOOM_PADDING 1
#define APP_WINDOW_ZOOM_CLICK 45
#define APP_WINDOW_INIT_TOP_LEFT_X 50
#define APP_WINDOW_INIT_TOP_LEFT_Y 50
#define APP_WINDOW_INIT_WIDTH 800
#define APP_WINDOW_INIT_HEIGHT 600
#define APP_WINDOW_RESIZE_NONE 0
#define APP_WINDOW_RESIZE_TOP 2
#define APP_WINDOW_RESIZE_RIGHT 3
#define APP_WINDOW_RESIZE_BOTTOM 6
#define APP_WINDOW_RESIZE_LEFT 7
#define APP_WINDOW_DEFAULT_STYLE_SHEET ":/qss/default"
#define APP_WINDOW_BACKGROUND_TRANSPARENT "background-color:transparent"

// 编辑器参数
#define APP_MARKDOWN_EDITOR_TAB_WIDTH 4

// 主窗体导航栏参数
#define APP_DOCK_FIX_HEIGHT 55
#define APP_DOCK_BAR_TITLE_BUTTON_SIZE 24
#define APP_DOCK_BAR_BACKGROUND_IMAGE ":/images/title_bg"
#define APP_DOCK_BAR_MINIM_BUTTON ":/images/mini"
#define APP_DOCK_BAR_MAXIM_BUTTON ":/images/max"
#define APP_DOCK_BAR_NORMAL_BUTTON ":/images/normal"
#define APP_DOCK_BAR_CLOSE_BUTTON ":/images/close"
#define APP_DOCK_BAR_SETUP_BUTTON ":/images/setup"
#define APP_DOCK_BAR_LOGO_LABEL ":/images/logo_m_t"

// 主窗体状态栏参数
#define APP_STATUS_BAR_FIX_HEIGHT 10

// 文件状态
#define FILE_STATUS_MARKDOWN_EXTENSION_MD ".md"
#define FILE_STATUS_MARKDOWN_EXTENSION_MARKDOWN ".markdown"
#define FILE_STATUS_MARKDOWN_EXTENSION_HTM ".htm"
#define FILE_STATUS_MARKDOWN_EXTENSION_HTML ".html"
#define FILE_STATUS_TYPE_MARKDOWN 1
#define FILE_STATUS_TYPE_HTML 2
#define FILE_STATUS_TYPE_OTHER 3

// HTML模板相关
#define HTML_TEMPLATE_DEFAULT ":/html/default"

// 对话框相关参数
#define DIALOG_COMMON_MARGIN_WIDTH 10                   // 对话框布局margin宽度
#define DIALOG_COMMON_SPECING_WIDTH 10                  // 对话框布局padding宽度
#define DIALOG_COMMON_TITLE_BAR_ICON_CLOSE_BUTTON ":/images/close_dialog" // 对话框关闭按钮图标
#define DIALOG_COMMON_TITLE_BAR_BUTTON_FIX_HEIGHT 14    // 对话框标题栏按钮固定高度
#define DIALOG_COMMON_TITLE_BAR_BUTTON_FIX_WIDTH 14     // 对话框标题栏按钮固定宽度
#define DIALOG_COMMON_BUTTON_FIX_HEIGHT 33              // 对话框按钮固定高度
#define DIALOG_COMMON_BUTTON_FIX_WIDTH 101              // 对话框按钮固定宽度
#define DIALOG_ABOUT_ICON_LABEL_FIX_HEIGHT 200          // 关于对话框图标固定高度
#define DIALOG_ABOUT_ICON_LABEL_FIX_WIDTH 200           // 关于对话框图标固定宽度
#define DIALOG_ABOUT_HEAD_TEXT_FIX_HEIGHT 25            // 关于对话框正文标题固定高度
#define DIALOG_ABOUT_UPDATE_TEXT_FIX_HEIGHT 40          // 关于对话框更新文本固定高度
#define DIALOG_ABOUT_ICON_LABEL_ICON ":/images/about_icon"     // 关于对话框图标标签图标
#define DIALOG_ABOUT_FIX_HEIGHT 313                     // 关于对话框固定高度
#define DIALOG_ABOUT_FIX_WIDTH 616                      // 关于对话框固定宽度
#define DIALOG_MESSAGE_BOX_FIX_HEIGHT 170               // 消息对话框固定高度
#define DIALOG_MESSAGE_BOX_FIX_WIDTH 400                // 消息对话框固定宽度
#define DIALOG_MESSAGE_BOX_DONE_CLOSE 0                 // 消息对话框按钮Close的返回值
#define DIALOG_MESSAGE_BOX_DONE_NO 2                    // 消息对话框按钮No的返回值
#define DIALOG_MESSAGE_BOX_DONE_YES_WITH_CHECK 3        // 消息对话框按钮Yes附带checkBox的返回值
#define DIALOG_MESSAGE_BOX_DONE_YES_WITHOUT_CHECK 4     // 消息对话框按钮Yes不带checkBox的返回值
#define DIALOG_MESSAGE_BOX_DONE_CANCEL 5                 // 消息对话框按钮Cancel的返回值
#define DIALOG_MSESSAGE_TYPE_FILE 1                     // 消息类型 1：文件
#define DIALOG_MESSAGE_BOX_PAGE_OPERATE_ICON ":/images/page_process" // 消息对话框文件操作提醒ICON


#endif // APPPARAM_H
