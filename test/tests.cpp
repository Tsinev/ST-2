// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>

#include "circle.h"
#include "tasks.h"

TEST(CircleTest, ConstructorRadius) {
    Circle c(10);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
}

TEST(CircleTest, ConstructorFerence) {
    Circle c(1);
    EXPECT_NEAR(c.getFerence(), 6.283185, 0.0001);
}

TEST(CircleTest, ConstructorArea) {
    Circle c(1);
    EXPECT_NEAR(c.getArea(), 3.141592, 0.0001);
}

TEST(CircleTest, SetRadiusRecalculatesFerence) {
    Circle c(0);
    c.setRadius(5);
    EXPECT_NEAR(c.getFerence(), 31.4159, 0.001);
}

TEST(CircleTest, SetRadiusRecalculatesArea) {
    Circle c(0);
    c.setRadius(5);
    EXPECT_NEAR(c.getArea(), 78.5398, 0.001);
}

TEST(CircleTest, SetRadiusZero) {
    Circle c(10);
    c.setRadius(0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetFerenceRecalculatesRadius) {
    Circle c(0);
    c.setFerence(62.8318);
    EXPECT_NEAR(c.getRadius(), 10.0, 0.001);
}

TEST(CircleTest, SetFerenceRecalculatesArea) {
    Circle c(0);
    c.setFerence(31.4159);
    EXPECT_NEAR(c.getArea(), 78.5398, 0.001);
}

TEST(CircleTest, SetFerenceLarge) {
    Circle c(1);
    c.setFerence(1000);
    EXPECT_GT(c.getRadius(), 150);
}

TEST(CircleTest, SetAreaRecalculatesRadius) {
    Circle c(0);
    c.setArea(314.159);
    EXPECT_NEAR(c.getRadius(), 10.0, 0.001);
}

TEST(CircleTest, SetAreaRecalculatesFerence) {
    Circle c(0);
    c.setArea(78.5398);
    EXPECT_NEAR(c.getFerence(), 31.4159, 0.001);
}

TEST(CircleTest, SetAreaSmall) {
    Circle c(10);
    c.setArea(0.0001);
    EXPECT_LT(c.getRadius(), 0.01);
}

TEST(CircleTest, ConsistencyRadiusFerenceArea) {
    Circle c(7.5);
    double f = c.getFerence();
    c.setFerence(f);
    EXPECT_NEAR(c.getArea(), 176.7145, 0.001);
}

TEST(CircleTest, ConsistencyAreaToRadius) {
    Circle c(1);
    c.setArea(100);
    double r = c.getRadius();
    c.setRadius(r);
    EXPECT_NEAR(c.getArea(), 100.0, 0.00001);
}

TEST(CircleTest, ExtremeValueSmall) {
    Circle c(1e-9);
    EXPECT_GT(c.getArea(), 0);
}

TEST(TaskEarthRope, ResultIsPositive) {
    EXPECT_GT(taskEarthRope(), 0);
}

TEST(TaskEarthRope, CorrectCalculation) {
    EXPECT_NEAR(taskEarthRope(), 0.159, 0.001);
}

TEST(TaskEarthRope, IndependentOfInitialRadius) {
    double res = taskEarthRope();
    EXPECT_NEAR(res, 0.1591549, 0.0000001);
}

TEST(TaskEarthRope, ResultUnit) {
    double res = taskEarthRope();
    EXPECT_LT(res, 1.0);
}

TEST(TaskPool, ConcreteCostPositive) {
    EXPECT_GT(taskPoolCost(), 0);
}

TEST(TaskPool, FenceCostPositive) {
    EXPECT_GT(taskFenceCost(), 0);
}

TEST(TaskPool, ConcreteCostValue) {
    EXPECT_NEAR(taskPoolCost(), 21991.148, 0.1);
}

TEST(TaskPool, FenceCostValue) {
    EXPECT_NEAR(taskFenceCost(), 50265.48, 0.1);
}

TEST(TaskPool, FenceVsConcrete) {
    EXPECT_GT(taskFenceCost(), taskPoolCost());
}

TEST(TaskPool, AreaRatio) {
    Circle pool(3);
    Circle total(4);
    EXPECT_LT(pool.getArea(), total.getArea());
}

TEST(CircleTest, HugeRadius) {
    Circle c(1e6);
    EXPECT_GT(c.getArea(), 1e12);
}

TEST(CircleTest, SetRadiusTwice) {
    Circle c(5);
    c.setRadius(10);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
}

TEST(CircleTest, SetSameArea) {
    Circle c(10);
    double old_r = c.getRadius();
    c.setArea(c.getArea());
    EXPECT_NEAR(c.getRadius(), old_r, 1e-9);
}