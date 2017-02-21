#ifndef TRANSNAMES_H
#define TRANSNAMES_H

/**
* dockBar组件显示名称定义
*/
#define APP_DOCK_BAR_TRANS_NAMES_TITLE_LABEL " - KK"
#define APP_DOCK_BAR_TRANS_NAMES_BLANK " "
#define APP_DOCK_BAR_TRANS_NAMES_TEXT_LABEL QObject::tr("undefine")

/**
* 设置菜单显示名称定义
*/
#define APP_SETUP_MENU_EDIT_POST QObject::tr("Editor View")
#define APP_SETUP_MENU_PRE_POST QObject::tr("Preview View")
#define APP_SETUP_MENU_DOUBLE_VIEW QObject::tr("Double View")
#define APP_SETUP_MENU_PUB_POST QObject::tr("Publish Post")
#define APP_SETUP_MENU_FIND QObject::tr("Find")
#define APP_SETUP_MENU_PRINT QObject::tr("Print")
#define APP_SETUP_MENU_OPEN QObject::tr("Open")
#define APP_SETUP_MENU_SAVE QObject::tr("Save")
#define APP_SETUP_MENU_SAVE_AS QObject::tr("Save As")
#define APP_SETUP_MENU_TO_HTML QObject::tr("Save To Html")
#define APP_SETUP_MENU_SYNC_POST QObject::tr("Sync To Cloud")
#define APP_SETUP_MENU_SET_ACCOUNT QObject::tr("Set Your Account")
#define APP_SETUP_MENU_SET_ACTION QObject::tr("Setting")
#define APP_SETUP_MENU_ABOUT QObject::tr("About")
#define APP_SETUP_MENU_FEED_BACK QObject::tr("Feed Back")
#define APP_SETUP_MENU_HELP QObject::tr("Help")
#define APP_SETUP_MENU_EXIT QObject::tr("Exit")

/**
* 快捷键定义
*/
#define APP_SHOT_CUT_EDIT_POST QObject::tr("Ctrl+Alt+E")
#define APP_SHOT_CUT_PREVIEW_VIEW QObject::tr("Ctrl+Alt+P")
#define APP_SHOT_CUT_DOUBLE_VIEW QObject::tr("Ctrl+Alt+D")
#define APP_SHOT_CUT_PUBLISH_POST QObject::tr("Ctrl+Alt+T")
#define APP_SHOT_CUT_FIND QObject::tr("Ctrl+F")
#define APP_SHOT_CUT_PRINT QObject::tr("Ctrl+P")
#define APP_SHOT_CUT_OPEN QObject::tr("Ctrl+O")
#define APP_SHOT_CUT_SAVE QObject::tr("Ctrl+S")
#define APP_SHOT_CUT_SAVE_TO_HTML QObject::tr("Ctrl+H")
#define APP_SHOT_CUT_EXIT QObject::tr("Ctrl+Alt+X")

/**
* 文件对话框显示名称定义
*/
#define FILE_OPERATE_SHOW_NOTE QObject::tr("Note")
#define FILE_OPERATE_CAN_NOT_OPEN_FILE QObject::tr("Can not open file")
#define FILE_OPERATE_CAN_NOT_CREATE_FILE QObject::tr("Can not create file")
#define FILE_OPERATE_SAVE_TO_MARKDOAN_TITLE QObject::tr("Save as markdown file")
#define FILE_OPERATE_SAVE_TO_HTML_TITLE QObject::tr("Save as html file")
#define FILE_OPERATE_SAVE_AS QObject::tr("Save as")
#define FILE_OPERATE_SAVE_TO_MARKDOWN_EXTEND QObject::tr("Markdown file(*.md *.markdown)")
#define FILE_OPERATE_SAVE_TO_HTML_EXTEND QObject::tr("Html file(*.htm *.html)")
#define FILE_OPERATE_SAVE_AS_EXTEND QObject::tr("All file(*.*)")
#define FILE_OPERATE_OPEN_FILE_TITLE QObject::tr("Open")
#define FILE_OPERATE_OPEN_FILE_EXTEND QObject::tr("Markdown file(*.md *.markdown)")
#define FILE_OPERATE_NOTE_SAVE_FILE QObject::tr("Do you want to save the current file ?")

/**
* 文件信息KEY值定义
*/
#define FILE_INFO_KEY_TEXT "Text"   // 文件内容
#define FILE_INFO_KEY_TITLE "Title" // 文件标题
#define FILE_INFO_KEY_FILE_NAME "FileName" // 文件名称
#define FILE_INFO_KEY_MARKDOWN_FILE_FULL_NAME "MarkdownFileFullName" // markdown文件全路径名称

/**
* 关于对话框内容
*/
#define DIALOG_ABOUT_TITLE_TEXT QObject::tr("About") // 关于对话框标题
#define DIALOG_ABOUT_HEAD_TEXT QObject::tr("KK v0.5.2") // 关于对话框正文标题
#define DIALOG_ABOUT_VERSION_INFO QObject::tr("windows<br>Is the latest version.")
#define DIALOG_ABOUT_VERSION_UPDATE_INFO QObject::tr("Please update to the latest version.")
#define DIALOG_ABOUT_CONTENT_TEXT QObject::tr("KK is a excellent markdown editor.<br>It is built with QT and other open source software.<br><br><br>Home Page : http://www.twokk.com<br>Copyright 2013-2014 KK Plc. All rights reserved.") // 关于对话框正文内容

/**
* 对话框内容
*/
#define DIALOG_COMMON_TEXT_OK QObject::tr("Ok")     // 对话框OK按钮
#define DIALOG_COMMON_TEXT_YES QObject::tr("Yes")   // 对话框Yes按钮
#define DIALOG_COMMON_TEXT_NO QObject::tr("No")     // 对话框No按钮
#define DIALOG_COMMON_TEXT_CANCEL QObject::tr("Cancel") // 对话框Cancel按钮

#endif // TRANSNAMES_H
