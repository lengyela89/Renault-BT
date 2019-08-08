EESchema Schematic File Version 4
LIBS:RenaultBT-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 8
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
	4150 3300 4450 3300
Wire Wire Line
	4150 3250 4150 3300
Wire Wire Line
	4150 2950 4150 2900
Wire Wire Line
	6500 2100 6500 2150
Wire Wire Line
	6500 2100 6150 2100
Wire Wire Line
	6500 2500 6500 2450
Wire Wire Line
	6150 2500 6500 2500
Wire Wire Line
	6150 2400 6150 2100
Wire Wire Line
	4450 3000 4450 3300
Wire Wire Line
	4600 3000 4450 3000
$Comp
L Device:C C?
U 1 1 5CCA1ADD
P 4150 3100
AR Path="/5CCA1ADD" Ref="C?"  Part="1" 
AR Path="/5CCA0E0E/5CCA1ADD" Ref="C5"  Part="1" 
F 0 "C5" H 4265 3146 50  0000 L CNN
F 1 "1uF" H 4265 3055 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L7.2mm_W5.5mm_P5.00mm_FKS2_FKP2_MKS2_MKP2" H 4188 2950 50  0001 C CNN
F 3 "~" H 4150 3100 50  0001 C CNN
	1    4150 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5CCA1AE4
P 6500 2300
AR Path="/5CCA1AE4" Ref="C?"  Part="1" 
AR Path="/5CCA0E0E/5CCA1AE4" Ref="C8"  Part="1" 
F 0 "C8" H 6615 2346 50  0000 L CNN
F 1 "0.1uF" H 6615 2255 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 6538 2150 50  0001 C CNN
F 3 "~" H 6500 2300 50  0001 C CNN
	1    6500 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 4150 6150 4150
Connection ~ 6000 4150
$Comp
L Device:C C?
U 1 1 5CCA1AF4
P 6000 4000
AR Path="/5CCA1AF4" Ref="C?"  Part="1" 
AR Path="/5CCA0E0E/5CCA1AF4" Ref="C7"  Part="1" 
F 0 "C7" H 5800 4050 50  0000 L CNN
F 1 "15pF" H 5700 3950 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 6038 3850 50  0001 C CNN
F 3 "~" H 6000 4000 50  0001 C CNN
	1    6000 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5CCA1AFE
P 4600 4000
AR Path="/5CCA1AFE" Ref="C?"  Part="1" 
AR Path="/5CCA0E0E/5CCA1AFE" Ref="C6"  Part="1" 
F 0 "C6" H 4715 4046 50  0000 L CNN
F 1 "15pF" H 4715 3955 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 4638 3850 50  0001 C CNN
F 3 "~" H 4600 4000 50  0001 C CNN
	1    4600 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:Crystal Y?
U 1 1 5CCA1B05
P 5300 3700
AR Path="/5CCA1B05" Ref="Y?"  Part="1" 
AR Path="/5CCA0E0E/5CCA1B05" Ref="Y1"  Part="1" 
F 0 "Y1" H 5300 3968 50  0000 C CNN
F 1 "12Mhz" H 5300 3877 50  0000 C CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 5300 3700 50  0001 C CNN
F 3 "~" H 5300 3700 50  0001 C CNN
	1    5300 3700
	1    0    0    -1  
$EndComp
$Comp
L WM8804:WM8804 U?
U 1 1 5CCA1B0C
P 5300 2500
AR Path="/5CCA1B0C" Ref="U?"  Part="1" 
AR Path="/5CCA0E0E/5CCA1B0C" Ref="U3"  Part="1" 
F 0 "U3" H 5300 2965 50  0000 C CNN
F 1 "WM8804" H 5300 2874 50  0000 C CNN
F 2 "WM8804:WM8804_Breakout_18mm_x_25mm" H 5350 2500 50  0001 C CNN
F 3 "" H 5350 2500 50  0001 C CNN
	1    5300 2500
	1    0    0    -1  
$EndComp
Text HLabel 7050 2100 2    50   Input ~ 0
DVDD
Text HLabel 3350 3200 0    50   Input ~ 0
PVDD
Text HLabel 3350 3300 0    50   Input ~ 0
PGND
Text HLabel 7050 2500 2    50   Input ~ 0
DGND
Wire Wire Line
	4150 2900 4600 2900
Connection ~ 4150 3300
Connection ~ 6500 2500
Wire Wire Line
	7050 2100 6950 2100
Connection ~ 6500 2100
Wire Wire Line
	6150 2400 6000 2400
Wire Wire Line
	6000 2500 6150 2500
Connection ~ 6150 2500
Text HLabel 3350 2300 0    50   Input ~ 0
SCLK
Text HLabel 3350 2500 0    50   BiDi ~ 0
SDIN
Text HLabel 3350 2800 0    50   Input ~ 0
RESETB
Connection ~ 6850 2500
Wire Wire Line
	6950 1700 6950 2100
Connection ~ 6950 2100
Wire Wire Line
	6950 2100 6500 2100
$Comp
L Device:R R3
U 1 1 5CCAD3EE
P 4450 1950
F 0 "R3" H 4380 1904 50  0000 R CNN
F 1 "10k" H 4380 1995 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Vertical" V 4380 1950 50  0001 C CNN
F 3 "~" H 4450 1950 50  0001 C CNN
	1    4450 1950
	-1   0    0    1   
$EndComp
Wire Wire Line
	4450 1800 4450 1700
Wire Wire Line
	4450 2100 4450 2700
Wire Wire Line
	4450 2700 4600 2700
Text HLabel 6550 3250 2    50   Input ~ 0
I2S_SD_IN
Text HLabel 6550 3050 2    50   BiDi ~ 0
I2S_WS
Text HLabel 6550 3150 2    50   BiDi ~ 0
I2S_CLK
Wire Wire Line
	6150 2500 6150 4150
Wire Wire Line
	6550 3050 6400 3050
Wire Wire Line
	6400 3050 6400 2800
Wire Wire Line
	6400 2800 6000 2800
Wire Wire Line
	6550 3150 6300 3150
Wire Wire Line
	6300 3150 6300 2900
Wire Wire Line
	6300 2900 6000 2900
Wire Wire Line
	6550 3250 6200 3250
Wire Wire Line
	6200 3000 6000 3000
Wire Wire Line
	6850 2500 7050 2500
Wire Wire Line
	6850 2500 6500 2500
Wire Wire Line
	6200 3000 6200 3250
Text HLabel 8350 2850 2    50   Output ~ 0
SPDIF_OUTPUT
$Sheet
S 7050 2650 1050 350 
U 5CD29B0B
F0 "SPDIFOutput_buffered" 50
F1 "SPDIFOutput_buffered.sch" 50
F2 "SPDIF_TTL" I L 7050 2950 50 
F3 "VCC" I L 7050 2750 50 
F4 "GND" I L 7050 2850 50 
F5 "SPDIF" O R 8100 2850 50 
$EndSheet
Wire Wire Line
	6000 2600 6500 2600
Wire Wire Line
	6950 2750 7050 2750
Wire Wire Line
	6950 2100 6950 2750
Wire Wire Line
	6850 2850 7050 2850
Wire Wire Line
	6850 2500 6850 2850
Wire Wire Line
	6500 2950 7050 2950
Wire Wire Line
	6500 2600 6500 2950
Wire Wire Line
	8100 2850 8350 2850
NoConn ~ 6000 2300
NoConn ~ 6000 2700
NoConn ~ 6000 3100
Wire Wire Line
	4600 4150 6000 4150
Wire Wire Line
	4600 3200 4600 3700
Wire Wire Line
	6000 3200 6000 3700
Wire Wire Line
	5450 3700 6000 3700
Connection ~ 6000 3700
Wire Wire Line
	6000 3700 6000 3850
Wire Wire Line
	5150 3700 4600 3700
Connection ~ 4600 3700
Wire Wire Line
	4600 3700 4600 3850
NoConn ~ 4600 3100
Wire Wire Line
	4450 1700 6950 1700
NoConn ~ 4600 2600
$Comp
L Device:R R4
U 1 1 5D0A1968
P 4300 1950
F 0 "R4" H 4450 1900 50  0000 R CNN
F 1 "10K" H 4500 2000 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P2.54mm_Vertical" V 4230 1950 50  0001 C CNN
F 3 "~" H 4300 1950 50  0001 C CNN
	1    4300 1950
	-1   0    0    1   
$EndComp
$Comp
L Transistor_FET:2N7000 Q3
U 1 1 5D0A1A0C
P 3600 2800
F 0 "Q3" H 3800 2950 50  0000 L CNN
F 1 "2N7000" H 3800 2850 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Wide" H 3800 2725 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 3600 2800 50  0001 L CNN
	1    3600 2800
	1    0    0    -1  
$EndComp
Connection ~ 4450 1700
Wire Wire Line
	4300 1700 4300 1800
Wire Wire Line
	4300 1700 4450 1700
Wire Wire Line
	3350 3200 4000 3200
Wire Wire Line
	4000 3200 4000 2900
Wire Wire Line
	4000 2900 4150 2900
Connection ~ 4150 2900
Wire Wire Line
	4600 2400 4550 2400
Wire Wire Line
	4300 2100 4300 2600
Wire Wire Line
	4300 2800 4600 2800
Wire Wire Line
	3350 3300 4150 3300
Text HLabel 3350 3050 0    50   Input ~ 0
DGND
Wire Wire Line
	3700 2600 4300 2600
Connection ~ 4300 2600
Wire Wire Line
	4300 2600 4300 2800
Wire Wire Line
	3350 3050 3700 3050
Wire Wire Line
	3700 3050 3700 3000
Wire Wire Line
	3350 2800 3400 2800
Wire Wire Line
	3700 3050 3850 3050
Wire Wire Line
	3850 3050 3850 2850
Wire Wire Line
	3850 2850 4550 2850
Wire Wire Line
	4550 2850 4550 2400
Connection ~ 3700 3050
Wire Wire Line
	3350 2500 4600 2500
Wire Wire Line
	3350 2300 4600 2300
$EndSCHEMATC
