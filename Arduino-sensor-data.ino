/*
This program reads sensor values (given by read_sensor_data) and sends them to the PC
 */


const int analogInPin = A0; 
const int rolling_average_number = 200; //number of iterations for the rolling average

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  int average = 0;
  int square_average = 0;
  for (int i=1;i <= rolling_average_number;i++){
    delay(2); // wait 2 milliseconds to let the ADC settle
    int sensor_value = read_sensor_data();
    average = (average * i + sensor_value)/(i+1); //run rolling average
    square_average = (square_average * i + (sensor_value*sensor_value))/(i+1); //run rolling average on the square of sensor value
  }
//calculte standard deviation                    
  int variance = abs(square_average - average^2); // E[x^2] - E[x]^2
  int standard_deviation = sqrt(variance);
  
// print the results to the serial monitor:  
  Serial.print("\nmean =");
  Serial.print(average);
  Serial.print("\nSD =");
  Serial.print(standard_deviation);
                 
}

int read_sensor_data(){
  return analogRead(analogInPin);
  }
