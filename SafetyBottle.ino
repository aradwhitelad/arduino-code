//include code libraries for sensors
#include <OneWire.h>
#include <DallasTemperature.h>

//tell the arduino which input the temp sensor is connected to
#define ONE_WIRE_BUS 10
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

//initialize variables
int temp;
int red = 9;
int green = 6;

void setup(void)
{
  pinMode(red, OUTPUT); //establish pin #9, where the red LED is connected to as output
  pinMode(green, OUTPUT); //establish pin #6, where the green LED is connected to as output
  
  Serial.begin(9600); // start serial port
  Serial.println("Serial up and running!");
 
  sensors.begin(); //start temp sensor
}
void loop(void)
{

  sensors.requestTemperatures(); //requests temperatures from temperature sensor
  temp = sensors.getTempFByIndex(0); //store the temperature as an integer value
  
  Serial.print("Ben is currently eating kids in ");
  Serial.print(temp);
  Serial.println("° weather.");
  
  if(temp>80){
    //turns red LED on and green LED off if temperature is 80 degrees F or above
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  }else{
    //turns green LED on and red LED off if temperature is below 80 degrees 
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    }
    
  delay(1000); //waits two seconds, then repeats
}
