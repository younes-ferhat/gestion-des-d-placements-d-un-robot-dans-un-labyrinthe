#ifndef OBSERVATEURROBOT_H
#define OBSERVATEURROBOT_H
#include <string>
#include "Robot.h"
class ObservateurRobot {
public:
    virtual ~ObservateurRobot() = default;
    virtual void notifier(const std::string& action, const Robot& robot) = 0;
};

#endif
