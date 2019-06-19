EESchema Schematic File Version 4
LIBS:RenaultBT-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 1750 1250 1400 850 
U 5CC08323
F0 "PowerSupply" 50
F1 "PowerSupply.sch" 50
F2 "12V" I L 1750 1450 50 
F3 "HU_ON" I L 1750 1700 50 
F4 "5V" O R 3150 1450 50 
F5 "3V3" O R 3150 1700 50 
F6 "GND" I L 1750 1950 50 
$EndSheet
$Sheet
S 5000 1300 1500 900 
U 5CCA0E0E
F0 "I2SToSPDIF" 50
F1 "I2SToSPDIF.sch" 50
F2 "DVDD" I L 5000 1400 50 
F3 "PVDD" I L 5000 1600 50 
F4 "PGND" I L 5000 1700 50 
F5 "DGND" I L 5000 1500 50 
F6 "SCLK" I L 5000 1850 50 
F7 "SDIN" B L 5000 1950 50 
F8 "RESETB" I L 5000 2100 50 
F9 "I2S_SD_IN" I R 6500 2050 50 
F10 "I2S_WS" B R 6500 1950 50 
F11 "I2S_CLK" B R 6500 1850 50 
F12 "SPDIF_OUTPUT" O R 6500 1600 50 
$EndSheet
Wire Wire Line
	3150 1700 4450 1700
Wire Wire Line
	4450 1700 4450 1600
Wire Wire Line
	4450 1400 5000 1400
Wire Wire Line
	4450 1600 5000 1600
Wire Wire Line
	1750 1950 1600 1950
Wire Wire Line
	1600 1950 1600 2350
Wire Wire Line
	1600 2350 4650 2350
Wire Wire Line
	4650 2350 4650 1700
Wire Wire Line
	4650 1500 5000 1500
Wire Wire Line
	5000 1700 4650 1700
Connection ~ 4650 1700
Wire Wire Line
	4650 1700 4650 1500
Connection ~ 4450 1600
Wire Wire Line
	4450 1600 4450 1400
$Sheet
S 4950 2900 1550 950 
U 5CCFC614
F0 "BTModule" 50
F1 "BTModule.sch" 50
F2 "VBAT" I L 4950 2950 50 
F3 "GND" I L 4950 3050 50 
F4 "I2S_SD_OUT" O R 6500 3250 50 
F5 "I2S_WS" B R 6500 3350 50 
F6 "I2S_CLK" B R 6500 3450 50 
F7 "PIO21" I L 4950 3750 50 
F8 "PIO18" I L 4950 3650 50 
F9 "PIO9" I L 4950 3550 50 
F10 "PIO8" I L 4950 3450 50 
F11 "PIO7" I L 4950 3350 50 
F12 "PIO6" I L 4950 3250 50 
$EndSheet
Wire Wire Line
	4650 2350 4650 3050
Connection ~ 4650 2350
Wire Wire Line
	6500 3250 6600 3250
Wire Wire Line
	6600 3250 6600 2050
Wire Wire Line
	6600 2050 6500 2050
Wire Wire Line
	6500 1950 6700 1950
Wire Wire Line
	6700 1950 6700 3350
Wire Wire Line
	6700 3350 6500 3350
Wire Wire Line
	6500 3450 6800 3450
Wire Wire Line
	6800 3450 6800 1850
Wire Wire Line
	6800 1850 6500 1850
$Sheet
S 1750 2850 1400 1200
U 5D07E636
F0 "MainController" 50
F1 "MainController.sch" 50
F2 "I2C1_SCL" B R 3150 3200 50 
F3 "I2C1_SDA" B R 3150 3300 50 
F4 "WM8804_RESET" O R 3150 3450 50 
F5 "I2S2_SCL" B R 3150 3600 50 
F6 "I2C2_SDA" B R 3150 3700 50 
F7 "3V3" I R 3150 2950 50 
F8 "GND" I R 3150 3050 50 
F9 "UART_RX" I R 3150 3950 50 
F10 "UART_TX" O R 3150 3850 50 
$EndSheet
Connection ~ 4450 1700
Wire Wire Line
	4450 2950 4450 1700
Wire Wire Line
	3150 3050 4650 3050
Wire Wire Line
	4650 3050 4950 3050
Connection ~ 4650 3050
Wire Wire Line
	4950 2950 4450 2950
Wire Wire Line
	3150 2950 4450 2950
Connection ~ 4450 2950
Wire Wire Line
	3150 3200 4150 3200
Wire Wire Line
	4150 3200 4150 1850
Wire Wire Line
	4150 1850 5000 1850
Wire Wire Line
	5000 1950 4250 1950
Wire Wire Line
	4250 1950 4250 3300
Wire Wire Line
	4250 3300 3150 3300
Wire Wire Line
	5000 2100 4350 2100
Wire Wire Line
	4350 2100 4350 3450
Wire Wire Line
	4350 3450 3150 3450
$Sheet
S 4950 4400 800  500 
U 5D113669
F0 "HU_CDC_InterfaceAdapter" 50
F1 "HU_CDC_InterfaceAdapter.sch" 50
F2 "GND" I L 4950 4850 50 
F3 "CDC_TX" I L 4950 4450 50 
F4 "HU_RX" O R 5750 4450 50 
F5 "HU_TX" I R 5750 4550 50 
F6 "CDC_RX" O L 4950 4550 50 
F7 "3V3" I L 4950 4750 50 
$EndSheet
Wire Wire Line
	3150 3850 4350 3850
Wire Wire Line
	4350 3850 4350 4450
Wire Wire Line
	4350 4450 4950 4450
Wire Wire Line
	4950 4550 4250 4550
Wire Wire Line
	4250 4550 4250 3950
Wire Wire Line
	4250 3950 3150 3950
Wire Wire Line
	4450 2950 4450 4750
Wire Wire Line
	4450 4750 4950 4750
Wire Wire Line
	4650 3050 4650 4850
Wire Wire Line
	4650 4850 4950 4850
$EndSCHEMATC
