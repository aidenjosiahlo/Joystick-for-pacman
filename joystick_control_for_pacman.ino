#include <Keyboard.h>

int xAxis = A0;
int yAxis = A1;
int button = A2;
int x;
int y;
int buttonState;

void setup() {
  pinMode(xAxis, INPUT);
  pinMode(yAxis, INPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  x = analogRead(xAxis);
  y = analogRead(yAxis);
  buttonState = analogRead(button);
  delay(5);

  if(x <= 200 and y <= 200){
    Keyboard.releaseAll();
  }

  if(x >= 800) {
    Keyboard.press(KEY_RIGHT_ARROW);
    Serial.println("RIGHT PRESSED");
  }

  if(x <= 400) {
    Keyboard.press(KEY_LEFT_ARROW);
    Serial.println("LEFT PRESSED");
  }

   if(y >= 800) {
    Keyboard.press(KEY_UP_ARROW);
    Serial.println("UP PRESSED");
  }
  
  if(y <= 400) {
    Keyboard.press(KEY_DOWN_ARROW);
    Serial.println("DOWN PRESSED");
  }

  if(buttonState == 255){
    Keyboard.releaseAll();
  }
}
  
