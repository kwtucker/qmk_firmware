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
#define QWERTY M(_QW)

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR LSFT(KC_LBRC)
#define R_CURBR LSFT(KC_RBRC)

    // K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B,
    // K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B,
    // K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,
    // K30, K31, K32,           K33, K37,           K38, K39, K3B
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_TAB,       KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,    KC_Y,    KC_U, KC_I,      KC_O,    KC_P,    KC_BSPC,
    MO(_L1),      KC_A,    KC_S,    KC_D,  KC_F,  KC_G,    KC_H,    KC_J, KC_K,      KC_L,    KC_SCLN, MO(_L2),
    LSFT(KC_ESC), KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,    KC_N,    KC_M, KC_COMM,   KC_DOT,  KC_SLSH, RGUI(KC_SPC),
    KC_LCTL,      MO(_L3), KC_LGUI,               KC_SPC,  KC_ENT,                   TG(_L1), TG(_L2), TG(_L3)
  ),
  [_L1] = LAYOUT( /* LAYER 1 */
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, L_CURBR, R_CURBR, KC_QUES, KC_COLN, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, _______, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  ),
  [_L2] = LAYOUT( /* LAYER 2 */
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_PIPE, KC_DQUO, KC_UNDS, KC_PLUS, L_CURBR, R_CURBR, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  ),
  [_L3] = LAYOUT( /* LAYER 3 */
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_DOWN, KC_UP,   KC_LEFT, KC_RGHT, _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
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
