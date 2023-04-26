
/*
 * When the RGB is yellow green, you are relaxed.
 * When the RGB is red, you are angry.
 * When the RGB is purple, you are sad.
 */

  



// temp sensor variables
int tempSensPin = A0;  // variable for the temperature sensor pin
int tempRead = 0;  // variable for the signal the sensor returns

float volt = 0.0;  // variable to calculate the voltage of the returned signal
float tempC = 0.0; // variable for celcus
float tempF = 0.0; // variable for ferenhight

int red = 11;   // red pin for RGB
int green = 10; // green pin for RGB
int blue = 9;   // blue pin for RGB

void setup() {

  Serial.begin(9600); // setup serial monitor

  // setup RGB pins as output
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

}

void loop() {

  rgb(0,0,0,0); // reset RGB
  
  temp(); // get the tempuature
  
  if (tempF <= 70) {  // when the temp is , or is less than 70, blink purple
    
    for (int i = 0; i < 2; i++){ // do 2 times
      rgb(150,0,150,500); // turn purple for half a sec
      rgb(0,0,0,500); // trun off for half a sec
    }
  
  } else if (tempF > 70 && tempF <= 83 ) { // when the temp is or is more than 70, and is or is less than 83
    
    for (int i = 0; i < 2; i ++) { // do 2 times
      rgb(176, 240, 26, 500); // turn the rgb yellow green for half sec
      rgb(0,0,0,500); // turn RGB off for half sec
    }
  
  } else { // any other temp else
    
    for (int i = 0; i < 2; i ++){ // do 2 times
      rgb(255,0,0,500); // turn red for half a sec
      rgb(0,0,0,500); // turn off for half a sec
    }
  
  }

}



void rgb(int r,int g,int b, int waitTime) { // setup function

  analogWrite(red, r); // red pin
  analogWrite(green, g); // green pin
  analogWrite(blue, b); // blue pin

  delay(waitTime); // delay so the RGB has time to visabley turn on
  
}



void temp(){
  tempRead = analogRead(tempSensPin);  // read the sensor

  volt = (tempRead*5.0)/1024; // calculate the returned voltage of the sensor
  tempC = (volt - 0.5)*100;   // calculate celcius
  tempF = (tempC*9.0/5.0)+32.0;  // calculate farenhight

  Serial.print(tempF); // pint temperature in farenhight
  Serial.println(" F°");  // print the farenhight label

}
