// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// https://docs.qmk.fm/squeezing_avr#squeezing-the-most-out-of-avr
#define LAYER_STATE_8BIT
#define NO_ACTION_ONESHOT
#undef LOCKING_RESYNC_ENABLE
#undef LOCKING_SUPPORT_ENABLE

#ifdef CONSOLE_ENABLE
#    define DEBUG_MATRIX_SCAN_RATE
#endif // CONSOLE_ENABLE

#ifdef NKRO_ENABLE
#    define NKRO_DEFAULT_ON true
#endif // NKRO_ENABLE

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_DEFAULT_ON false
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#    define RGBLIGHT_MAX_LAYERS 2
#endif // RGBLIGHT_ENABLE
