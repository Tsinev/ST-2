// Copyright 2022 UNN-CS

#include "tasks.h"
#include "circle.h"
double earthTask() {
  double earthRadius = 6378100.0;
  Circle earth(earthRadius);
  earth.setFerence(earth.getFerence() + 1.0);
  return earth.getRadius() - earthRadius;
}
double poolTask(double rPool, double widthPath,
                double priceConcrete, double priceFence) {
  Circle pool(rPool);
  Circle outer(rPool + widthPath);
  double pathArea = outer.getArea() - pool.getArea();
  double costConcrete = pathArea * priceConcrete;
  double costFence = outer.getFerence() * priceFence;
  return costConcrete + costFence;
}
