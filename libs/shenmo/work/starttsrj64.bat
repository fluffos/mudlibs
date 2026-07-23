@echo off
for /f "delims=" %%i in ('dir log /b /a-d /s ^|findstr /i /v "init.txt %~nx0"') do (del /f /q "%%i" 2>nul)
@echo on
fluffos64\driver.exe config.cfg