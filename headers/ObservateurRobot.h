#ifndef OBSERVATEURROBOT_H
#define OBSERVATEURROBOT_H

#include "Point.h"
#include <string>

class ObservateurRobot {
public:
    virtual ~ObservateurRobot() = default;
    virtual void notifier(const std::string& action, const Robot& robot) = 0;
};

#endif
