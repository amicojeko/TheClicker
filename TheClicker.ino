
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

boolean clicking = false;
boolean reading = false;


int buttonState = 0;         


void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);     
}

void loop(){

  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && !reading) {     
    clicking = !clicking;
    reading = true;
    Serial.println("click");
  } 
  
  if (buttonState == HIGH){
    reading = false;
  }

  if(clicking){
    digitalWrite(ledPin, HIGH);
    Mouse.press(MOUSE_LEFT); 
    delay(10);
    Mouse.release(MOUSE_LEFT);
  }

}
