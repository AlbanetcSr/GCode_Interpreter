void init_servo()
{
  //setup our pins
  pinMode(SERVO_PWM_PIN, OUTPUT);	
  //initialize values
  analogWrite(SERVO_PWM_PIN, 0);	
}

void servo_set(byte pwm)
{
  analogWrite(SERVO_PWM_PIN, pwm);  
}
