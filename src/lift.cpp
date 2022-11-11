#include "main.h"
#include "lift.hpp"

//MOTORS
extern pros::Motor lift;

//CONTROLLERS
extern pros::Controller master;

//HELPER FUNCTIONS
void setLift(int power) {
    lift = power;
}

//INTAKE CONTROL FUNCTIONS
void setLiftMotors() {
    int liftPower = 127 * (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - master.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    setLift(liftPower);
}