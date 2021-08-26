QT += quick core gui quickwidgets qml quickcontrols2 widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CInterface/CI.cpp \
        CInterface/CUdpSocket.cpp \
        CInterface/CameraListModel.cpp \
        CInterface/cameramodel.cpp \
        CInterface/localsetting.cpp \
        OpenNetStream/opennetstream.cpp \
        main.cpp \
        util/json/json_reader.cpp \
        util/json/json_value.cpp \
        util/json/json_writer.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CInterface/CEnum.h \
    CInterface/CI.h \
    CInterface/CUdpSocket.h \
    CInterface/CameraListModel.h \
    CInterface/cameramodel.h \
    CInterface/localsetting.h \
    OpenNetStream/INS_ErrorCode.h \
    OpenNetStream/OpenNetStreamDefine.h \
    OpenNetStream/OpenNetStreamError.h \
    OpenNetStream/OpenNetStreamInterFace.h \
    OpenNetStream/backward/OpenNetStreamBackwardWarning.h \
    OpenNetStream/backward/OpenNetStreamInterfaceBackward.h \
    OpenNetStream/opennetstream.h \
    OpenNetStream/opennetstream_p.h \
    util/json/autolink.h \
    util/json/config.h \
    util/json/features.h \
    util/json/forwards.h \
    util/json/json.h \
    util/json/json_batchallocator.h \
    util/json/json_internalarray.inl \
    util/json/json_internalmap.inl \
    util/json/json_valueiterator.inl \
    util/json/reader.h \
    util/json/value.h \
    util/json/writer.h
