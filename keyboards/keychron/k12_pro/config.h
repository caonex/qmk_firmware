/* Copyright 2023 ~ 2025 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Turn off effects when suspended */
#define RGB_MATRIX_SLEEP
#define LED_MATRIX_SLEEP

/* DIP switch for Mac/win OS switch */
#define DIP_SWITCH_PINS \
    { A8 }

/* Caps lock LED Pin */
#define LED_CAPS_LOCK_PIN A0
#define LED_PIN_ON_STATE 1

/* Increase I2C speed to 1000 KHz */
#define I2C1_TIMINGR_PRESC 0U
#define I2C1_TIMINGR_SCLDEL 3U
#define I2C1_TIMINGR_SDADEL 0U
#define I2C1_TIMINGR_SCLH 15U
#define I2C1_TIMINGR_SCLL 51U

#ifdef KC_BLUETOOTH_ENABLE
/* Hardware configuration */
#    define USB_BT_MODE_SELECT_PIN A10

#    define CKBT51_RESET_PIN A9
#    define CKBT51_INT_INPUT_PIN A5
#    define BLUETOOTH_INT_INPUT_PIN A6

#    define USB_POWER_SENSE_PIN B1
#    define USB_POWER_CONNECTED_LEVEL 0

#    define BAT_LOW_LED_PIN A4
#    define BAT_LOW_LED_PIN_ON_STATE 1

#    define HOST_DEVICES_COUNT 3

#    if defined(RGB_MATRIX_ENABLE) || defined(LED_MATRIX_ENABLE)

#        define SNLED27351_SDB_PIN C14

#        define BT_INDCATION_LED_MATRIX_LIST \
            { 15, 16, 17 }

#        define BAT_LEVEL_LED_LIST \
            { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }

/* Backlit disable timeout when keyboard is disconnected(unit: second) */
#        define DISCONNECTED_BACKLIGHT_DISABLE_TIMEOUT 40

/* Backlit disable timeout when keyboard is connected(unit: second) */
#        define CONNECTED_BACKLIGHT_DISABLE_TIMEOUT 600
#    endif

/* Keep USB connection in blueooth mode */
#    define KEEP_USB_CONNECTION_IN_BLUETOOTH_MODE

#endif

/* Emulated EEPROM configuration */
#define WEAR_LEVELING_LOGICAL_SIZE 2048
#define WEAR_LEVELING_BACKING_SIZE (WEAR_LEVELING_LOGICAL_SIZE * 2)
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 2047

/* Old default behavior of mod-taps */
//#define HOLD_ON_OTHER_KEY_PRESS

/* Factory test keys */
#define FN_KEY1 MO(4)

#define CHORDAL_HOLD
// Define 5 Layers vs Default 4
//#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// Configure the global tapping term
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

//#define RETRO_TAPPING

// Enable Rapid Switch from tap to hold, disables double tap hold auto-repeat
//#define QUICK_TAP_TERM 300

//#define PERMISSIVE_HOLD

// Pick good defaults for enabling homerow modifiers
//#define TAP_CODE_DELAY 5
//#define TAP_HOLD_CAPS_DELAY 0
//#define BILATERAL_COMBINATIONS

// Combo Definition
//#define COMBO_TERM 25        // how quickly all combo keys must be pressed in succession to trigger
//#define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
//#define COMBO_HOLD_TERM 300  // how long at least one of the combo keys must be held to trigger

//#define COMBO_ALLOW_ACTION_KEYS
//#define COMBO_STRICT_TIMER
//#define EXTRA_SHORT_COMBOS
//#define COMBO_TERM (TAPPING_TERM / 5) // time to get all combo keys down
//#define COMBO_HOLD (COMBO_TERM*4) // time to hold to trigger delayed combo
//#define ADAPTIVE_TERM COMBO_HOLD  // use COMBO_HOLD time as a standard threshold (same recation time)
