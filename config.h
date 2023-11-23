#pragma once

// Then run `make jorne/rev1:ss668:avrdude-split-right`.
#define EE_HANDS

#ifdef NKRO_ENABLE
#    define FORCE_NKRO
#endif // NKRO_ENABLE

#ifdef OLED_ENABLE
#    define OLED_BRIGHTNESS 96
#endif // OLED_ENABLE

#ifdef WPM_ENABLE
#    define SPLIT_WPM_ENABLE
#endif // WPM_ENABLE
