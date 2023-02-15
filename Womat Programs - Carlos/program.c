#include <stdio.h>
#include <kipr/wombat.h>

int main()
{
  enable_servos();
  // -- Starts up the Robot -- //
  printf("> Starting Program\n");
  set_servo_position(3, -1);
  msleep(1000);

  // -- Lowers down the Claw -- //
  printf("> Lowering Claw\n");
  set_servo_position(0, -1);
  // -- Opens claw Up --//
  printf("> Openning Claw\n");
  set_servo_position(3, 1);

  // -- Moves the Robot --//
  printf("> Moving Robot\n");
  msleep(10);
  motor(0, 100);
  motor(3, 100);
  msleep(2300);

  // -- Picks up the Can --//
  printf("> Closing Claw\n");
  set_servo_position(3,-1);
  msleep(1000);

  //-- Moves Robot Back -- //
  printf("> Rotating\n");
  motor(0, 100);
  motor(3, -100);
  msleep(1800);
  printf("> Moving Robot\n");
  motor(0, 100);
  motor(3, 100);
  msleep(1620);

  // -- Lower/Release Can -- //
  printf("> Lowering Claw\n");
  motor(0,0);
  motor(3,0);
  msleep(1000);
  set_servo_position(3, 1);
  msleep(2000);

    // -- Move Back -- //
  printf("> Moving Robot");
  motor(3, -100);
  motor(0, -100);
  msleep(3000);

  return 0;
}
