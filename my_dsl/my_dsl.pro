#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T15:50:05
#
#-------------------------------------------------

QT       -= core gui

TARGET = ../lib/my_dsl
TEMPLATE = lib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXXFLAGS += -DACE_NTRACE=1
QMAKE_CXXFLAGS += -DYYDEBUG=1

QMAKE_FLEX = flex
QMAKE_YACC = bison

QMAKE_LEXFLAGS += -d #-Pdsl
QMAKE_YACCFLAGS += -t -d #-pdsl


HEADERS += my_dsl.h\
    grammar/my_defines.h \
    value.h \
    ast.h \
    expression.h \
    statement.h \
    result_type.h \
    interpretor.h \
    variable.h \
    function.h

SOURCES += my_dsl.cpp \
    value.cpp \
    ast.cpp \
    expression.cpp \
    statement.cpp \
    result_type.cpp \
    interpretor.cpp \
    variable.cpp \
    function.cpp

LEXSOURCES += \
    grammar/my_dsl.l

YACCSOURCES += \
    grammar/my_dsl.y

unix {
    target.path = /usr/lib
    INSTALLS += target
}

