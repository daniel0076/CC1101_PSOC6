#ifndef PINS_h
#define PINS_h

#if defined (TARGET_CY8CKIT_062_WIFI_BT)                    /* Cypress PSoC62 Wifi Bt */

#define SPI_MOSI               (P6_0)
#define SPI_MISO               (P6_1)
#define SPI_SCLK               (P6_2)
#define SPI_CSN                (P6_3)
#define SPI_GDO0               (P9_0)
#define SPI_GDO2               (P9_1)

#else
#error "This Cypress Device is not supported by the CC1101 radio library."
#endif /* #if defined (TARGET_CY8CKIT_062_WIFI_BT)*/

#define SPI_DRIVE_CSN_LOW()     cyhal_gpio_write(SPI_CSN, 0)
#define SPI_DRIVE_CSN_HIGH()    cyhal_gpio_write(SPI_CSN, 1)
#define SPI_SI_IS_HIGH()        cyhal_gpio_read(SPI_MOSI)
#define SPI_SO_IS_HIGH()        cyhal_gpio_read(SPI_MISO)
#define GDO2_PIN_IS_HIGH()      cyhal_gpio_read(SPI_GDO2)

#endif /* #ifndef PINS_h */