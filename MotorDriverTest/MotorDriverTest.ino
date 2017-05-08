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
  
}

void loop() {
  digitalWrite(RIn1, forward);
  digitalWrite(LIn3, forward);
  digitalWrite(RIn2, !forward);
  digitalWrite(LIn4, !forward);
  //go forward and backwards with both wheels
  for(int k = 0; k < 2; k++){
     //increase the speeds
    for(int j = 0; j <= 255; j++){
      analogWrite(REnable, j);
      analogWrite(LEnable, j);
      delay(10);
    }
    //decrease the speeds
    for(int j = 255; j >= 0; j--){
      analogWrite(REnable, j);
      analogWrite(LEnable, j);
      delay(10);
    }
    //go backwards
    forward = !forward;
  }

  //do the same thing but now have left wheel increase/decrease speed at half the rate and in the opposite direction
    digitalWrite(RIn1, forward);
    digitalWrite(LIn3, !forward);
    digitalWrite(RIn2, !forward);
    digitalWrite(LIn4, forward);
 for(int k = 0; k < 2; k++){
     //increase the speeds
    for(int j = 0; j <= 255; j++){
      analogWrite(REnable, j);
      analogWrite(LEnable, j/2);
      delay(10);
    }
    //decrease the speeds
    for(int j = 255; j >= 0; j--){
      analogWrite(REnable, j);
      analogWrite(LEnable, j/2);
      delay(10);
    }
    //go backwards
    forward = !forward;
  }
}
