// Copyright 2022 UNN-CS

#include "tasks.h"
#include "circle.h"
double earthTask() {
    double earthRadius = 6378100.0;
    Circle earth(earthRadius);
    double newFerence = earth.getFerence() + 1.0;
    earth.setFerence(newFerence);
    return earth.getRadius() - earthRadius;
}
double poolTask(double rPool, double widthPath, double priceConcrete, double priceFence) {
    Circle pool(rPool);
    Circle outerCircle(rPool + widthPath);
    double pathArea = outerCircle.getArea() - pool.getArea();
    double concreteCost = pathArea * priceConcrete;
    double fenceCost = outerCircle.getFerence() * priceFence;
    return concreteCost + fenceCost;
}
