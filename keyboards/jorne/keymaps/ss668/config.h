// Copyright 2024 Yaroslav Chvanov
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Then run `make jorne/rev1:ss668:avrdude-split-right`.
#define EE_HANDS

// https://qmk.github.io/qmk-11ty/faqs/squeezing-the-most-out-of-avr/
#define LAYER_STATE_8BIT
#define NO_ACTION_ONESHOT
#undef LOCKING_RESYNC_ENABLE
#undef LOCKING_SUPPORT_ENABLE

#ifdef NKRO_ENABLE
#    define FORCE_NKRO
#endif // NKRO_ENABLE

#ifdef OLED_ENABLE
#    define OLED_BRIGHTNESS 64
#endif // OLED_ENABLE

#ifdef WPM_ENABLE
#    define SPLIT_WPM_ENABLE
#endif // WPM_ENABLE

#ifdef CONSOLE_ENABLE
#    define DEBUG_MATRIX_SCAN_RATE
#endif // CONSOLE_ENABLE
