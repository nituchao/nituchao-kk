TEMPLATE = app

TARGET = markplus

QT += core widgets webkitwidgets

SOURCES += ./main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ui/release/ -lui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ui/debug/ -lui
else:unix: LIBS += -L$$OUT_PWD/../ui/ -lui

INCLUDEPATH += $$PWD/../ui
DEPENDPATH += $$PWD/../ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/v8/release/ -lv8_base.ia32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/v8/debug/ -lv8_base.ia32
else:unix: LIBS += -L$$PWD/../lib/v8/ -lv8_base.ia32

INCLUDEPATH += $$PWD/../lib/v8/release \
            += $$PWD/../lib/v8/debug
DEPENDPATH += $$PWD/../lib/v8/release \
            $$PWD/../lib/v8/debug

RC_ICONS = ui.ico

OTHER_FILES +=

RESOURCES += \
    res.qrc
