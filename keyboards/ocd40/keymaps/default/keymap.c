// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include QMK_KEYBOARD_H
#include "action_layer.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ocd40_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

/*
enum ocd40_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE
};
*/


//Tap Dance Declarations
enum {
    TD_LGUI_APP = 0,
    TD_RS_END_HOME
};

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
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LGUI_APP] = ACTION_TAP_DANCE_DOUBLE (KC_LGUI, KC_APP),
    [TD_RS_END_HOME] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rseh_finished, dance_rseh_reset)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ins LS|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |End RS|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |GU2xAp| Alt  | Del  |Lower |    Space    |Raise | Left |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ocd40_mit(
    KC_TAB ,        KC_Q   ,         KC_W   , KC_E   , KC_R   ,    KC_T   , KC_Y   , KC_U   ,    KC_I   , KC_O   , KC_P   , KC_BSPC           ,
    KC_ESC ,        KC_A   ,         KC_S   , KC_D   , KC_F   ,    KC_G   , KC_H   , KC_J   ,    KC_K   , KC_L   , KC_SCLN, KC_ENT            ,
    LSFT_T(KC_INS), KC_Z   ,         KC_X   , KC_C   , KC_V   ,    KC_B   , KC_N   , KC_M   ,    KC_COMM, KC_DOT , KC_SLSH, TD(TD_RS_END_HOME),
    KC_LCTL,        TD(TD_LGUI_APP), KC_LALT, KC_DEL , TT(_LOWER),     KC_SPC      , TT(_RAISE), KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | WH_L | WH_U | WH_D | WH_R |   "  |   |  |PrnScr|Pause | PgUp | PgDn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ocd40_mit(
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
    _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_DQUO, KC_PIPE, KC_PSCR, KC_PAUS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______,     _______     , _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | WH_L | WH_U | WH_D | WH_R |   '  |   \  |PrnScr|Pause | PgUp | PgDn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ocd40_mit(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, _______,
    _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_QUOT, KC_BSLS, KC_PSCR, KC_PAUS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______,     _______     , _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | BTN1 | MS_U | BTN2 | VOL+ |NumLck|  P/  |  P7  |  P8  |  P9  |  P*  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MS_L | MS_D | MS_R | VOL- |CapLck|  P-  |  P4  |  P5  |  P6  |  P+  | PEnt |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | WH_L | WH_U | WH_D | WH_R |ScrLck|  P0  |  P1  |  P2  |  P3  |  P.  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ocd40_mit(
    _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_VOLU, KC_NLCK, KC_PSLS, KC_P7  , KC_P8  , KC_P9  , KC_PAST, _______,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD, KC_CAPS, KC_PMNS, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PENT,
    _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_SLCK, KC_P0  , KC_P1  , KC_P2  , KC_P3  , KC_PDOT, _______,
    _______, _______, _______, _______, _______,     _______     , _______, _______, _______, _______, _______
)

};


/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
    }
    return true;
}
*/


/*
void led_set_user(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        ocd40_led_on();
    } else {
        ocd40_led_off();
    }
}*/


// LED flashing configuration
const struct {
    uint32_t time[2];  // off duration, on duration
} led_flash_config[] = {
    [_QWERTY] = {{UINT32_MAX, 0          }},
    [_LOWER] =  {{900       , 100        }},
    [_RAISE] =  {{100       , 400        }},
    [_ADJUST] = {{0         , UINT32_MAX }}
};

void matrix_scan_user(void) {
    // LED flash on various frequency depend on the active layer
    static uint32_t led_last_change = 0;
    static bool led_status = false;
    uint32_t now, duration;
    uint8_t active_config = _QWERTY;
    bool lon_ADJUST, lon_RAISE, lon_LOWER;


    lon_ADJUST = IS_LAYER_ON(_ADJUST);
    lon_RAISE  = IS_LAYER_ON(_RAISE);
    lon_LOWER  = IS_LAYER_ON(_LOWER);


    if (lon_ADJUST && !(lon_RAISE && lon_LOWER))
        layer_off(_ADJUST);
    else if (!lon_ADJUST && (lon_RAISE && lon_LOWER))
        layer_on(_ADJUST);


    if (lon_ADJUST)
        active_config = _ADJUST;
    else if (lon_RAISE)
        active_config = _RAISE;
    else if (lon_LOWER)
        active_config = _LOWER;


    duration = led_flash_config[active_config].time[led_status];
    if (duration == UINT32_MAX)
        return;

    now = timer_read32();
    if (TIMER_DIFF_32(now, led_last_change) < duration)
        return;

//TOGGLE_LED:

    led_status ? ocd40_led_off() : ocd40_led_on();
    led_status ^= true;
    led_last_change = now;
}
