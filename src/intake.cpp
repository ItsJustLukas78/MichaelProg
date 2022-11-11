#include "main.h"
#include "intake.hpp"

//MOTORS
extern pros::Motor intakeLeft;
extern pros::Motor intakeRight;

//CONTROLLERS
extern pros::Controller master;

//HELPER FUNCTIONS
void setIntake(int power) {
    intakeLeft = power;
    intakeRight = power;
}

//INTAKE CONTROL FUNCTIONS
void setIntakeMotors() {
    //bottom trigger intakes, top trigger outtakes
    int intakePower = 127 * (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - master.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    setIntake(intakePower);
}