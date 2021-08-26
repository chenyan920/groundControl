#ifndef CENUM_H
#define CENUM_H

#include <QObject>

class CEnum: public QObject {
    Q_OBJECT

    Q_ENUMS(PTZCtrl)

public:
    CEnum() = default;

    enum PTZCtrl{
        DIRECTUP,
        DIRECTDOWN,
        DIRECTLEFT,
        DIRECTRIGHT,
        DIRECTUNKNWN = 1000,
    };
};

#endif // CENUM_H
