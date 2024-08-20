int led_pin1 = 2, buzz_pin = 3, echo_pin = 4, trig_pin = 5, led_pin2 = 6, distance;
 // Led1 is red, led2 is green


void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin1, OUTPUT);
  pinMode(buzz_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  Serial.begin(9600);

  // Turn leds off at start  
  digitalWrite(led_pin1, LOW);
  digitalWrite(buzz_pin, LOW);
  digitalWrite(led_pin2, LOW);
  // Turn the echo of the ultrasonic sensor off
  digitalWrite(echo_pin, LOW);
  // Turn off the buzzer at the beginning 
  noTone(buzz_pin);

};

void loop() {
  distance = getDistance();
  Serial.println("Intruder is: ");
  Serial.print(distance);
  Serial.println("cm away");
  if (distance < 12) {
    tone(buzz_pin, 600);
    digitalWrite(led_pin1, HIGH);
    digitalWrite(led_pin2, LOW);
    delay(1500);
  }
  else if (distance < 24 && distance > 12) {
      digitalWrite(led_pin2, HIGH); 
      delay(1500);
  } 

  noTone(buzz_pin);
  digitalWrite(led_pin1, LOW);
  digitalWrite(led_pin2, LOW);
};

int getDistance() {
  // Define variables
  long duration;
  int proximity;

   // Clear the trigPin
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo_pin, HIGH);

  // Calculate the distance in cm
  proximity = duration * 0.034 / 2;

  return proximity;
};