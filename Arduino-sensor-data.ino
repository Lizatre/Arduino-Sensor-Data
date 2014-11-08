/*
This program reads sensor values (given by read_sensor_data) and sends them to the PC

 
 */


const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to
const int rolling_average_number = 200;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  int total = 0;
  int square_total = 0;
  for (int i=1;i <= rolling_average_number;i++){
    int sensor_value = read_sensor_data();
    total = total * (i/(i+1));
    square_total = square_total * (i/(i+1));
    total = total + (1/(i+1))* sensor_value; //run a rolling average
    square_total = square_total + (sensor_value ^ sensor_value) * (1/i);
    delay(2); // wait 2 milliseconds to let the ADC settle
  }
  // print the results to the serial monitor:                      
  int average = total;
  int square_average = square_total;
  int variance = abs(square_average - average^2);
  int standard_deviation = sqrt(variance);
  
  Serial.print("\nmean =");
  Serial.print(average);
  Serial.print("\nSD =");
  Serial.print(standard_deviation);
                 
}

int read_sensor_data(){
  return analogRead(analogInPin);
  }
