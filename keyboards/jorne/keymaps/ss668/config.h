// Copyright 2024 Yaroslav Chvanov
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Then run `make jorne/rev1:ss668:avrdude-split-right`.
#define EE_HANDS

#ifdef NKRO_ENABLE
#    define FORCE_NKRO
#endif // NKRO_ENABLE

#ifdef OLED_ENABLE
#    define OLED_BRIGHTNESS 64
#endif // OLED_ENABLE

#ifdef WPM_ENABLE
#    define SPLIT_WPM_ENABLE
#endif // WPM_ENABLE
