#include "main.h"
#include "angler.hpp"

//MOTORS
extern pros::Motor angler;

//CONTROLLERS
extern pros::Controller master;

//HELPER FUNCTIONS
void setAngler(int power) {
    angler = power;
}

//INTAKE CONTROL FUNCTIONS
void setAnglerMotors() {
    int anglerPower = 127 * (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) - master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
    setAngler(anglerPower);
}