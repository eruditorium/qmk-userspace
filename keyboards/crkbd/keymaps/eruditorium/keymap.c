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

// qmk compile -j 0 -kb crkbd -km nico
// qmk flash -j 0 -kb crkbd -km nico
// qmk c2json -o ~/crkbd-nico.json -km nico -kb crkbd keymap.c --no-cpp

#include QMK_KEYBOARD_H
// ┌──────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S │
// └──────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘
// Each layer gets a name for readability, which is then used in the keymap
// matrix below. The underscores don't mean anything - you can have a layer
// called STUFF or any other name. Layer names don't all need to be of the same
// length, obviously, and you can also skip them entirely and just use numbers.
enum crkbd_layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘
enum custom_keycodes {
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  SNAP,
  MC_QUOT,
};

#include "features/macro.c"
#include "features/combos.c"

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R', 
        '*', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', '*', 
                       'L', '*', 'L',  'R', '*', 'R'
    );

// ┌──────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S │
// └──────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
      ┌─────────────────────────────────────────────────┐
      │ q w e r t y                                     │
      └─────────────────────────────────────────────────┘
    */
    [_QWERTY] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       QK_GESC,   KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  SELLINE,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       SELWORD,   KC_A,    KC_S,    KC_D,    SHT_F,    KC_G,                         KC_H,    SHT_J,   KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LCTL,   CTL_Z,  GUI_X,    ALT_C,    KC_V,    KC_B,                         KC_N,    KC_M, ALT_COMM,GUI_DOT,CTL_SLSH, KC_LSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC,   LOWER,  KC_ENTER,   KC_SPACE, RAISE, ALT_DEL
                                        //`--------------------------'  `--------------------------'
  ),

    /*╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
      ┌─────────────────────────────────────────────────┐
      │ l o w e r                                       │
      └─────────────────────────────────────────────────┘
    */
    [_LOWER] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, KC_CAPS, KC_HOME,   KC_UP, KC_PGUP, KC_LCBR,                      KC_RCBR,    KC_7,    KC_8,    KC_9, KC_PPLS, SELWORD,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       SELWBAK,  KC_NUM, KC_LEFT, KC_DOWN, KC_RIGHT, KC_LBRC,                    KC_RBRC,    KC_4,    KC_5,    KC_6, KC_MINS,  KC_EQL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, XXXXXXX,  KC_END, XXXXXXX, KC_PGDN, KC_LPRN,                      KC_RPRN,    KC_1,    KC_2,    KC_3, KC_PAST, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          WRDBSPC,   _______,  _______,   _______, ADJUST,    KC_0
                                        //`--------------------------'  `--------------------------'
  ),

    /* ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
      ┌─────────────────────────────────────────────────┐
      │ r a i s e                                       │
      └─────────────────────────────────────────────────┘
    */
    [_RAISE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC,   KC_UE, KC_AMPR,   KC_OE, CELSIUS,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       SELWBAK,   KC_AE,   KC_SS, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_BSLS,  XXXXXXX,    EURO,     MUE, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_PIPE,  KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           WRDBSPC,  ADJUST, _______,   _______,_______, WORDDEL
                                        //`--------------------------'  `--------------------------'
  ),
    /*╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

      ┌─────────────────────────────────────────────────┐
      │ a d j u s t                                     │
      └─────────────────────────────────────────────────┘
       */
    [_ADJUST] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       QK_BOOT,  RGB_TOG, RM_SATU, RM_HUEU, RM_SATU, RM_NEXT,                      KC_VOLU,   KC_F7,   KC_F8,   KC_F9,  KC_F12, XXXXXXX,  
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       SELWBAK,   LUMINO, RM_SATD, RM_HUED, RM_SATD, RM_PREV,                      KC_VOLD,   KC_F4,   KC_F5,   KC_F6,  KC_F11, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______,  RM_VALU, RM_VALD, RM_SPDU, RM_SPDD, XXXXXXX,                      KC_MUTE,   KC_F1,   KC_F2,   KC_F3,  KC_F10, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           _______,  _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
        ),
};
/*╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
#include "features/tapping_term.c"
/*╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸*/
//#include "features/oled.c"
/* ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        case SHT_F:
            if (other_keycode == KC_ENTER) {
                return true;
            }
            break;
    }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}
/* ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/
