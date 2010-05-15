TEMPLATE = app
TARGET = WebOfTrust
QT += core \
    gui
HEADERS +=  exception.h \
	net.h \
	node.h \
	relation.h \
	relnet.h \
	settings.h \
	utils.h \
	weboftrust.h
SOURCES += exception.cpp \
	main.cpp \
	net.cpp \
	node.cpp \
	relation.cpp \
	relnet.cpp \
	settings.cpp \
	utils.cpp \
	weboftrust.cpp
FORMS += settings.ui \
    weboftrust.ui
RESOURCES += 
