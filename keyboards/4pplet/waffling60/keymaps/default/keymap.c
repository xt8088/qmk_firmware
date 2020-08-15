#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// main layer
[0] = LAYOUT_all(
  KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,      KC_7,      KC_8,      KC_9,       KC_0,    KC_MINS, KC_EQL,  KC_NO, KC_BSPC,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,       KC_Y,      KC_U,      KC_I,      KC_O,       KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, 
  KC_LCTRL, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,       KC_H,      KC_J,      KC_K,      KC_L,       KC_SCLN, KC_QUOT,          KC_ENT,  
  KC_LSFT,  KC_NO,    KC_Z,     KC_X,     KC_C,     KC_V,       KC_B,      KC_N,      KC_M,      KC_COMM,    KC_DOT,  KC_SLSH, KC_RSFT, KC_NO,
  KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,               KC_SPC,               KC_SPC,                KC_RALT, KC_RGUI, KC_APP,  MO(1)),
// basic function layer
[1] = LAYOUT_all(
  RESET,    KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,      KC_F10,  KC_F11,   KC_F12,  KC_TRNS, KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_UP,    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS,           KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,              KC_TRNS,              KC_TRNS,               KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS)
};
