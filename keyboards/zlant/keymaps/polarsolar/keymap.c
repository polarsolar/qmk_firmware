// 40%: polarsolar cannot mannage.
// Still a major work in progress. No, it won't compile & I know it.
// Keymap also requires some (also-work-in-progress) files from a local user directory.

#include "zlant.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "config.h"
// #include "polarsolar.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _QWERTY 1
#define _RAISE 2
#define _LOWER 3
#define _FL 4
#define _CL 5

#define RGB_RST F(0)

// Tap Dance Declarations
enum {
  TD_U_H = 0,
  TD_D_E,
  TD_4,
  TD_N
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Page Up or Page Down; tap twice for Home or End
  [TD_U_H] = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, KC_HOME),
  [TD_D_E] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_END),
  [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
  [TD_N] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_NLCK)
};

// Useful defines
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LO_ESC LT(_LOWER, KC_ESC)           // Tap for Esc, Hold for _LOWER Layer
#define OOPS GUI_T(KC_NO)                   // Nothing on single press, GUI on hold
#define CTL_ALT MT(MOD_LCTL | MOD_LALT, KC_NO)
#define CENTER LT(4, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _DVORAK: Base layer (default layer), but other layers can also be reached from the Qwerty layer.
   * ,-----------------------------------------------------------------------------------.
   * |TabEsc|   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | / =  |  //Tap for Tab; chord Tab with "'" for Esc //Tap for /; double-tap for =; chord / with "L" for Del
    * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |LO_ESC|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Ent++!|  //Tap for Esc; hold for MO(_LOWER) //Tap for Enter; hold for ???
      * |------+------+------+------+------+------|------+------+------+------+------+------|
       * |ShiftR|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |ShiftU|  //Tap=Shift; double-tap=RAISE //Tap=up; single hold=Shift; double-tap=RAISE
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * | Ctrl |CTLALT| OOPS |  Alt | Bksp |CENTER|  Spc |TT(1) |      | Left | Down |Right |  //Tap for del; hold for MO(_FL) //Tap-toggle Qwerty
         * `-----------------------------------------------------------------------------------'
   */

[_DVORAK] = LAYOUT (
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
  LO_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT
  KC_LCTL, CTL_ALT, OOPS,    KC_LALT, KC_BSPC, CENTER,  KC_SPC,  TT(1),   _______, KC_UP  , KC_DOWN, KC_RGHT),

  /* Keymap _QWERTY: Qwerty layer. Straight map back from Dvorak. Only for use as fake-Dvorak on computers that have Dvorak enabled on the OS.
   * ,-----------------------------------------------------------------------------------.
   * |TabEsc|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | [ ]  |  //Tap for Tab; chord Tab with "Q" for Esc //Tap for [; double-tap for ]; chord [ with "P" for Del
    * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |LO_ESC|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Ent++!|  //Tap for Esc; hold for MO(_LOWER) //Tap for Enter; hold for ???
      * |------+------+------+------+------+------+------+------+------+------+------+------|
       * |ShiftR|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |ShiftU|  //Tap or single hold = Shift; double-tap=RAISE //Tap=up; single hold=Shift; double-tap=RAISE;
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * | Ctrl |CTLALT| OOPS | Alt  | Bksp |CENTER|  Spc |TT(1) |      | Left | Down |Right |  //Tap for del; hold for MO(FL) //Tap-toggle Qwerty
         * `-----------------------------------------------------------------------------------'
   */
[_QWERTY] = LAYOUT (
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  LO_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, CTL_ALT, OOPS,    KC_LALT, KC_BSPC, CENTER,  KC_SPC,  TT(1),   _______, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Layer _RAISE
   * ,-----------------------------------------------------------------------------------.
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |  -   |
      * |------+------+------+------+------+------|------+------+------+------+------+------|
       * |      |      |      |      |      |      |      |      |      |      |      |      |
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      | Bksp |CENTER|  Spc |      |      |      |      |      |
         * `-----------------------------------------------------------------------------------'
   */
[_RAISE] = LAYOUT (
  KC_GESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, KC_BSPC, CENTER,  KC_SPC,  _______, _______, _______, _______, _______),
  /* Layer _LOWER
   * ,-----------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |  _CL |      |      |      |      |      |      |      |      |      |
      * |------+------+------+------+------+------+------+------+------+------+------+------|
       * |      |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |      |      |      |      |
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      | Bksp | Del  |  Spc |      |      |      |      |      |
         * `-----------------------------------------------------------------------------------'
   */
[_LOWER] = LAYOUT (
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, _______,
  _______, _______, MO(_CL), _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, KC_BSPC, CENTER,  KC_SPC,  _______, _______, _______, _______, _______),

  /* Layer _FL
   * ,-----------------------------------------------------------------------------------.
   * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |[] {} |  //Tap for [{; double tap for ]}
    * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |  -   |  //
      * |------+------+------+------+------+------|------+------+------+------+------+------|
       * |Shift |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      | PgUp |  //Tap for PgUp; double-tap for Home
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      | Bksp |  Del |  Spc |      |      |      | PgDn |      |  //Tap for PgDn; double-tap for End
         * `-----------------------------------------------------------------------------------'   */
  /* Keymap _FL: Function Layer.
   */
[_FL] = LAYOUT (
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, KC_MINS,
  KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, TD(TD_U_H),
  _______, _______, _______, _______, KC_BSPC, CENTER,  KC_SPC,  _______, _______, _______, TD(TD_D_E),_______),

  /* Keymap _CL: Control layer.  Layer indicator color: red.
   * ,-----------------------------------------------------------------------------------.
   * |TG(_CL)|      |      |      |RESET |      |      |      |      |      |      |BLtog | //BL_TOGG
    * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      | F[0] |
      * |------+------+------+------+------+------+------+------+------+------+------+------|
       * |      |      |      |      |      |      |      |      |      |      |      |BL_INC|
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |      |      |      |      |      |      |BL_DEC|      |
         * `-----------------------------------------------------------------------------------'

   */
[_CL] = LAYOUT (
  TG(_CL), _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, RGB_TOG,
  _______, _______, MO(_CL), _______, _______, _______, _______, _______, _______, _______, _______, RGB_RST,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAI,
  _______, _______, _______, _______, _______, _______, KC_SPC,  _______, _______, RGB_HUD, RGB_SAD, RGB_HUI),

};

/* This is a list of user defined functions. F(N) corresponds to item N
   of this list.
 */

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(0),  // Calls action_function()
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case 0:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(320, 255, 255);
      }
  }
}

// const uint16_t PROGMEM test_combo[] = {KC_TAB, KC_QUOT, COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {COMBO(test_combo, KC_ESC)};
// Commenting this out for now because I still need to set up my users directory.
// See: https://github.com/qmk/qmk_firmware/blob/master/keyboards/handwired/promethium/keymaps/priyadi/keymap.c

// Note on combos. Need to define the COMBO_TERM in config.h, because the default in the following file
// TAPPING_TERM (which is long!): quantum/process_keycode/process_combo.h

// Additional note for macros: layer_on(layer)
