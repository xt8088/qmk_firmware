/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ansi(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SLCK, KC_PAUS, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_INS,  KC_HOME, KC_PGUP, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,  KC_END,  KC_PGDN, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                      \
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,                   KC_UP,            \
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, TT(1),   KC_APP,  KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT  \
  ),
  [1] = LAYOUT_ansi(
    _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______,          _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______,          _______, _______, _______, \
    _______, BL_TOGG, BL_STEP, BL_INC,  BL_DEC,  BL_BRTG, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______, _______,          _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PAST, _______,          _______,                                     \
    _______,          _______, _______, _______, _______, _______, KC_P0,   _______, _______, _______, _______,          _______,                   _______,          \
    _______, _______, _______,                            _______,                            _______, _______, _______, _______,          _______, _______, _______  \
  )
};


// turn LEDs on and off depending on USB caps/num/scroll lock states.
void led_set_user(uint8_t usb_led) {
    if (!IS_LAYER_ON(1))
    {
        if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
            b87_led_on();
        } else {
            b87_led_off();
        }
    }
}


// LED flashing configuration
const struct {
    uint32_t time[2];  // off duration, on duration
} led_flash_config[] = {
    [0] = {{UINT32_MAX, UINT32_MAX }},
    [1] = {{500       , 500        }}
};


void matrix_scan_user(void) {
    // LED flash on various frequency depend on the active layer
    static uint32_t led_last_change = 0;
    static bool led_status = false;
    uint32_t now, duration;
    static uint8_t active_config = 0;
    static bool resume_numlock_status = false;

    if (!IS_LAYER_ON(1)) {
        if (active_config == 1) {
            if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK)) {
                b87_led_on();
            } else {
                b87_led_off();
            }
            if (IS_LED_ON(host_keyboard_leds(), USB_LED_NUM_LOCK) !=  resume_numlock_status) {
                tap_code(KC_NUMLOCK);
            }
        } else {
            resume_numlock_status = IS_LED_ON(host_keyboard_leds(), USB_LED_NUM_LOCK);
        }
    } else if (active_config != 1) {
        if (!IS_LED_ON(host_keyboard_leds(), USB_LED_NUM_LOCK)) {
            tap_code(KC_NUMLOCK);
        }
    }
    active_config = (IS_LAYER_ON(1)? 1: 0);

    duration = led_flash_config[active_config].time[led_status];
    if (duration == UINT32_MAX)
        return;

    now = timer_read32();
    if (TIMER_DIFF_32(now, led_last_change) < duration)
        return;

//TOGGLE_LED:

    led_status ? b87_led_off() : b87_led_on();
    led_status ^= true;
    led_last_change = now;
}
