int a(0);
int lastbuttonstate(0); //#zero is not pressed and one is pressed.

void check(int x){ //checks if the number is even or odd
    if(x%2!=0){
      digitalWrite(3, HIGH); //led diode
      Serial.println(x);
  }else{
    digitalWrite(3, LOW);
    Serial.println(x);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); //a button
  pinMode(3, OUTPUT); //a led diode
}
 
void loop() {
  if(lastbuttonstate==0){ //makes sure that the button is not pressed.
    if(digitalRead(2)==LOW){
      a++;
      check(a);
      lastbuttonstate=1;
    }else{
      check(a);
    }
  }

  if(lastbuttonstate==1){  //check if the button IS presed
    if(digitalRead(2)==LOW){
      check(a);
    }else{
      lastbuttonstate=0;
      check(a);
    }
  }
  
  delay(100);
}
