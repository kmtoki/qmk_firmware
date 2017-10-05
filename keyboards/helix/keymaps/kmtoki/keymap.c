#include "helix.h"
#include "bootloader.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "tmk_core/protocol/lufa/LUFA-git/LUFA/Drivers/Peripheral/TWI.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif
#ifdef SSD1306OLED
//#include "ssd1306.h"
#include "ssd1306_graffiti.h"
#endif

extern keymap_config_t keymap_config;

//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum my_layer {
  QWERTY,
  LOWER,
  RAISE,
  MEDIA,
  ADJUST
};

enum custom_keycodes {
  _QWERTY = SAFE_RANGE,
  _LOWER,
  _RAISE,
  _MEDIA,
  _ADJUST,
  SSD1306_ON,
  SSD1306_OFF,
  BACKLIT,
  RGBLED_TOGGLE,
  RGBLED_STEP_MODE,
  RGBLED_INCREASE_HUE,
  RGBLED_DECREASE_HUE,
  RGBLED_INCREASE_SAT,
  RGBLED_DECREASE_SAT,
  RGBLED_INCREASE_VAL,
  RGBLED_DECREASE_VAL,
};


// Fillers to make layering more clear
#define ____ KC_TRNS
#define XXXX KC_NO

// for MacOS
#define NEXTTAB ACTION_MODS_KEY(MOD_LGUI, KC_RCBR)
#define PREVTAB ACTION_MODS_KEY(MOD_LGUI, KC_LCBR)

#ifdef SSD1306OLED
//#include "ssd1306.h"
#include "ssd1306_graffiti.h"
#endif

#if HELIX_ROWS == 5 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |EscCtl| A/MD |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  -   |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Enter |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [QWERTY] = KEYMAP( \
      KC_GRV,        KC_1,     KC_2,    KC_3,    KC_4,      KC_5,          KC_6,          KC_7,      KC_8,    KC_9,    KC_0,    KC_DEL,  \
      KC_TAB,        KC_Q,     KC_W,    KC_E,    KC_R,      KC_T,          KC_Y,          KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC, \
      CTL_T(KC_ESC), LT(MEDIA, KC_A),   KC_S,    KC_D,      KC_F,          KC_G,          KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT,       KC_Z,     KC_X,    KC_C,    KC_V,      KC_B,          KC_N,          KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_MINS, \
      MO(ADJUST),    KC_LCTL,  KC_LGUI, KC_LALT, MO(LOWER), SFT_T(KC_SPC), SFT_T(KC_ENT), MO(RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   ~  |   |  |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      | Kana |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [LOWER] = KEYMAP( \
      KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
      KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
      ____,    ____,    ____,  ____,    ____,   ____,    ____,    KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, ____,    \
      ____,    ____,    ____,  ____,    ____,   ____,    ____,    KC_TILD,  KC_PIPE, ____,    ____,    ____,    \
      ____,    ____,    ____,  ____,    ____,   ____,    ____,    KC_LANG1, ____,    ____,    ____,    ____     \
      ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   `  |   \  |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      | Eisu |      |      |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [RAISE] = KEYMAP( \
      KC_GRV, KC_1, KC_2, KC_3, KC_4,     KC_5, KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
      KC_GRV, KC_1, KC_2, KC_3, KC_4,     KC_5, KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
      ____,   ____, ____, ____, ____,     ____, ____, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, ____,    \
      ____,   ____, ____, ____, ____,     ____, ____, KC_GRV,  KC_BSLS, ____,    ____,    ____,    \
      ____,   ____, ____, ____, KC_LANG2, ____, ____, ____,    ____,    ____,    ____,    ____     \
      ),

  /* Media 
   * ,------+------+------+------+------+-------------+------+------+------+------+------.
   * |      |      |      |      |      |      | Prev |StpPly| Next |Mute  |VolDn |VolUp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      | WhUp | MsUp | WhDn |Pause | Home | PgDn |  Up  | PgUp |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      | MsLf | MsDn | MsRg |Insert| End  | Left | Down | Right|      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |Click2|Click1|PrevTB|NextTB|      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [MEDIA] = KEYMAP( \
      ____, ____, ____,    ____,    ____,    ____,    KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD, KC_VOLU, \
      ____, ____, KC_WH_U, KC_MS_U, KC_WH_D, KC_PAUS, KC_HOME, KC_PGDN, KC_UP,   KC_PGUP,  ____,    ____,    \
      ____, ____, KC_MS_L, KC_MS_D, KC_MS_R, KC_INS,  KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT, ____,    ____,    \
      ____, ____, ____,    ____,    ____,    ____,    ____,    ____,    ____,    ____,     ____,    ____,    \
      ____, ____, ____,    ____,    KC_BTN2, KC_BTN1, PREVTAB, NEXTTAB, ____,    ____,     ____,    ____     \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |Aud on|Audoff|AGnorm|AGswap|SSDOn |SSDOff|      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |RGB_TO|RGB_HI|RGB_HD|RGB_SI|RGB_SD|RGB_VI|RGB_VD|RGB_MD|      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |Reset |
   * `-----------------------------------------------------------------------------------'
   */
  [ADJUST] =  KEYMAP( \
      KC_F1, KC_F2, KC_F3, KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,       KC_F10,  KC_F11,  KC_F12, \
      ____,  ____,  ____,  ____,    ____,    ____,    ____,    ____,       ____,        ____,    ____,    ____,   \
      ____,  ____,  ____,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, SSD1306_ON, SSD1306_OFF, ____,    ____,    ____,   \
      ____,  ____,  ____,  RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,    RGB_VAI,     RGB_VAD, RGB_MOD, ____,   \
      ____,  ____,  ____,  ____,    ____,    ____,    ____,    ____,       ____,        ____,    ____,    RESET   \
      )
};
#else
#error "undefined keymaps"
#endif

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
float tone_goodbye[][2]    = SONG(GOODBYE_SOUND);
#endif

// ssd1306 display status
bool ssd1306_display_status = true;

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (ssd1306_display_status && record->event.pressed) {
    ssd1306_graffiti();
  }

  switch (keycode) {
    case SSD1306_ON:
      if (record->event.pressed) {
        ssd1306_on();
        ssd1306_display_status = true;
      }
      break;
    case SSD1306_OFF:
      if (record->event.pressed) {
        ssd1306_off();
        ssd1306_display_status = false;
      }
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
        backlight_step();
#endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      if (record->event.pressed) {
        rgblight_mode(RGB_current_mode);
        rgblight_step();
        RGB_current_mode = rgblight_config.mode;
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
#ifdef AUDIO_ENABLE
  startup_user();
#endif
  RGB_current_mode = rgblight_config.mode;
}

//SSD1306 OLED init and update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
void matrix_master_OLED_init (void) {
  TWI_Init(TWI_BIT_PRESCALE_1, TWI_BITLENGTH_FROM_FREQ(1, 800000));
  ssd1306_init();
  ssd1306_graffiti();
}

void matrix_scan_user(void) {
}
#endif

#ifdef AUDIO_ENABLE

void startup_user() {
  _delay_ms(20); // gets rid of tick
  PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user() {
  PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
  _delay_ms(150);
  stop_all_notes();
}

void music_on_user(void) {
  music_scale_user();
}

void music_scale_user(void) {
  PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (!eeconfig_is_enabled()) {
    eeconfig_init();
  }

  return MACRO_NONE;
}
