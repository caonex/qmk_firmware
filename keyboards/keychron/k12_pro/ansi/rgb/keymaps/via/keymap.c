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

#include QMK_KEYBOARD_H

// Define shorter version of homerow mods
#define IL_S MT(MOD_LSFT,KC_A)
#define IL_C MT(MOD_LCTL,KC_S)
#define IL_A MT(MOD_LALT,KC_D)
#define IL_G MT(MOD_LGUI,KC_F)
#define IR_G MT(MOD_RGUI,KC_J)
#define IR_A MT(MOD_RALT,KC_K)
#define IR_C MT(MOD_RCTL,KC_L)
#define IR_S MT(MOD_RSFT,KC_SCLN)

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
   LAYOUT_61_ansi(
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R','R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R','R',
    'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',     'R',
    'L',      'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R',     'R',
    'L', 'L', 'L',                '*',                'R', 'R', 'R','R'
   );

// Tapping term per key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2,KC_SPC):
            return TAPPING_TERM + 400;
	case IL_S:
	case IL_C:
	case IL_A:
	case IL_G:
	case IR_G:
	case IR_A:
	case IR_C:
	case IR_S:
	    return 250;
        default:
            return TAPPING_TERM;
    }
}

enum tapdances {
	TD_ESC_TICK_TILDE,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_TICK_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
};

// Define Combo Names
enum combos {
    COMBO_LGUI,
    COMBO_LALT,
    COMBO_LCTL,
    COMBO_LALTGUI,
    COMBO_FDSA,
    COMBO_RLGUI,
    COMBO_RLALT,
    COMBO_RLCTL,
    COMBO_RLALTGUI,
    COMBO_JKLSCLN,
    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

const uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos
// LEFT HAND
//const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
//const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
//const uint16_t PROGMEM fa_combo[] = {KC_F, KC_A, COMBO_END};
//const uint16_t PROGMEM fds_combo[] = {KC_F, KC_D, KC_S, COMBO_END};
//const uint16_t PROGMEM fdsa_combo[] = {KC_F, KC_D, KC_S, KC_A, COMBO_END};

// RIGHT HAND
//const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
//const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
//const uint16_t PROGMEM jscln_combo[] = {KC_J, KC_SCLN, COMBO_END};
//const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
//const uint16_t PROGMEM jklscln_combo[] = {KC_J, KC_K, KC_L,KC_SCLN, COMBO_END};

// map combo names to their keys and the key they trigger
//combo_t key_combos[] = {
//    [COMBO_LGUI] = COMBO(fd_combo, KC_LGUI),
//    [COMBO_LALT] = COMBO(fs_combo, KC_LALT),
//    [COMBO_LCTL] = COMBO(fa_combo, KC_LCTL),
//    [COMBO_LALTGUI] = COMBO(fds_combo, LALT(KC_LGUI)),
//    [COMBO_FDSA] = COMBO(fdsa_combo, LCTL(LALT(KC_LGUI))),
//    [COMBO_RLGUI] = COMBO(jk_combo, KC_RGUI),
//    [COMBO_RLALT] = COMBO(jl_combo, KC_RALT),
//    [COMBO_RLCTL] = COMBO(jscln_combo, KC_RCTL),
//    [COMBO_RLALTGUI] = COMBO(jkl_combo, RALT(KC_RGUI)),
//    [COMBO_JKLSCLN] = COMBO(jklscln_combo, RCTL(RALT(KC_RGUI))),
//};


// clang-format off
enum layers{
  MAC_BASE,
  WIN_BASE,
  MAC_FN1,
  WIN_FN1,
  FN2,
//  MODS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_61_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS,  IL_S,     IL_C,     IL_A,     IL_G,     KC_G,     KC_H,     IR_G,     IR_A,     IR_C,     IR_S,     KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               LT(2,KC_SPC),                           KC_RCMMD,MO(MAC_FN1),MO(FN2), KC_RCTL),

    [WIN_BASE] = LAYOUT_61_ansi(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT, MO(WIN_FN1),MO(FN2), KC_RCTL),

    [MAC_FN1] = LAYOUT_61_ansi(
        KC_GRV,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  KC_INS,   KC_PGUP,  KC_HOME,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  KC_UP,    KC_SNAP,  KC_PGDN,  KC_END,             _______,
        _______,            RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,             _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    [WIN_FN1] = LAYOUT_61_ansi(
        KC_GRV,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  KC_APP,   KC_SCRL,  KC_INS,   KC_PGUP,  KC_HOME,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  KC_UP,    KC_PSCR,  KC_PGDN,  KC_END,             _______,
        _______,            RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,             _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    [FN2] = LAYOUT_61_ansi(
        KC_TILD,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

};
