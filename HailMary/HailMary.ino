int REnable = 5;
int LEnable = 6;

int RIn1 = 4;
int RIn2 = 3;
int LIn3 = 7;
int LIn4 = 8;

int leftLED = A1;
int rightLED = A0;

int MAX_SPEED = 175;
int SPEED_DIFF = 0;
bool forward = true;

//the threshold for 
int thresh = 100;
//constant to convert diff to PWM amount
int ratio  = 1;

int originalDifference = 0;

void setup() {
  //SAY GOODBYE TO THE WENCHES
  Serial.begin(9600);
  //TAKE THE HELM
  pinMode(REnable, OUTPUT);
  pinMode(LEnable, OUTPUT);
  pinMode(RIn1, OUTPUT);
  pinMode(RIn2, OUTPUT);
  pinMode(LIn3, OUTPUT);
  pinMode(LIn4, OUTPUT);
  //RAISE THE MAINSAIL
  digitalWrite(RIn1, forward);
  digitalWrite(LIn3, forward);
  //RAISE THE JIB
  digitalWrite(RIn2, !forward);
  digitalWrite(LIn4, !forward);
  //FULL SPEED AHEAD!!!
  analogWrite(REnable, MAX_SPEED);
  analogWrite(LEnable, MAX_SPEED);
  //AY AY CAPTAIN!!!
  originalDifference = getDifference();
}

int getDifference() {
  //return map(analogRead(leftLED), 470, 1023, 500, 1023) - map(analogRead(rightLED), 320, 1023, 500, 1023) +  originalDifference;
  return analogRead(leftLED) - analogRead(rightLED) -  originalDifference;
}

void loop() {
  //CHECK THE SEXTANT
  int diff = getDifference();
  if(diff > thresh){ //THE SEA BE BRINGING HER WORST!!!
    //BRING HER PORTSIDE!!!
    analogWrite(REnable, constrain(MAX_SPEED - (diff * ratio) - SPEED_DIFF, 0, 255));
    analogWrite(LEnable, MAX_SPEED);
    //AY AY CAPTAIN!!!
    
  } else if(thresh < (-1 * diff)){ //GIMME YOUR BEST YOU LAND LUBBERS!!!
    //VEER HER STARBOARD!!!
    analogWrite(REnable, MAX_SPEED - SPEED_DIFF);
    analogWrite(LEnable, constrain(MAX_SPEED + (diff * ratio), 0, 255)); //Note that diff is negative
    //AY AY CAPTAIN!!!
  } else { //PREPARE TO BOARD, YOU BILGE RATS!!!
    //FULL SPEED AHEAD!!!
    analogWrite(REnable, MAX_SPEED);
    analogWrite(LEnable, MAX_SPEED);
    //AY AY CAPTAIN!!!
  }
  //LET THE CREW REST!!!
  Serial.print("Sensor 1: ");
  Serial.print(analogRead(leftLED));//470
  Serial.print("   |||   Sensor 2: ");
  Serial.println(analogRead(rightLED)); //320
  Serial.print("DIFF: ");
  Serial.println(getDifference());
  delay(1);
}
