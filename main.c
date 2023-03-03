#include <stdio.h>
#include <kipr/wombat.h>

int main() {
        while(0==0) {

            while(analog(0)<=2000) {
                enable_servos();
                set_servo_position(0, 1790);
                set_servo_position(3, 1000);
                motor(0, 30);
                motor(3, -30);
            }

            while(analog(0)<=3900) {
                motor(0, 90);
                motor(3, 90);

                if(analog(0)>=3900) {
                    motor(0, 0);
                    motor(3, 0);

                    enable_servos();
                    set_servo_position(3, 3000);
                    msleep(1000);

                }
            }

            while(analog(1)<=2000) {
                motor(0, -90);
                motor(3, -90);
            }

            motor(0, 0);
            motor(3, 90);
            msleep(4000);
            set_servo_position(3, 1000);
            msleep(4000);
        }


    return 0;
}
