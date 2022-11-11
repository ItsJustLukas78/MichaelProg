#include "main.h"
#include "auto.hpp"
#include "drive.hpp"

//SENSORS
extern pros::ADIGyro gyro;

//MOTORS
extern pros::Motor leftFront;
extern pros::Motor leftBack;
extern pros::Motor rightFront;
extern pros::Motor rightBack;

//CONTROLLERS
extern pros::Controller master;

//AUTONOMOUS ROUTINES

void redLeftCorner() {
    translate(500, 100);
    rotate(90, 64);
}
