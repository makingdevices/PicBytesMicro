# MPLAB IDE generated this makefile for use with GNU make.
# Project: Pic Bytes Micro.mcp
# Date: Sun Aug 09 22:58:22 2020

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

Pic\ Bytes\ Micro.cof : main.o
	$(LD) /p18F4550 /l"C:\Program Files (x86)\Microchip\mplabc18\v3.47\lib" "main.o" /u_CRUNTIME /z__MPLAB_BUILD=1 /o"Pic Bytes Micro.cof" /M"Pic Bytes Micro.map" /W

main.o : main.c ../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/delays.h core.h snake.h main.c ../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f4550.h
	$(CC) -p=18F4550 "main.c" -fo="main.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "main.o" "Pic Bytes Micro.cof" "Pic Bytes Micro.hex"

