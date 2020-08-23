/*
Copyright 2018 Jeff Shufelt <jshuf@puppyfish.com> @jshuf

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H


//Tap Dance Declarations
enum {
    TD_LGUI_APP = 0/*,
    TD_RS_END_HOME*/
};
/*
static bool dance_rseh_rshold = false;

// the call sequence of dance functions is always "tap(s) > finished > reset"
void dance_rseh_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->pressed) {
            register_code(KC_RSFT);
            dance_rseh_rshold = true;
        } else {
            register_code(KC_END);
            unregister_code(KC_END);
        }
    } else if (state->count == 2) {
        register_code(KC_HOME);
        unregister_code(KC_HOME);
    }
}

void dance_rseh_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (dance_rseh_rshold && (state->count == 1)) {
        unregister_code(KC_RSFT);
    }
    dance_rseh_rshold = false;
}*/

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LGUI_APP] = ACTION_TAP_DANCE_DOUBLE (KC_LGUI, KC_APP)/*,
    [TD_RS_END_HOME] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rseh_finished, dance_rseh_reset)*/
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all( /* Base */
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_HOME,                   KC_END,  KC_PSCR, KC_PAUS, KC_INS,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PGUP, KC_PGDN,                   KC_NLCK, KC_PSLS, KC_PAST, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS,                   KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,                    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_LSFT, KC_DEL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,            KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    KC_LCTL, TD(TD_LGUI_APP), KC_LALT,                    KC_SPC,                             KC_BSPC, MO(1),   KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT,          KC_P0,   KC_PDOT, XXX
  ),
  [1] = LAYOUT_all( /* Func */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,                   _______, _______, KC_SLCK, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,
    _______, KC_BTN1, KC_MS_U, KC_BTN2, BL_TOGG, BL_STEP, BL_BRTG, _______, _______, _______, _______, _______, _______,          _______,                   _______, _______, _______, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, RGB_TOG,RGB_RMOD, RGB_MOD, _______, _______, _______, _______, _______,                   _______,                   _______, _______, _______, _______,
    _______, _______, KC_BTN3, KC_WH_U, KC_WH_D, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______,
    _______, _______, _______,                            _______,                            _______, _______, _______,          _______, _______, _______,          _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
