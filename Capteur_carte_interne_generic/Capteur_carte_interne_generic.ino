/*
  Clignotement de LED
  Allume une LED pendant 1 seconde, puis l'éteint pendant 1 seconde
  puis le programme se répète indéfiniment

  Cet exemple est dans le domaine public
  Traduction française par X. HINAULT - www.mon-club-elec.fr
 */

void setup() {                
  // initialise la broche 13 en sortie numérique
  // la broche 13 a une LED déjà connectée sur la plupart des cartes Arduino :
  pinMode(13, OUTPUT);    
  String trame, s_temp, s_hygro, s_CO, s_vib, s_bal, s_temp_bal;
  int temp, hygro, CO, vib, bal, temp_bal;
  
}

void loop() {
  digitalWrite(13, HIGH);   // allume la LED
  delay(1000);              // ne fait rien pendant 1 seconde
  digitalWrite(13, LOW);    // éteint la LED
  delay(1000);              // ne fait rien pendant 1 seconde
  
  String trame, s_temp, s_hygro, s_CO, s_vib, s_bal, s_temp_bal;
  int temp, hygro, CO, vib, bal, temp_bal;

  temp = Temp();
  s_temp = String(temp);
  hygro = Hygro();
  s_hygro = String(hygro);
  CO = CO2();
  s_CO = String(CO);
  vib = Vibration();
  s_vib = String(vib);
  bal = Balance();
  s_bal = String(bal);
  temp_bal = Temp_balance();
  s_temp_bal = String(temp_bal);
  
  //trame = "s_temp"+"s_hygro"+"s_CO"+"s_vib"+"s_bal"+"s_temp_bal";  
  trame = temp + hygro + CO + vib + bal + temp_bal; 
  Serial.print(trame);
}

int Temp()
{
  int temp_func;
  temp_func = 0x00;

  return temp_func;
}

int Hygro()
{
  int hygro_func;
  hygro_func = 0x00;

  return hygro_func;  
}

int CO2(void)
{
  int CO_func;
  CO_func = 0x00;

  return CO_func;  
}

int Vibration(void)
{
  int vib_func;
  vib_func = 0x00;

  return vib_func;  
}

int Balance(void)
{
  int bal_func;
  bal_func = 0x00;

  return bal_func;  
}

int Temp_balance(void)
{
   int temp_bal_func;
   temp_bal_func = 0x00;

  return temp_bal_func; 
}
