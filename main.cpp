#include <iostream>
#include <windows.h>

typedef double (*CalculateForceFunction)(double, double);
typedef double (*CalculateMassFunction)(double, double);
typedef double (*CalculateEnergyFunction)(double);
typedef double (*CalculateWorkFunction)(double, double);
typedef double (*CalculateMomentumFunction)(double, double);

int main() {
    HINSTANCE hDLL = LoadLibrary("dll.dll");
    if (!hDLL) {
        std::cerr << "Could not load the DLL!" << std::endl;
        return 1;
    }

    CalculateForceFunction calculateForce = (CalculateForceFunction)GetProcAddress(hDLL, "calculateForce");
    CalculateMassFunction calculateMass = (CalculateMassFunction)GetProcAddress(hDLL, "calculateMass");
    CalculateEnergyFunction calculateEnergy = (CalculateEnergyFunction)GetProcAddress(hDLL, "calculateEnergy");
    CalculateWorkFunction calculateWork = (CalculateWorkFunction)GetProcAddress(hDLL, "calculateWork");
    CalculateMomentumFunction calculateMomentum = (CalculateMomentumFunction)GetProcAddress(hDLL, "calculateMomentum");
    if (!calculateForce || !calculateMass || !calculateEnergy || !calculateWork || !calculateMomentum) {
        std::cerr << "Could not locate the functions!" << std::endl;
        return 1;
    }

    // TODO: а еще calculateMass юзать?
    // TODO: вас так учили скорость света писать?
    SetConsoleOutputCP(CP_UTF8);
    double mass = 10.0; // масса в килограммах
    double acceleration = 9.81; // ускорение в м/с^2
    double force = calculateForce(mass, acceleration);
    std::cout << "Сила: " << force << " Н" << std::endl;

    double energy = calculateEnergy(mass);
    std::cout << "Энергия: " << energy << " Дж" << std::endl;

    double distance = 5.0; // расстояние в метрах
    double work = calculateWork(force, distance);
    std::cout << "Работа: " << work << " Дж" << std::endl;

    double velocity = 3.0; // скорость в м/с
    double momentum = calculateMomentum(mass, velocity);
    std::cout << "Импульс: " << momentum << " кг·м/с" << std::endl;

    system("pause");
    FreeLibrary(hDLL);
    return 0;
}
