// Includes.
#include <HTS221Sensor.h>
#include <LPS25HBSensor.h>
#include <LSM6DS0Sensor.h>

#define DEV_I2C Wire
#define SerialPort Serial

// Components.
HTS221Sensor  *HumTemp;
LPS25HBSensor *PressTemp;
LSM6DS0Sensor *AccGyr;

void setup() {                
  // initialise la broche 13 en sortie numérique
  // la broche 13 a une LED déjà connectée sur la plupart des cartes Arduino :
  pinMode(13, OUTPUT);    
  String trame, s_temp, s_hygro, s_CO, s_vib, s_bal, s_temp_bal;
  int temp, hygro, CO, vib, bal, temp_bal;

  // Initlialize components.
  HumTemp = new HTS221Sensor (&DEV_I2C);
  HumTemp->Enable();
  PressTemp = new LPS25HBSensor(&DEV_I2C);
  PressTemp->Enable();
  AccGyr = new LSM6DS0Sensor(&DEV_I2C);
  AccGyr->Enable_X();
  AccGyr->Enable_G();
}

void loop() {
  // Initialize serial for output.
  SerialPort.begin(115200);
  
  digitalWrite(13, HIGH);   // allume la LED
  delay(1000);              // ne fait rien pendant 1 seconde
  digitalWrite(13, LOW);    // éteint la LED
  delay(1000);              // ne fait rien pendant 1 seconde
  
  String trame, s_temp, s_hygro, s_temp2, s_press, s_accelero1, s_accelero2, s_accelero3, s_gyro1, s_gyro2, s_gyro3;

    // Read humidity and temperature.
  float humidity, temperature;
  HumTemp->GetHumidity(&humidity);
  HumTemp->GetTemperature(&temperature);
  
  // Read pressure.
  float pressure, temperature2;
  PressTemp->GetPressure(&pressure);
  PressTemp->GetTemperature(&temperature2);
  
  // Read accelerometer and gyroscope.
  int32_t accelerometer[3];
  int32_t gyroscope[3];
  AccGyr->Get_X_Axes(accelerometer);
  AccGyr->Get_G_Axes(gyroscope);

  s_temp = String(temperature);
  s_hygro = String(humidity);
  s_temp2 = String(temperature2);
  s_press = String(pressure);
  s_accelero1 = String(accelerometer[1]); 
  s_accelero2 = String(accelerometer[2]); 
  s_accelero3 = String(accelerometer[3]); 
  s_gyro1 = String(gyroscope[1]); 
  s_gyro2 = String(gyroscope[2]); 
  s_gyro3 = String(gyroscope[3]);
  
  //trame = "s_temp"+"s_hygro"+"s_temp2"+"s_press"+"s_accelero1"+"s_accelero2"+"s_accelero3"+"s_gyro1"+"s_gyro2"+"s_gyro3";  
  trame = s_temp+s_hygro+s_temp2+s_press+s_accelero1+s_accelero2+s_accelero3+s_gyro1+s_gyro2+s_gyro3;  

  Serial.print(trame);
}
