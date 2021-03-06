EESchema Schematic File Version 4
LIBS:RenaultBT-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 7
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
L STM32:STM32F103 U?
U 1 1 5D07EA70
P 5900 4000
AR Path="/5D07EA70" Ref="U?"  Part="1" 
AR Path="/5D07E636/5D07EA70" Ref="U6"  Part="1" 
F 0 "U6" H 5900 5175 50  0000 C CNN
F 1 "STM32F103" H 5900 5084 50  0000 C CNN
F 2 "STM32:STM32F103C8T6" H 5900 4150 50  0001 C CNN
F 3 "" H 5900 4150 50  0001 C CNN
	1    5900 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5D07EA77
P 4650 4650
AR Path="/5D07EA77" Ref="R?"  Part="1" 
AR Path="/5D07E636/5D07EA77" Ref="R21"  Part="1" 
F 0 "R21" H 4580 4604 50  0000 R CNN
F 1 "4.7K" H 4580 4695 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4580 4650 50  0001 C CNN
F 3 "~" H 4650 4650 50  0001 C CNN
	1    4650 4650
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5D07EA7E
P 4250 4650
AR Path="/5D07EA7E" Ref="R?"  Part="1" 
AR Path="/5D07E636/5D07EA7E" Ref="R20"  Part="1" 
F 0 "R20" H 4180 4604 50  0000 R CNN
F 1 "4.7K" H 4180 4695 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4180 4650 50  0001 C CNN
F 3 "~" H 4250 4650 50  0001 C CNN
	1    4250 4650
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 4350 5050 4350
Wire Wire Line
	4650 4500 4650 4450
Wire Wire Line
	4650 4450 5050 4450
Wire Wire Line
	4650 4950 5050 4950
Wire Wire Line
	4650 4800 4650 4950
Wire Wire Line
	4650 4950 4250 4950
Wire Wire Line
	4250 4800 4250 4950
Connection ~ 4650 4950
$Comp
L Device:R R?
U 1 1 5D07EA9F
P 7400 3750
AR Path="/5D07EA9F" Ref="R?"  Part="1" 
AR Path="/5D07E636/5D07EA9F" Ref="R23"  Part="1" 
F 0 "R23" H 7330 3704 50  0000 R CNN
F 1 "4.7K" H 7330 3795 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7330 3750 50  0001 C CNN
F 3 "~" H 7400 3750 50  0001 C CNN
	1    7400 3750
	-1   0    0    1   
$EndComp
Text HLabel 3600 4350 0    50   BiDi ~ 0
I2C1_SCL
Text HLabel 3600 4450 0    50   BiDi ~ 0
I2C1_SDA
Wire Wire Line
	3600 4350 4250 4350
Connection ~ 4250 4350
Wire Wire Line
	3600 4450 4650 4450
Connection ~ 4650 4450
Wire Wire Line
	4250 4500 4250 4350
Text HLabel 8250 4750 2    50   Output ~ 0
WM8804_RESET
Wire Wire Line
	7400 3450 6750 3450
$Comp
L Device:R R22
U 1 1 5D0801B5
P 7050 3750
F 0 "R22" H 7120 3796 50  0000 L CNN
F 1 "4.7K" H 7120 3705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6980 3750 50  0001 C CNN
F 3 "~" H 7050 3750 50  0001 C CNN
	1    7050 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3900 7050 4000
Wire Wire Line
	7050 5300 4650 5300
Wire Wire Line
	4650 5300 4650 4950
Wire Wire Line
	7050 3550 7050 3600
Wire Wire Line
	6750 3550 7050 3550
Wire Wire Line
	7400 3600 7400 3450
Wire Wire Line
	7400 3900 7400 4000
Wire Wire Line
	7400 4000 7050 4000
Connection ~ 7050 4000
Wire Wire Line
	7050 4000 7050 5300
Text HLabel 8250 3550 2    50   BiDi ~ 0
I2S2_SCL
Text HLabel 8250 3450 2    50   BiDi ~ 0
I2C2_SDA
Wire Wire Line
	8250 3550 7050 3550
Connection ~ 7050 3550
Wire Wire Line
	7400 3450 8250 3450
Connection ~ 7400 3450
Text HLabel 8250 3250 2    50   Input ~ 0
3V3
Text HLabel 8250 3150 2    50   Input ~ 0
GND
Wire Wire Line
	8250 3150 6750 3150
NoConn ~ 6750 3350
NoConn ~ 6750 3650
NoConn ~ 6750 3750
NoConn ~ 6750 3850
NoConn ~ 6750 3950
NoConn ~ 6750 4050
NoConn ~ 6750 4150
NoConn ~ 6750 4250
NoConn ~ 6750 4350
NoConn ~ 6750 4450
NoConn ~ 6750 4550
NoConn ~ 6750 4650
NoConn ~ 6750 4850
NoConn ~ 6750 4950
NoConn ~ 5050 4750
NoConn ~ 5050 4650
NoConn ~ 5050 4550
NoConn ~ 5050 4250
NoConn ~ 5050 4150
NoConn ~ 5050 4050
NoConn ~ 5050 3950
NoConn ~ 5050 3850
NoConn ~ 5050 3750
NoConn ~ 5050 3450
NoConn ~ 5050 3350
NoConn ~ 5050 3250
NoConn ~ 5050 3150
NoConn ~ 5050 3050
NoConn ~ 5750 5200
NoConn ~ 5850 5200
NoConn ~ 5950 5200
NoConn ~ 6050 5200
NoConn ~ 5050 4850
Wire Wire Line
	6750 3250 8250 3250
Wire Wire Line
	6750 4750 8250 4750
Text HLabel 4300 3650 0    50   Input ~ 0
UART_RX
Wire Wire Line
	4300 3650 5050 3650
Text HLabel 4300 3550 0    50   Output ~ 0
UART_TX
Wire Wire Line
	4300 3550 5050 3550
NoConn ~ 6750 3050
$EndSCHEMATC
