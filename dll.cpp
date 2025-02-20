#include <windows.h>

#define EXPORT __declspec(dllexport)

const double SPEED_OF_LIGHT = 299792458.0;

extern "C" EXPORT double calculateForce(double mass, double acceleration) {
  return mass * acceleration;
}

extern "C" EXPORT double calculateMass(double force, double acceleration) {
  return force / acceleration;
}

extern "C" EXPORT double calculateEnergy(double mass) {
  return mass * SPEED_OF_LIGHT * SPEED_OF_LIGHT;
}

extern "C" EXPORT double calculateWork(double force, double distance) {
  return force * distance;
}

extern "C" EXPORT double calculateMomentum(double mass, double velocity) {
  return mass * velocity;
}