/*
  weact_mini_h743_map.h - Minimal board map for WeAct MiniSTM32H743 (incl Trinamic support for testing)

  Part of grblHAL

  Copyright (c) 2022 Jon Escombe

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 3
#error "WeAct Mini STM32H743 supports 6 motors max."
#endif

#if !defined(STM32H743xx) || HSE_VALUE != 25000000
#error "This board has STM32H743 processor with a 25MHz crystal, please select a corresponding build!"
#endif

#define BOARD_NAME "WeAct Mini H743"
#define BOARD_URL "https://github.com/WeActStudio/MiniSTM32H7xx"

#define SERIAL_PORT  1   // GPIOA: TX =  9, RX = 10

#define HAS_BOARD_INIT

// Define step pulse output pins.
#define X_STEP_PORT                 GPIOB
#define X_STEP_PIN                  10                  // X
#define Y_STEP_PORT                 GPIOB
#define Y_STEP_PIN                  11                  // Y
#define Z_STEP_PORT                 GPIOB
#define Z_STEP_PIN                  12                  // Z
#define STEP_OUTMODE                GPIO_SINGLE
//#define STEP_PINMODE                PINMODE_OD // Uncomment for open drain outputs

// Define step direction output pins.
#define X_DIRECTION_PORT            GPIOB
#define X_DIRECTION_PIN             13
#define Y_DIRECTION_PORT            GPIOB
#define Y_DIRECTION_PIN             14
#define Z_DIRECTION_PORT            GPIOB
#define Z_DIRECTION_PIN             15
#define DIRECTION_OUTMODE           GPIO_SINGLE
//#define DIRECTION_PINMODE           PINMODE_OD // Uncomment for open drain outputs

// Define stepper driver enable/disable output pin.
#define X_ENABLE_PORT               GPIOC
#define X_ENABLE_PIN                0
#define Y_ENABLE_PORT               GPIOC
#define Y_ENABLE_PIN                1
#define Z_ENABLE_PORT               GPIOC
#define Z_ENABLE_PIN                2
//#define STEPPERS_ENABLE_PINMODE   PINMODE_OD // Uncomment for open drain outputs

// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT                GPIOC
#define X_LIMIT_PIN                 3                           // X- Limit
#define Y_LIMIT_PORT                GPIOC
#define Y_LIMIT_PIN                 4                           // Y- Limit
#define Z_LIMIT_PORT                GPIOC
#define Z_LIMIT_PIN                 5                           // Z- Limit
#define LIMIT_INMODE                GPIO_SINGLE

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE                        // Motor-4
#define M3_STEP_PORT                GPIOE
#define M3_STEP_PIN                 7
#define M3_DIRECTION_PORT           GPIOE
#define M3_DIRECTION_PIN            8
#define M3_LIMIT_PORT               GPIOC
#define M3_LIMIT_PIN                6       // MIN4
#define M3_ENABLE_PORT              GPIOE
#define M3_ENABLE_PIN               9       // EN for M3 motor
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 1
#define M4_AVAILABLE                        // Motor-5
#define M4_STEP_PORT                GPIOE
#define M4_STEP_PIN                 11
#define M4_DIRECTION_PORT           GPIOE
#define M4_DIRECTION_PIN            12
#define M4_LIMIT_PORT               GPIOC
#define M4_LIMIT_PIN                7       // MIN5
#define M4_ENABLE_PORT              GPIOE
#define M4_ENABLE_PIN               13       // EN for M4
#endif

// Define ganged axis or C axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 2
#define M5_AVAILABLE                        // Motor-6
#define M5_STEP_PORT                GPIOA
#define M5_STEP_PIN                 0
#define M5_DIRECTION_PORT           GPIOA
#define M5_DIRECTION_PIN            1
#define M5_LIMIT_PORT               GPIOA
#define M5_LIMIT_PIN                3      // MIN6
#define M5_ENABLE_PORT              GPIOA
#define M5_ENABLE_PIN               2       // EN for M5 motor
#endif

// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT         GPIOB
#define SPINDLE_ENABLE_PIN          7                           //
#define SPINDLE_DIRECTION_PORT      GPIOB
#define SPINDLE_DIRECTION_PIN       5                           //

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT_BASE       GPIOB_BASE
#define SPINDLE_PWM_PIN             0                           //

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT          GPIOD
#define COOLANT_FLOOD_PIN           14
#define COOLANT_MIST_PORT           GPIOD
#define COOLANT_MIST_PIN            15

// Define user-control controls (cycle start, reset, feed hold) input pins.
// These are all available on EXP2 along with electrical RESET* (EXP2, pin 3)
#define CONTROL_PORT                GPIOD
#define RESET_PIN                   8
#define FEED_HOLD_PIN               9
#define CYCLE_START_PIN             10


// #define AUXINPUT0_PORT              GPIOD
// #define AUXINPUT0_PIN               3

#define AUXINPUT0_PORT              GPIOD
#define AUXINPUT0_PIN               0

#define AUXOUPUT0_PORT              GPIOB
#define AUXOUPUT0_PIN               1

#define AUXINTPUT0_ANALOG_PORT              GPIOD  // same typo as for PIN?
#define AUXINTPUT0_ANALOG_PIN               1   // is this a typo? see Src/driver.c


#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PORT            AUXINPUT0_PORT
#define SAFETY_DOOR_PIN             AUXINPUT0_PIN
#endif

#if MOTOR_WARNING_ENABLE
#define MOTOR_WARNING_PORT            GPIOD
#define MOTOR_WARNING_PIN             5
#endif


#define CONTROL_INMODE              GPIO_SINGLE

// Define probe switch input pin.
#define PROBE_PORT                  GPIOA
#define PROBE_PIN                   15                         // Z probe

#if TRINAMIC_UART_ENABLE

#define MOTOR_UARTX_PORT            GPIOE
#define MOTOR_UARTX_PIN             4
#define MOTOR_UARTY_PORT            GPIOE
#define MOTOR_UARTY_PIN             5
#define MOTOR_UARTZ_PORT            GPIOE
#define MOTOR_UARTZ_PIN             6

#ifdef  M3_AVAILABLE
#define MOTOR_UARTM3_PORT           GPIOE
#define MOTOR_UARTM3_PIN            15
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_UARTM4_PORT           GPIOE
#define MOTOR_UARTM4_PIN            14
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_UARTM5_PORT           GPIOA
#define MOTOR_UARTM5_PIN            4
#endif

#elif TRINAMIC_SPI_ENABLE

#ifdef TRINAMIC_SOFT_SPI // Software SPI implementation

#define TRINAMIC_MOSI_PORT          GPIOA
#define TRINAMIC_MOSI_PIN           7
#define TRINAMIC_MISO_PORT          GPIOA
#define TRINAMIC_MISO_PIN           6
#define TRINAMIC_SCK_PORT           GPIOA
#define TRINAMIC_SCK_PIN            5

#else // Hardware SPI implementation

#define SPI_PORT                    1 // GPIOA, SCK_PIN = 5, MISO_PIN = 6, MOSI_PIN = 7

#endif //TRINAMIC_SOFT_SPI

#define MOTOR_CSX_PORT              GPIOE
#define MOTOR_CSX_PIN               4
#define MOTOR_CSY_PORT              GPIOE
#define MOTOR_CSY_PIN               5
#define MOTOR_CSZ_PORT              GPIOE
#define MOTOR_CSZ_PIN               6

#ifdef  M3_AVAILABLE
#define MOTOR_CSM3_PORT             GPIOE
#define MOTOR_CSM3_PIN              15
#endif

#ifdef  M4_AVAILABLE
#define MOTOR_CSM4_PORT             GPIOE
#define MOTOR_CSM4_PIN              14
#endif

#ifdef  M5_AVAILABLE
#define MOTOR_CSM5_PORT             GPIOA
#define MOTOR_CSM5_PIN              4
#endif

#endif // TRINAMIC_SPI_ENABLE

// EOF
