int pin[] = {6,7,8,9,10,11,12};

void initDisplay(){
   pinMode(4, OUTPUT);
  for(int i = 0; i<7;i++){
    pinMode(pin[i], OUTPUT);
  }
}

void initSerial(){
  Serial.begin(9600);
}

void display(char digit){

 digitalWrite(pin[0], LOW);
 digitalWrite(pin[1], LOW);
 digitalWrite(pin[2], LOW);
 digitalWrite(pin[3], LOW);
 digitalWrite(pin[4], LOW);
 digitalWrite(pin[5], LOW);
 digitalWrite(pin[6], LOW);
  
  switch(digit){
    case '0': digitalWrite(pin[0], HIGH);
              digitalWrite(pin[1], HIGH);
              digitalWrite(pin[2], HIGH);
              digitalWrite(pin[3], HIGH);
              digitalWrite(pin[4], HIGH);
              digitalWrite(pin[5], HIGH);
              break;
    case '1': digitalWrite(pin[2], HIGH);
              digitalWrite(pin[3], HIGH);
              break;
    case '2': digitalWrite(pin[0], HIGH);
              digitalWrite(pin[1], HIGH);
              digitalWrite(pin[3], HIGH);
              digitalWrite(pin[4], HIGH);
              digitalWrite(pin[6], HIGH);
              break;
    case '3': digitalWrite(pin[4], HIGH);
              digitalWrite(pin[3], HIGH);
              digitalWrite(pin[6], HIGH);
              digitalWrite(pin[2], HIGH);
              digitalWrite(pin[1], HIGH);
              break;
    case '4': digitalWrite(pin[5], HIGH);
              digitalWrite(pin[6], HIGH);
              digitalWrite(pin[3], HIGH);
              digitalWrite(pin[2], HIGH);
              break;
    case '5': digitalWrite(pin[4], HIGH);
              digitalWrite(pin[5], HIGH);
              digitalWrite(pin[6], HIGH);
              digitalWrite(pin[2], HIGH);
              digitalWrite(pin[1], HIGH);
              break;
    case '6': digitalWrite(pin[0], HIGH);
              digitalWrite(pin[1], HIGH);
              digitalWrite(pin[2], HIGH);
              digitalWrite(pin[4], HIGH);
              digitalWrite(pin[5], HIGH);
              digitalWrite(pin[6], HIGH);
              break;
    case '7': digitalWrite(pin[4], HIGH);
              digitalWrite(pin[3], HIGH);
              digitalWrite(pin[2], HIGH);
              break;
    case '8': digitalWrite(pin[0], HIGH);
              digitalWrite(pin[1], HIGH);
              digitalWrite(pin[2], HIGH);
              digitalWrite(pin[3], HIGH);
              digitalWrite(pin[4], HIGH);
              digitalWrite(pin[5], HIGH);
              digitalWrite(pin[6], HIGH);
              break;
    case '9': digitalWrite(pin[1], HIGH);
              digitalWrite(pin[2], HIGH);
              digitalWrite(pin[3], HIGH);
              digitalWrite(pin[4], HIGH);
              digitalWrite(pin[5], HIGH);
              digitalWrite(pin[6], HIGH);
              break;
    default: break;
  }
}

void setup(){
  initDisplay();
  initSerial();
}


int getData(){
  if(Serial.available()){
    return Serial.read();
  }
}

void loop(){
  int resp = getData();
  delay(200);
  display(resp);
}
