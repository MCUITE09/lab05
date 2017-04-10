#include <SevSeg.h>
#include <Keypad.h>
SevSeg sevseg; 

void setup() {
  Serial.begin(9600); 
  byte numDigits =1;
  byte digitPins[] = {13};
  byte segmentPins[] = {A1,A2,A3,A4,A5,11,12,A0};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
}

const byte ROWS = 4;
const byte COLS = 4;
char key;
int k;
char keys[ROWS][COLS]={
  {'F','B','A','0'},
  {'E','3','2','1'},
  {'D','6','5','4'},
  {'C','9','8','7'}
};

byte rowPins[ROWS]={9,8,7,6};
byte colPins[COLS]={5,4,3,2};

Keypad keypad =Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void loop() {
key = keypad.getKey();
if (key != NO_KEY){
  if(key>='A' && key<='Z')
  k=key-'A';
else
  k=key-'0';
Serial.println(key);
sevseg.setNumber(k,0);
sevseg.refreshDisplay(); 
}
else
sevseg.refreshDisplay(); 
}
