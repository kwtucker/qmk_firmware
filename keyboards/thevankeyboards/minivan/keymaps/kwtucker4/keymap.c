#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QW 0
#define _L1 1
#define _L2 2
#define _L3 3

// Macro name shortcuts
#define QWERTY  M(_QW)

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)
#define SFT_ESC SFT_T(KC_ESC)  // Tap for Escape, hold for Shift


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
  *
  * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
  * |   Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   Bksp      |
  * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
  * |   Ctrl   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |    ML_2    |
  * |----------`------`------`------`------`------`------`------`------`------`------`------------|
  * | Shift/Esc |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   Shift   |
  * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
  * |   OSL_1 |   ML_3  |   GUI   |      Space     |     Enter      |   TG_1  |   TG_2  |  TG_3   |
  *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
  */
  [_QW] = LAYOUT( /* Qwerty */
    KC_TAB,   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    OSL(_L1), KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, OSL(_L2),
    SFT_ESC,  KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSHIFT,
    KC_LCTL,  OSL(_L3), KC_LGUI,                   KC_SPC,  KC_ENT,                    TG(_L1), TG(_L2), TG(_L3)
  ),

  /* Layer 1
  *
  * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
  * |   `/~   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |    TRNS     |
  * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
  * |   TRNS   |   \  |   '  |   -  |   =  |   [  |   ]  |   {  |   }  |   ?  |   :  |    TRNS    |
  * |----------`------`------`------`------`------`------`------`------`------`------`------------|
  * |   TRNS    |      |  ESC |      |      |     |       |      |   <  |   >  | TRNS |   TRNS    |
  * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
  * |   TRNS  |   TRNS  |   TRNS  |     TRNS       |     TRNS       |   TRNS  |         |         |
  *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
  */
  [_L1] = LAYOUT( /* LAYER 1 */
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, L_CURBR, R_CURBR, KC_QUES, KC_COLN, _______,
    _______, XXXXXXX, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, _______, _______,
    _______, _______, _______,                   _______, _______,                   _______, XXXXXXX, XXXXXXX
  ),

 /* LAYER 2
 * ,---------+------+------+------+------+------+------+------+------------+------+------------.
 * |    0    |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |    TRNS    |
 * |---------`------`------`------`------`------`------`------`------`------`------`------------|
 * |   TRNS   |   |  |   "  |   _  |   +  |  {   |  }   |   4  |   5  |   6  |      |    TRNS   |
 * |----------`------`------`------`------`------`------`------`------`------`------`-----------|
 * |   TRNS    | MUTE | VOLD | VOLU |      |      |       |   1  |   2  |   3  |      |  TRNS   |
 * |-----------`------`------`------`------`------`-------`------`------`------`------`---------|
 * |   TRNS  |   TRNS  |   TRNS  |     TRNS       |     TRNS       |         |   TRNS  |        |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+--------'
 */
  [_L2] = LAYOUT( /* LAYER 2 */
    KC_0   , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_PIPE, KC_DQUO, KC_UNDS, KC_PLUS, L_CURBR, R_CURBR, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, _______,
    _______, _______, _______,                   _______, _______,                   XXXXXXX, _______, XXXXXXX
  ),


  /* LAYER 3
  * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
  * |  RESET  |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |    TRNS     |
  * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
  * |          |  F5  |  F6  |  F7  |  F8  |      | LEFT | DOWN |  UP  | RIGHT|      |    TRNS    |
  * |----------`------`------`------`------`------`------`------`------`------`------`------------|
  * |           |  F9  |  F10 | F11  |  F12 |     |       |      |      |      |      |    TRNS   |
  * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
  * |  TRNS   |  TRNS   |   TRNS  |      TRNS      |     TRNS       |         |         |  TRNS   |
  *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
  */
  [_L3] = LAYOUT( /* LAYER 3 */
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX,  _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  _______,
    _______, _______, _______,                   _______, _______,                   XXXXXXX,  XXXXXXX,  _______
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
       case _QW:
          if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QW);
          }
          break;
      }
    return MACRO_NONE;
};
