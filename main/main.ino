#define pinSwitch 9  // Pin that controls the switch (on/off)
#define pin1 3       //
#define pin2 4       //
#define pin3 6       //
#define pin4 7       //
#define pinSenL 2    // Left pin of reflectance sensor
#define pinSenR 11   // Right pin of reflectance sensor

void setup() {
  Serial.begin(9600);

  pinMode(pinSwitch, INPUT_PULLUP);

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);

  pinMode(pinSenL, INPUT);
  pinMode(pinSenL, INPUT);
}

void loop() {
  int switchStatus = digitalRead(pinSwitch);

  int senStatusL = digitalRead(pinSenL);
  int senStatusR = digitalRead(pinSenR);

  switch (switchStatus) {
    case HIGH:
      Serial.println("ON");
      moveToFront();
      break;
    case LOW:
      Serial.println("OFF");
      stopMoving();
      break;
    default:
      Serial.println("The status of the switch is unknown.");
      stopMoving();
  }
}
