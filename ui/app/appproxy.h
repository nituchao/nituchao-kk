#ifndef APPPROXY_H
#define APPPROXY_H

#include <QObject>
#include <QFileDialog>
#include "../script/appscript.h"
#include "../model/fileinfo.h"
#include "appdockbar.h"
#include "appsplitter.h"
#include "appstatusbar.h"
#include "../include/appparam.h"
#include "../include/buildnames.h"
#include "../include/transnames.h"
#include "../dialog/aboutdialog.h"
#include "../dialog/messagebox.h"

class AppDockBar;
class AppSplitter;
class AppStatusBar;

/**
* 事件代理类AppProxy，用户代理处理UI事件
*/

class AppProxy : public QObject
{
    Q_OBJECT
public:
    explicit AppProxy(QObject *parent = 0);
    AppProxy(AppDockBar*, AppSplitter*, AppStatusBar*);

private:
    AppDockBar* dockBar;
    AppSplitter* splitter;
    AppStatusBar* statusBar;
    FileInfo* memFileInfo;
    AppScript script;

signals:
    void exitSignals(bool);     // 退出程序信号

public slots:
    void openFileSlots();       // 打开文件槽
    void saveHtmlSlots();       // 导出成HTML槽
    void saveAsSlots();         // 另存为槽
    void saveMarkdownSlots();   // 保存成markdown格式槽
    void textChangeSlots();     // 编辑器内容发生变化槽
    void previewSlots();        // 预览模式槽
    void editViewSlots();       // 编辑模式槽
    void doubleViewSlots();     // 双栏模式槽
    void helpSlots();           // 帮助模式槽
    void aboutSlots();          // 关于模式槽
    void feedBackSlots();       // 反馈槽
    void dropMarkdownSlots(QString);   // 放下markdown文件槽
    void exitSlots();           // 退出程序槽

private:
    QString readFile();
    bool readFile(QString);
    bool writeFile(QString, int);
    void updateBrowserHtml();   // 更新浏览器HTML内容

};

#endif // APPPROXY_H
