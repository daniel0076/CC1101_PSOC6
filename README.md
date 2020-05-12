CC1101_PSOC6
===

Driver library for Ti CC1101 on Cypress PSoC6 Development Kits

The project is adopted from [abhra0897/msp430_cc1101_energia_v2](https://github.com/abhra0897/msp430_cc1101_energia_v2), which is based on CC1101 library from [SpaceTeddy](https://github.com/SpaceTeddy/CC1101)


+ CC1101 library for Arduino and Raspberry Pi provided by SpaceTeddy <br />
https://github.com/SpaceTeddy/CC1101

+ A compatible and tested library for TI MSP430 is provided by abhra0897 <br />
https://github.com/abhra0897/msp430_cc1101_energia_v2

Credits
+ SpaceTeddy (https://github.com/SpaceTeddy)
+ Avra Mitra (https://github.com/abhra0897)

## Hardware

The library is only tested on
[Cypress PSoC® 6 WiFi-BT Pioneer Kit](https://www.cypress.com/CY8CKIT-062-WIFI-BT) (CY8CKIT-062-WIFI-BT)

Other Cypress Development Kits with SPI support should also work

## Software resources

- [ModusToolbox™ software](https://www.cypress.com/products/modustoolbox-software-environment) v2.1

- Retarget-IO UART (HAL): For UART debug messages
- SPI (HAL): For SPI communication
- GPIO (HAL): For GPIO communication (control GDOX pins)

The HAL components must be enabled, and provide the specific header files.

## Connections

Check `pins.h` pin description, change the pins to meet your needs.

CC1101 VDD = 1.8V-3.3V (max 3.3V)

```
CC1101 <-> PSoC6 Development Kit (My settings)

VDD    -    3.3V
SI     -    MOSI (P6_0)
SO     -    MISO (P6_1)
SCLK   -    SCLK (P6_2)
CSN    -    CSN  (P6_3)
GDO2   -    GPIO (P9_0)
GDO0   -    GPIO (P9_1)
GND    -    GND
```

General description of RF packet
================================

```
pkt_len [1byte] | rx_addr [1byte] | tx_addr [1byte] | payload data [1..60bytes]
```

+ pkt_len = count of bytes which shall transfered over air (rx_addr + tx_addr + payload data)
+ rx_addr = address of device, which shall receive the message (0x00 = broadcast to all devices)
+ tx_addr = transmitter or my address. the receiver should know who has sent a message
+ payload = 1 to 60 bytes payload data

TX Bytes example
```
0x06 0x03 0x01 0x00 0x01 0x02 0x03
```

## Basic configuration

use `uint8_t CC1100::begin(volatile uint8_t &My_addr)` always as first configuration step.

### Device address
you should set a unique device address for the transmitter and a unique device address for the receiver.
This can be done with `void CC1100::set_myaddr(uint8_t addr)`

```
TX = 0x01; RX = 0x03
```


### Modulation modes
the following modulation modes can be set by `void CC1100::set_mode(uint8_t mode)`. Transmitter and receiver must have the same Mode setting.

```
1 = GFSK_1_2_kb
2 = GFSK_38_4_kb
3 = GFSK_100_kb
4 = MSK_250_kb
5 = MSK_500_kb
6 = OOK_4_8_kb
```

### ISM frequency band
you can set a frequency operation band by `void CC1100::set_ISM(uint8_t ism_freq)` to make it compatible with your hardware.

```
1 = 315
2 = 433
3 = 868
4 = 915
```
