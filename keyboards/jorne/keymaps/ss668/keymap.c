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
  XXXXXXX, KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
           XXXXXXX, LGUI_A,  LALT_S,  LCTL_D,  LSFT_F,  KC_G,         KC_H,    LSFT_J,  LCTL_K,  LALT_L,  LG_CLN,  KC_QUOT,
           XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                      TAB_RSE, KC_SPC,  ESC_LWR,      ENT_LWR, KC_BSPC, DEL_RSE
),

[MY_LAYER_LOWER] = LAYOUT(
  XXXXXXX, KC_UNDS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  F12_RGU,
           PLS_LCT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MIN_RCT,
           EQL_LAL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
                                      _______, _______, _______,      _______, _______, _______
),

[MY_LAYER_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_VOLU, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_VOLD, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,
                                      _______, _______, _______,      _______, _______, _______
),

[MY_LAYER_ADJUST] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      GAY_LYR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  QK_BOOT,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
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

bool shutdown_user(const bool jump_to_bootloader) {
#ifdef OLED_ENABLE
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (jump_to_bootloader) {
            oled_write_P(PSTR("flash"), false);
        } else {
            oled_write_P(PSTR("start"), false);
        }
    }
    oled_render_dirty(true);
#endif // OLED_ENABLE
    // `false` - don't run _kb task.
    return false;
}

#ifdef OLED_ENABLE
static void render_logo(void) {
    // TODO: show a cat picture!!
    // https://joric.github.io/qle/
    static const char PROGMEM raw_logo[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 15, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 131, 130, 128, 192, 124, 28, 28, 56, 48, 96, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 255, 241, 113, 63, 15, 1, 0, 0, 0, 0, 0, 0, 1, 3, 3, 4, 28, 56, 224, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 252, 254, 5, 199, 198, 198, 198, 198, 198, 230, 230, 102, 100, 102, 102, 102, 102, 230, 134, 6, 7, 7, 254, 252, 0, 0, 0, 0, 0, 0, 0, 0, 255, 11, 0, 0, 15, 14, 12, 4, 7, 0, 255, 224, 0, 0, 8, 8, 0, 255, 127, 128, 128, 128, 255, 255, 128, 128, 128, 128, 254, 254, 254, 254, 255, 254, 254, 254, 254, 254, 254, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
    oled_set_cursor(0, 8);
    oled_write_P(PSTR("Home!"), false);
}

// NOTE: rotation 90/270 can fit 5 characters horizontally
static void render_status(void) {
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case MY_LAYER_BASE:
            oled_write_P(PSTR("Base "), false);
            break;
        case MY_LAYER_LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case MY_LAYER_RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case MY_LAYER_ADJUST:
            oled_write_P(PSTR("Adj  "), false);
            break;
        case MY_LAYER_GAYMING:
            oled_write_P(PSTR("Gayms"), false);
            break;
        default:
            // Should be unreachable.
            oled_write_P(PSTR("Undef"), false);
            break;
    }

    led_t         led_state = host_keyboard_led_state();
    const uint8_t modifiers = get_mods() | get_oneshot_mods();
    oled_write_P(PSTR("\nMods\n"), false);
    oled_write_P((modifiers & MOD_MASK_SHIFT) || led_state.caps_lock ? PSTR("S") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("C") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("A") : PSTR(" "), false);
    oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("G") : PSTR(" "), false);

    oled_set_cursor(0, 9);
    oled_write_P(PSTR("WPM\n"), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
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
    (void)rotation;
    return OLED_ROTATION_270;
}

#endif // OLED_ENABLE
