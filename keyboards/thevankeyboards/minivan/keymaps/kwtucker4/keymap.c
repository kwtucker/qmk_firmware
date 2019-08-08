#include QMK_KEYBOARD_H

extern rgblight_config_t rgblight_config;
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum {
	_QW = 0,
	_L1,
	_L2,
	_L3,
	_RGB,
	_COLEQL,
	TD_GUISPC,	
};

// Macro name shortcuts
#define QWERTY  M(_QW)
#define RGBTGL  M(_RGB)
#define COLEQL  M(_COLEQL)

// Curly braces have their own keys. These are defined to make them not mess up
// the grid in layer 2.
#define L_CURBR  LSFT(KC_LBRC)
#define R_CURBR  LSFT(KC_RBRC)
#define SFT_ESC  SFT_T(KC_ESC)  // Tap for Escape, hold for Shift
#define TD_GS    TD(TD_GUISPC)  // Tap for Escape, hold for Shift

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for LGUI, twice for LGUI and SPC 
  [TD_GUISPC]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, LGUI(KC_SPC))
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_QW] = LAYOUT( /* Qwerty */
    KC_TAB,    KC_Q,     KC_W,    		   KC_E,    KC_R,  KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,    KC_BSPC,
    KC_LCTL,   KC_A,     KC_S,    		   KC_D,    KC_F,  KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN, OSL(_L2),
    KC_LSHIFT, KC_Z,     KC_X,    		   KC_C,    KC_V,  KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_RSHIFT,
    OSL(_L1),  KC_LALT,  KC_LGUI,                 KC_SPC,KC_ENT,                              OSL(_L3), DF(_QW), KC_RCTL
  ),


  [_L1] = LAYOUT( /* LAYER 1 */
    KC_TILDE, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______,  KC_QUOT, KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, L_CURBR, R_CURBR, KC_QUES, KC_COLN, _______,
    _______,  XXXXXXX, XXXXXXX, XXXXXXX, COLEQL,  KC_GRV,  XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, _______, _______,
    _______,  _______, _______,                   _______, _______,                   _______, _______, _______
  ),


  [_L2] = LAYOUT( /* LAYER 2 */
    KC_0   , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_ESC , KC_DQUO, KC_PIPE, KC_UNDS, KC_PLUS, L_CURBR, R_CURBR, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MRWD, KC_MPLY, KC_MFFD, KC_1,    KC_2,    KC_3,    XXXXXXX, _______,
    _______, _______, _______,                   _______, _______,                   _______, _______, _______
  ),

  [_L3] = LAYOUT( /* LAYER 3 */
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  RGBTGL,       _______,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, LGUI(KC_SPC), _______,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,      _______,
    _______, _______, _______,                   _______, _______,                   _______,  _______,      _______
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
        case _COLEQL:
          if (record->event.pressed) {
            SEND_STRING(":=");
          }
          break;
        case _RGB: 
          if (record->event.pressed) {
            rgblight_toggle();
          }
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {
  rgblight_enable();
  rgblight_setrgb(15, 106, 139);
}

void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE

  static uint8_t old_layer = 255;
  uint8_t new_layer = biton32(layer_state);

  // Color of the Icons.
  if (old_layer != new_layer) {
    switch (new_layer) {
      case _QW:
        // #0F6A8B
        rgblight_setrgb(15, 106, 139);
        break;
      case _L1:
        // #FE7F2D
        rgblight_setrgb(254, 127, 45);
        break;
      case _L2:
        // #069800
        rgblight_setrgb(6, 152, 0);
        break;
      case _L3:
        // #D79500
        rgblight_setrgb(215, 149, 0);
        break;
      default: //  for any other layers, or the default layer
        rgblight_setrgb(15, 106, 139);
        break;
    }
    old_layer = new_layer;
  }
  #endif
}

