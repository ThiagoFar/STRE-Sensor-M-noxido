const int AOUTpin=0;
const int DOUTpin=8;
const int greenPin=12;
const int buzzer = 13;

int limit;
int value;
int ctr=0;


void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(DOUTpin,INPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(buzzer, OUTPUT);
 limit = 400;
}

void loop() {
  digitalWrite(greenPin, HIGH);
  if (ctr==0){
    delay(1000);
    
    }
    ctr=0;
  value= analogRead(AOUTpin);
 // limit=digitalRead(DOUTpin);
  Serial.print("Limit: ");
  Serial.print(limit);
  Serial.print(" ");
  
  Serial.print("CO value: ");
  Serial.print(value);
  Serial.print(" ");
  
  delay(100);
  if (value >= limit){
  Serial.println("Alarm");
  //sequencia de barulho
  digitalWrite(greenPin, HIGH);
  tone(buzzer, 1000);  
  delay(400);     
  digitalWrite(greenPin, LOW);                                                           
  noTone(buzzer);                     
  delay(100);  

  digitalWrite(greenPin, HIGH);
  tone(buzzer, 1000);  
  delay(400);      
  digitalWrite(greenPin, LOW);                                                          
  noTone(buzzer);                     
  delay(100);  
  ctr=1;
}else{
  Serial.println("OK");
}

}
