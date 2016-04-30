#include "circle.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "point.h"
#include <math.h>

#define pi 3.1415926535

Circle:: Circle(Point p, double r): center(p), radius(r){
} 

void Circle:: move(double dx, double dy) {
  center.move(dx, dy);
}

double Circle:: intersectionArea(const Circle & otherCircle) {
  double d = center.distanceFrom(otherCircle.center);
  if(d >= radius + otherCircle.radius || !radius 
     || !otherCircle.radius) {
      return 0;
  }
  else if(d <= fabs(radius - otherCircle.radius)) {
    if(radius < otherCircle.radius) {
    return radius * radius * pi;
  }
    else {
    return pow(otherCircle.radius,2) * pi;
    }
  }
  else {
    double radian1 = 2 * acos((radius * radius + d * d - otherCircle.radius * otherCircle.radius)/(2*radius*d));
    double radian2 = 2 * acos((otherCircle.radius * otherCircle.radius+ d * d - radius * radius)/(2*otherCircle.radius*d));
    double sr1 = 0.5 * radius * radius * radian1;
    double sr2 = 0.5 * otherCircle.radius * otherCircle.radius * radian2;
    double st1 = 0.5 * radius * radius * sin(radian1);
    double st2 = 0.5 * pow(otherCircle.radius,2) * sin(radian2);
    return (sr1 + sr2) - (st1 + st2);
 }
}
