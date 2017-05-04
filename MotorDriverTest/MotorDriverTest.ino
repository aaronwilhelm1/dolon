int REnable = 5;
int LEnable = 6;

int RIn1 = 3;
int RIn2 = 4;
int LIn3 = 8;
int LIn4 = 7;

bool forward = true;

void setup() {
  pinMode(REnable, OUTPUT);
  pinMode(LEnable, OUTPUT);
  pinMode(RIn1, OUTPUT);
  pinMode(RIn2, OUTPUT);
  pinMode(LIn3, OUTPUT);
  pinMode(LIn4, OUTPUT);
  digitalWrite(RIn1, forward);
  digitalWrite(LIn3, forward);
  digitalWrite(RIn2, !forward);
  digitalWrite(LIn4, !forward);
  
}

void loop() {
  
  for(int j = 0; j <= 255; j++){
    analogWrite(REnable, j);
    analogWrite(LEnable, j);
    delay(10);
  }
  for(int j = 255; j >= 0; j--){
    analogWrite(REnable, j);
    analogWrite(LEnable, j);
    delay(10);
  }

  forward = !forward;
  
  digitalWrite(RIn1, forward);
  digitalWrite(LIn3, forward);
  digitalWrite(RIn2, !forward);
  digitalWrite(LIn4, !forward);
}
