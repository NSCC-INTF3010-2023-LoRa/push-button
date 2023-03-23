#include <SPI.h>
#include <RH_RF95.h>

RH_RF95 rf95;
int btn1 = A0;
int btn2 = A1;
int btn3 = A2;

void setup() {
  Serial.begin(9600);

  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  
  if (!rf95.init()) {
    Serial.println("RF95 init failed. Check your connections.");
    while (true); // halt
  }
  Serial.println("RF95 ready.");
}

void loop() {
  int button1 = digitalRead(btn1);
  int button2 = digitalRead(btn2);
  int button3 = digitalRead(btn3);
  
  // Client  
  Serial.println("Sending message...");
  // generate characters based on pressed buttens combinations
  if (button1 == 0 && button2 == 0 && button3 == 1){
    char message[] = "H";
    rf95.send((uint8_t *)message, sizeof(message));
  }

  if (button1 == 0 && button2 == 1 && button3 == 0){
    char message[] = "E";
    rf95.send((uint8_t *)message, sizeof(message));
  }

  if (button1 == 0 && button2 == 1 && button3 == 1){
    char message[] = "L";
    rf95.send((uint8_t *)message, sizeof(message));
  }
  if (button1 == 1 && button2 == 0 && button3 == 0){
    char message[] = "O";
    rf95.send((uint8_t *)message, sizeof(message));
  }

  if (button1 == 1 && button2 == 0 && button3 == 1){
    char message[] = "S";
    rf95.send((uint8_t *)message, sizeof(message));
  }

  if (button1 == 1 && button2 == 1 && button3 == 0){
    char message[] = "A";
    rf95.send((uint8_t *)message, sizeof(message));
  }

  // to add spaces between words
  if (button1 == 1 && button2 == 1 && button3 == 1){
    char message[] = " ";
    rf95.send((uint8_t *)message, sizeof(message));
  }
  
  else {
    char message[] = "";
    rf95.send((uint8_t *)message, sizeof(message));
  }
  
  if (rf95.waitPacketSent()) {
    Serial.println("Message sent.");
  }

  delay(300);
}
