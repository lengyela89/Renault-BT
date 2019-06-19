EESchema Schematic File Version 4
LIBS:RenaultBT-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	6100 3700 6250 3700
$Comp
L Device:R R?
U 1 1 5CD1F99D
P 5400 4000
AR Path="/5CD1F99D" Ref="R?"  Part="1" 
AR Path="/5CCA0E0E/5CD1F99D" Ref="R?"  Part="1" 
AR Path="/5CCA0E0E/5CD1D027/5CD1F99D" Ref="R4"  Part="1" 
F 0 "R?" H 5600 4050 50  0000 R CNN
F 1 "110" H 5600 3950 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5330 4000 50  0001 C CNN
F 3 "~" H 5400 4000 50  0001 C CNN
	1    5400 4000
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5CD1F9A4
P 5950 3700
AR Path="/5CD1F9A4" Ref="C?"  Part="1" 
AR Path="/5CCA0E0E/5CD1F9A4" Ref="C?"  Part="1" 
AR Path="/5CCA0E0E/5CD1D027/5CD1F9A4" Ref="C11"  Part="1" 
F 0 "C?" V 5800 3800 50  0000 C CNN
F 1 "0.1uF" V 5900 3850 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 5988 3550 50  0001 C CNN
F 3 "~" H 5950 3700 50  0001 C CNN
	1    5950 3700
	0    1    1    0   
$EndComp
Text HLabel 6250 3700 2    50   Output ~ 0
SPDIF
$Comp
L Device:R R?
U 1 1 5CD1F9AC
P 4900 3700
AR Path="/5CCA0E0E/5CD1F9AC" Ref="R?"  Part="1" 
AR Path="/5CCA0E0E/5CD1D027/5CD1F9AC" Ref="R3"  Part="1" 
F 0 "R?" V 4693 3700 50  0000 C CNN
F 1 "210" V 4784 3700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4830 3700 50  0001 C CNN
F 3 "~" H 4900 3700 50  0001 C CNN
	1    4900 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 3700 5400 3700
Wire Wire Line
	5400 3850 5400 3700
Connection ~ 5400 3700
Wire Wire Line
	5400 3700 5800 3700
Text HLabel 4500 3700 0    50   Input ~ 0
SPDIF_TTL
Text HLabel 4500 4200 0    50   Input ~ 0
GND
Wire Wire Line
	4500 3700 4750 3700
Wire Wire Line
	4500 4200 5400 4200
Wire Wire Line
	5400 4200 5400 4150
$EndSCHEMATC
