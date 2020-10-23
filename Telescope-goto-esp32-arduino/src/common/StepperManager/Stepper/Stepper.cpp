#include "Stepper.h"


Stepper::Stepper(GPIOPin stepPin, GPIOPin dirPin, int steps, int microstepping, float gearRatio, Constraints constraints): 
    stepPin(stepPin), dirPin(dirPin), steps(steps), microstepping(microstepping), gearRatio(gearRatio), constraints(constraints){}

Stepper Stepper::stepper1(){
    return Stepper(GPIOPin(Stepper1_Step_Pin), GPIOPin(Stepper1_Dir_Pin), Stepper1_Steps, Stepper1_Microstepping, Stepper1_GearRatio, Constraints());
}

Stepper Stepper::stepper2(){
    return Stepper(GPIOPin(Stepper2_Step_Pin), GPIOPin(Stepper2_Dir_Pin), Stepper2_Steps, Stepper2_Microstepping, Stepper2_GearRatio, Constraints());
}

void Stepper::changeDir(bool clockwise){
    clockwise? this->dirPin.low(): this->dirPin.high();
}

bool Stepper::moveDegree(float degree){
    float degreePerStep = (this->steps * this->microstepping * this->gearRatio) / 360;
    int steps = round(degree / degreePerStep);
    if(degree < 0){
        return this->moveSteps((steps * -1), false);
    }else{
        return this->moveSteps(steps, true);
    }
}

bool Stepper::moveSteps(int steps, bool clockwise){
    bool isValid = this->constraints.isValid(steps, !clockwise);
    if(isValid){
        this->changeDir(clockwise);
        for (int i = 0; i < steps; i++){
            this->stepPin.toggle();
        }
        this->constraints.moveSteps(steps, !clockwise);
    }
    return isValid;
}

Constraints& Stepper::getConstraints(){
    return this->constraints;
}