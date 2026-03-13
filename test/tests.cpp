// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>

#include "circle.h"
#include "tasks.h"

TEST(CircleTest, ConstructorRadius) {
    Circle c(10.0);
    EXPECT_NEAR(c.getRadius(), 10.0, 1e-7);
}

TEST(CircleTest, ConstructorFerence) {
    Circle c(10.0);
    EXPECT_NEAR(c.getFerence(), 62.83185307, 1e-7);
}

TEST(CircleTest, ConstructorArea) {
    Circle c(10.0);
    EXPECT_NEAR(c.getArea(), 314.15926535, 1e-7);
}

TEST(CircleTest, ConstructorZero) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetRadiusSimple) {
    Circle c(1.0);
    c.setRadius(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, SetRadiusUpdatesFerence) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_NEAR(c.getFerence(), 62.83185307, 1e-7);
}

TEST(CircleTest, SetRadiusUpdatesArea) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_NEAR(c.getArea(), 314.15926535, 1e-7);
}

TEST(CircleTest, SetRadiusLarge) {
    Circle c(1.0);
    c.setRadius(1000.0);
    EXPECT_NEAR(c.getArea(), 3141592.6535, 1e-4);
}

TEST(CircleTest, SetRadiusSmall) {
    Circle c(10.0);
    c.setRadius(0.1);
    EXPECT_NEAR(c.getFerence(), 0.6283185, 1e-7);
}

TEST(CircleTest, SetRadiusAndBack) {
    Circle c(10.0);
    c.setRadius(20.0);
    c.setRadius(10.0);
    EXPECT_NEAR(c.getArea(), 314.15926535, 1e-7);
}

TEST(CircleTest, SetFerenceSimple) {
    Circle c(1.0);
    c.setFerence(100.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 100.0);
}

TEST(CircleTest, SetFerenceUpdatesRadius) {
    Circle c(1.0);
    c.setFerence(62.83185307);
    EXPECT_NEAR(c.getRadius(), 10.0, 1e-7);
}

TEST(CircleTest, SetFerenceUpdatesArea) {
    Circle c(1.0);
    c.setFerence(62.83185307);
    EXPECT_NEAR(c.getArea(), 314.15926535, 1e-7);
}

TEST(CircleTest, SetFerenceZero) {
    Circle c(10.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
}

TEST(CircleTest, SetFerenceLarge) {
    Circle c(1.0);
    c.setFerence(1000.0);
    EXPECT_NEAR(c.getRadius(), 159.154943, 1e-5);
}

TEST(CircleTest, SetFerenceSmall) {
    Circle c(1.0);
    c.setFerence(0.001);
    EXPECT_NEAR(c.getArea(), 0.0000000795, 1e-10);
}

TEST(CircleTest, SetAreaSimple) {
    Circle c(1.0);
    c.setArea(100.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 100.0);
}

TEST(CircleTest, SetAreaUpdatesRadius) {
    Circle c(1.0);
    c.setArea(314.15926535);
    EXPECT_NEAR(c.getRadius(), 10.0, 1e-7);
}

TEST(CircleTest, SetAreaUpdatesFerence) {
    Circle c(1.0);
    c.setArea(314.15926535);
    EXPECT_NEAR(c.getFerence(), 62.83185307, 1e-7);
}

TEST(CircleTest, SetAreaZero) {
    Circle c(10.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, SetAreaSmall) {
    Circle c(1.0);
    c.setArea(0.01);
    EXPECT_NEAR(c.getRadius(), 0.0564189, 1e-6);
}

TEST(CircleTest, SetAreaConsistency) {
    Circle c(1.0);
    c.setArea(50.0);
    double r = c.getRadius();
    EXPECT_NEAR(c.getFerence(), 2 * 3.1415926535 * r, 1e-7);
}

TEST(TasksTest, EarthTaskResult) {
    double result = earthTask();
    EXPECT_NEAR(result, 0.1591549, 1e-6);
}

TEST(TasksTest, EarthTaskPositive) {
    EXPECT_GT(earthTask(), 0.0);
}

TEST(TasksTest, PoolTaskTotalCost) {
    double cost = poolTask(3.0, 1.0, 1000.0, 2000.0);
    EXPECT_NEAR(cost, 72256.63, 0.1);
}

TEST(TasksTest, PoolTaskOnlyConcrete) {
    double cost = poolTask(3.0, 1.0, 1000.0, 0.0);
    EXPECT_NEAR(cost, 21991.14, 0.1);
}

TEST(TasksTest, PoolTaskOnlyFence) {
    double cost = poolTask(3.0, 1.0, 0.0, 2000.0);
    EXPECT_NEAR(cost, 50265.48, 0.1);
}

TEST(TasksTest, PoolTaskSmallWidth) {
    double cost = poolTask(3.0, 0.0, 1000.0, 2000.0);
    EXPECT_NEAR(cost, 37699.1, 0.1);
}
