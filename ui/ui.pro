#-------------------------------------------------
#
# Project created by QtCreator 2013-12-11T21:55:16
#
#-------------------------------------------------
TEMPLATE = app

TARGET = markplus

QT       += core widgets webkitwidgets

DEFINES += UI_LIBRARY

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

INCLUDEPATH += ../include \
                ../include/v8

OTHER_FILES +=

RESOURCES += \
    res.qrc

HEADERS += \
    ui_global.h \
    app/appdockbar.h \
    app/appsetupmenu.h \
    app/appsplitter.h \
    app/appstatusbar.h \
    app/appui.h \
    app/bppmarkdown.h \
    base/basestatusbar.h \
    base/basetoolbar.h \
    model/fileinfo.h \
    include/appparam.h \
    include/buildnames.h \
    include/transnames.h \
    app/ui_global.h \
    script/appscript.h \
    app/appproxy.h \
    dialog/aboutdialog.h \
    dialog/messagebox.h

SOURCES += \
    app/appdockbar.cpp \
    app/appsetupmenu.cpp \
    app/appsplitter.cpp \
    app/appstatusbar.cpp \
    app/appui.cpp \
    app/bppmarkdown.cpp \
    base/basestatusbar.cpp \
    base/basetoolbar.cpp \
    model/fileinfo.cpp \
    script/appscript.cpp \
    main.cpp \
    app/appproxy.cpp \
    dialog/aboutdialog.cpp \
    dialog/messagebox.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/v8/release/ -lv8_base.ia32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/v8/debug/ -lv8_base.ia32
else:unix: LIBS += -L$$PWD/../lib/v8/ -lv8_base.ia32

INCLUDEPATH += $$PWD/../lib/v8/release
DEPENDPATH += $$PWD/../lib/v8/release

TRANSLATIONS = lang_zh_CN.ts

RC_ICONS = logo-m.ico
