EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title "PicBytes Micro - General"
Date "2020-12-30"
Rev "V0.1"
Comp "Making Devices"
Comment1 "Rubén G.S."
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 2050 1750 1300 1300
U 5FEC722B
F0 "LED MATRIX" 50
F1 "Screen.sch" 50
F2 "Vcc_screen" I L 2050 1850 50 
F3 "CC1" I L 2050 2050 50 
F4 "CC2" I L 2050 2150 50 
F5 "CC3" I L 2050 2250 50 
F6 "CC4" I L 2050 2350 50 
F7 "CC5" I L 2050 2450 50 
F8 "CC6" I L 2050 2550 50 
F9 "CC7" I L 2050 2650 50 
F10 "CC8" I L 2050 2750 50 
F11 "CC9" I L 2050 2850 50 
F12 "CC10" I L 2050 2950 50 
F13 "CR0" I R 3350 1850 50 
F14 "CR1" I R 3350 1950 50 
F15 "CR2" I R 3350 2050 50 
F16 "CR3" I R 3350 2150 50 
F17 "CR4" I R 3350 2250 50 
F18 "CR5" I R 3350 2350 50 
F19 "CR6" I R 3350 2450 50 
F20 "CR7" I R 3350 2550 50 
F21 "UN" I R 3350 2650 50 
F22 "DN" I R 3350 2750 50 
F23 "Vgnd_screen" I R 3350 2950 50 
$EndSheet
$Comp
L PicBytesMicro-rescue:PIC18F45K50-I_PT-SamacSys_Parts PIC18F45K50
U 1 1 6124E0BF
P 7600 2750
F 0 "PIC18F45K50" H 9444 2146 50  0000 L CNN
F 1 "PIC18F45K50-I_PT" H 9444 2055 50  0001 L CNN
F 2 "QFP80P1200X1200X120-44N" H 9250 3350 50  0001 L CNN
F 3 "http://uk.rs-online.com/web/p/products/7864031P" H 9250 3250 50  0001 L CNN
F 4 "Microchip PIC18F45K50-I/PT, 8bit PIC Microcontroller, 48MHz, 32 kB Flash, 44-Pin TQFP" H 9250 3150 50  0001 L CNN "Description"
F 5 "1.2" H 9250 3050 50  0001 L CNN "Height"
F 6 "7864031P" H 9250 2950 50  0001 L CNN "RS Part Number"
F 7 "http://uk.rs-online.com/web/p/products/7864031P" H 9250 2850 50  0001 L CNN "RS Price/Stock"
F 8 "Microchip" H 9250 2750 50  0001 L CNN "Manufacturer_Name"
F 9 "PIC18F45K50-I/PT" H 9250 2650 50  0001 L CNN "Manufacturer_Part_Number"
F 10 "70323053" H 9250 2550 50  0001 L CNN "Allied_Number"
	1    7600 2750
	1    0    0    -1  
$EndComp
Text GLabel 7450 3450 0    50   Input ~ 0
P_CR0
Text GLabel 7450 3550 0    50   Input ~ 0
P_CR1
Text GLabel 7450 3650 0    50   Input ~ 0
P_CR2
Text GLabel 7450 3750 0    50   Input ~ 0
P_CR3
Text GLabel 8200 4950 3    50   Input ~ 0
P_CR4
Text GLabel 8300 4950 3    50   Input ~ 0
P_CR5
Text GLabel 8400 4950 3    50   Input ~ 0
P_CR6
Text GLabel 8500 4950 3    50   Input ~ 0
P_CR7
Wire Wire Line
	7450 3450 7600 3450
Wire Wire Line
	7600 3550 7450 3550
Wire Wire Line
	7450 3650 7600 3650
Wire Wire Line
	7600 3750 7450 3750
Wire Wire Line
	8200 4950 8200 4850
Wire Wire Line
	8300 4950 8300 4850
Wire Wire Line
	8400 4950 8400 4850
Wire Wire Line
	8500 4950 8500 4850
Text GLabel 3450 1850 2    50   Input ~ 0
P_CR0
Text GLabel 3450 1950 2    50   Input ~ 0
P_CR1
Text GLabel 3450 2050 2    50   Input ~ 0
P_CR2
Text GLabel 3450 2150 2    50   Input ~ 0
P_CR3
Text GLabel 3450 2250 2    50   Input ~ 0
P_CR4
Text GLabel 3450 2350 2    50   Input ~ 0
P_CR5
Text GLabel 3450 2450 2    50   Input ~ 0
P_CR6
Text GLabel 3450 2550 2    50   Input ~ 0
P_CR7
Text GLabel 3450 2650 2    50   Input ~ 0
P_UN
Text GLabel 3450 2750 2    50   Input ~ 0
P_DN
Text GLabel 1950 1850 0    50   Input ~ 0
Vcc_main
Text GLabel 3450 2950 2    50   Input ~ 0
Vgnd_main
Text GLabel 1950 2050 0    50   Input ~ 0
P_CC1
Text GLabel 1950 2150 0    50   Input ~ 0
P_CC2
Text GLabel 1950 2250 0    50   Input ~ 0
P_CC3
Text GLabel 1950 2350 0    50   Input ~ 0
P_CC4
Text GLabel 1950 2450 0    50   Input ~ 0
P_CC5
Text GLabel 1950 2550 0    50   Input ~ 0
P_CC6
Text GLabel 1950 2650 0    50   Input ~ 0
P_CC7
Text GLabel 1950 2750 0    50   Input ~ 0
P_CC8
Text GLabel 1950 2850 0    50   Input ~ 0
P_CC9
Text GLabel 1950 2950 0    50   Input ~ 0
P_CC10
Wire Wire Line
	3450 1850 3350 1850
Wire Wire Line
	3450 1950 3350 1950
Wire Wire Line
	3450 2050 3350 2050
Wire Wire Line
	3450 2150 3350 2150
Wire Wire Line
	3450 2250 3350 2250
Wire Wire Line
	3350 2350 3450 2350
Wire Wire Line
	3450 2450 3350 2450
Wire Wire Line
	3350 2550 3450 2550
Wire Wire Line
	3450 2650 3350 2650
Wire Wire Line
	3350 2750 3450 2750
Wire Wire Line
	3450 2950 3350 2950
Wire Wire Line
	2050 1850 1950 1850
Wire Wire Line
	2050 2050 1950 2050
Wire Wire Line
	1950 2150 2050 2150
Wire Wire Line
	2050 2250 1950 2250
Wire Wire Line
	1950 2350 2050 2350
Wire Wire Line
	2050 2450 1950 2450
Wire Wire Line
	1950 2550 2050 2550
Wire Wire Line
	2050 2650 1950 2650
Wire Wire Line
	1950 2750 2050 2750
Wire Wire Line
	2050 2850 1950 2850
Wire Wire Line
	1950 2950 2050 2950
Text GLabel 7400 3150 0    50   Input ~ 0
P_CC1
Text GLabel 7400 3050 0    50   Input ~ 0
P_CC2
Text GLabel 7400 2950 0    50   Input ~ 0
P_CC3
Text GLabel 7400 2850 0    50   Input ~ 0
P_CC4
Text GLabel 8300 1850 1    50   Input ~ 0
P_CC5
Text GLabel 8400 1850 1    50   Input ~ 0
P_CC6
Text GLabel 8500 1850 1    50   Input ~ 0
P_CC7
Text GLabel 8600 1850 1    50   Input ~ 0
P_CC8
Text GLabel 7400 2750 0    50   Input ~ 0
P_CC9
Text GLabel 8000 1850 1    50   Input ~ 0
P_CC10
Text GLabel 10250 3450 2    50   Input ~ 0
P_UN
Text GLabel 10250 3550 2    50   Input ~ 0
P_DN
Wire Wire Line
	10250 3450 9400 3450
Wire Wire Line
	9400 3550 10250 3550
Wire Wire Line
	8600 1850 8600 1950
Wire Wire Line
	8500 1850 8500 1950
Wire Wire Line
	8400 1850 8400 1950
Wire Wire Line
	8300 1850 8300 1950
Wire Wire Line
	8000 1850 8000 1950
Wire Wire Line
	7600 2750 7400 2750
Wire Wire Line
	7400 2850 7600 2850
Wire Wire Line
	7600 2950 7400 2950
Wire Wire Line
	7400 3050 7600 3050
Wire Wire Line
	7600 3150 7400 3150
$Sheet
S 2150 4400 800  1050
U 600718E8
F0 "Dpad" 50
F1 "Dpad.sch" 50
F2 "Up" I L 2150 4550 50 
F3 "Down" I L 2150 4700 50 
F4 "Right" I L 2150 4850 50 
F5 "Left" I L 2150 5000 50 
F6 "A" I L 2150 5200 50 
F7 "B" I L 2150 5350 50 
F8 "Dpad_Vcc" I R 2950 4600 50 
F9 "Dpad_gnd" I R 2950 4750 50 
$EndSheet
Text GLabel 3050 4750 2    50   Input ~ 0
Vgnd_main
Wire Wire Line
	3050 4750 2950 4750
Text GLabel 3050 4600 2    50   Input ~ 0
Vcc_main
Wire Wire Line
	3050 4600 2950 4600
Text GLabel 2050 4700 0    50   Input ~ 0
S_down
Text GLabel 2050 4550 0    50   Input ~ 0
S_up
Text GLabel 2050 4850 0    50   Input ~ 0
S_right
Text GLabel 2050 5000 0    50   Input ~ 0
S_left
Text GLabel 2050 5200 0    50   Input ~ 0
S_a
Text GLabel 2050 5350 0    50   Input ~ 0
S_b
Wire Wire Line
	2150 4550 2050 4550
Wire Wire Line
	2150 4700 2050 4700
Wire Wire Line
	2050 4850 2150 4850
Wire Wire Line
	2150 5000 2050 5000
Wire Wire Line
	2050 5200 2150 5200
Wire Wire Line
	2150 5350 2050 5350
Text GLabel 8700 4950 3    50   Input ~ 0
S_up
Text GLabel 8800 4950 3    50   Input ~ 0
S_down
Text GLabel 8900 4950 3    50   Input ~ 0
S_left
Text GLabel 9000 4950 3    50   Input ~ 0
S_right
Text GLabel 9500 3750 2    50   Input ~ 0
S_a
Text GLabel 9500 3650 2    50   Input ~ 0
S_b
Wire Wire Line
	9500 3650 9400 3650
Wire Wire Line
	9500 3750 9400 3750
Wire Wire Line
	9000 4950 9000 4850
Wire Wire Line
	8900 4950 8900 4850
Wire Wire Line
	8800 4950 8800 4850
Wire Wire Line
	8700 4950 8700 4850
$Comp
L PicBytesMicro-rescue:KTR10EZPF4220-SamacSys_Parts R_10k_1
U 1 1 600DC8FC
P 7900 5550
F 0 "R_10k_1" H 8250 5775 50  0000 C CNN
F 1 "KTR10EZPF4220" H 8250 5684 50  0001 C CNN
F 2 "RESC2012X65N" H 8450 5600 50  0001 L CNN
F 3 "http://rohmfs.rohm.com/en/products/databook/datasheet/passive/resistor/chip_resistor/ktr.pdf" H 8450 5500 50  0001 L CNN
F 4 "ROHM 0805 Resistor Chip" H 8450 5400 50  0001 L CNN "Description"
F 5 "0.65" H 8450 5300 50  0001 L CNN "Height"
F 6 "" H 8450 5200 50  0001 L CNN "RS Part Number"
F 7 "" H 8450 5100 50  0001 L CNN "RS Price/Stock"
F 8 "ROHM Semiconductor" H 8450 5000 50  0001 L CNN "Manufacturer_Name"
F 9 "KTR10EZPF4220" H 8450 4900 50  0001 L CNN "Manufacturer_Part_Number"
	1    7900 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 5550 8600 4850
Text GLabel 7900 5550 0    50   Input ~ 0
Vcc_main
Text GLabel 7450 3350 0    50   Input ~ 0
Vcc_main
Text GLabel 7450 3250 0    50   Input ~ 0
Vgnd_main
Wire Wire Line
	7600 3350 7450 3350
Wire Wire Line
	7450 3250 7600 3250
$Comp
L PicBytesMicro-rescue:SMMBT5551LT1G-SamacSys_Parts Q?
U 1 1 6014F4C8
P 5400 2300
AR Path="/5FEC722B/6014F4C8" Ref="Q?"  Part="1" 
AR Path="/6014F4C8" Ref="Q29"  Part="1" 
F 0 "Q29" H 5938 2346 50  0000 L CNN
F 1 "SMMBT5551LT1G" H 5938 2255 50  0000 L CNN
F 2 "SOT96P237X111-3N" H 5950 2150 50  0001 L CNN
F 3 "http://uk.rs-online.com/web/p/products/1841498P" H 5950 2050 50  0001 L CNN
F 4 "NPN Bipolar Transistor, 600 mA 160 V, 3-pin SOT-23" H 5950 1950 50  0001 L CNN "Description"
F 5 "1.11" H 5950 1850 50  0001 L CNN "Height"
F 6 "1841498P" H 5950 1750 50  0001 L CNN "RS Part Number"
F 7 "http://uk.rs-online.com/web/p/products/1841498P" H 5950 1650 50  0001 L CNN "RS Price/Stock"
F 8 "ON Semiconductor" H 5950 1550 50  0001 L CNN "Manufacturer_Name"
F 9 "SMMBT5551LT1G" H 5950 1450 50  0001 L CNN "Manufacturer_Part_Number"
F 10 "70300580" H 5950 1350 50  0001 L CNN "Allied_Number"
	1    5400 2300
	1    0    0    -1  
$EndComp
$Comp
L PicBytesMicro-rescue:KTR10EZPF4220-SamacSys_Parts R4K7_?
U 1 1 6014F4D4
P 4600 2300
AR Path="/5FEC722B/6014F4D4" Ref="R4K7_?"  Part="1" 
AR Path="/6014F4D4" Ref="R4K7_29"  Part="1" 
F 0 "R4K7_29" H 4950 2525 50  0000 C CNN
F 1 "KTR10EZPF4220" H 4950 2434 50  0000 C CNN
F 2 "RESC2012X65N" H 5150 2350 50  0001 L CNN
F 3 "http://rohmfs.rohm.com/en/products/databook/datasheet/passive/resistor/chip_resistor/ktr.pdf" H 5150 2250 50  0001 L CNN
F 4 "ROHM 0805 Resistor Chip" H 5150 2150 50  0001 L CNN "Description"
F 5 "0.65" H 5150 2050 50  0001 L CNN "Height"
F 6 "" H 5150 1950 50  0001 L CNN "RS Part Number"
F 7 "" H 5150 1850 50  0001 L CNN "RS Price/Stock"
F 8 "ROHM Semiconductor" H 5150 1750 50  0001 L CNN "Manufacturer_Name"
F 9 "KTR10EZPF4220" H 5150 1650 50  0001 L CNN "Manufacturer_Part_Number"
	1    4600 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2300 5300 2300
Wire Wire Line
	4600 2300 4500 2300
$Comp
L PicBytesMicro-rescue:TMB12A05-SamacSys_Parts LS1
U 1 1 60153C61
P 5800 3250
F 0 "LS1" H 6092 2885 50  0000 C CNN
F 1 "TMB12A05" H 6092 2976 50  0000 C CNN
F 2 "TMB12A05" H 6450 3350 50  0001 L CNN
F 3 "https://datasheet.lcsc.com/szlcsc/Jiangsu-Huaneng-Elec-TMB12A05_C96093.pdf" H 6450 3250 50  0001 L CNN
F 4 "12*9.5 Buzzers RoHS" H 6450 3150 50  0001 L CNN "Description"
F 5 "9.5" H 6450 3050 50  0001 L CNN "Height"
F 6 "" H 6450 2950 50  0001 L CNN "RS Part Number"
F 7 "" H 6450 2850 50  0001 L CNN "RS Price/Stock"
F 8 "Jiangsu Huaneng Elec" H 6450 2750 50  0001 L CNN "Manufacturer_Name"
F 9 "TMB12A05" H 6450 2650 50  0001 L CNN "Manufacturer_Part_Number"
	1    5800 3250
	-1   0    0    1   
$EndComp
Wire Wire Line
	5800 2600 5800 3150
Text GLabel 5800 3250 2    50   Input ~ 0
Vgnd_main
Text GLabel 5800 1750 0    50   Input ~ 0
Vcc_main
Wire Wire Line
	5800 1750 5800 2000
Text GLabel 8800 1850 1    50   Input ~ 0
Buzzer
Wire Wire Line
	8800 1850 8800 1950
Text GLabel 4500 2200 1    50   Input ~ 0
Buzzer
Wire Wire Line
	4500 2300 4500 2200
$Sheet
S 5200 4750 650  300 
U 6009E6F5
F0 "BMS" 50
F1 "BatteryCharger.sch" 50
F2 "BMS_gnd" I L 5200 4900 50 
F3 "5V" I R 5850 4900 50 
$EndSheet
Text GLabel 5200 4900 0    50   Input ~ 0
Vgnd_main
Text GLabel 5850 4900 2    50   Input ~ 0
Vcc_main
$Comp
L PicBytesMicro-rescue:AS-16.000MAHK-B-SamacSys_Parts 16MhzCrystal1
U 1 1 600A0DA2
P 9800 2950
F 0 "16MhzCrystal1" H 10292 3123 50  0000 C CNN
F 1 "AS-16.000MAHK-B" H 10292 3124 50  0001 C CNN
F 2 "AS16000MAHKB" H 10850 3050 50  0001 L CNN
F 3 "https://componentsearchengine.com/Datasheets/1/AS-16.000MAHK-B.pdf" H 10850 2950 50  0001 L CNN
F 4 "Crystal 16MHz +/-30ppm (Tol) +/-30ppm (Stability) 20pF FUND 60Ohm Automotive 2-Pin HC-49/S Thru-Hole Bulk" H 10850 2850 50  0001 L CNN "Description"
F 5 "3.68" H 10850 2750 50  0001 L CNN "Height"
F 6 "" H 10850 2650 50  0001 L CNN "RS Part Number"
F 7 "" H 10850 2550 50  0001 L CNN "RS Price/Stock"
F 8 "TXC" H 10850 2450 50  0001 L CNN "Manufacturer_Name"
F 9 "AS-16.000MAHK-B" H 10850 2350 50  0001 L CNN "Manufacturer_Part_Number"
	1    9800 2950
	1    0    0    -1  
$EndComp
Text GLabel 9400 3250 2    50   Input ~ 0
Vcc_main
Text GLabel 9400 3150 2    50   Input ~ 0
Vgnd_main
NoConn ~ 8900 1950
NoConn ~ 8700 1950
NoConn ~ 8200 1950
NoConn ~ 8100 1950
Wire Wire Line
	9800 3050 9750 3050
Wire Wire Line
	9800 2950 9500 2950
$Comp
L PicBytesMicro-rescue:GCG21BR71H154KA01K-SamacSys_Parts C_22p_1
U 1 1 600B27D4
P 9500 2200
F 0 "C_22p_1" H 9750 2328 50  0000 L CNN
F 1 "GCG21BR71H154KA01K" V 9795 2328 50  0001 L CNN
F 2 "CAPC2012X145N" H 9850 2250 50  0001 L CNN
F 3 "https://psearch.en.murata.com/capacitor/product/GCG21BR71H154KA01%23.html" H 9850 2150 50  0001 L CNN
F 4 "Capacitor L=2.0mm W=1.25mm T=1.25mm" H 9850 2050 50  0001 L CNN "Description"
F 5 "1.45" H 9850 1950 50  0001 L CNN "Height"
F 6 "" H 9850 1850 50  0001 L CNN "RS Part Number"
F 7 "" H 9850 1750 50  0001 L CNN "RS Price/Stock"
F 8 "Murata Electronics" H 9850 1650 50  0001 L CNN "Manufacturer_Name"
F 9 "GCG21BR71H154KA01K" H 9850 1550 50  0001 L CNN "Manufacturer_Part_Number"
	1    9500 2200
	0    1    1    0   
$EndComp
$Comp
L PicBytesMicro-rescue:GCG21BR71H154KA01K-SamacSys_Parts C_22p_2
U 1 1 600B8862
P 9750 2200
F 0 "C_22p_2" H 10000 2328 50  0000 L CNN
F 1 "GCG21BR71H154KA01K" V 10045 2328 50  0001 L CNN
F 2 "CAPC2012X145N" H 10100 2250 50  0001 L CNN
F 3 "https://psearch.en.murata.com/capacitor/product/GCG21BR71H154KA01%23.html" H 10100 2150 50  0001 L CNN
F 4 "Capacitor L=2.0mm W=1.25mm T=1.25mm" H 10100 2050 50  0001 L CNN "Description"
F 5 "1.45" H 10100 1950 50  0001 L CNN "Height"
F 6 "" H 10100 1850 50  0001 L CNN "RS Part Number"
F 7 "" H 10100 1750 50  0001 L CNN "RS Price/Stock"
F 8 "Murata Electronics" H 10100 1650 50  0001 L CNN "Manufacturer_Name"
F 9 "GCG21BR71H154KA01K" H 10100 1550 50  0001 L CNN "Manufacturer_Part_Number"
	1    9750 2200
	0    1    1    0   
$EndComp
Wire Wire Line
	9750 3050 9750 2700
Connection ~ 9750 3050
Wire Wire Line
	9750 3050 9400 3050
Wire Wire Line
	9500 2700 9500 2950
Connection ~ 9500 2950
Wire Wire Line
	9500 2950 9400 2950
Wire Wire Line
	9750 2200 9750 2150
Wire Wire Line
	9750 2150 9600 2150
Wire Wire Line
	9500 2150 9500 2200
Text GLabel 9600 2000 2    50   Input ~ 0
Vgnd_main
Wire Wire Line
	9600 2000 9600 2150
Connection ~ 9600 2150
Wire Wire Line
	9600 2150 9500 2150
Wire Notes Line
	10900 950  10900 5950
Wire Notes Line
	6700 5950 6700 950 
Wire Notes Line
	4200 5950 4200 950 
Wire Notes Line
	6700 3800 1100 3800
Wire Notes Line
	1100 950  10900 950 
Wire Notes Line
	1100 5950 10900 5950
Wire Notes Line
	1100 950  1100 5950
Text Notes 1350 1150 0    50   ~ 0
LED MATRIX SCREEN\n
Text Notes 4350 1150 0    50   ~ 0
Buzzer\n
Text Notes 6800 1150 0    50   ~ 0
MicroController
Text Notes 4300 4000 0    50   ~ 0
Battery Management System
Text Notes 1200 3950 0    50   ~ 0
KeyPad buttons
NoConn ~ 9400 3350
NoConn ~ 9400 2850
NoConn ~ 9400 2750
$Comp
L PicBytesMicro-rescue:M20-9990645-SamacSys_Parts PicKit1
U 1 1 600D26A9
P 9850 4400
F 0 "PicKit1" H 10478 4150 50  0000 L CNN
F 1 "M20-9990645" H 10478 4105 50  0001 L CNN
F 2 "HDRV6W66P0X254_1X6_1524X254X874P" H 10500 4500 50  0001 L CNN
F 3 "http://uk.rs-online.com/web/p/products/6812994P" H 10500 4400 50  0001 L CNN
F 4 "M20 Header, Pin, Sil, Vertical, 6 W HARWIN M20 Series, 2.54mm Pitch 6 Way 1 Row Straight Pin Header, Through Hole, Solder Termination" H 10500 4300 50  0001 L CNN "Description"
F 5 "8.74" H 10500 4200 50  0001 L CNN "Height"
F 6 "6812994P" H 10500 4100 50  0001 L CNN "RS Part Number"
F 7 "http://uk.rs-online.com/web/p/products/6812994P" H 10500 4000 50  0001 L CNN "RS Price/Stock"
F 8 "Harwin" H 10500 3900 50  0001 L CNN "Manufacturer_Name"
F 9 "M20-9990645" H 10500 3800 50  0001 L CNN "Manufacturer_Part_Number"
F 10 "R1052705" H 10500 3700 50  0001 L CNN "Allied_Number"
	1    9850 4400
	1    0    0    -1  
$EndComp
Text GLabel 9850 4400 0    50   Input ~ 0
MCLR
Text GLabel 9850 4700 0    50   Input ~ 0
ICSPDA
Text GLabel 9850 4800 0    50   Input ~ 0
ICSPCLK
Text GLabel 9850 4500 0    50   Input ~ 0
Vcc_main
Text GLabel 9850 4600 0    50   Input ~ 0
Vgnd_main
Text GLabel 8600 5400 2    50   Input ~ 0
MCLR
Text GLabel 8100 4950 3    50   Input ~ 0
ICSPDA
Wire Wire Line
	8100 4950 8100 4850
Text GLabel 8000 4950 3    50   Input ~ 0
ICSPCLK
Wire Wire Line
	8000 4950 8000 4850
NoConn ~ 9850 4900
$EndSCHEMATC
