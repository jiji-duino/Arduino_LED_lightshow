enum LEDS {red1=8, yellow1=9, green1=10, red2=11, yellow2=12, green2=13, red3=2, green3=3, yellow3=4, red4=5, green4=6, yellow4=7}; // leds=pins
int leds1[] = {red1, yellow1, green1, red2, yellow2, green2, red3, green3, yellow3, red4, green4, yellow4};         // table of led enum first order
int leds2[] = {red3, green3, yellow3, red4, green4, yellow4, red1, yellow1, green1, red2, yellow2, green2};         // table of led enum second order
int leds3[] = {green1, yellow1, red1, yellow4, green4, red4};  // table of led enum third and fourth order
int leds4[] = {red2, yellow2, green2, red3, green3, yellow3};  // table of led enum third andfourth order
int alternate[] = {red1, green1, yellow2, red3, yellow3, green4, yellow4, yellow1, red2, green2, green3, red4}; // table of alternation order

int rows[4][6] = { {red1, yellow1, green1, red2, yellow2, green2} , {red3, yellow3, green3, red4, yellow4, green4}, {red1, yellow1, green1, red2, yellow2, green2} , {red3, yellow3, green3, red4, yellow4, green4} }; // table of rows (row1, row2, row1, row2)

int colors[3][4] = { {red1, red2, red3, red4} , {yellow1, yellow2, yellow3, yellow4} , {green1, green2, green3, green4} }; // table of colors order

int parity[6][2] = { {red1, yellow1} , {red4, yellow3} , {yellow2, green2} , {red3, green3} , {red2, green1} , {green4, yellow4} }; // table of parity order


void setup() {

  for (int i=0; i<12; i++) {
    pinMode(leds1[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("Type start to start the lightshow!");
}

void loop() {
  int count = 0;
  if (Serial.readString() == "start") {
    Serial.println("Show started!");
  //round 1

  // first order
    for (int i=0; i<12; i++) {
      digitalWrite(leds1[i], HIGH);
      delay(70);
    }
    for (int i=11; i>=0; i--) {
      digitalWrite(leds1[i], LOW);
      delay(70);
    }
    delay(150);

  // second order
    for (int i=0; i<12; i++) {
      digitalWrite(leds2[i], HIGH);
      delay(70);
    }
    for (int i=11; i>=0; i--) {
      digitalWrite(leds2[i], LOW);
      delay(70);
    }
    delay(150);

  //third order
    for (int i=0; i<6; i++) {
      digitalWrite(leds3[i], HIGH);
      digitalWrite(leds4[i], HIGH);
      delay(100);
    }
    for (int i=5; i>=0; i--) {
      digitalWrite(leds3[i], LOW);
      digitalWrite(leds4[i], LOW);
      delay(100);
    }
    delay(200);

  // fourth order
    for (int i=5; i>=0; i--) {
      digitalWrite(leds3[i], HIGH);
      digitalWrite(leds4[i], HIGH);
      delay(70);
    }
    for (int i=0; i<6; i++) {
      digitalWrite(leds3[i], LOW);
      digitalWrite(leds4[i], LOW);
      delay(100);
    }
    delay(200);

  // color order
    while (count != 2) {
      for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
          digitalWrite(colors[i][j], HIGH);
        }
        delay(150);

        for (int j=0; j<4; j++) {
          digitalWrite(colors[i][j], LOW);
        }
      }
      delay(200);
      count ++;
    }

  // row order
    for (int i=0; i<4; i++) {
      for (int j=0; j<6; j++) {
        digitalWrite(rows[i][j], HIGH);
      }
      delay(150);

      for (int j=0; j<6; j++) {
        digitalWrite(rows[i][j], LOW);
      }
    }
    delay(200);

  // parity order
    for (int i=0; i<6; i++) {
      for (int j=0; j<2; j++) {
        digitalWrite(parity[i][j], HIGH);
      }
      delay(150);
    }
    delay(200);

  
  // stop all
    for (int i=0; i<12; i++) {
      digitalWrite(leds1[i], LOW);
    }
    delay(1000);

  // alternation order
    for (int i=0; i<12; i++) {
      digitalWrite(alternate[i],HIGH);
      delay(150);
    }
    delay(200);

    for (int i=11; i>=0; i--) {
      digitalWrite(alternate[i],LOW);
    }
    delay(200);

  // Breathe IN (0 → 255)
    for (int b = 0; b <= 255; b++) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
          analogWrite(colors[i][j], b);
        }
      }
      delay(10);  // ← Inside brightness loop, outside LED loops
    }

  // Breathe OUT (255 → 0)  
    for (int b = 255; b >= 0; b--) {
      for (int i = 2; i >= 0; i--) {
        for (int j = 3; j >= 0; j--) {
          analogWrite(colors[i][j], b);
        }
      }
      delay(10);
    }
    delay(200);
  Serial.println("Show stopped!");
  }
}