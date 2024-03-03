## !!! personal development fork !!!

I want to build firmware fo this rather bare 144 pin board called `FK723M1-ZGT6 V1.0`

https://www.aliexpress.com/item/1005005919904877.html



Maybe, this is quite similiar to

https://www.st.com/en/evaluation-tools/nucleo-h743zi.html



I see that exitsting board config hits GPIO limits, which have no justification whith this kind of 144-package boards

Features I'd like to implement - among others:
- gantry autosquare 
- plasma THC
- TMC2209 current control (UART connected)

Machines in mind:
- twotrees ttc450 (add gantry autoalign and wired ethernet control)
- DIY plasma cutter (inspired by JD garage) w/ dual Y and THC
- DIY will with dual Z and VFD spindle
- maybe some parallel kinematics in the future


Any support welcome :-)

If it works, I'll issue a pull request - take the promise :-)))


## grblHAL driver for STM32H7xx processors

This is a port of [grblHAL](https://www.github.com/grblhAL) for the STM32H7xx series of processors, originally based on the F7 driver from the official repository.

__NOTE:__ This is an initial version, currently only lightly tested with [BTT SKR 3 (EZ)](https://www.biqu.equipment/products/bigtreetech-btt-skr-3-ez-control-board-mainboard-for-3d-printer), [Nucleo-H743ZI2](https://www.st.com/en/evaluation-tools/nucleo-h743zi.html), and [WeAct MiniSTM32H743](https://github.com/WeActTC/MiniSTM32H7xx) boards.

Builds should be supported from both STMCubeIDE and PlatformIO. Board specific settings have been included in the IDE configurations where possible - to avoid the need for code changes when building for different boards. (Please see the upstream Wiki-page [compiling grblHAL](https://github.com/grblHAL/core/wiki/Compiling-GrblHAL) for further instructions for how to import the project, configure the driver and compile).

PlatformIO firmware builds are run automatically as a GitHub Action on each push to the master branch. For convenience, the resulting firmwares are archived in the artifacts for each run, and can be found under the Actions tab on the GitHub repo (these files remain available for 90 days).

The current build configurations include;
- WeAct MiniSTM32H743 with SDCard and USB serial support.
- BTT SKR 3 (including EZ) with SDCard, USB serial, and TMC 2209/5160 driver support. (Note that settings are currently stored in FLASH, as the onboard EEPROM will need a software I2C implementation).
- Nucleo H743ZI with Ethernet support. (WebUI support has also been added to the Nucleo build, however this requires an SDCard breakout).

Note that the PlatformIO builds are currently using a custom download url for the latest (v1.10) **framework-stm32cubeh7** files. This will be removed once these updates are available in the upstream PlatformIO package registry.

Available driver options can be found [here](Inc/my_machine.h).

---
2022-08-12
