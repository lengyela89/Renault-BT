EESchema Schematic File Version 4
LIBS:RenaultBT-cache
EELAYER 30 0
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
P 5800 3100
F 0 "Q2" H 6005 3146 50  0000 L CNN
F 1 "2N7000" H 6005 3055 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 6000 3025 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 5800 3100 50  0001 L CNN
	1    5800 3100
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:2N7000 Q4
U 1 1 5D113720
P 6000 3850
F 0 "Q4" H 6206 3804 50  0000 L CNN
F 1 "2N7000" H 6206 3895 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 6200 3775 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 6000 3850 50  0001 L CNN
	1    6000 3850
	-1   0    0    1   
$EndComp
$Comp
L Device:R R24
U 1 1 5D11378B
P 5550 3300
F 0 "R24" V 5343 3300 50  0000 C CNN
F 1 "10K" V 5434 3300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 5480 3300 50  0001 C CNN
F 3 "~" H 5550 3300 50  0001 C CNN
	1    5550 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R25
U 1 1 5D1137C8
P 5250 4250
F 0 "R25" V 5043 4250 50  0000 C CNN
F 1 "1K" V 5134 4250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 5180 4250 50  0001 C CNN
F 3 "~" H 5250 4250 50  0001 C CNN
	1    5250 4250
	0    1    1    0   
$EndComp
$Comp
L Device:R R26
U 1 1 5D11384C
P 5900 4600
F 0 "R26" H 5970 4646 50  0000 L CNN
F 1 "47K" H 5970 4555 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5830 4600 50  0001 C CNN
F 3 "~" H 5900 4600 50  0001 C CNN
	1    5900 4600
	1    0    0    -1  
$EndComp
Text HLabel 5350 3500 0    50   Input ~ 0
GND
Text HLabel 4700 3100 0    50   Input ~ 0
CDC_TX
Text HLabel 6450 2700 2    50   Output ~ 0
HU_RX
Wire Wire Line
	5900 2900 5900 2700
Text HLabel 6450 3850 2    50   Input ~ 0
HU_TX
Text HLabel 4650 4250 0    50   Output ~ 0
CDC_RX
Wire Wire Line
	4650 4250 5100 4250
Text HLabel 5900 4850 3    50   Input ~ 0
3V3
Wire Wire Line
	5900 3650 5900 3500
Wire Wire Line
	6450 3850 6200 3850
Wire Wire Line
	5900 4450 5900 4250
Wire Wire Line
	5900 4750 5900 4850
Wire Wire Line
	5400 4250 5900 4250
Connection ~ 5900 4250
Wire Wire Line
	5900 4250 5900 4050
Connection ~ 5550 3100
Wire Wire Line
	5550 3100 5600 3100
Wire Wire Line
	4700 3100 5550 3100
Wire Wire Line
	5350 3500 5550 3500
Wire Wire Line
	5550 3150 5550 3100
Wire Wire Line
	5550 3450 5550 3500
Connection ~ 5550 3500
Wire Wire Line
	5550 3500 5900 3500
Wire Wire Line
	5900 3300 5900 3500
Connection ~ 5900 3500
$Comp
L Device:R R10
U 1 1 5DB88B27
P 6150 2700
F 0 "R10" V 5943 2700 50  0000 C CNN
F 1 "470" V 6034 2700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 6080 2700 50  0001 C CNN
F 3 "~" H 6150 2700 50  0001 C CNN
	1    6150 2700
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 2700 5900 2700
Wire Wire Line
	6300 2700 6450 2700
$EndSCHEMATC
