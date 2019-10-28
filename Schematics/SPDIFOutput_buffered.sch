EESchema Schematic File Version 4
LIBS:RenaultBT-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74xx:74HC04 U?
U 2 1 5CD2B25D
P 5800 2750
AR Path="/5CCA0E0E/5CD2B25D" Ref="U?"  Part="2" 
AR Path="/5CCA0E0E/5CD29B0B/5CD2B25D" Ref="U5"  Part="2" 
AR Path="/5CD2B25D" Ref="U?"  Part="2" 
F 0 "U5" H 5800 3067 50  0000 C CNN
F 1 "74HC04" H 5800 2976 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 5800 2750 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 5800 2750 50  0001 C CNN
	2    5800 2750
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 3 1 5CD2B264
P 5800 3200
AR Path="/5CCA0E0E/5CD2B264" Ref="U?"  Part="3" 
AR Path="/5CCA0E0E/5CD29B0B/5CD2B264" Ref="U5"  Part="3" 
AR Path="/5CD2B264" Ref="U?"  Part="3" 
F 0 "U5" H 5800 3517 50  0000 C CNN
F 1 "74HC04" H 5800 3426 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 5800 3200 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 5800 3200 50  0001 C CNN
	3    5800 3200
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 4 1 5CD2B26B
P 5800 3650
AR Path="/5CCA0E0E/5CD2B26B" Ref="U?"  Part="4" 
AR Path="/5CCA0E0E/5CD29B0B/5CD2B26B" Ref="U5"  Part="4" 
AR Path="/5CD2B26B" Ref="U?"  Part="4" 
F 0 "U5" H 5800 3967 50  0000 C CNN
F 1 "74HC04" H 5800 3876 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 5800 3650 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 5800 3650 50  0001 C CNN
	4    5800 3650
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 5 1 5CD2B272
P 5800 4100
AR Path="/5CCA0E0E/5CD2B272" Ref="U?"  Part="5" 
AR Path="/5CCA0E0E/5CD29B0B/5CD2B272" Ref="U5"  Part="5" 
AR Path="/5CD2B272" Ref="U?"  Part="5" 
F 0 "U5" H 5800 4417 50  0000 C CNN
F 1 "74HC04" H 5800 4326 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 5800 4100 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 5800 4100 50  0001 C CNN
	5    5800 4100
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 6 1 5CD2B279
P 5800 4550
AR Path="/5CCA0E0E/5CD2B279" Ref="U?"  Part="6" 
AR Path="/5CCA0E0E/5CD29B0B/5CD2B279" Ref="U5"  Part="6" 
AR Path="/5CD2B279" Ref="U?"  Part="6" 
F 0 "U5" H 5800 4867 50  0000 C CNN
F 1 "74HC04" H 5800 4776 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 5800 4550 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 5800 4550 50  0001 C CNN
	6    5800 4550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HC04 U?
U 1 1 5CD2B280
P 4950 3650
AR Path="/5CCA0E0E/5CD2B280" Ref="U?"  Part="1" 
AR Path="/5CCA0E0E/5CD29B0B/5CD2B280" Ref="U5"  Part="1" 
AR Path="/5CD2B280" Ref="U?"  Part="1" 
F 0 "U5" H 4950 3967 50  0000 C CNN
F 1 "74HC04" H 4950 3876 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 4950 3650 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 4950 3650 50  0001 C CNN
	1    4950 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 3650 5350 3650
Wire Wire Line
	5350 3650 5350 3200
Wire Wire Line
	5350 3200 5500 3200
Connection ~ 5350 3650
Wire Wire Line
	5350 3650 5500 3650
Wire Wire Line
	5350 3200 5350 2750
Wire Wire Line
	5350 2750 5500 2750
Connection ~ 5350 3200
Wire Wire Line
	5350 3650 5350 4100
Wire Wire Line
	5350 4100 5500 4100
Wire Wire Line
	5350 4100 5350 4550
Wire Wire Line
	5350 4550 5500 4550
Connection ~ 5350 4100
Wire Wire Line
	6100 2750 6250 2750
Wire Wire Line
	6250 2750 6250 3200
Wire Wire Line
	6250 3200 6100 3200
Wire Wire Line
	6250 3200 6250 3650
Wire Wire Line
	6250 3650 6100 3650
Connection ~ 6250 3200
Wire Wire Line
	6250 3650 6250 4100
Wire Wire Line
	6250 4100 6100 4100
Connection ~ 6250 3650
Wire Wire Line
	6250 4100 6250 4550
Wire Wire Line
	6250 4550 6100 4550
Connection ~ 6250 4100
$Comp
L 74xx:74HC04 U?
U 7 1 5CD2C32A
P 4950 4650
AR Path="/5CCA0E0E/5CD2C32A" Ref="U?"  Part="7" 
AR Path="/5CCA0E0E/5CD29B0B/5CD2C32A" Ref="U5"  Part="7" 
AR Path="/5CD2C32A" Ref="U?"  Part="7" 
F 0 "U5" H 5180 4696 50  0000 L CNN
F 1 "74HC04" H 5180 4605 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 4950 4650 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/74HC_HCT04.pdf" H 4950 4650 50  0001 C CNN
F 4 "X" H 4950 4650 50  0001 C CNN "Spice_Primitive"
F 5 "74HC04" H 4950 4650 50  0001 C CNN "Spice_Model"
F 6 "Y" H 4950 4650 50  0001 C CNN "Spice_Netlist_Enabled"
F 7 "/home/lengyela/Downloads/74hc.lib" H 4950 4650 50  0001 C CNN "Spice_Lib_File"
	7    4950 4650
	1    0    0    -1  
$EndComp
Text HLabel 4150 3650 0    50   Input ~ 0
SPDIF_TTL
Text HLabel 4150 4150 0    50   Input ~ 0
VCC
Text HLabel 4150 5150 0    50   Input ~ 0
GND
$Comp
L Device:R R5
U 1 1 5CD2DB92
P 6650 3650
F 0 "R5" V 6443 3650 50  0000 C CNN
F 1 "210" V 6534 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6580 3650 50  0001 C CNN
F 3 "~" H 6650 3650 50  0001 C CNN
	1    6650 3650
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5CD2DBF9
P 7050 4050
F 0 "R6" H 7120 4096 50  0000 L CNN
F 1 "110" H 7120 4005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P12.70mm_Horizontal" V 6980 4050 50  0001 C CNN
F 3 "~" H 7050 4050 50  0001 C CNN
	1    7050 4050
	1    0    0    -1  
$EndComp
Text HLabel 8200 3650 2    50   Output ~ 0
SPDIF
Wire Wire Line
	7800 3650 8200 3650
Wire Wire Line
	4950 5150 7050 5150
Connection ~ 4950 5150
Wire Wire Line
	4150 5150 4350 5150
Wire Wire Line
	4150 4150 4350 4150
Wire Wire Line
	4150 3650 4650 3650
$Comp
L Device:C C3
U 1 1 5D46DA2E
P 7650 3650
F 0 "C3" V 7398 3650 50  0000 C CNN
F 1 "0.1u" V 7489 3650 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 7688 3500 50  0001 C CNN
F 3 "~" H 7650 3650 50  0001 C CNN
	1    7650 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	6250 3650 6500 3650
Wire Wire Line
	6800 3650 7050 3650
Wire Wire Line
	7050 3900 7050 3650
Connection ~ 7050 3650
Wire Wire Line
	7050 3650 7500 3650
Wire Wire Line
	7050 4200 7050 5150
$Comp
L Device:C C9
U 1 1 5D4C91AD
P 4350 4650
F 0 "C9" H 4465 4696 50  0000 L CNN
F 1 "0.1uF" H 4465 4605 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 4388 4500 50  0001 C CNN
F 3 "~" H 4350 4650 50  0001 C CNN
	1    4350 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 4500 4350 4150
Connection ~ 4350 4150
Wire Wire Line
	4350 4150 4950 4150
Wire Wire Line
	4350 4800 4350 5150
Connection ~ 4350 5150
Wire Wire Line
	4350 5150 4950 5150
$EndSCHEMATC
