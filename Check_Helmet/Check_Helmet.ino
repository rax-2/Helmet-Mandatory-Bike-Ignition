int infra_1 = 6;
int infra_2 = 7;
int gas = A5;

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  pinMode(infra_1,INPUT);
  pinMode(infra_2,INPUT);
  pinMode(gas,INPUT);

}

void loop() {
  delay(10); // Wait for 1 second

  Serial.print("Gas : ");
  Serial.println(analogRead(gas));

  Serial.print("IR 1 : ");
  Serial.println(digitalRead(infra_1));

  Serial.print("IR 2 : ");
  Serial.println(digitalRead(infra_2));
  
  delay(1000); // Wait for 1 second

}
