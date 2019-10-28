EESchema Schematic File Version 4
LIBS:RenaultBT-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 7
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
L Transistor_FET:2N7000 Q2
U 1 1 5D113680
P 4100 2650
F 0 "Q2" H 4305 2696 50  0000 L CNN
F 1 "2N7000" H 4305 2605 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 4300 2575 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 4100 2650 50  0001 L CNN
	1    4100 2650
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7000 Q4
U 1 1 5D113720
P 4300 3400
F 0 "Q4" H 4506 3354 50  0000 L CNN
F 1 "2N7000" H 4506 3445 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 4500 3325 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 4300 3400 50  0001 L CNN
	1    4300 3400
	-1   0    0    1   
$EndComp
$Comp
L Device:R R24
U 1 1 5D11378B
P 3850 2850
F 0 "R24" V 3643 2850 50  0000 C CNN
F 1 "10K" V 3734 2850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 3780 2850 50  0001 C CNN
F 3 "~" H 3850 2850 50  0001 C CNN
	1    3850 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R25
U 1 1 5D1137C8
P 3550 3800
F 0 "R25" V 3343 3800 50  0000 C CNN
F 1 "1K" V 3434 3800 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 3480 3800 50  0001 C CNN
F 3 "~" H 3550 3800 50  0001 C CNN
	1    3550 3800
	0    1    1    0   
$EndComp
$Comp
L Device:R R26
U 1 1 5D11384C
P 4200 4150
F 0 "R26" H 4270 4196 50  0000 L CNN
F 1 "47K" H 4270 4105 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4130 4150 50  0001 C CNN
F 3 "~" H 4200 4150 50  0001 C CNN
	1    4200 4150
	1    0    0    -1  
$EndComp
Text HLabel 3650 3050 0    50   Input ~ 0
GND
Text HLabel 3000 2650 0    50   Input ~ 0
CDC_TX
Text HLabel 4750 2250 2    50   Output ~ 0
HU_RX
Wire Wire Line
	4200 2450 4200 2250
Text HLabel 4750 3400 2    50   Input ~ 0
HU_TX
Text HLabel 2950 3800 0    50   Output ~ 0
CDC_RX
Wire Wire Line
	2950 3800 3400 3800
Text HLabel 4200 4400 3    50   Input ~ 0
3V3
Wire Wire Line
	4200 3200 4200 3050
Wire Wire Line
	4750 3400 4500 3400
Wire Wire Line
	4200 4000 4200 3800
Wire Wire Line
	4200 4300 4200 4400
Wire Wire Line
	3700 3800 4200 3800
Connection ~ 4200 3800
Wire Wire Line
	4200 3800 4200 3600
Connection ~ 3850 2650
Wire Wire Line
	3850 2650 3900 2650
Wire Wire Line
	3000 2650 3850 2650
Wire Wire Line
	3650 3050 3850 3050
Wire Wire Line
	3850 2700 3850 2650
Wire Wire Line
	3850 3000 3850 3050
Connection ~ 3850 3050
Wire Wire Line
	3850 3050 4200 3050
Wire Wire Line
	4200 2850 4200 3050
Connection ~ 4200 3050
$Comp
L Device:R R10
U 1 1 5DB88B27
P 4450 2250
F 0 "R10" V 4243 2250 50  0000 C CNN
F 1 "470" V 4334 2250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 4380 2250 50  0001 C CNN
F 3 "~" H 4450 2250 50  0001 C CNN
	1    4450 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	4300 2250 4200 2250
Wire Wire Line
	4600 2250 4750 2250
$EndSCHEMATC
