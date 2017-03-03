int speed;
 #define runEvery(t) for (static typeof(t) _lasttime;(typeof(t))((typeof(t))millis() - _lasttime) > (t);_lasttime += (t))
const float Kp = 200;
const float Ki = 150;
const float Kd = 100;
float pTerm, iTerm, dTerm, integrated_error, last_error, error;
const float K = 1.9*1.12;
#define   GUARD_GAIN   0.0

void Pid(double CurrentAngle){
  error = 1 - CurrentAngle;  // 180 = level
  pTerm = Kp * error;
  integrated_error += error;
  iTerm = Ki * constrain(integrated_error, -GUARD_GAIN, GUARD_GAIN);
  dTerm = Kd * (error - last_error);
  last_error = error;
  speed = constrain(K*(pTerm + iTerm + dTerm), -255, 255);
}


/*int speed;
 
double Kp = 1.2;
double Ki = 2.5;
double Kd = 3.2;

double error;
double error_previous;
double desired_angle = 5;
double current_angle;

double P_control,I_control,D_control;
double Time = 0.004;

double PID_control;

void Pid(int current_angle){
  error=desired_angle-current_angle; 
  P_control = Kp * error;
  I_control = I_control + Ki * error * Time;
  D_control = Kd * (error - error_previous) / Time;

  PID_control = P_control + I_control + D_control;
  error_previous = error;
  PID_control = constrain(PID_control, -255, 255);
  speed = PID_control;
  

}

const float Kp = 3;
const float Ki = 1.5;
const float Kd = 3;
float pTerm, iTerm, dTerm, integrated_error, last_error, error;
const float K = 1.9*1.12;
#define   GUARD_GAIN   0.0
#define runEvery(t) for (static typeof(t) _lasttime;(typeof(t))((typeof(t))millis() - _lasttime) > (t);_lasttime += (t))


void Pid(double CurrentAngle){
  error = 0 - CurrentAngle;  // 180 = level
  pTerm = Kp * error;
  integrated_error += error;
  iTerm = Ki * constrain(integrated_error, -GUARD_GAIN, GUARD_GAIN);
  dTerm = Kd * (error - last_error);
  last_error = error;
  speed = constrain(K*(pTerm + iTerm + dTerm), -255, 255);
}*/

