QMAKE_CXXFLAGS += -Werror -std=c++11 -z defs
QMAKE_LFLAGS += -std=c++11

QT += network serialbus

TARGET = nymea-sunspec1
TEMPLATE = lib

SOURCES += \
    sunspec.cpp \
    sunspecdevice.cpp \
    sunspecinverter.cpp \
    sunspecmeter.cpp \
    sunspecstorage.cpp

HEADERS += \
    sunspec.h \
    sunspecdevice.h \
    sunspecinverter.h \
    sunspecmeter.h \
    sunspecstorage.h

# define install target
target.path = $$[QT_INSTALL_LIBS]
INSTALLS += target

# install header file with relative subdirectory
for (header, HEADERS) {
    path = $$[QT_INSTALL_PREFIX]/include/nymea-sunspec/$${dirname(header)}
    eval(headers_$${path}.files += $${header})
    eval(headers_$${path}.path = $${path})
    eval(INSTALLS *= headers_$${path})
}

# Create pkgconfig file
CONFIG += create_pc create_prl no_install_prl
QMAKE_PKGCONFIG_NAME = libnymea-sunspec
QMAKE_PKGCONFIG_DESCRIPTION = nymea-sunspec development library
QMAKE_PKGCONFIG_PREFIX = $$[QT_INSTALL_PREFIX]
QMAKE_PKGCONFIG_INCDIR = $$[QT_INSTALL_PREFIX]/include/nymea-sunspec/
QMAKE_PKGCONFIG_LIBDIR = $$target.path
QMAKE_PKGCONFIG_VERSION = 1.0.0
QMAKE_PKGCONFIG_FILE = nymea-sunspec
QMAKE_PKGCONFIG_DESTDIR = pkgconfig
