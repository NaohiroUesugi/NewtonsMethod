#include <math.h> // exp, pow, fabsを読み込む
#include <stdio.h>

double func(double x) {
  return exp(-x) - x;
}

double derivative_func(double x) { // 導関数
  return -exp(-x) - 1;
}

#define EPSILON pow(10, -6)

int main(void) {
  double x_distance = 0;
  double x0 = 0; // 初期値
  double x = x0;
  do {
    x_distance = func(x)/derivative_func(x);
    x -= x_distance;
  } while(fabs(x_distance) > EPSILON);
  printf("result x=%lf\n", x);
  return 0;
}