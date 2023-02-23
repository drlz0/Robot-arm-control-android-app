/* Control robotic arm */
#include <Servo.h>
#include <SoftwareSerial.h>

#define servo1PIN 4
#define servo2PIN 5
#define servo3PIN 6
#define servo4PIN 7
#define servo5PIN 8
#define servo6PIN 9
#define RX_PIN 2
#define TX_PIN 3

/* creating servo objects */
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

SoftwareSerial Bluetooth(RX_PIN, TX_PIN); // RX, TX
int servo1_Npos, servo2_Npos, servo3_Npos, servo4_Npos, servo5_Npos, servo6_Npos; // new arduino position
int servo1_Ppos, servo2_Ppos, servo3_Ppos, servo4_Ppos, servo5_Ppos, servo6_Ppos; // previous position
String Rx_data = "";

void setup() {
  servo1.attach(servo1PIN);
  servo2.attach(servo2PIN);
  servo3.attach(servo3PIN);
  servo4.attach(servo4PIN);
  servo5.attach(servo5PIN);
  servo6.attach(servo6PIN);
  Bluetooth.begin(9600);
  Bluetooth.setTimeout(1);
  delay(20);

  /* initial position */
  servo1_Ppos = 90;
  servo1.write(servo1_Ppos); 
  servo2_Ppos = 90;
  servo2.write(servo2_Ppos);
  servo3_Ppos = 90;
  servo3.write(servo3_Ppos);
  servo4_Ppos = 90;
  servo4.write(servo4_Ppos);
  servo5_Ppos = 90;
  servo5.write(servo5_Ppos);
  servo6_Ppos = 90;
  servo6.write(servo6_Ppos);
}

void loop() {
  // Check for incoming data
  if (Bluetooth.available() > 0) {
    Rx_data = Bluetooth.readString(); // Read data string

    /* Servo 1 - Base Rotation */
    if (Rx_data.startsWith("s1")) {
      String Rx_dataS = Rx_data.substring(2, Rx_data.length()); // Extract only the number. E.g. from "s1120" to "120"
      servo1_Ppos = Rx_dataS.toInt();

      if (servo1_Ppos > servo1_Npos) {
        for (int i=servo1_Ppos; i>= servo1_Npos; i--)
        {
          servo1.write(i);
          delay(20);
        }
      }
      if (servo1_Ppos < servo1_Npos) {
        for (int i=servo1_Ppos; i>=servo1_Npos; i++)
        servo1.write(i);
        delay(20);
      }
      servo1_Ppos = servo1_Npos;
    }

    /* Servo 2 - Shoulder */
    if (Rx_data.startsWith("s2")) {
      String Rx_dataS = Rx_data.substring(2, Rx_data.length()); // Extract only the number. E.g. from "s1120" to "120"
      servo2_Ppos = Rx_dataS.toInt();

      if (servo2_Ppos > servo2_Npos) {
        for (int i=servo2_Ppos; i>= servo2_Npos; i--)
        {
          servo2.write(i);
          delay(20);
        }
      }
      if (servo2_Ppos < servo2_Npos) {
        for (int i=servo2_Ppos; i>=servo2_Npos; i++)
        servo2.write(i);
        delay(20);
      }
      servo2_Ppos = servo2_Npos;
    }

    /* Servo 3 - Elbow */
    if (Rx_data.startsWith("s3")) {
      String Rx_dataS = Rx_data.substring(2, Rx_data.length()); // Extract only the number. E.g. from "s1120" to "120"
      servo3_Ppos = Rx_dataS.toInt();

      if (servo3_Ppos > servo3_Npos) {
        for (int i=servo3_Ppos; i>= servo3_Npos; i--)
        {
          servo3.write(i);
          delay(20);
        }
      }
      if (servo3_Ppos < servo3_Npos) {
        for (int i=servo3_Ppos; i>=servo3_Npos; i++)
        servo3.write(i);
        delay(20);
      }
      servo3_Ppos = servo3_Npos;
    }

    /* Servo 4 - Hand Rotation */
    if (Rx_data.startsWith("s4")) {
      String Rx_dataS = Rx_data.substring(2, Rx_data.length()); // Extract only the number. E.g. from "s1120" to "120"
      servo4_Ppos = Rx_dataS.toInt();

      if (servo4_Ppos > servo4_Npos) {
        for (int i=servo4_Ppos; i>= servo4_Npos; i--)
        {
          servo4.write(i);
          delay(20);
        }
      }
      if (servo4_Ppos < servo4_Npos) {
        for (int i=servo4_Ppos; i>=servo4_Npos; i++)
        servo4.write(i);
        delay(20);
      }
      servo4_Ppos = servo4_Npos;
    }

    /* Servo 5 - Hand Up/Down */
    if (Rx_data.startsWith("s5")) {
      String Rx_dataS = Rx_data.substring(2, Rx_data.length()); // Extract only the number. E.g. from "s1120" to "120"
      servo5_Ppos = Rx_dataS.toInt();

      if (servo5_Ppos > servo5_Npos) {
        for (int i=servo5_Ppos; i>= servo5_Npos; i--)
        {
          servo5.write(i);
          delay(20);
        }
      }
      if (servo5_Ppos < servo5_Npos) {
        for (int i=servo5_Ppos; i>=servo5_Npos; i++)
        servo5.write(i);
        delay(20);
      }
      servo5_Ppos = servo5_Npos;
    }

    /* Servo 6 - Grab */
    if (Rx_data.startsWith("s6")) {
      String Rx_dataS = Rx_data.substring(2, Rx_data.length()); // Extract only the number. E.g. from "s1120" to "120"
      servo6_Ppos = Rx_dataS.toInt();

      if (servo6_Ppos > servo6_Npos) {
        for (int i=servo6_Ppos; i>= servo6_Npos; i--)
        {
          servo6.write(i);
          delay(20);
        }
      }
      if (servo6_Ppos < servo6_Npos) {
        for (int i=servo6_Ppos; i>=servo6_Npos; i++)
        servo6.write(i);
        delay(20);
      }
      servo6_Ppos = servo6_Npos;
    }

  }

}
