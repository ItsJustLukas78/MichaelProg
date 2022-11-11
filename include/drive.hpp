#ifndef _DRIVE_HPP_
#define _DRIVE_HPP_

//HELPER FUNCTIONS
void setDrive(int left, int right);

void resetDriveEncoders();

double averageDriveEncoderValue();

//DRIVER CONTROL FUNCTIONS
void setDriveMotors();

//AUTONOMOUS FUNCTIONS
void translate(int units, int voltage);

void rotate(int degrees, int voltage);

#endif