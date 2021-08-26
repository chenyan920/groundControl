#include "CameraListModel.h"
#include <QtDebug>

CameraListModel::CameraListModel()
{}

QVariant CameraListModel::data(const QModelIndex &index, int role) const
{
        int row = index.row();
        if (row < 0 || row >= m_cameraList.count())
            return QVariant();
        Json::Value json = m_cameraList[row];
        int roleType = role;
        switch (roleType) {
        case DeviceSerialRole:
        case CameraNameRole:
        case IsSharedRole:
            return json[roleNames()[roleType].data()].asString().c_str();
        case CameraNoRole:
        case StatusRole:
        case IsEncryptRole:
        case VideoLevelRole:
            return json[roleNames()[roleType].data()].asInt();
        }

        return QVariant();
}

