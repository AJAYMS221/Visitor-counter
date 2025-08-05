#define e_s1 A0 // echo pin
#define t_s1 A1 // trigger pin

#define e_s2 A2 // echo pin
#define t_s2 A3 // trigger pin

int relay = 8; // Output for light
int motor = 9; // Output for motor

long dis_a = 0, dis_b = 0;
int flag1 = 0, flag2 = 0;
int person = 0;

//*ultra_read***************************
void ultra_read(int pin_t, int pin_e, long &ultra_time) {
  long time;
  pinMode(pin_t, OUTPUT);
  pinMode(pin_e, INPUT);
  digitalWrite(pin_t, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_t, HIGH);
  delayMicroseconds(5);
  time = pulseIn(pin_e, HIGH);
  ultra_time = time / 29 / 2;
}

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(relay, OUTPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  ultra_read(t_s1, e_s1, dis_a); delay(30);
  ultra_read(t_s2, e_s2, dis_b); delay(30);

  Serial.print("Distance A: "); Serial.println(dis_a);
  Serial.print("Distance B: "); Serial.println(dis_b);

  if (dis_a < 30 && flag1 == 0) {
    flag1 = 1;
    if (flag2 == 0) person++;
  }

  if (dis_b < 30 && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) person--;
  }

  if (dis_a > 30 && dis_b > 30 && flag1 == 1 && flag2 == 1) {
    flag1 = 0;
    flag2 = 0;
    delay(10);
  }

  if (person > 0) {
    digitalWrite(relay, HIGH);
    Serial.println("Light is ON");
  } else {
    digitalWrite(relay, LOW);
    Serial.println("Light is OFF");
  }

  // Motor control based on relay state
  if (digitalRead(relay) == HIGH) {
    digitalWrite(motor, HIGH); // Run motor
    Serial.println("Motor is ON");
  } else {
    digitalWrite(motor, LOW);  // Stop motor
    Serial.println("Motor is OFF");
  }

  Serial.print("People Count: ");
  Serial.println(person);
  Serial.println("----------------------");

  delay(30); // optional delay for readability
}
