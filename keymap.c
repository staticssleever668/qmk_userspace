// Copyright 2021 Joric (@joric)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "quantum.h"

enum MY_LAYER___________ {
    MY_LAYER_BASE = 0,
    MY_LAYER_LOWER,
    MY_LAYER_RAISE,
    MY_LAYER_ADJUST,
    MY_LAYER_GAYMING,
};

#define RBR_RGU MT(MOD_RGUI, KC_RBRC)
#define F12_RGU MT(MOD_RGUI, KC_F12)
#define PLS_LCT MT(MOD_LCTL, KC_PPLS)
#define EQL_LCT MT(MOD_LCTL, KC_PEQL)
#define APP_LCT MT(MOD_LCTL, KC_APP)
#define EQL_RCT MT(MOD_RCTL, KC_PEQL)
#define QUO_RCT MT(MOD_RCTL, KC_QUOT)
#define APP_RCT MT(MOD_RCTL, KC_APP)
#define MIN_RCT MT(MOD_RCTL, KC_MINS)
#define EQL_LAL MT(MOD_LALT, KC_EQL)
#define BSL_RAL MT(MOD_RALT, KC_BSLS)
#define BSP_LSH MT(MOD_LSFT, KC_BSPC)
#define SPC_RSH MT(MOD_RSFT, KC_SPC)
#define DEL_RSE LT(MY_LAYER_RAISE, KC_DEL)
#define TAB_RSE LT(MY_LAYER_RAISE, KC_TAB)
#define ENT_LWR LT(MY_LAYER_LOWER, KC_ENT)
#define ESC_LWR LT(MY_LAYER_LOWER, KC_ESC)
#define GAY_LYR TO(MY_LAYER_GAYMING)
#define BSE_LYR TO(MY_LAYER_BASE)

#define LALT_L MT(MOD_LALT, KC_L)
#define LALT_S MT(MOD_LALT, KC_S)
#define LCTL_D MT(MOD_LCTL, KC_D)
#define LCTL_K MT(MOD_LCTL, KC_K)
#define LGUI_A MT(MOD_LGUI, KC_A)
#define LG_CLN MT(MOD_LGUI, KC_SCLN)
#define LSFT_F MT(MOD_LSFT, KC_F)
#define LSFT_J MT(MOD_LSFT, KC_J)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[MY_LAYER_BASE] = LAYOUT(
  _______, KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
           _______, LGUI_A,  LALT_S,  LCTL_D,  LSFT_F,  KC_G,         KC_H,    LSFT_J,  LCTL_K,  LALT_L,  LG_CLN,  KC_QUOT,
           _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, BSL_RAL,
                                      TAB_RSE, KC_SPC,  ESC_LWR,      ENT_LWR, KC_BSPC, DEL_RSE
),

[MY_LAYER_LOWER] = LAYOUT(
  _______, KC_UNDS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  F12_RGU,
           PLS_LCT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MIN_RCT,
           EQL_LAL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                                      _______, _______, _______,      _______, _______, _______
),

[MY_LAYER_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______,      _______, KC_PSCR, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
           _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
                                      _______, _______, _______,      _______, _______, _______
),

[MY_LAYER_ADJUST] = LAYOUT(
  QK_BOOT, _______, _______, _______, _______, _______, _______,      GAY_LYR, _______, _______, _______, _______, _______,  QK_BOOT,
           _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
                                      _______, _______, _______,      _______, _______, _______
),

[MY_LAYER_GAYMING] = LAYOUT(
  KC_LGUI, KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, RBR_RGU,
           KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
           KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, BSL_RAL,
                                      KC_TAB,  KC_SPC,  KC_ESC,       KC_ENT,  KC_BSPC, BSE_LYR
),

}; // keymaps

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, MY_LAYER_LOWER, MY_LAYER_RAISE, MY_LAYER_ADJUST);
}

#ifdef OLED_ENABLE
static void render_logo(void) {
    // TODO: show a cat picture!!
    // clang-format off
    // https://joric.github.io/qle/
    static const char PROGMEM raw_logo[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 192, 224, 240, 240, 240, 240, 240, 240, 240, 224,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 112, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 192, 224, 240, 0, 0, 240, 252, 254, 255, 255, 255, 1, 240, 252, 255,
        255, 255, 255, 255, 255, 255, 255, 127, 31, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 254, 254, 254, 0, 0, 240,
        248, 252, 30, 14, 14, 14, 14, 14, 14, 30, 252, 248, 240, 0, 0, 254, 254, 252, 28, 14, 14, 14, 14, 0, 0, 254, 254, 252, 28, 14, 14,
        14, 14, 30, 252, 248, 240, 0, 0, 240, 248, 252, 222, 206, 206, 206, 206, 206, 206, 222, 252, 248, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 255, 254, 240, 255, 255, 255, 255, 255, 255, 248, 255, 255, 255, 255,
        255, 255, 255, 255, 255, 193, 128, 128, 128, 192, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 255, 255, 255, 0, 0,
        15, 31, 63, 120, 112, 112, 112, 112, 112, 112, 120, 63, 31, 15, 0, 0, 127, 127, 127, 0, 0, 0, 0, 0, 0, 0, 127, 127, 127, 0, 0, 0,
        0, 0, 0, 127, 127, 127, 0, 0, 15, 31, 63, 121, 113, 113, 113, 113, 113, 113, 121, 61, 29, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 3, 3, 1, 1, 3, 3, 7, 7, 7, 3, 3, 1, 3, 7, 7, 7, 7, 7, 7, 7, 3, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0
    }; // raw_logo
    // clang-format on
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

// NOTE: rotation 90/270 can fit 5 characters horizontally
static void render_status(void) {
    oled_write_P(PSTR("Layer\n     "), false);
    switch (get_highest_layer(layer_state)) {
        case MY_LAYER_BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case MY_LAYER_LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case MY_LAYER_RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case MY_LAYER_ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case MY_LAYER_GAYMING:
            oled_write_P(PSTR("Gayms\n"), false);
            break;
        default:
            // Should be unreachable.
            oled_write_P(PSTR("Undef\n"), false);
            break;
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NMLCK\n") : PSTR("     \n"), false);
    oled_write_P(led_state.caps_lock ? PSTR("CPLCK\n") : PSTR("     \n"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCLCK\n") : PSTR("     \n"), false);

    oled_set_cursor(0, 9);
    oled_write("WPM:\n", false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);

    // TODO: show ctrl, shift, alt
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        render_status();
    } else {
        render_logo();
    }
    // `false` - don't run built-in OLED task.
    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

#endif // OLED_ENABLE
