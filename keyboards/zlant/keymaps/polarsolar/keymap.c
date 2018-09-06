// 40%: polarsolar cannot mannage.

#include "zlant.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "config.h"
#include "polarsolar.h"

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

// Useful defines
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define LO_ESC LT(_LOWER, KC_ESC)           // Tap for Esc, Hold for _LOWER Layer
#define OOPS GUI_T(KC_NO)                   // Nothing on single press, GUI on hold
#define CTL_ALT MT(MOD_LCTL | MOD_LALT, KC_NO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _DVORAK: Base layer (default layer), but other layers can also be reached from the Qwerty layer.
   * ,-----------------------------------------------------------------------------------.
   * |TabEsc|   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | / =  |  //Tap for Tab; chord Tab with "'" for Esc //Tap for /; double-tap for =; chord / with "L" for Del
    * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |LO_ESC|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Ent++!|  //Tap for Esc; hold for MO(_LOWER) //Tap for Enter; hold for ???
      * |------+------+------+------+------+------|------+------+------+------+------+------|
       * |ShiftR|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  | Z Up |ShiftR|  //Tap=Shift; double-tap=RAISE //Tap for Up arrow; chord Up with V for Z
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * | Ctrl |CTLALT| OOPS |  Alt |  Bksp  |LT(4,Del)|   Spc  |TT(Q) | Left | Down |Right |  //Tap for del; hold for MO(_FL) //Tap-toggle Qwerty
         * `-----------------------------------------------------------------------------------'
   */

[_DVORAK] = LAYOUT (
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, 
  LO_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,                             
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT
  KC_LCTL, CTL_ALT, OOPS,    KC_LALT, KC_BSPC, LT(4, KC_DEL), KC_SPC,     TT(1),   KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _QWERTY: Qwerty layer. Straight map back from Dvorak. Only for use as fake-Dvorak on computers that have Dvorak enabled on the OS.
   * ,-----------------------------------------------------------------------------------.
   * |TabEsc|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | [ ]  |  //Tap for Tab; chord Tab with "Q" for Esc //Tap for [; double-tap for ]; chord [ with "P" for Del
    * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |LO_ESC|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Ent++!|  //Tap for Esc; hold for MO(_LOWER) //Tap for Enter; hold for ???
      * |------+------+------+------+------+------+------+------+------+------+------+------|
       * |ShiftR|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  | / Up |ShiftR|  //Tap=Shift; double-tap=RAISE //Tap for Up arrow; chord Up with . for /
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * | Ctrl |CTLALT| OOPS | Alt  |  Bksp  |LT(4,Del)|   Spc  |TT(Q) | Left | Down |Right |  //Tap for del; hold for MO(FL) //Tap-toggle Qwerty
         * `-----------------------------------------------------------------------------------'
   */
[_QWERTY] = LAYOUT (
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, 
  LO_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, 
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, CTL_ALT, OOPS,    KC_LALT, KC_BSPC, LT(4, KC_DEL), KC_SPC,     TT(1),   KC_LEFT, KC_DOWN, KC_RGHT),

  /* Layer _RAISE
   * ,-----------------------------------------------------------------------------------.
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |  -   | 
      * |------+------+------+------+------+------|------+------+------+------+------+------|
       * |      |      |      |      |      |      |      |      |      |      |      |      |
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |  Bksp  |         |   Spc  |      |      |      |      |
         * `-----------------------------------------------------------------------------------'

  /* Layer _LOWER
   * ,-----------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |  _CL |      |      |      |      |      |      |      |      |      | 
      * |------+------+------+------+------+------+------+------+------+------+------+------|
       * |      |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |      |      |      |      |
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |  Bksp  |         |   Spc  |      |      |      |      |
         * `-----------------------------------------------------------------------------------'

  /* Layer _FL
   * ,-----------------------------------------------------------------------------------.
   * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |[] {} |  //Tap for [{; double tap for ]}
    * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |  -   |  //
      * |------+------+------+------+------+------|------+------+------+------+------+------|
       * |Shift |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      | PgUp |Shift |  //Tap for PgUp; double-tap for Home
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |  Bksp  |         |   Spc  |      |      | PgDn |      |  //Tap for PgDn; double-tap for End
         * `-----------------------------------------------------------------------------------'   */
  /* Keymap _FL: Function Layer.  Layer indicator color: blue.
   */
[_FL] = LAYOUT (
  TG(_FL),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, KC_DEL,           BL_STEP, 
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______,                   _______, 
  _______, _______, MO(_CL), _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______,                            
  _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______,          KC_PGUP,          
  _______, _______, _______, _______,                   _______, _______,                   _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END),
  
  /* Keymap _CL: Control layer.  Layer indicator color: red.
   * ,-----------------------------------------------------------------------------------.
   * |      |      |      |      |RESET |      |      |      |      |      |      |BLtog | //BL_TOGG 
    * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      | F[0] | 
      * |------+------+------+------+------+------+------+------+------+------+------+------|
       * |      |      |      |      |      |      |      |      |      |      |BL_INC|      |
        * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |      |      |      |      |        |         |        |      |      |BL_DEC|      |
         * `-----------------------------------------------------------------------------------'

   */
[_CL] = LAYOUT (
  TG(_CL), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG,          RGB_VAI, 
  _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, RGB_RST,                   RGB_VAD, 
  _______, _______, MO(_CL), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                            
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          RGB_SAI,          
  _______, _______, _______, _______,                   RGB_MOD, RGB_MOD,                   _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_HUI),


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


enum layer_id {
  LAYER_DVORAK,
  LAYER_QWERTY,
  LAYER_RAISE,
  LAYER_LOWER,
  LAYER_FL
  LAYER_CL,
};


void clueboard_set_led(uint8_t id, uint8_t val) {
  switch (id) {
    case LAYER_DVORAK:
      rgblight_sethsv_noeeprom(320, 255, val);
      break;
    case LAYER_QWERTY:
      rgblight_sethsv_noeeprom(120, 255, val);
      break;
    case LAYER_RAISE:
      rgblight_sethsv_noeeprom(120, 255, val);
      break;
    case LAYER_LOWER:
      rgblight_sethsv_noeeprom(60, 255, val);
      break;
    case LAYER_FL:
      rgblight_sethsv_noeeprom(240, 255, val);
      break;
    case LAYER_CL:
      rgblight_sethsv_noeeprom(0, 255, val);
      break;
  }
};

void matrix_scan_user(void) {
  rgblight_config_t rgblight_config;
  rgblight_config.raw = eeconfig_read_rgblight();

  if (!rgblight_config.enable || rgblight_config.mode != 1) { return; }

  uint32_t layer = layer_state;
  uint8_t val = rgblight_config.val;

    if (layer & (1<<_CL)) {
      clueboard_set_led(LAYER_CL, val);
      } else if (layer & (1<<_FL)) {
        clueboard_set_led(LAYER_FL, val);
        } else if (layer & (1<<_LOWER)) {
          clueboard_set_led(LAYER_LOWER, val);
          } else if (layer & (1<<_RAISE)) {
            clueboard_set_led(LAYER_RAISE, val);
            } else if (layer & (1<<_QWERTY)) {
            clueboard_set_led(LAYER_QWERTY, val);
        } else {
    clueboard_set_led(LAYER_DVORAK, val);
    }
};

const uint16_t PROGMEM test_combo[] = {KC_TAB, KC_ESC, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(test_combo, KC_ESC)};

// See: https://github.com/qmk/qmk_firmware/blob/master/keyboards/handwired/promethium/keymaps/priyadi/keymap.c

// Note on combos. Need to define the COMBO_TERM in config.h, because the default in the following file is
// TAPPING_TERM (which is long!): quantum/process_keycode/process_combo.h