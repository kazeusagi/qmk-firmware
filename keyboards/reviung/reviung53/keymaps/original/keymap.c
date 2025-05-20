// Copyright 2021 gtips (@gtips)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
	_BASE,
	_LOWER,
	_RAISE,
	_ADJUST
};

#define TT_LOWER  TT(_LOWER)
#define TT_RAISE  TT(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(
                        KC_ESC,   KC_F2,    KC_F5,    KC_F7,    KC_F12,   KC_MINUS, KC_EQUAL, KC_HOME,  KC_END,   KC_DEL,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_ENT,   XXXXXXX,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,             KC_SLSH,
    KC_LCTL,  KC_LGUI,  KC_LALT,               KC_SPC,                 TT_RAISE,              TT_LOWER, KC_QUOT,  KC_SCLN
	),
	[_LOWER] = LAYOUT(
                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    _______,  XXXXXXX,  KC_UP,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_BSLS,
    _______,  _______,  _______,               _______,                 _______,              _______,  _______,  _______
	),
	[_RAISE] = LAYOUT(
                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            _______,
    _______,  _______,  _______,               _______,                 _______,              _______,  _______,  _______
	),
	[_ADJUST] = LAYOUT(
                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            _______,
    _______,  _______,  _______,               _______,                 _______,              _______,  _______,  _______
	)
};

void keyboard_post_init_user(void) {
  rgblight_setrgb (0x7A, 0x00, 0xFF);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  switch(get_highest_layer(state)) {
    case _BASE:
      rgblight_setrgb (0x7A, 0x00, 0xFF);
      break;
    case _RAISE:
      rgblight_setrgb (0x00, 0x00, 0xFF);
      break;
    case _LOWER:
      rgblight_setrgb (0xFF, 0x00, 0x00);
      break;
    case _ADJUST:
      rgblight_setrgb (0xFF, 0xFF, 0x00);
      break;
    default:
      rgblight_setrgb (0xFF, 0xFF, 0xFF);
      break;
    }
  return state;
}
