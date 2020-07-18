/**
 * NTC Temperature Thermistor Code
 * 
 * Edited by: Diego Ferreira, diego.ferreiraa@outlook.com
 * Based on: Eletrogate, https://www.eletrogate.com/pagina/apostilas.html
 * 
 */

#define Vin 5.0             // Input Voltage 5V of Arduino
#define T0 298.15       
#define Rl 10000  // Value of resistence RL (pull-down resistor): 10k ohm resistor
#define R0 10000  // Value of resistence R0 NTC Thermistor: 10k ohm resistor
#define T1 273.15 //
#define T2 373.15
#define RT1 35563
#define RT2 549
float beta = 0.0;
float Rinf = 0.0;
float tempKelvin = 0.0; // Value of temperature in Kelvin [K]
float tempCelsius = 0.0;  // Value of temperature in Celsius [°C]
float Vout = 0.0; // Output Voltage
float Rout = 0.0; // Output Resistence

void setup()
{
Serial.begin(9600);
  // monitor serial - velocidade 9600 Bps
  beta = (log(RT1 / RT2)) / ((1 / T1) - (1 / T2));
  // calculo de beta
  Rinf = R0 * exp(-beta / T0);
  // calculo de Rinf
  delay(100);
  // atraso de 100 milisegundos
}


void loop()
{
  Vout = Vin * ((float)(analogRead(0)) / 1024.0);
  Rout = (Rt * Vout / (Vin - Vout));
  TempKelvin = (beta / log(Rout / Rinf));
  TempCelsius = TempKelvin - 273.15;
  Serial.print("Temperatura em Celsius: ");
  Serial.print(tempCelsius);
  Serial.print("Temperatura em Kelvin: ");
  Serial.println(tempKelvin);
  delay(500);
}
