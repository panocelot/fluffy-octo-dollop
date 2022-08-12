int a(0);
int lastbuttonstate(0); //#zero is not pressed and one is pressed.

void check(int x){
    if(x%2!=0){
      digitalWrite(3, HIGH);
      Serial.println(x);
  }else{
    digitalWrite(3, LOW);
    Serial.println(x);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
}
 
void loop() {
  if(lastbuttonstate==0){
    if(digitalRead(2)==LOW){
      a++;
      check(a);
      lastbuttonstate=1;
    }else{
      check(a);
    }
  }

  if(lastbuttonstate==1){
    if(digitalRead(2)==LOW){
      check(a);
    }else{
      lastbuttonstate=0;
      check(a);
    }
  }
  
  delay(100);
}
