
#define LED_ROT 3          
#define LED_ORANGE 4
#define LED_GRUEN 5


#define RELAY_ROT 9                  
#define RELAY_ORANGE 10                   
#define RELAY_GRUEN 11


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(LED_ROT, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_GRUEN, OUTPUT);
  
  pinMode(RELAY_ROT, OUTPUT);
  pinMode(RELAY_ORANGE, OUTPUT);
  pinMode(RELAY_GRUEN, OUTPUT);  
}

void loop() {
  digitalWrite(RELAY_ROT,LOW);
  digitalWrite(RELAY_ORANGE,LOW);
  digitalWrite(RELAY_GRUEN,LOW);
  delay(1000);
  
  // put your main code here, to run repeatedly:
  digitalWrite(LED_ROT,HIGH);
  digitalWrite(RELAY_ROT,HIGH);
  delay (2000);
  digitalWrite(LED_ORANGE,HIGH);
  digitalWrite(RELAY_ORANGE,HIGH);
  delay (1000);
  digitalWrite(LED_ROT,LOW);
  digitalWrite(RELAY_ROT,LOW);
  digitalWrite(LED_ORANGE,LOW);
  digitalWrite(RELAY_ORANGE,LOW);
  digitalWrite(LED_GRUEN,HIGH);
  digitalWrite(RELAY_GRUEN,HIGH);
  delay(2000);
  digitalWrite(LED_GRUEN,LOW);
  digitalWrite(RELAY_GRUEN,LOW);
  digitalWrite(LED_ORANGE,HIGH);
  digitalWrite(RELAY_ORANGE,HIGH);
  delay(1000);
  digitalWrite(LED_ORANGE,LOW);
  digitalWrite(RELAY_ORANGE,LOW);
}
