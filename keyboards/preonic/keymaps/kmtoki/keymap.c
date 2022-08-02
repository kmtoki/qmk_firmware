#include QMK_KEYBOARD_H
#include "keymap_jp.h"

enum preonic_layers {
  _QWERTY = 0,
  _LOWER = 1,
  _RAISE = 2,
  _ADJUST = 3,
  _NICOLA = 4,
  _NICOLA_L = 5,
  _NICOLA_R = 6,
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  NICOLA,
  NICOLA_L,
  NICOLA_R,
  IME,
  WINDOWS,
  LINUX,
  DARWIN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | BS   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | IME  |NICORA| GUI  | ALT  |Lower |Space |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

[_QWERTY] = LAYOUT_preonic_grid( \
  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,    KC_DEL,  \
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS, \
  IME,       NICOLA,  KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_ENT, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   ~  |   |  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | HOME | PgDn | PgUp | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TILD, KC_PIPE, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   `  |   \  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | HOME | PgDn | PgUp | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_GRV,  KC_BSLS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | MS_U |      |      |      | WH_L | WH_D | WH_U | WH_R |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | MS_L | MS_D | MS_R |      |      |      | BTN1 | BTN2 | BTN3 | BTN4 | BTN5 |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, _______, KC_MS_U, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, \
  _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, AG_NORM, AG_SWAP, \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, DARWIN,  LINUX,   WINDOWS  \
),

/* Nicola
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  1   |  2   |   3  |  4   |  5   |  6   |  7   |  8   |  9   |  0   | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  。  |  か  |  た  |  こ  |  さ  |  ら  |  ち  |  く  |  つ  | 	、  | BS   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |  う  |  し  |  て  |  け  |  せ  |  は  |  と  |  き  |  い  |  ん  |  ，  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  ．  |  ひ  |  す  |  ふ  |  へ  |  め  |  そ  |  ね  |  ほ  |  ・  |  ー  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Qwerty|      | GUI  | ALT  | NCLS | Space| Enter| NCRS |  ←  |  ↓  |  ↑  |  →  |
 * `-----------------------------------------------------------------------------------'
 */
[_NICOLA] = LAYOUT_preonic_grid( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,   KC_6,   KC_7,     KC_8,    KC_9,    KC_0,     KC_DEL,   \
  KC_TAB,  JP_STOP, JP_KA,   JP_TA,   JP_KO,    JP_SA,  JP_RA,  JP_TI,    JP_KU,   JP_TU,   JP_COMMA, KC_BSPC,  \
  KC_LCTL, JP_U,    JP_SI,   JP_TE,   JP_KE,    JP_SE,  JP_HA,  JP_TO,    JP_KI,   JP_I,    JP_NN,    FL_COMMA, \
  KC_LSFT, FL_STOP, JP_HI,   JP_SU,   JP_HU,    JP_HE,  JP_ME,  JP_SO,    JP_NE,   JP_HO,   JP_DOT,   JP_MINS,  \
  QWERTY,  QWERTY,  KC_LGUI, KC_LALT, NICOLA_L, KC_SPC, KC_ENT, NICOLA_R, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT   \
),

/* Nicola Left Shift
 * ,-----------------------------------------------------------------------------------.
 * |      |  ？  |  ／  |  ～  |  「  |  」  |  ［  |  ］  |  （  |  ）  |  ＿  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ぁ  |  え  |  り  |  ゃ  |  れ  |  ぱ  |  ぢ  |  ぐ  |  づ  |  ぴ  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  を  |  あ  |  な  |  ゅ  |  も  |  ば  |  ど  |  ぎ  |  ぽ  |  っ  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  ぅ  |  ー  |  ろ  |  や  |  ぃ  |  ぷ  |  ぞ  |  ぺ  |  ぼ  |  ぉ  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NICOLA_L] = LAYOUT_preonic_grid( \
  _______, FL_QM,   FL_SOL,  FL_TILD, JP_LCB,  JP_RCB,  FL_LSB,  FL_RSB,  FL_LP,   FL_RP,   FL_LL,   _______, \
  _______, JP_XA,   JP_E,    JP_RI,   JP_XYA,  JP_RE,   JP_PA,   JP_DI,   JP_GU,   JP_DU,   JP_PI,   _______, \
  _______, JP_WO,   JP_A,    JP_NA,   JP_XYU,  JP_MO,   JP_BA,   JP_DO,   JP_GI,   JP_PO,   JP_XTU,  _______, \
  _______, JP_XU,   JP_MINS, JP_RO,   JP_YA,   JP_XI,   JP_PU,   JP_ZO,   JP_PE,   JP_BO,   JP_XO,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Nicola Right Shift
 * ,-----------------------------------------------------------------------------------.
 * |      |  ？  |  ／  |  ～  |  「  |  」  |  ［  |  ］  |  （  |  ）  |  ＿  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  ぁ  |  が  |  だ  |  ご  |  ざ  |  よ  |  に  |  る  |  ま  |  ぇ  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  ゔ  |  じ  |  で  |  げ  |  ぜ  |  み  |  お  |  の  |  ょ  |  っ  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  ぅ  |  び  |  ず  |  ぶ  |  べ  |  ぬ  |  ゆ  |  む  |  わ  |  ぉ  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NICOLA_R] = LAYOUT_preonic_grid( \
  _______, FL_QM,   FL_SOL,  FL_TILD, JP_LCB,  JP_RCB,  FL_LSB,  FL_RSB,  FL_LP,   FL_RP,   FL_LL,   _______, \
  _______, JP_XA,   JP_GA,   JP_DA,   JP_GO,   JP_ZA,   JP_YO,   JP_NI,   JP_RU,   JP_MA,   JP_XE,   _______, \
  _______, JP_VU,   JP_ZI,   JP_DE,   JP_GE,   JP_ZE,   JP_MI,   JP_O,    JP_NO,   JP_XYO,  JP_XTU,  _______, \
  _______, JP_XU,   JP_BI,   JP_ZU,   JP_BU,   JP_BE,   JP_NU,   JP_YU,   JP_MU,   JP_WA,   JP_XO,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

void matrix_init_user(void) {
  set_unicode_input_mode(UC_WINC);
  set_single_persistent_default_layer(_QWERTY);
}


bool is_ime = false;
bool is_nicola = false;
int os_mode = 0; // 0: windows, 1: linux, 2: darwin
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        if (is_nicola) {
          layer_off(_NICOLA);
        }
        is_nicola = false;
        is_ime = false;
        set_single_persistent_default_layer(_QWERTY);
        if (os_mode != 0) {
          tap_code(KC_LNG1);
        } else {
          tap_code16(LALT(KC_GRV));
        }
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case IME:
      if (record->event.pressed) {
        if (os_mode != 0) {
          if (is_ime) {
            tap_code(KC_LNG1);
          } else {
            tap_code(KC_LNG2);
          }
        } else {
          tap_code16(LALT(KC_GRV));
        }
        is_ime = !is_ime;
      }
      return false;
    case WINDOWS:
      if (record->event.pressed) {
        os_mode = 0;
        set_unicode_input_mode(UC_WINC);
      }
      return false;
    case LINUX:
      if (record->event.pressed) {
        os_mode = 1;
        set_unicode_input_mode(UC_LNX);
      }
      return false;
    case DARWIN:
      if (record->event.pressed) {
        os_mode = 2;
        set_unicode_input_mode(UC_MAC);
      }
      return false;
    case NICOLA:
      if (record->event.pressed) {
        is_nicola = true;
        is_ime = true;
        layer_on(_NICOLA);
        if (os_mode != 0) {
          tap_code(KC_LNG2);
        } else {
          tap_code16(LALT(KC_GRV));
        }
      }
      return false;
    case NICOLA_L:
      if (record->event.pressed) {
        layer_on(_NICOLA_L);
      } else {
        layer_off(_NICOLA_L);
      }
      return false;
    case NICOLA_R:
      if (record->event.pressed) {
        layer_on(_NICOLA_R);
      } else {
        layer_off(_NICOLA_R);
      }
      return false;
    case KC_LCTL:
    case KC_LALT:
    case KC_LGUI:
    case KC_LSFT:
    case KC_RCTL:
    case KC_RALT:
    case KC_RGUI:
    case KC_RSFT:
      if (is_nicola) {
        if (record->event.pressed) {
          layer_off(_NICOLA);
          layer_on(_QWERTY);
        }
        else {
          layer_off(_QWERTY);
          layer_on(_NICOLA);
        }
      }
      return true;
  }
  return true;
};
