/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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
#pragma once

#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//----------------------------------------------------------------------------
// home row mods
//----------------------------------------------------------------------------
// https://sunaku.github.io/home-row-mods.html
// https://github.com/manna-harbour/qmk_firmware/pull/56
// https://github.com/manna-harbour/qmk_firmware/issues/29

// Tap-hold configuration for home row mods.
#define TAPPING_TERM 225
//#define TAPPING_TERM_PER_KEY
//#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define QUICK_TAP_TERM 150
// #define QUICK_TAP_TERM_PER_KEY


#define COMBO_COUNT 10

// Activate CAPS WORD by pressing Left Shift + Right Shift
// https://docs.qmk.fm/#/feature_caps_word
//#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// Activate by double tapping Left Shift:-
//alternative:
//#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// Holding Shift while Caps Word is active inverts the shift state.
//#define CAPS_WORD_INVERT_ON_SHIFT
// When idle, turn off Caps Word after 5 seconds.
// #define CAPS_WORD_IDLE_TIMEOUT 5000

// #undef LOCKING_SUPPORT_ENABLE
// #undef LOCKING_RESYNC_ENABLE

// source: https://jasoncarloscox.com/blog/combo-mods/
// #define COMBO_TERM 25        // how quickly all combo keys must be pressed in succession to trigger
// #define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
// #define COMBO_HOLD_TERM 175  // how long at least one of the combo keys must be held to trigger

#ifdef RGBLIGHT_ENABLE
    #undef RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_LIMIT_VAL 40
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

// Enable just the Gradient and Ripple effects.
#define PALETTEFX_GRADIENT_ENABLE
// #define PALETTEFX_FLOW_ENABLE
#define PALETTEFX_RIPPLE_ENABLE
// #define PALETTEFX_SPARKLE_ENABLE
// #define PALETTEFX_VORTEX_ENABLE
// #define PALETTEFX_REACTIVE_ENABLE

// Or enable all effects with
// #define PALETTEFX_ENABLE_ALL_EFFECTS

// Enable just the Afterburn, Not Pink, and Phosphor palettes.
#define PALETTEFX_AFTERBURN_ENABLE
// #define PALETTEFX_AMBER_ENABLE
// #define PALETTEFX_BADWOLF_ENABLE
// #define PALETTEFX_CARNIVAL_ENABLE
// #define PALETTEFX_CLASSIC_ENABLE
// #define PALETTEFX_DRACULA_ENABLE
// #define PALETTEFX_GROOVY_ENABLE
#define PALETTEFX_NOTPINK_ENABLE
#define PALETTEFX_PHOSPHOR_ENABLE
// #define PALETTEFX_POLARIZED_ENABLE
// #define PALETTEFX_ROSEGOLD_ENABLE
// #define PALETTEFX_SPORT_ENABLE
// #define PALETTEFX_SYNTHWAVE_ENABLE
// #define PALETTEFX_THERMAL_ENABLE
// #define PALETTEFX_VIRIDIS_ENABLE
// #define PALETTEFX_WATERMELON_ENABLE

// Or enable all palettes with
// #define PALETTEFX_ENABLE_ALL_PALETTES

#undef OLED_FONT_H
#undef OLED_FONT_WIDTH
#undef OLED_FONT_HEIGHT
#undef OLED_FONT_END

#define OLED_FONT_H "features/glcdfont.c"
#define OLED_FONT_WIDTH 8
#define OLED_FONT_HEIGHT 8
//#define OLED_FONT_START 65  // 'A'
//#define OLED_FONT_END   87  // 'W'
//#define OLED_FONT_WIDTH 8   // 8x8
#define OLED_FONT_END 0x9F

#define OLED_DISABLE_TIMEOUT
#define OLED_DISABLE_SCROLL

// Add these flags to your rules.mk file:
// This enables Link Time Optimization, saving a significant amount of space.
// Because the Macro and Function features are incompatible with Link Time Optimization,
// disable those features in config.h:
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
// Drashna, on QMK issue 3224, paraphrased
#define NO_ACTION_ONESHOT
#define DISABLE_LEADER

// configure the amount of keys a combo can be composed of
#define EXTRA_SHORT_COMBOS

// Lumino cycles among off, LUMINO_LOW_BRIGHTNESS, and LUMINO_HIGH_BRIGHTNESS.
// The latter two are values between 0.0 (off) and 1.0 (max).
#define LUMINO_HIGH_BRIGHTNESS  1.0  // = max.
#define LUMINO_LOW_BRIGHTNESS   (0.4 * (LUMINO_HIGH_BRIGHTNESS))  // = 40%.
// By default, the set brightness is saved to EEPROM. Uncomment the next line
// to tell Lumino to never write to EEPROM.
// #define LUMINO_NO_EEPROM

// Normal idle timeout in milliseconds after which the lighting turns off. 
#define LUMINO_LONG_TIMEOUT     120000  // = 2 minutes.
// Fast idle timeout, used when few keystrokes were received since the last 
// time the keyboard woke up.
#define LUMINO_SOON_TIMEOUT     5000    // = 5 seconds.
// Animated transition time for smoothly changing brightness levels.
#define LUMINO_TRANSITION       500     // = 500 ms.

// Lighting color set when `QK_BOOT` is pressed.
#define LUMINO_BOOT_COLOR       RGB_RED
