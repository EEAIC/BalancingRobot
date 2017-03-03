#define MotorCW_L 4
#define MotorPWM_L 5
#define MotorCCW_L 6

#define MotorCW_R 9
#define MotorPWM_R 10
#define MotorCCW_R 11

void Motorsetup(){
  pinMode(MotorPWM_L, OUTPUT);
  pinMode(MotorCW_L, OUTPUT);
  pinMode(MotorCCW_L, OUTPUT);
  pinMode(MotorPWM_R, OUTPUT);
  pinMode(MotorCW_R, OUTPUT);
  pinMode(MotorCCW_R, OUTPUT);
  }

void Motor_L(int Speed){
  if(Speed>=0){
    digitalWrite(MotorCW_L, HIGH);
    digitalWrite(MotorCCW_L, LOW);
    analogWrite(MotorPWM_L, Speed);
    }
   else{
    digitalWrite(MotorCW_L, LOW);
    digitalWrite(MotorCCW_L, HIGH);
    analogWrite(MotorPWM_L, -Speed);
    } 
 }

 void Motor_R(int Speed){
  if(Speed>=0){
    digitalWrite(MotorCW_R, HIGH);
    digitalWrite(MotorCCW_R, LOW);
    analogWrite(MotorPWM_R, Speed);
    }
   else{
    digitalWrite(MotorCW_R, LOW);
    digitalWrite(MotorCCW_R, HIGH);
    analogWrite(MotorPWM_R, 255-Speed);
    } 
 }

