#include "main.h"
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

//HELPER FUNCTIONS
void setDrive(int left, int right) {
    leftBack = left;
    leftFront = left;
    rightBack = right;
    rightFront = right;
}

void resetDriveEncoders() {
    leftFront.tare_position();
    leftBack.tare_position();
    rightFront.tare_position();
    rightBack.tare_position();
}

double averageDriveEncoderValue() {
    return (
        fabs(leftFront.get_position()) + 
        fabs(leftBack.get_position()) + 
        fabs(rightFront.get_position()) + 
        fabs(rightBack.get_position())) / 4;
}

//DRIVER CONTROL FUNCTIONS
void setDriveMotors() {
    int leftJoystick = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightJoystick = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    if(abs(leftJoystick) < 10) {
        leftJoystick = 0;
    }

    if(abs(rightJoystick) < 10) {
        rightJoystick = 0;
    }

    setDrive(leftJoystick, rightJoystick); //set drive motors to joystick values
}

//AUTONOMOUS FUNCTIONS

void translate(int units, int voltage) {
    //define direction based on units provided
    int direction = units / abs(units);

    //reset motor encoders
    resetDriveEncoders();
    gyro.reset();

    //drive forward until units are reached
    while(averageDriveEncoderValue() < abs(units)) {
        setDrive(voltage * direction - gyro.get_value(), voltage * direction + gyro.get_value());
        pros::delay(10);
    }

    //brief brake
    setDrive(-10 * direction, -10 * direction);
    pros::delay(50);

    //set drive back to neutral
    setDrive(0, 0);
}

void rotate(int degrees, int voltage) {
    //define direction based on units provided
    int direction = degrees / abs(degrees);

    //reset the gyro
    gyro.reset();

    //turn unil units are reached
    setDrive(voltage * direction, -voltage * direction);
    while(fabs(gyro.get_value()) < abs(degrees * 10) - 50) {
        pros::delay(10);
    }

    //reset rive to neutral
    setDrive(0, 0);

    // letting robot lose momentum
    pros::delay(100);

    // correcting any over or undershoot
    if(fabs(gyro.get_value()) > abs(degrees * 10)) {
        setDrive(0.5 * -voltage * direction, 0.5 * voltage * direction);
        while(fabs(gyro.get_value()) > degrees * 10) {
            pros::delay(10);
        }
    }
    else if(fabs(gyro.get_value()) < abs(degrees * 10)) {
        setDrive(0.5 * voltage * direction, 0.5 * -voltage * direction);
        while(fabs(gyro.get_value()) < abs(degrees * 10)) {   
            pros::delay(10);
        }
    }

    //reset rive to neutral
    setDrive(0, 0);
}