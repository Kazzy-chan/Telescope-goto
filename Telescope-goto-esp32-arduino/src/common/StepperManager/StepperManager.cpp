#include "StepperManager.h"

StepperManager::StepperManager(): stepper1(Stepper::stepper1()), stepper2(Stepper::stepper2()){}


Stepper& StepperManager::getStepper1(){
    return this->stepper1;
}

Stepper& StepperManager::getStepper2(){
    return this->stepper2;
}