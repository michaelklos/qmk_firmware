// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _NUMPAD 6
#define _MOVEMENT 7
#define _ADJUST 16

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0
};

//Tap Dance Definitions
const qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
// ,[CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset)
// ,[CT_EGG] = ACTION_TAP_DANCE_FN (dance_egg)
// ,[CT_FLSH] = ACTION_TAP_DANCE_FN_ADVANCED (dance_flsh_each, dance_flsh_finished, dance_flsh_reset)
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

//Keymap Definitions
#define NUMPAD      MO(_NUMPAD)           //Activate NUMPAD layer
#define KC_SH_ENT   MT(MOD_LSFT, KC_ENT)  //Shift when held, Enter when tapped
#define KC_SH_F7    MT(MOD_LSFT, KC_F7)   //Shift when held, F7 when tapped
#define KC_ESC_CAPS TD(TD_ESC_CAPS)       //Tap Dance - Single==Escape, Double==Caps
#define KC_UNDR     LSFT(KC_MINS)         //UNDERSCORE


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Es/Cap|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Numpad|Lower |Sh/Ent| Spce |Raise | GUI  |   -  |   =  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSPO,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC},
  {KC_LCTL,      KC_LALT, KC_LGUI, NUMPAD,  LOWER,   KC_SH_ENT,  KC_SPC,  RAISE,   KC_RGUI, KC_MINS, KC_EQL, KC_ENT }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Undo | Cut  | Copy |Paste |      |      |   ^  |   &  |   *  |   [  |   ]  |  _   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Redo | Mute | Vol- | Vol+ |      |      |      |      |      |      |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_UNDO,  KC_CUT,   KC_COPY,     KC_PASTE,  _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_UNDR},
  {KC_AGAIN, KC__MUTE, KC__VOLDOWN, KC__VOLUP, _______, _______, _______, _______, _______, _______, _______, KC_BSLS},
  {_______,  _______,  _______,     _______,   _______, _______, _______, _______, _______, _______, KC_UP, _______},
  {_______,  _______,  _______,     _______,   _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |      |      |      |  Ins | Home | PgUp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2 |   F3  |  F4  |  F5  |  F6  |      |      |      |  Del |  End |PgDown|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Sh/F7 |  F8  |  F8  |  F10 |  F11 |  F12 |      |      |      |      |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,   KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,  _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP},
  {KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,    _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN},
  {KC_SH_F7, KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,   _______, _______, _______, _______, KC_UP,   _______},
  {_______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT}
},

/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * | Del  |  Up  | Bksp |      |      |      |NumLck|   7  |   8  |   9  |   *  |   -  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Left | Down |Right |      |      |      |      |   4  |   5  |   6  |   /  |   +  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   (  |      |   )  |      |      |      |      |   1  |   2  |   3  |   %  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |   ,  |   .  |   $  | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = {
  {KC_DEL,  KC_UP,   KC_BSPC, _______, _______, _______, KC_NLCK, KC_P7, KC_P8,   KC_P9,   KC_PAST, KC_PMNS},
  {KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, KC_P4, KC_P5,   KC_P6,   KC_PSLS, KC_PPLS},
  {KC_LPRN, _______, KC_RPRN, _______, _______, _______, _______, KC_P1, KC_P2,   KC_P3,   KC_PERC, KC_EQL },
  {_______, _______, _______, _______, _______, _______, _______, KC_P0, KC_PCMM, KC_PDOT, KC_DLR,  KC_PENT}
},

/* MOVEMENT
 * ,-----------------------------------------------------------------------------------.
 * |      |  Up  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Left | Down |Right |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |MousB1|MousUp|MousB2|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |MousLf|MousDn|MousRt|
 * `-----------------------------------------------------------------------------------'
 */
[_MOVEMENT] = {
  {_______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_L, KC_DOWN, KC_MS_R}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |Reset |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  }
}

};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        //LOWER used with both RAISE and NUMPAD
        if(IS_LAYER_ON(_NUMPAD)){
          update_tri_layer(_LOWER, _NUMPAD, _MOVEMENT);
        } else{
          update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
      } else {
        layer_off(_LOWER);
        if(IS_LAYER_ON(_NUMPAD)){
          update_tri_layer(_LOWER, _NUMPAD, _MOVEMENT);
        } else{
          update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
        update_tri_layer(_LOWER, _NUMPAD, _MOVEMENT);
      } else {
        layer_off(_NUMPAD);
        update_tri_layer(_LOWER, _NUMPAD, _MOVEMENT);
      }
      return false;
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
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif

