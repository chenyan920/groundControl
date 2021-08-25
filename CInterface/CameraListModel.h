#ifndef CAMERALISTMODEL_H
#define CAMERALISTMODEL_H

#include "cameramodel.h"

class CameraListModel : public CameraModel
{

public:
    CameraListModel();

    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
};

#endif // CAMERALISTMODEL_H
