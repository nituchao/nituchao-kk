#include "appproxy.h"
#include <QDebug>

AppProxy::AppProxy(QObject *parent) :
    QObject(parent)
{

}

/**
* 重载的构造函数，用于从AppUi获取各个组件的指针
* @dockBar
* @splitter
* @statusBar
*/
AppProxy::AppProxy(AppDockBar* dockBar, AppSplitter* splitter, AppStatusBar* statusBar)
{
    this->dockBar = dockBar;
    this->splitter = splitter;
    this->statusBar = statusBar;
    memFileInfo = new FileInfo();
}

/**
* 预览模式
*/
void AppProxy::previewSlots()
{
    splitter->setPrevewMode();
}

/**
* 编辑模式
*/
void AppProxy::editViewSlots()
{
    splitter->setEditMode();
}

/**
* 双栏模式
*/
void AppProxy::doubleViewSlots()
{

    splitter->setDoubleMode();
}

/**
* 帮助
*/
void AppProxy::helpSlots()
{
    QMessageBox::information(NULL, APP_SETUP_MENU_HELP, "<H2>Help</h2><h3>QQ Group:348234568        </h3><br>", QMessageBox::Ok);
}

/**
* 关于对话框
*/
void AppProxy::aboutSlots()
{
    AboutDialog* aboutDialog = new AboutDialog();
    aboutDialog->exec();
}

/**
* 反馈
*/
void AppProxy::feedBackSlots()
{
    MessageBox* msg = new MessageBox(0, true, true, true, true, "Warn", "Do you want to save the file?", DIALOG_MSESSAGE_TYPE_FILE, "include css");
    qDebug() << "adfadfa";
    qDebug() << msg->exec();
}

/*******************************************槽函数*****************************************************/
/**
 * 打开文件
 */
void AppProxy::openFileSlots()
{
    // 如果文件全路径名为空，内容不为空，则提醒用户是否保存文件
    if(memFileInfo->getMarkdownFileFullName().isEmpty() && !memFileInfo->getMarkdown().isEmpty())
    {
        MessageBox* msg = new MessageBox(NULL, true, true, true, false, FILE_OPERATE_SHOW_NOTE, FILE_OPERATE_NOTE_SAVE_FILE, DIALOG_MSESSAGE_TYPE_FILE, NULL);
        int msgCode = msg->exec();

        // YES || CANCLE || CLOSE
        if(msgCode == DIALOG_MESSAGE_BOX_DONE_YES_WITHOUT_CHECK
                || msgCode == DIALOG_MESSAGE_BOX_DONE_CLOSE
                || msgCode == DIALOG_MESSAGE_BOX_DONE_CANCEL)
        {
            return;
        }
    }

    // 如果文件全路径名不为空，则先保存
    if(!memFileInfo->getMarkdownFileFullName().isEmpty())
    {
        writeFile(memFileInfo->getMarkdownFileFullName(), FILE_STATUS_TYPE_MARKDOWN);
    }

    // 文件名为空，则弹出打开对话框
    QString fileFullName = QFileDialog::getOpenFileName(NULL, FILE_OPERATE_OPEN_FILE_TITLE, "D:\\", FILE_OPERATE_OPEN_FILE_EXTEND, 0, QFileDialog::DontUseNativeDialog);
    if(!fileFullName.isEmpty() && readFile(fileFullName))
    {
        // 更新编辑器
        splitter->setMarkdown(memFileInfo->getMarkdown());

        // 更新预览
        splitter->setBrowserHtml(memFileInfo->getMarkdown());

        // 激发编辑器内容保存信号
        // emit textChangeSlots(memFileInfo->getFileTitle());

        // 补充，更新文件状态为保存
        memFileInfo->setSaved(true);
    }

}

/**
* 导出成HTML
*/
void AppProxy::saveHtmlSlots()
{
    // 弹出保存对话框
    QString fileFullName = QFileDialog::getSaveFileName(NULL, FILE_OPERATE_SAVE_TO_HTML_TITLE, ".", FILE_OPERATE_SAVE_TO_HTML_EXTEND, 0, QFileDialog::DontUseNativeDialog);

    // 保存HTML文件
    writeFile(fileFullName, FILE_STATUS_TYPE_HTML);
}

/**
* 另存为
*/
void AppProxy::saveAsSlots()
{
    QString fileFullName = QFileDialog::getSaveFileName(NULL, FILE_OPERATE_SAVE_AS, ".", FILE_OPERATE_SAVE_AS_EXTEND, 0, QFileDialog::DontUseNativeDialog);
    if(!fileFullName.isEmpty() && writeFile(fileFullName, FILE_STATUS_TYPE_OTHER))
    {
        // 如果另存为格式为.md或.markdown，则设置文件为已保存
        if(fileFullName.endsWith(FILE_STATUS_MARKDOWN_EXTENSION_MD) || fileFullName.endsWith(FILE_STATUS_MARKDOWN_EXTENSION_MARKDOWN))
        {
            dockBar->updateTitleText(memFileInfo->getFileTitle(), true);
        }
    }
}

/**
* 保存成markdown格式槽
*/
void AppProxy::saveMarkdownSlots()
{
    if(memFileInfo->getMarkdownFileFullName().isEmpty())
    {
        QString fileFullName = QFileDialog::getSaveFileName(NULL, FILE_OPERATE_SAVE_TO_MARKDOAN_TITLE, ".", FILE_OPERATE_SAVE_TO_MARKDOWN_EXTEND, 0, QFileDialog::DontUseNativeDialog);
        // 保存markdown文件
        if(!fileFullName.isEmpty() && writeFile(fileFullName, FILE_STATUS_TYPE_MARKDOWN))
        {
            // 更新标题栏为保存状态
            dockBar->updateTitleText(memFileInfo->getFileTitle(), true);
        }
    }
    else if(writeFile(memFileInfo->getMarkdownFileFullName(), FILE_STATUS_TYPE_MARKDOWN))
    {
        // 更新标题栏为保存状态
        dockBar->updateTitleText(memFileInfo->getFileTitle(), true);
    }
}

/**
* 编辑器内容发生变化槽
*/
void AppProxy::textChangeSlots()
{
    // 更新文件markdown内容
    memFileInfo->setMarkdown(splitter->getMarkdown());

    // 更新文件保存状态
    memFileInfo->setSaved(false);

    // 更新浏览器预览内容
    updateBrowserHtml();

    // 更新标题栏内容为未保存状态
    dockBar->updateTitleText(memFileInfo->getFileTitle(), false);
}

/**
* 退出程序
*/
void AppProxy::exitSlots()
{
    // 文件名不为空&&未保存，提醒是否保存，可直接保存
    if(!memFileInfo->getMarkdownFileFullName().isEmpty() && !memFileInfo->isSaved())
    {
        // 询问用户是否保存文件
        MessageBox* msg = new MessageBox(NULL, true, true, true, false, FILE_OPERATE_SHOW_NOTE, FILE_OPERATE_NOTE_SAVE_FILE, DIALOG_MSESSAGE_TYPE_FILE, NULL);
        int msgCode = msg->exec();

        // 用户要求保存文件
        if(msgCode == DIALOG_MESSAGE_BOX_DONE_YES_WITHOUT_CHECK)
        {
            writeFile(memFileInfo->getMarkdownFileFullName(), FILE_STATUS_TYPE_MARKDOWN);

            // 关闭窗口
            emit exitSignals(true);
        }
        else if(msgCode == DIALOG_MESSAGE_BOX_DONE_NO)
        {
            // 关闭窗口
            emit exitSignals(true);
        }
        else if(msgCode == DIALOG_MESSAGE_BOX_DONE_CANCEL)
        {
            // 取消关闭
            emit exitSignals(false);
        }

        return;
    }
    else if(!memFileInfo->getMarkdownFileFullName().isEmpty() && memFileInfo->isSaved())
    {
        emit exitSignals(true);

        return;
    }

    // 文件为空&&文件名为空，不需要保存
    if(memFileInfo->getMarkdown().isEmpty() && memFileInfo->getMarkdownFileFullName().isEmpty())
    {
        // 关闭窗口
        emit exitSignals(true);

        return;
    }

    // 文件不为空&&文件名为空，需要新建保存文件
    if(!memFileInfo->getMarkdown().isEmpty() && memFileInfo->getMarkdownFileFullName().isEmpty())
    {
        // 询问用户是否保存文件
        MessageBox* msg = new MessageBox(NULL, true, true, true, false, FILE_OPERATE_SHOW_NOTE, FILE_OPERATE_NOTE_SAVE_FILE, DIALOG_MSESSAGE_TYPE_FILE, NULL);
        int msgCode = msg->exec();

        // 保存文件
        if(msgCode == DIALOG_MESSAGE_BOX_DONE_YES_WITHOUT_CHECK)
        {
            // 弹出保存对话
            QString fileFullName = QFileDialog::getSaveFileName(NULL, FILE_OPERATE_SAVE_TO_MARKDOAN_TITLE, ".", FILE_OPERATE_SAVE_TO_MARKDOWN_EXTEND, 0, QFileDialog::DontUseNativeDialog);

            if(!fileFullName.isEmpty() && writeFile(fileFullName + FILE_STATUS_MARKDOWN_EXTENSION_MD, FILE_STATUS_TYPE_MARKDOWN))
            {
                // 关闭窗口
                emit exitSignals(true);
            }
            else
            {
                // 用户取消了保存文件，取消关闭窗口
                emit exitSignals(false);
            }
        }
        else if(msgCode == DIALOG_MESSAGE_BOX_DONE_NO)
        {
            // 不保存文件，关闭窗口
            emit exitSignals(true);
        }
        else if(msgCode == DIALOG_MESSAGE_BOX_DONE_CANCEL)
        {
            // 取消关闭
            emit exitSignals(false);
        }

        return;
    }
}

/**
* 放下markdown文件
* @fileFullName 放下的文件全路径
*/
void AppProxy::dropMarkdownSlots(QString fileFullName)
{
    // 如果文件名为空，直接返回
    if(NULL == fileFullName || fileFullName.isEmpty())
    {
        return;
    }

    // 文件名为空 || 文件内容不为空，询问是否保存文件
    if(memFileInfo->getMarkdownFileFullName().isEmpty() && !memFileInfo->getMarkdown().isEmpty())
    {
        MessageBox* msg = new MessageBox(NULL, true, true, true, false, FILE_OPERATE_SHOW_NOTE, FILE_OPERATE_NOTE_SAVE_FILE, DIALOG_MSESSAGE_TYPE_FILE, NULL);
        int msgCode = msg->exec();

        // YES || CANCEL || CLOSE
        if(msgCode == DIALOG_MESSAGE_BOX_DONE_YES_WITHOUT_CHECK
                || msgCode == DIALOG_MESSAGE_BOX_DONE_CANCEL
                || msgCode == DIALOG_MESSAGE_BOX_DONE_CLOSE)
        {
            return;
        }
    }

    // 保存已经存在的文件
    if(!memFileInfo->getMarkdownFileFullName().isEmpty())
    {
        writeFile(memFileInfo->getMarkdownFileFullName(), FILE_STATUS_TYPE_MARKDOWN);
    }

    // 读取文件内容
    if(readFile(fileFullName))
    {
        // 设置markdown编辑器内容
        splitter->setMarkdown(memFileInfo->getMarkdown());
    }
}

/*******************************************槽函数*****************************************************/

/**
* 读取文件
* @fileFullName 文件的全路径名称
*/
bool AppProxy::readFile(QString fileFullName)
{
    if(!fileFullName.isEmpty())
    {
        // 读取文件
        QFile file(fileFullName);

        // 打开文件失败
        if (!file.open(QIODevice::ReadOnly|QIODevice::WriteOnly|QIODevice::Text)) {
            QMessageBox::critical(NULL, FILE_OPERATE_SHOW_NOTE, FILE_OPERATE_CAN_NOT_CREATE_FILE);
            return false;
        }

        // 读文件
        QTextStream in(&file);
        QFileInfo info(fileFullName);
        QString text(in.readAll());

        // 更新文件信息
        memFileInfo->setFileTitle(info.filePath());
        memFileInfo->setMarkdown(text);
        memFileInfo->setHtmlText(script.markdownToHtml(text));
        memFileInfo->setMarkdownFileName(info.baseName());
        memFileInfo->setHtmlFileName("");
        memFileInfo->setMarkdownFileFullName(info.filePath());
        memFileInfo->setHtmlFileFullName("");
        memFileInfo->setSaved(true);
        memFileInfo->setTitled(true);

        file.close();

        return true;
    }

    return false;
}

/**
* 写文件
* @fileFullName 文件全路径名称
* @type 写文件类型，1:markdown,2:html
*/
bool AppProxy::writeFile(QString fileFullName, int type)
{
    if(!fileFullName.isEmpty()) {
        QFile file(fileFullName);

        // 打开文件失败
        if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {
            QMessageBox::critical(NULL, FILE_OPERATE_SHOW_NOTE, FILE_OPERATE_CAN_NOT_CREATE_FILE);
            return false;
        }

        // 写文件
        QTextStream out(&file);
        // 保存markdown
        if(type == FILE_STATUS_TYPE_MARKDOWN || type == FILE_STATUS_TYPE_OTHER)
        {
            // 如果文件不是以.md|.markdown，则追加结尾
            if(type == FILE_STATUS_TYPE_MARKDOWN && !fileFullName.endsWith(FILE_STATUS_MARKDOWN_EXTENSION_MD) && !fileFullName.endsWith(FILE_STATUS_MARKDOWN_EXTENSION_MARKDOWN))
            {
                fileFullName = fileFullName + FILE_STATUS_MARKDOWN_EXTENSION_MD;
            }

            QFileInfo info(fileFullName);
            // 更新文件标题
            memFileInfo->setFileTitle(info.filePath());
            // 更新文件名称
            memFileInfo->setMarkdownFileName(info.fileName());
            // 更新文件路径
            memFileInfo->setMarkdownFileFullName(info.filePath());
            // 更新文件状态
            memFileInfo->setSaved(true);
            // 更新文件标题状态
            memFileInfo->setTitled(true);

            // 写文件内容到输出流
            out << memFileInfo->getMarkdown();
        }
        // 保存html
        else if(type == FILE_STATUS_TYPE_HTML)
        {
            // 写文件内容到输出流
            out << memFileInfo->getHtml();
        }

        out.flush();
        file.close();

        return true;
    }

    return false;
}

/**
* 更新浏览器内容.ps:此处可以扩展，可以添加HTML模板和CSS样式
*/
void AppProxy::updateBrowserHtml()
{
    // 如果此时漏设置markdown内容了，则补设置
    if(memFileInfo->getMarkdown().isEmpty())
    {
        memFileInfo->setMarkdown(splitter->getMarkdown());
    }

    // 将 markdown编译成html
    QString html = script.markdownToHtml(memFileInfo->getMarkdown());

    // 更新内存中的html
    memFileInfo->setHtml(memFileInfo->getHtmlTemplete().arg(html));

    qDebug() << memFileInfo->getHtml();

    // 更新浏览器的html
    splitter->setBrowserHtml(memFileInfo->getHtml());
}
