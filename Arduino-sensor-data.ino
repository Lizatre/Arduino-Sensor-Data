/*
This program reads sensor values (given by read_sensor_data) and sends them to the PC

 
 */


const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to
const int rolling_average_number = 1000

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  total = 0
  for (i=1;i <= rolling_average_number;i++){
    total = total * (i/(i+1))
    total = total + (1/(i+1))* read_sensor_data() //run a rolling average
    delay(2); // wait 2 milliseconds to let the ADC settle
  }
  // print the results to the serial monitor:                      
  Serial.print(sensorValue);      
                 
}

int read_sensor_data(){
  return analogRead(analogInPin);
  }
