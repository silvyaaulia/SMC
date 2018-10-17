//Test tunning
//17/10/18
#define joy_tunning1 A5         
#define joy_tunning2 A4         
#define joy_tunning3 A3         
#define joy_tunning4 A2            

int tunning1 = 0;
int tunning2 = 0;
int tunning3 = 0;
int tunning4 = 0;
      

/* Tunning Function (KP and KD) */
double pulse_tunning_pd(int joytune_1, double tunning_1) {
  if (joytune_1 <=100){
    tunning_1 -= 0.1;
   }
  else if (joytune_1 >=900){
    tunning_1 += 0.1;
   }
  return tunning_1;
}

/*Tunning Function (KI)*/
float pulse_tunning_i(int joytune_2, float tunning_2) {
  if (joytune_2 <=100){
    tunning_2 -= 0.001;
   }
  else if (joytune_2 >=900){
    tunning_2 += 0.001;
   }
  return tunning_2;
}


void setup() {
  // Serial begin
  Serial.begin(57600);
}

void loop() {      
  double kp1,kd1, kp2, kd2,kp3,kd3,kp4,kd4;
  float ki1, ki2, ki3,ki4;

  
  
      // switch tunning 1 on
//      if (state_steer1 == LOW && state_steer2 == HIGH && state_steer2 == HIGH && state_steer2 == HIGH) {
        tunning1 = analogRead(joy_tunning1);
        tunning2 = analogRead(joy_tunning2);
        tunning3 = analogRead(joy_tunning3);
        delay(1000);
        Serial.print(" T.STEER1: ");
        kp1 = pulse_tunning_pd(tunning1, kp1);
        ki1 = pulse_tunning_i(tunning2, ki1);
        kd1 = pulse_tunning_pd(tunning3, kd1);
       Serial.print(" kp:");
       Serial.print(kp1);
       Serial.print(" ki:");
       Serial.print(ki1);
       Serial.print(" kd:");
       Serial.println(kd1);

       delay(500);
 } 
