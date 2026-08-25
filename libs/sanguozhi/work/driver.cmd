@echo off
title 三国志@FLuffOS v2017
color 02

set DRIVER="%cd%\bin\driver.exe"
set CONFIG="%cd%\config.cfg"

%DRIVER% %CONFIG% %*

pause
