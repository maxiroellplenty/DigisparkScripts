//This DigiKeyboard Script downloads and sets a wallpaper through the Windows PowerShell. It has been tested successfully
//on Windows 10 and should probably work with Windows 7/8/8.1 etc.

// credits to https://github.com/CedArctic based on script & https://github.com/timmyrs for german layout

// move the german-key.h file into ~/Library/Arduino15/packages/digistump/hardware/avr/1.6.7/libraries/DigisparkKeyboard directory
#include "german-key.h" 
void setup() 
{
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  pn("powershell", 500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  pn("$client = new-object System.Net.WebClient", 500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  pn("$client.DownloadFile(\"https://tr3.cbsistatic.com/hub/i/2014/05/15/f8964afd-bd82-4e0e-bcbe-e927363dcdc1/3b858e39e2cf183b878f54cad0073a67/codedoge.jpg\" , \"doge.jpg\")", 500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  pn("reg add \"HKCU\\Control Panel\\Desktop\" /v WallPaper /d \"%USERPROFILE%\\doge.jpg\" /f", 500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  pn("RUNDLL32.EXE USER32.DLL,UpdatePerUserSystemParameters ,1 ,True");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() 
{
  
}
