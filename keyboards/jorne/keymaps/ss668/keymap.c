// Copyright 2023 Yaroslav Chvanov
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "quantum.h"

enum SS668_LAYER {
    SS668_LAYER_HOME = 0,
    SS668_LAYER_NUMBERS,
    SS668_LAYER_NAVIGATION,
    SS668_LAYER_ADJUST,
    SS668_LAYER_GAMING,
};

#define RBR_RGU MT(MOD_RGUI, KC_RBRC)
#define BSL_RAL MT(MOD_RALT, KC_BSLS)
#define DEL_RSE LT(SS668_LAYER_NAVIGATION, KC_DEL)
#define TAB_RSE LT(SS668_LAYER_NAVIGATION, KC_TAB)
#define ENT_LWR LT(SS668_LAYER_NUMBERS, KC_ENT)
#define ESC_LWR LT(SS668_LAYER_NUMBERS, KC_ESC)
#define GAY_LYR TO(SS668_LAYER_GAMING)
#define BSE_LYR TO(SS668_LAYER_HOME)

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

[SS668_LAYER_HOME] = LAYOUT(
  XXXXXXX, KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
           XXXXXXX, LGUI_A,  LALT_S,  LCTL_D,  LSFT_F,  KC_G,         KC_H,    LSFT_J,  LCTL_K,  LALT_L,  LG_CLN,  KC_QUOT,
           XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                      TAB_RSE, KC_SPC,  ESC_LWR,      ENT_LWR, KC_BSPC, DEL_RSE
),

[SS668_LAYER_NUMBERS] = LAYOUT(
  XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
           KC_PLUS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
           KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                                      _______, _______, _______,      _______, _______, _______
),

[SS668_LAYER_NAVIGATION] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_VOLU, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_VOLD, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,
                                      _______, _______, _______,      _______, _______, _______
),

[SS668_LAYER_ADJUST] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      GAY_LYR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  QK_BOOT,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
),

[SS668_LAYER_GAMING] = LAYOUT(
  KC_LGUI, KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, RBR_RGU,
           KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
           KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, BSL_RAL,
                                      KC_TAB,  KC_SPC,  KC_ESC,       KC_ENT,  KC_BSPC, BSE_LYR
),

}; // keymaps

_Static_assert(ARRAY_SIZE(keymaps) < MAX_LAYER, "More layers than enabled");

// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SS668_LAYER_NUMBERS, SS668_LAYER_NAVIGATION, SS668_LAYER_ADJUST);
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

// Notes:
//
// Useful for making new images: https://joric.github.io/qle/

// clang-format off
static const char PROGMEM s_ss668_logo_home[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 15, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 131, 130, 128, 192, 124, 28, 28, 56, 48, 96, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 255, 241, 113, 63, 15, 1, 0, 0, 0, 0, 0, 0, 1, 3, 3, 4, 28, 56, 224, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 252, 254, 5, 199, 198, 198, 198, 198, 198, 230, 230, 102, 100, 102, 102, 102, 102, 230, 134, 6, 7, 7, 254, 252, 0, 0, 0, 0, 0, 0, 0, 0, 255, 11, 0, 0, 15, 14, 12, 4, 7, 0, 255, 224, 0, 0, 8, 8, 0, 255, 127, 128, 128, 128, 255, 255, 128, 128, 128, 128, 254, 254, 254, 254, 255, 254, 254, 254, 254, 254, 254, 254, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
};
// TODO: replace this ugliness.
static const char PROGMEM s_ss668_logo_adjust[] = {
    0, 0, 0, 0, 0, 28, 30, 31, 31, 63, 60, 120, 248, 240, 224, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 224, 248, 252, 126, 31, 15, 7, 7, 7, 15, 31, 126, 28, 56, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 224, 240, 252, 126, 63, 15, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
// TODO: draw something :D.
static const char PROGMEM s_ss668_logo_navigation[] = {};
// TODO: replace this ugliness.
static const char PROGMEM s_ss668_logo_numbers[] = {
    0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 128, 0, 0, 0, 0, 0, 240, 240, 248, 124, 63, 31, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 254, 255, 255, 207, 135, 135, 63, 255, 255, 248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 0, 14, 14, 14, 14, 14, 14, 14, 0, 0, 1, 3, 3, 7, 7, 231, 255, 255, 255, 15, 0, 0, 0, 0, 0, 0, 0, 0, 192, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 56, 60, 60, 62, 31, 31, 15, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
static const char PROGMEM s_ss668_logo_error[] = {
    0, 0, 232, 16, 8, 8, 136, 136, 128, 128, 240, 240, 16, 96, 128, 0, 224, 32, 96, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 6, 9, 9, 9, 8, 8, 8, 0, 63, 13, 30, 51, 97, 0, 255, 0, 60, 103, 64, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
// Author: Dean.
static const char PROGMEM s_ss668_logo_cat[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 64, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 224, 60, 3, 0, 0, 240, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 252, 3, 0, 0, 0, 254, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 96, 24, 8, 6, 2, 3, 17, 33, 192, 0, 0, 0, 192, 97, 17, 3, 2, 2, 12, 24, 48, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 28, 96, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 96, 24, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 248, 15, 0, 0, 0, 0, 0, 0, 0, 149, 21, 0, 0, 0, 0, 0, 0, 7, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 127, 224, 0, 0, 0, 32, 16, 0, 0, 146, 0, 0, 0, 16, 32, 0, 0, 64, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 57, 97, 129, 1, 66, 34, 20, 20, 72, 72, 8, 0, 8, 72, 64, 24, 20, 34, 66, 1, 129, 193, 49, 15, 0, 0, 0, 0, 0, 0, 0, 128, 96, 16, 222, 0, 8, 14, 1, 15, 15, 2, 64, 192, 64, 2, 15, 15, 1, 14, 8, 0, 70, 152, 96, 192, 0, 0, 0, 0, 0, 0, 0, 0, 4, 7, 0, 28, 226, 4, 4, 8, 27, 178, 18, 2, 18, 146, 51, 8, 4, 4, 0, 254, 0, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 96, 128, 224, 128, 127, 0, 0, 0, 127, 128, 224, 128, 64, 63, 0, 0, 0, 0, 0, 0, 0, 0,
};
// clang-format on

// @param[out] out_logo Non-null pointer to pointer with logo
// @param[out] out_logo_size Non-null pointer with size of 'out_logo'
static void get_logo(const layer_state_t layer_idx, const char** out_logo, uint16_t* out_logo_size) {
    switch (layer_idx) {
        case SS668_LAYER_HOME:
            *out_logo      = s_ss668_logo_home;
            *out_logo_size = sizeof(s_ss668_logo_home);
            break;
        case SS668_LAYER_NUMBERS:
            *out_logo      = s_ss668_logo_numbers;
            *out_logo_size = sizeof(s_ss668_logo_numbers);
            break;
        case SS668_LAYER_NAVIGATION:
            *out_logo      = s_ss668_logo_navigation;
            *out_logo_size = sizeof(s_ss668_logo_navigation);
            break;
        case SS668_LAYER_ADJUST:
            *out_logo      = s_ss668_logo_adjust;
            *out_logo_size = sizeof(s_ss668_logo_adjust);
            break;
        case SS668_LAYER_GAMING:
            *out_logo      = s_ss668_logo_cat;
            *out_logo_size = sizeof(s_ss668_logo_cat);
            break;
        default:
            *out_logo      = s_ss668_logo_error;
            *out_logo_size = sizeof(s_ss668_logo_error);
            break;
    }
}

static void render_right(void) {
    const layer_state_t current_layer = get_highest_layer(layer_state);

    // OPTIMIZATION: don't re-render the same thing when not needed.
    static layer_state_t last_layer = MAX_LAYER + 1;
    if (current_layer == last_layer) {
        return;
    }
    last_layer = current_layer;

    oled_clear();
    const char* raw_logo;
    uint16_t    raw_logo_size;
    get_logo(current_layer, &raw_logo, &raw_logo_size);
    // TODO: maybe draw at the bottom?
    oled_write_raw_P(raw_logo, raw_logo_size);
}

// NOTE: rotation 90/270 can fit 5 characters horizontally
static void render_left(void) {
    oled_write_P(PSTR("Layer"), false);
    switch (get_highest_layer(layer_state)) {
        case SS668_LAYER_HOME:
            oled_write_P(PSTR("Base "), false);
            break;
        case SS668_LAYER_NUMBERS:
            oled_write_P(PSTR("Lower"), false);
            break;
        case SS668_LAYER_NAVIGATION:
            oled_write_P(PSTR("Raise"), false);
            break;
        case SS668_LAYER_ADJUST:
            oled_write_P(PSTR("Adj  "), false);
            break;
        case SS668_LAYER_GAMING:
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

#    ifdef WPM_ENABLE
    oled_set_cursor(0, 9);
    oled_write_P(PSTR("WPM\n"), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
#    endif // WPM_ENABLE
}

// @retval false don't run built-in OLED task
bool oled_task_user(void) {
    if (is_keyboard_left()) {
        render_left();
    } else {
        render_right();
    }
    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    (void)rotation;
    return OLED_ROTATION_270;
}

#endif // OLED_ENABLE
