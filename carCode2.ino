#include "Car.h"

Car car("NTNU-IOT", "");

bool linemode = false;

float P = 1;
float I = 0.000001;
float D = 0.001;

int eprev = 0;
float i = 0;
int der = 0;
int err = 0;

float u;

void setup() {
   car.initCar();
}

float sat(float x, float maxlim, float minlim) {
   if (x > maxlim)
      return maxlim;
   if (x < minlim)
      return minlim;
   return x;
}

void loop() {
   if (linemode == true) {
      eprev = err;
      err = car.data[LINE].value;
      i = sat(i + I * err, 100, -100);
      der = err - eprev;

      u = sat(P * err + i + D * der, 100, -100);

      if (u > 0) {
         car.drive(100, 100 - abs(u));
      } else {
         car.drive(100 - abs(u), 100);
      }
   } else {
      //car.drive(??, ??);
   }
}

void triangle(bool button) {
   if (button == DOWN) {
      // knappen trykkes ned
      // skru på linjefølging?
      linemode != linemode;
      if (!linemode) {
        car.drive(0, 0);
      }
      car.calibrateLine(BLACK);
   }
   if (button == UP) {
      // knappen slippes opp
      // skru av linjefølging?
   }
}

void circle(bool button) {

}

void square(bool button) {
  
}

void q_key(bool button) {
  
}
void w_key(bool button) {
  
}
void e_key(bool button) {
  
}
void a_key(bool button) {
  
}
void s_key(bool button) {
  
}
void d_key(bool button) {
  
}