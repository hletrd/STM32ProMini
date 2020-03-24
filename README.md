# STM32ProMini
- STM32 Pro Mini dev board
- Based on STM32F411CEU6 MCU (100MHz ARM Cortex M4 CPU, 512kB Flash, 128kB SRAM) or STM32F103CxT6 MCU (72MHz ARM Cortex M3 CPU, 20kB SRAM)
  - Virtually support all 48 pin packaged(LQFP48, UFQFPN48, ...) STM32 MCUs.

## Setup for Arduino IDE
- Install STM32duino package along with STM32CubeProgrammer.
- Add ```./variants/PROMINI_F411``` directory to Arduino IDE ```packages/STM32/hardware/stm32/(version)/variants``` directory.
- Add the content of ```boards-add.txt``` to ```packages/STM32/hardware/stm32/(version)/boards.txt```.
