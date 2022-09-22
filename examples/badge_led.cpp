#define PIN_RGB_RED 0
#define PIN_RGB_GREEN 1
#define PIN_RGB_BLUE 2

#define VALUES (uint8_t) (255,0,0)
#define redIndex uint8_t 0
#define greenIndex uint8_t 1
#define blueIndex uint8_t 2

void setup(){
  pinMode(PIN_RGB_RED, OUTPUT);
  pinMode(PIN_RGB_GREEN, OUTPUT);
  pinMode(PIN_RGB_BLUE, OUTPUT);

}

void loop() {
  analogWrite(PIN_RGB_RED, redIndex);
  analogWrite(PIN_RGB_GREEN, greenIndex);
  analogWrite(PIN_RGB_BLUE, blueIndex);
  redIndex += 1;
  greenIndex += 1;
  blueIndex += 1;
}