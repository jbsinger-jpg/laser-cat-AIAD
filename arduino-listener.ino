// Lib imports
//#include <Stepper.h>

// universal constants
#define DELAY_DUR 2

// vertical motor attrs
#define DIR_PIN 5
#define STEP_PIN 6

// horizontal motor attrs
#define DIR2_PIN 7
#define STEP2_PIN 8

void setup() {
 Serial.begin(9600);
 pinMode(DIR_PIN, OUTPUT);
 pinMode(STEP_PIN, OUTPUT);

 pinMode(DIR2_PIN, OUTPUT);
 pinMode(STEP2_PIN, OUTPUT);
}

void loop() {
 if (Serial.available() > 0) {
   String command = Serial.readStringUntil('z');
   Serial.print(command);

   if (command.startsWith("m0") && command.charAt(2) == 'b') {
       Serial.println("command: horizontal -180");
       digitalWrite(DIR2_PIN, LOW);  // CCW
        // Send signal to activate appropriate motor
       digitalWrite(STEP2_PIN, HIGH);
       digitalWrite(STEP_PIN, LOW);
   }
   else if (command.startsWith("m1") && command.charAt(2) == 'b') {
     Serial.println("command: vertical -180");
     digitalWrite(DIR_PIN, LOW);  // CCW
     // Send signal to activate appropriate motor
     digitalWrite(STEP2_PIN, LOW);
     digitalWrite(STEP_PIN, HIGH);
   }
   else if (command.startsWith("m0") && command.charAt(2) == 'f') {
     Serial.println("command: horizontal 180");
     digitalWrite(DIR2_PIN, HIGH);  // CW
     // Send signal to activate appropriate motor
     digitalWrite(STEP2_PIN, HIGH);
     digitalWrite(STEP_PIN, LOW);
   }
   else if (command.startsWith("m1") && command.charAt(2) == 'f') {
     Serial.println("command: vertical 180");
     digitalWrite(DIR_PIN, HIGH);  // CW
     // Send signal to activate appropriate motor
     digitalWrite(STEP2_PIN, LOW);
     digitalWrite(STEP_PIN, HIGH);
   }
   delay(1000 * DELAY_DUR);
 }
}
