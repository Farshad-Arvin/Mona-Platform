// Basic test of Mona robot including proximity sensors and open-loop motion control

// pin config for basic platform test
// Motors
int Motor_right_PWM = 10;  //   0 (min speed) - 255 (max speed) 
int Motor_right_direction = 5;  //   0 Forward - 1 Reverse
int Motor_left_PWM = 9;    //   0 (min speed) - 255 (max speed)  
int Motor_left_direction = 6;   //   0 Forward - 1 Reverse
#define Forward 0
#define Reverse 1
// LED
int LED1 = 13;
int LED2 = 12;
int IR_enable=4;
int IR_threshold= 900; // 0 white close obstacle -- 1023 no obstacle


void setup() {
// initialize serial communication at 9600 bits per second:
 Serial.begin(9600);
// initialize Ports
  pinMode(Motor_left_PWM, OUTPUT);
  pinMode(Motor_right_PWM, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(IR_enable, OUTPUT);
}

void forward(){
  analogWrite(Motor_right_PWM,40); // right motor
  digitalWrite(Motor_right_direction,Forward); //right
  analogWrite(Motor_left_PWM, 40); // left 
  digitalWrite(Motor_left_direction,Forward); //left
}

void reverse(int delay_time){
  analogWrite(Motor_right_PWM,120 ); // right motor
  digitalWrite(Motor_right_direction,Reverse); //right
  analogWrite(Motor_left_PWM, 120); // left 
  digitalWrite(Motor_left_direction,Reverse); //left
  delay(delay_time);
}

void right(int delay_time){
  reverse(50);
  analogWrite(Motor_right_PWM,120 ); // right motor
  digitalWrite(Motor_right_direction,Reverse); //right
  analogWrite(Motor_left_PWM, 40); // left 
  digitalWrite(Motor_left_direction,Forward); //left
  delay(delay_time);
}

void left(int delay_time){
  reverse(50);
  analogWrite(Motor_right_PWM,40 ); // right motor
  digitalWrite(Motor_right_direction,Forward); //right
  analogWrite(Motor_left_PWM, 120); // left 
  digitalWrite(Motor_left_direction,Reverse); //left
  delay(delay_time);
}

// Variables for 5 IR proximity sensors 
int IR_right,IR_right_front,IR_front,IR_left_front,IR_left;

void IR_proximity_read(){    // read IR sensors 
  int n=5;  // average parameter
  digitalWrite(IR_enable, HIGH);  //IR Enable
  IR_right=0;
  IR_right_front=0;
  IR_front=0;
  IR_left_front=0;
  IR_left=0;
  for (int i=0;i<n;i++){
    IR_right+=analogRead(A3);
    IR_right_front+=analogRead(A2);
    IR_front+=analogRead(A1);
    IR_left_front+=analogRead(A0);
    IR_left+=analogRead(A7);
    delay(5);
  }
  IR_right/=n;
  IR_right_front/=n;
  IR_front/=n;
  IR_left_front/=n;
  IR_left/=n; 
}

// obstacle avoidance
void Obstacle_avoidance(){
  if (IR_front<IR_threshold){
      digitalWrite(LED2,HIGH);
      reverse(300);
      right(500);
      digitalWrite(LED2,LOW);
  }
  if (IR_right<IR_threshold || IR_right_front<IR_threshold ){
      digitalWrite(LED2,HIGH);
      right(500);
      digitalWrite(LED2,LOW);
  } else {
      if (IR_left<IR_threshold || IR_left_front<IR_threshold ){
          digitalWrite(LED2,HIGH);
          left(500);
          digitalWrite(LED2,LOW);
      } else forward();
  }  
}

// send IR readings to Serial Monitor
void Send_sensor_readings(){
 Serial.print(IR_right);
 Serial.print(',');
 Serial.print(IR_right_front);
 Serial.print(',');
 Serial.print(IR_front);
 Serial.print(',');
 Serial.print(IR_left_front);
 Serial.print(',');
 Serial.println(IR_left);  
}


// the loop routine runs over and over again forever:
void loop() {

 digitalWrite(LED1,HIGH); //Top LED
 IR_proximity_read();
 Send_sensor_readings(); 
 Obstacle_avoidance();
 digitalWrite(LED1,LOW); //Top LED

 delay(100);        // delay in between reads for stability
}
