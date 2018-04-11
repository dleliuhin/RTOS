TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    global.cpp \
    os.cpp \
    resource.cpp \
    task.cpp \
    test.cpp \
    event.cpp

HEADERS += \
    defs.h \
    global.h \
    rtos_api.h \
    sys.h
