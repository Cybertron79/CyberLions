#include <stdio.h>
#include <kipr/wombat.h>

void forward() {
  int left_motor = 0;
  int right_motor = 3;
  int torque = 90;

  motor(left_motor, torque);
  motor(right_motor, torque);
}

void backwards() {
  int left_motor = 0;
  int right_motor = 3;
  int torque = -90;

  motor(left_motor, torque);
  motor(right_motor, torque);
}

void wait() {
  int left_motor = 0;
  int right_motor = 3;
  int torque = 0;

  motor(left_motor, torque);
  motor(right_motor, torque);
  msleep(1000);
}

int main() {
  int left_motor = 0;
  int right_motor = 3;
  int arm = 0;
  int claw = 3;
  int torque_positive = 90;
  int torque_negative = -90;

  enable_servos();
  set_servo_position(arm, 1900);
  set_servo_position(claw, 1600);
  msleep(1000);
  disable_servos();

  while (analog(0)<4000) {
    forward();
  }

  wait();

  enable_servos();
  set_servo_position(claw, 2100);  
  msleep(100);
  disable_servos();

  wait();

  motor(left_motor, torque_positive);
  motor(right_motor, torque_negative);
  msleep(2000);

  wait();

  while (analog(1)<4000) {
    forward();
  }

  wait();

  enable_servos();
  set_servo_position(claw, 1600);
  msleep(100);
  disable_servos();

  wait();

  backwards();
  msleep(2000);

  return 0;
}