/*
  DRV8871Quad.cpp - Library for interacting with DRV8871Quad
*/

#include "DRV8871Quad.h"
#include "Arduino.h"
#include "DRV8871.h"

DRV8871Quad::DRV8871Quad(DRV8871 *frontRightMotor, DRV8871 *frontLeftMotor,
                         DRV8871 *backRightMotor, DRV8871 *backLeftMotor) {
  _frontRightMotor = frontRightMotor;
  _frontLeftMotor = frontLeftMotor;
  _backRightMotor = backRightMotor;
  _backLeftMotor = backLeftMotor;
}

void DRV8871Quad::drive(byte speed, byte direction) {
  _frontRightMotor->drive(speed, direction, 0);
  _frontLeftMotor->drive(speed, direction, 0);
  _backRightMotor->drive(speed, direction, 0);
  _backLeftMotor->drive(speed, direction, 0);
}

void DRV8871Quad::turn(byte speed, byte direction) {
  if (direction == TURN_LEFT) {
    _frontLeftMotor->drive(speed, _frontLeftMotor->DIRECTION_BACKWARD, 0);
    _backLeftMotor->drive(speed, _backLeftMotor->DIRECTION_BACKWARD, 0);
    _frontRightMotor->drive(speed, _frontRightMotor->DIRECTION_FORWARD, 0);
    _backRightMotor->drive(speed, _backRightMotor->DIRECTION_FORWARD, 0);
  } else if (direction == TURN_RIGHT) {
    _frontLeftMotor->drive(speed, _frontLeftMotor->DIRECTION_FORWARD, 0);
    _backLeftMotor->drive(speed, _backLeftMotor->DIRECTION_FORWARD, 0);
    _frontRightMotor->drive(speed, _frontRightMotor->DIRECTION_BACKWARD, 0);
    _backRightMotor->drive(speed, _frontRightMotor->DIRECTION_BACKWARD, 0);
  }
}

void DRV8871Quad::breakdown(byte targetSpeed) {
  _frontRightMotor->breakdown(targetSpeed, 0);
  _frontLeftMotor->breakdown(targetSpeed, 0);
  _backRightMotor->breakdown(targetSpeed, 0);
  _backLeftMotor->breakdown(targetSpeed, 0);
}