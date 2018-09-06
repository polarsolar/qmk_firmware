// polarsolar's first keymap!

#include "66.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "config.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _QWERTY 1
#define _NM 2
#define _FL 3
#define _CL 4

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
#define FN_CAPS LT(_FL, KC_CAPS)            // Tap for Caps Lock, Hold for Function Layer
#define OOPS GUI_T(KC_NO)                   // Nothing on single press, GUI on hold
#define CTL_ALT MT(MOD_LCTL | MOD_LALT, KC_NO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _DVORAK: Base layer (default layer), but other layers can also be reached from the Qwerty layer.
   * Layer indicator color: purple-ish (to match keyboard case).
   * ,-----------------------------------------------------------------------------------------------------------------------.   ,-------.
   * | Esc/` |   1   |   2   |   3   | TD_4  |   5   |   6   |   7   |   8   |   9   |   0   |   [   |   ]   |  Bksp |  Del  |   |TD_U_H |
   * |-----------------------------------------------------------------------------------------------------------------------|   |-------|
   * | Tab       |   '   |   ,   |   .   |   P   |   Y   |   F   |   G   |   C   |   R   |   L   |   /   |    =   |    \     |   |TD_D_E |
   * |-----------------------------------------------------------------------------------------------------------------------|   `-------'
   * | Fn-Caps     |   A   |   O   |   E   |   U   |   I   |   D   |   H   |   T   |   N   |   S   |   -   |        Enter    |
   * |---------------------------------------------------------------------------------------------------------------------------.
   * | Shift           |   ;   |   Q   |   J   |   K   |   X   |   B   |   M   |   W   |   V   |   Z   |  Shift  |TD_G_NL|  Up   |
   * |-----------------------------------------------------------------------------------------------------------------------------------.
   * | Ctrl    |Ctl-Alt|   OOPS   |   Alt   |     Bksp      |     Space     |  TT(1)  |  TT(3) | MO(4) |  Ctrl   | Left  | Down  |Right  |
   * `-----------------------------------------------------------------------------------------------------------------------------------'
   */

[_DVORAK] = LAYOUT (
  KC_GESC, KC_1,    KC_2,    KC_3,    TD(TD_4),KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,           TD(TD_U_H), 
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_BSLS,                   TD(TD_D_E), 
  FN_CAPS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, XXXXXXX, KC_ENT,                             
  KC_LSFT, XXXXXXX, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, TD(TD_N),         KC_UP,            
  KC_LCTL, CTL_ALT, OOPS,    KC_LALT,                   KC_BSPC, KC_SPC,                    TT(1),   TT(2),   MO(3),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _QWERTY: Qwerty layer.  Layer indicator color: green.
   * ,-----------------------------------------------------------------------------------------------------------------------.   ,-------.
   * | Esc/` |   1   |   2   |   3   |  TD_4 |   5   |   6   |   7   |   8   |   9   |   0   |   -   |   =   |  Bksp |  Del  |   |TD_U_H |
   * |-----------------------------------------------------------------------------------------------------------------------|   |-------|
   * | Tab       |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   [   |    ]   |    \     |   |TD_D_E |
   * |-----------------------------------------------------------------------------------------------------------------------|   `-------'
   * | Fn-Caps     |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   "   |        Enter    |
   * |---------------------------------------------------------------------------------------------------------------------------.
   * | Shift           |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |  Shift  |  TD_N |  Up   |
   * |-----------------------------------------------------------------------------------------------------------------------------------.
   * | Ctrl    |CTL_ALT|   OOPS   |  Alt    |     Bksp      |     Space     |   TT(1)  | TT(3) | MO(4) |  Ctrl   | Left  | Down  |Right  |
   * `-----------------------------------------------------------------------------------------------------------------------------------'
  */
[_QWERTY] = LAYOUT (
  KC_GESC, KC_1,    KC_2,    KC_3,    TD(TD_4),KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,           TD(TD_U_H), 
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,                   TD(TD_D_E), 
  FN_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,                             
  KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, TD(TD_N),         KC_UP,            
  KC_LCTL, CTL_ALT, OOPS,    KC_LALT,                   KC_BSPC, KC_SPC,                    TT(1),   TT(2),   MO(3),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _NM: Numpad and mouse layer, but the mouse isn't active yet (and isn't enabled yet).  Layer indicator color: yellow-ish.
   * ,-----------------------------------------------------------------------------------------------------------------------.   ,-------.
   * |KC_GESC|       |       |       |       |       |       |       |       |       |   /   |       |       | Bksp  |  Del  |   |TD_U_H |
   * |-----------------------------------------------------------------------------------------------------------------------|   |-------|
   * |           |       |       |       |       |       |       | KC_P7 | KC_P8 | KC_P9 |   *   |       |        |          |   |TD_D_E |
   * |-----------------------------------------------------------------------------------------------------------------------|   `-------'
   * |             |       |       |       |       |       |       | KC_P4 | KC_P5 | KC_P6 |   -   |       |                 |
   * |---------------------------------------------------------------------------------------------------------------------------.
   * |                 |       |       |       |       |       |       | KC_P1 | KC_P2 | KC_P3 |   +   |         |       |  Up   |
   * |-----------------------------------------------------------------------------------------------------------------------------------.
   * |         |       |         |         |     Bksp      |     KC_P0     | KC_PDOT |  TT(2)  |  MO(3)|         | Left  | Down  | Right |
   * `-----------------------------------------------------------------------------------------------------------------------------------'
   */
[_NM] = LAYOUT (
  KC_GESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSLS, _______, _______, KC_BSPC, KC_DEL,           TD(TD_U_H), 
  _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PAST, _______, _______, _______,                   TD(TD_D_E), 
  _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, _______, _______, _______,                            
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PPLS, _______, _______,          KC_UP,          
  _______, _______, _______, _______,                   KC_BSPC, KC_P0,                     KC_PDOT, TT(2),   MO(3),   _______, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer.  Layer indicator color: blue.
   */
[_FL] = LAYOUT (
  TG(_FL),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, KC_DEL,           BL_STEP, 
  _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, _______,                   _______, 
  _______, _______, MO(_CL), _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______,                            
  _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______,          KC_PGUP,          
  _______, _______, _______, _______,                   _______, _______,                   _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END),
  
  /* Keymap _CL: Control layer.  Layer indicator color: red.
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
  LAYER_NM,
  LAYER_FL,
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
    case LAYER_NM:
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
        } else if (layer & (1<<_NM)) {
          clueboard_set_led(LAYER_NM, val);
          } else if (layer & (1<<_QWERTY)) {
            clueboard_set_led(LAYER_QWERTY, val);
        } else {
    clueboard_set_led(LAYER_DVORAK, val);
    }
};