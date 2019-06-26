EESchema Schematic File Version 4
LIBS:RenaultBT-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 8
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
L Regulator_Linear:LM1117-3.3 U?
U 1 1 5CC0929C
P 7800 3100
AR Path="/5CC0929C" Ref="U?"  Part="1" 
AR Path="/5CC08323/5CC0929C" Ref="U2"  Part="1" 
F 0 "U2" H 7800 3342 50  0000 C CNN
F 1 "LM1117-3.3" H 7800 3251 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 7800 3100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 7800 3100 50  0001 C CNN
	1    7800 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5CC092A3
P 3850 3450
AR Path="/5CC092A3" Ref="C?"  Part="1" 
AR Path="/5CC08323/5CC092A3" Ref="C1"  Part="1" 
F 0 "C1" H 3968 3496 50  0000 L CNN
F 1 "100uF" H 3968 3405 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 3888 3300 50  0001 C CNN
F 3 "~" H 3850 3450 50  0001 C CNN
	1    3850 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5CC092AA
P 6850 3550
AR Path="/5CC092AA" Ref="C?"  Part="1" 
AR Path="/5CC08323/5CC092AA" Ref="C2"  Part="1" 
F 0 "C2" H 6968 3596 50  0000 L CNN
F 1 "470uF" H 6968 3505 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 6888 3400 50  0001 C CNN
F 3 "~" H 6850 3550 50  0001 C CNN
	1    6850 3550
	1    0    0    -1  
$EndComp
$Comp
L pspice:INDUCTOR L?
U 1 1 5CC092B8
P 6400 3300
AR Path="/5CC092B8" Ref="L?"  Part="1" 
AR Path="/5CC08323/5CC092B8" Ref="L1"  Part="1" 
F 0 "L1" H 6400 3515 50  0000 C CNN
F 1 "330uH" H 6400 3424 50  0000 C CNN
F 2 "Inductor_THT:L_Radial_D10.0mm_P5.00mm_Fastron_07M" H 6400 3300 50  0001 C CNN
F 3 "" H 6400 3300 50  0001 C CNN
	1    6400 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3300 6000 3300
Wire Wire Line
	6000 3450 6000 3300
Connection ~ 6000 3300
Wire Wire Line
	6000 3300 6150 3300
Wire Wire Line
	6650 3300 6850 3300
Wire Wire Line
	6850 3300 6850 3400
Wire Wire Line
	6000 3750 6000 3900
Wire Wire Line
	6850 3700 6850 3900
Wire Wire Line
	6850 3900 6000 3900
Wire Wire Line
	5850 3100 6850 3100
Wire Wire Line
	6850 3100 6850 3300
Connection ~ 6850 3300
Connection ~ 6850 3100
Wire Wire Line
	7800 3400 7800 3900
Wire Wire Line
	8300 3400 8300 3100
Wire Wire Line
	8300 3100 8100 3100
Wire Wire Line
	8300 3700 8300 3900
Wire Wire Line
	8300 3900 7800 3900
Connection ~ 7800 3900
$Comp
L Device:R R?
U 1 1 5CC092F6
P 4450 3450
AR Path="/5CC092F6" Ref="R?"  Part="1" 
AR Path="/5CC08323/5CC092F6" Ref="R2"  Part="1" 
F 0 "R2" V 4243 3450 50  0000 C CNN
F 1 "10K" V 4334 3450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4380 3450 50  0001 C CNN
F 3 "~" H 4450 3450 50  0001 C CNN
	1    4450 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3300 3850 3100
Wire Wire Line
	3850 3100 4450 3100
Wire Wire Line
	4450 3300 4450 3100
Connection ~ 4450 3100
Wire Wire Line
	4450 3100 4850 3100
Wire Wire Line
	4800 3300 4850 3300
$Comp
L Device:R R?
U 1 1 5CC09303
P 4050 4300
AR Path="/5CC09303" Ref="R?"  Part="1" 
AR Path="/5CC08323/5CC09303" Ref="R1"  Part="1" 
F 0 "R1" H 4120 4346 50  0000 L CNN
F 1 "10K" H 4120 4255 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3980 4300 50  0001 C CNN
F 3 "~" H 4050 4300 50  0001 C CNN
	1    4050 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 4150 4050 4000
Wire Wire Line
	4050 4000 4150 4000
Wire Wire Line
	4050 4450 4050 4600
Wire Wire Line
	4050 4600 4450 4600
Wire Wire Line
	3850 4600 4050 4600
Wire Wire Line
	3850 3600 3850 4600
Wire Wire Line
	4450 3600 4450 3700
Wire Wire Line
	4450 3700 4800 3700
Wire Wire Line
	4450 3700 4450 3800
Connection ~ 4450 3700
Wire Wire Line
	4450 4200 4450 4600
Connection ~ 4050 4600
Wire Wire Line
	4450 4600 5350 4600
Wire Wire Line
	5350 4600 5350 3900
Connection ~ 4450 4600
Wire Wire Line
	6000 3900 5350 3900
Connection ~ 6000 3900
Connection ~ 5350 3900
Wire Wire Line
	5350 3900 5350 3500
Wire Wire Line
	5350 4600 5350 4650
Connection ~ 5350 4600
Wire Wire Line
	8300 2750 8300 3100
Connection ~ 8300 3100
Wire Wire Line
	7100 2750 7100 3100
Wire Wire Line
	7100 3100 6850 3100
Wire Wire Line
	3450 4000 4050 4000
Connection ~ 4050 4000
Wire Wire Line
	3450 3100 3850 3100
Connection ~ 3850 3100
Text HLabel 3450 3100 0    50   Input ~ 0
12V
Text HLabel 3450 4000 0    50   Input ~ 0
HU_ON
Text HLabel 7100 2750 1    50   Output ~ 0
5V
Text HLabel 8300 2750 1    50   Output ~ 0
3V3
Text HLabel 5350 4650 3    50   Input ~ 0
GND
$Comp
L Transistor_FET:2N7000 Q?
U 1 1 5CC092C5
P 4350 4000
AR Path="/5CC092C5" Ref="Q?"  Part="1" 
AR Path="/5CC08323/5CC092C5" Ref="Q1"  Part="1" 
F 0 "Q1" H 4555 4046 50  0000 L CNN
F 1 "2N7000" H 4555 3955 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 4550 3925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 4350 4000 50  0001 L CNN
F 4 "X" H 4350 4000 50  0001 C CNN "Spice_Primitive"
F 5 "2n7000" H 4350 4000 50  0001 C CNN "Spice_Model"
F 6 "Y" H 4350 4000 50  0001 C CNN "Spice_Netlist_Enabled"
F 7 "/home/lengyela/Downloads/2N7000.REV0.LIB" H 4350 4000 50  0001 C CNN "Spice_Lib_File"
	1    4350 4000
	1    0    0    -1  
$EndComp
Text GLabel 3400 3700 0    50   Output ~ 0
PWR_ON
Connection ~ 6850 3900
Connection ~ 7100 3100
$Comp
L Device:CP C4
U 1 1 5CC773D4
P 8300 3550
F 0 "C4" H 8418 3596 50  0000 L CNN
F 1 "100uF" H 8418 3505 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D10.0mm_P5.00mm" H 8338 3400 50  0001 C CNN
F 3 "~" H 8300 3550 50  0001 C CNN
	1    8300 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 3700 4450 3700
Wire Wire Line
	4800 3300 4800 3700
$Comp
L Regulator_Switching:LM2575-5.0BT U1
U 1 1 5D11C563
P 5350 3200
F 0 "U1" H 5350 3567 50  0000 C CNN
F 1 "LM2575-5.0BT" H 5350 3476 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-5_Vertical" H 5350 2950 50  0001 L CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/lm2575.pdf" H 5350 3200 50  0001 C CNN
	1    5350 3200
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N5819 D1
U 1 1 5D11C75B
P 6000 3600
F 0 "D1" V 5954 3679 50  0000 L CNN
F 1 "1N5819" V 6045 3679 50  0000 L CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 6000 3425 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88525/1n5817.pdf" H 6000 3600 50  0001 C CNN
	1    6000 3600
	0    1    1    0   
$EndComp
Wire Wire Line
	6850 3900 7800 3900
Wire Wire Line
	7100 3100 7500 3100
$EndSCHEMATC
