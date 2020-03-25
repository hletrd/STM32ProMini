# STM32ProMini
- STM32 Pro Mini dev board
- Based on STM32F411CEU6 MCU (100MHz ARM Cortex M4 CPU, 512kB Flash, 128kB SRAM) or STM32F103CxT6 MCU (72MHz ARM Cortex M3 CPU, 20kB SRAM)
  - Virtually support all 48 pin packaged(LQFP48, UFQFPN48, ...) STM32 MCUs.
  
## Variants
### ProMini F411
* Based on STM32F411CEU6 MCU
* PB11 is disabled in this variant, being used to connect a capacitor to supply internal voltage.

#### BOM
* 2.2uF or 4.7uF ceramic capacitor with low ESR have to placed on C13.
* USB pull-up resistor R1 is not needed. (The MCU integrates pull-up resistor for USB D+.)

### ProMini F103
* Based on STM32F103C8T6 / STM32F103CBT6 MCU
* Compatible with common Blue Pill development board with STM32F103C8T6, except for absence of 32.768kHz crystal.

#### BOM
* C13 is not needed in F103 variant.
* An 1.5k pull-up resistor R1 for USB D+ is needed.

## Setup for Arduino IDE
- Install STM32duino package along with STM32CubeProgrammer.
- Add ```./variants/PROMINI_F411``` directory to Arduino IDE ```packages/STM32/hardware/stm32/(version)/variants``` directory.
- Add the content of ```boards-add.txt``` to ```packages/STM32/hardware/stm32/(version)/boards.txt```.
