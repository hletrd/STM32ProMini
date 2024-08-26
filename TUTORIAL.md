## Setup for Arduino IDE
* What you need:
  * An STM32 ProMini F411CE board.
  * An ST-LINK V2 programmer. Any generic ST-LINK V2 programmer should work, which can be found on eBay or AliExpress.

### Software

#### IDE Setup
- [Download](https://www.arduino.cc/en/software) and install Arduino IDE.
- Download and install STM32duino package.
  * Open Arduino IDE.
  * Open `Preferences`.
  * Add `https://github.com/stm32duino/BoardManagerFiles/raw/main/package_stmicroelectronics_index.json` to `Additional Boards Manager URLs`.
  * Open `Boards Manager`.
  * Search for `STM32 MCU based boards` and install the package.

#### Installing the necessary board configurations
- Open library directory.
  * Windows: `C:\Users\<username>\AppData\Local\Arduino15\packages\STMicroelectronics\hardware\stm32\<version>\`
  * Linux: `~/Arduino15/packages/STMicroelectronics/hardware/stm32/<version>/`
  * macOS: `~/Library/Arduino15/packages/STMicroelectronics/hardware/stm32/<version>/`
- Locate the `boards.txt` file and open it.
- Copy and paste the ENTIRE contents of `arduino/boards-add.txt` from this repository to the `boards.txt` file.
- Save the file.
- Copy and paste the `arduino/variants` folder from this repository to the `variants` folder in the STM32duino package directory.
- Now, you should be able to find the `Custom` boards in the Arduino IDE, and `ProMini F411CE` will appear under the `Board part number` section.

### Wiring
- Connect ST-LINK V2 programmer to the board. Only 4 wires are needed:
  * SWDIO -> SWDIO
  * SWCLK -> SWCLK
  * 3.3V -> 3V3
  * GND -> GND

### Uploading code
- Connect ST-LINK V2 programmer to the computer.
- Write any code, such as
```cpp
// Blink LED on PC3
void setup() {
  pinMode(PC3, OUTPUT);
}

void loop() {
  digitalWrite(PC3, HIGH);
  delay(1000);
  digitalWrite(PC3, LOW);
  delay(1000);
}
```

- Select the board `Custom Boards` and set the board part number to `ProMini F411CE`.
- Make sure that the `Upload method` is set to `STM32CubeProgrammer (SWD)`. `Port` does not matter.
- Now, you can simply upload the code to the board by clicking the `Upload` button.