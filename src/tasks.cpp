// Copyright 2022 UNN-CS
#include <cmath>
#include "tasks.h"
#include "circle.h"

double taskEarthRope() {
    double earthRadius = 6378100.0;
    Circle c(earthRadius);
    double initialFerence = c.getFerence();
    c.setFerence(initialFerence + 1.0);
    return c.getRadius() - earthRadius;
}

double taskPoolCost() {
    double poolRadius = 3.0;
    double trackWidth = 1.0;
    Circle pool(poolRadius);
    Circle total(poolRadius + trackWidth);
    double trackArea = total.getArea() - pool.getArea();
    return trackArea * 1000.0;
}

double taskFenceCost() {
    double poolRadius = 3.0;
    double trackWidth = 1.0;
    Circle total(poolRadius + trackWidth);
    return total.getFerence() * 2000.0;
}
