#include QMK_KEYBOARD_H
#include "global_vars.h"
#include "transactions.h"
#include <string.h>

#define PRNT_WIN LGUI(LSFT(KC_S))
#define PRNT_UBU LCTL(KC_LBRC)
#define ALT_F4 RALT(KC_F4)
#define SFT_TAB LSFT(KC_TAB)
#define CS_C RCS(KC_C)
#define CS_ESC RCS(KC_ESC)
#define SPC_2 LT(2, KC_SPC)

/* Match original Corne animation behavior */
#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 200
#define ANIM_FRAME_TIME 45

enum layers {
    layer0,
    layer1,
    layer2,
    layer3,
    layer4,
    layer5,
    layer6,
    layer7,
    layer8,
    layer9,
    layer10,
    layer11,
    layer12,
};

enum custom_keycodes {
    F13_L = SAFE_RANGE,
    F13_K,
    F13_J,
    F13_H,
    F13_MIN,
    F13_I,
    F13_Q,
    F13_UNS,
    F13_SFL,
    F13_SFR,
    F13_X,
    F13_Y,
    F13_LFT,
    F13_DWN,
    F13_UP,
    F13_RGT,
    F13_4,
    F13_3,
    F13_2,
    F13_1,
    F13_PM,
    F13_PS,
    F13_TMN,
    F13_TF,
    F13_RT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [layer0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_HOME,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_ENT,   MO(1),      MO(3),   SPC_2, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),

    [layer1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC,    CS_C,                      KC_COMM,    KC_9,    KC_8,    KC_7, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_RCTL, KC_LSFT, KC_MINS,                       KC_DOT,    KC_6,    KC_5,    KC_4, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   MO(12), KC_SLSH,                         KC_0,    KC_3,    KC_2,    KC_1, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_ENT, _______,     MO(11), XXXXXXX, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),

    [layer2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F12,   KC_F9,   KC_F8,   KC_F7, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_RCTL, KC_LSFT, XXXXXXX,                       KC_F11,   KC_F6,   KC_F5,   KC_F4, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F10,   KC_F3,   KC_F2,   KC_F1, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_ENT, _______,    _______, _______, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),

    [layer3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     PRNT_UBU, KC_PGUP,   MO(4),    CS_C, XXXXXXX, TG(layer8),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_RCTL, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, SFT_TAB, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  MO(12),   MO(5),                     PRNT_WIN, KC_PGDN,  ALT_F4,  CS_ESC, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_ENT,  MO(11),    _______,  KC_SPC, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),


    [layer4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_CAPS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,   KC_LT,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,  KC_DQT,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD,  KC_GRV, KC_QUOT,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______, _______,    _______,  KC_SPC, KC_RCTL
                                      //`--------------------------'  `--------------------------'
  ),

    [layer5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DT_PRNT,   DT_UP, DT_DOWN, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+- -------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  QK_RBT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_ENT, _______,    _______,  KC_SPC, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),

  // komorebi 1 layers
    [layer6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        F13_Q, XXXXXXX, XXXXXXX, F13_SFL,   MO(7),  F13_RT,                       F13_PM, F13_SFL, F13_SFR,   F13_Q, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   F13_4,   F13_3,   F13_2,   F13_1, F13_TMN,                        F13_H,   F13_J,   F13_K,   F13_L,   F13_I, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, F13_MIN, KC_LSFT,  F13_TF,                        F13_4,   F13_3,   F13_2,   F13_1,  F13_PS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______, _______,    F13_UNS, KC_LSFT, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),

  // komorebi 2 layers
    [layer7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, F13_SFL, F13_SFR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      F13_LFT, F13_DWN,  F13_UP, F13_RGT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   F13_X,   F13_Y, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    F13_UNS,  F13_RT, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),

  // gaming layer: layer0 minus combos, enter/space swapped, Num/Alt hold into gaming2/gaming3
  // toggled on/off via Nav + Home (layer3's Home position is TG(layer8))
  // left ctrl replaced with alt (right half still has KC_RCTL on the thumb)
    [layer8] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MO(10),   SPC_2,   MO(9),      MO(3),  KC_ENT, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),

  // gaming2: numbers overlay, hold Num (layer8's MO(9)). a s d f z x c v e r -> 1 2 3 4 5 6 7 8 9 0, g -> esc, tab -> `
    [layer9] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV, _______, _______,    KC_9,    KC_0, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,  KC_ESC,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_5,    KC_6,    KC_7,    KC_8, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
    ),

  // gaming3: F-keys overlay, hold Alt (layer8's MO(10)). a s d f z x c v e r -> F1 F2 F3 F4 F5 F6 F7 F8 F9 F10
    [layer10] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______,   KC_F9,  KC_F10, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
    ),

  // F13-prefixed layer (hold layer0's MO(1), then MO(11) to reach this)
    [layer11] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_HOME,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_LSFT, KC_LCTL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_ENT, _______,    _______,  KC_SPC, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),

  // right-hand symbols (hold layer1's V key, or layer3's V key)
    [layer12] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_GT, KC_LCBR, KC_RCBR, KC_MINS, KC_PLUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PIPE, KC_LPRN, KC_RPRN,  KC_EQL, KC_UNDS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_BSLS, KC_LBRC, KC_RBRC,   KC_LT,   KC_GT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______,  KC_SPC, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),
};

const uint16_t PROGMEM esc_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM back_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM undo_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM right_alt_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM right_sft_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM spc_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM ctrl_combo[] = {KC_L, KC_SCLN, COMBO_END};

enum combo_indices {
    ESC_COMBO_IDX,
    BACK_COMBO_IDX,
    COPY_COMBO_IDX,
    CUT_COMBO_IDX,
    PASTE_COMBO_IDX,
    ENT_COMBO_IDX,
    UNDO_COMBO_IDX,
    DEL_COMBO_IDX,
    RIGHT_ALT_COMBO_IDX,
    RIGHT_SFT_COMBO_IDX,
    SPC_COMBO_IDX,
    CTRL_COMBO_IDX,
};

combo_t key_combos[] = {
    [ESC_COMBO_IDX]         = COMBO(esc_combo, KC_ESC),
    [BACK_COMBO_IDX]        = COMBO(back_combo, KC_BSPC),
    [COPY_COMBO_IDX]        = COMBO(copy_combo, LCTL(KC_C)),
    [CUT_COMBO_IDX]         = COMBO(cut_combo, LCTL(KC_X)),
    [PASTE_COMBO_IDX]       = COMBO(paste_combo, LCTL(KC_V)),
    [ENT_COMBO_IDX]         = COMBO(ent_combo, KC_ENT),
    [UNDO_COMBO_IDX]        = COMBO(undo_combo, LCTL(KC_Z)),
    [DEL_COMBO_IDX]         = COMBO(del_combo, KC_DEL),
    [RIGHT_ALT_COMBO_IDX]   = COMBO(right_alt_combo, KC_RALT),
    [RIGHT_SFT_COMBO_IDX]   = COMBO(right_sft_combo, KC_RSFT),
    [SPC_COMBO_IDX]         = COMBO(spc_combo, KC_SPC),
    [CTRL_COMBO_IDX]        = COMBO(ctrl_combo, KC_RCTL),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    uint8_t highest_layer = get_highest_layer(layer_state);
    return highest_layer != layer8 && highest_layer != layer9 && highest_layer != layer10;
}

static bool process_f13_code(uint16_t base_keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_F13);
        register_code(base_keycode);
    } else {
        unregister_code(base_keycode);
        unregister_code(KC_F13);
    }
    return false;
}

static bool process_f13_shift_code(uint16_t base_keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_F13);
        register_code(KC_LSFT);
        register_code(base_keycode);
    } else {
        unregister_code(base_keycode);
        unregister_code(KC_LSFT);
        unregister_code(KC_F13);
    }
    return false;
}

static bool rgb_sleeping = false;

static uint8_t f13_hold_count = 0;
static bool    f13_active_for_key[MATRIX_ROWS][MATRIX_COLS];

static bool key_display_dirty = false;

/* Right OLED key display: translate the custom F13-prefixed keycodes to a
 * short "F13+<key>" label, matching what process_f13_code/process_f13_shift_code
 * actually register. */
static bool f13_display_name(uint16_t keycode, char *out, size_t outlen) {
    switch (keycode) {
        case F13_L:
            snprintf(out, outlen, "F13+L");
            return true;
        case F13_UNS:
            snprintf(out, outlen, "F13+;");
            return true;
        case F13_K:
            snprintf(out, outlen, "F13+K");
            return true;
        case F13_J:
            snprintf(out, outlen, "F13+J");
            return true;
        case F13_H:
            snprintf(out, outlen, "F13+H");
            return true;
        case F13_I:
            snprintf(out, outlen, "F13+I");
            return true;
        case F13_Q:
            snprintf(out, outlen, "F13+Q");
            return true;
        case F13_MIN:
            snprintf(out, outlen, "F13+-");
            return true;
        case F13_SFL:
            snprintf(out, outlen, "F13+[");
            return true;
        case F13_SFR:
            snprintf(out, outlen, "F13+]");
            return true;
        case F13_X:
            snprintf(out, outlen, "F13+X");
            return true;
        case F13_Y:
            snprintf(out, outlen, "F13+Y");
            return true;
        case F13_LFT:
            snprintf(out, outlen, "F13+Left");
            return true;
        case F13_DWN:
            snprintf(out, outlen, "F13+Down");
            return true;
        case F13_UP:
            snprintf(out, outlen, "F13+Up");
            return true;
        case F13_RGT:
            snprintf(out, outlen, "F13+Right");
            return true;
        case F13_4:
            snprintf(out, outlen, "F13+4");
            return true;
        case F13_3:
            snprintf(out, outlen, "F13+3");
            return true;
        case F13_2:
            snprintf(out, outlen, "F13+2");
            return true;
        case F13_1:
            snprintf(out, outlen, "F13+1");
            return true;
        case F13_PM:
            snprintf(out, outlen, "F13+S-Ent");
            return true;
        case F13_PS:
            snprintf(out, outlen, "F13+P");
            return true;
        case F13_TMN:
            snprintf(out, outlen, "F13+S-F");
            return true;
        case F13_TF:
            snprintf(out, outlen, "F13+T");
            return true;
        case F13_RT:
            snprintf(out, outlen, "F13+S-R");
            return true;
        default:
            return false;
    }
}

/* Formats a plain basic keycode + currently-held mods the way neovim/which-key
 * shows a keypress: literal char for letters/digits/punctuation/space (case/
 * symbol already reflects shift), "<name>" for non-printable keys, and a
 * "<C-A-G-...>" prefix added whenever ctrl/alt/gui are held (shift only gets
 * its own "S-" prefix for the non-printable "<name>" keys, since it's baked
 * into the char otherwise). Returns false for anything it doesn't recognize. */
static bool basic_key_display(uint16_t keycode, uint8_t mods, char *out, size_t outlen) {
    char       core[8]     = {0};
    bool       named       = false;
    const bool has_shift   = mods & MOD_MASK_SHIFT;

    if (keycode >= KC_A && keycode <= KC_Z) {
        core[0] = (has_shift ? 'A' : 'a') + (keycode - KC_A);
    } else if (keycode >= KC_1 && keycode <= KC_0) {
        static const char digits[10]  = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
        static const char shifted[10] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')'};
        uint8_t            idx        = keycode - KC_1;
        core[0]                       = has_shift ? shifted[idx] : digits[idx];
    } else if (keycode == KC_SPC) {
        /* A plain space, not the bracket-named "<Space>" - the 3-key ticker
         * needs this to stay one character wide. */
        core[0] = ' ';
    } else {
        static const struct {
            uint16_t kc;
            char     norm;
            char     shift;
        } punct[] = {
            {KC_COMM, ',', '<'}, {KC_DOT, '.', '>'}, {KC_SLSH, '/', '?'}, {KC_SCLN, ';', ':'}, {KC_QUOT, '\'', '"'}, {KC_MINS, '-', '_'}, {KC_EQL, '=', '+'}, {KC_LBRC, '[', '{'}, {KC_RBRC, ']', '}'}, {KC_BSLS, '\\', '|'}, {KC_GRV, '`', '~'},
        };
        bool found = false;
        for (uint8_t i = 0; i < ARRAY_SIZE(punct); i++) {
            if (punct[i].kc == keycode) {
                core[0] = has_shift ? punct[i].shift : punct[i].norm;
                found   = true;
                break;
            }
        }

        if (!found) {
            static const struct {
                uint16_t    kc;
                const char *name;
            } names[] = {
                {KC_ENT, "CR"}, {KC_ESC, "Esc"}, {KC_TAB, "Tab"}, {KC_BSPC, "BS"}, {KC_DEL, "Del"}, {KC_LEFT, "Left"}, {KC_RGHT, "Right"}, {KC_UP, "Up"}, {KC_DOWN, "Down"}, {KC_HOME, "Home"}, {KC_END, "End"}, {KC_PGUP, "PgUp"}, {KC_PGDN, "PgDn"}, {KC_CAPS, "Caps"}, {KC_INS, "Ins"}, {KC_F1, "F1"}, {KC_F2, "F2"}, {KC_F3, "F3"}, {KC_F4, "F4"}, {KC_F5, "F5"}, {KC_F6, "F6"}, {KC_F7, "F7"}, {KC_F8, "F8"}, {KC_F9, "F9"}, {KC_F10, "F10"}, {KC_F11, "F11"}, {KC_F12, "F12"},
            };
            for (uint8_t i = 0; i < ARRAY_SIZE(names); i++) {
                if (names[i].kc == keycode) {
                    snprintf(core, sizeof(core), "%s", names[i].name);
                    named = true;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            return false;
        }
    }

    char   prefix[8] = {0};
    size_t plen      = 0;
    if (mods & MOD_MASK_CTRL) plen += snprintf(prefix + plen, sizeof(prefix) - plen, "C-");
    if (mods & MOD_MASK_ALT) plen += snprintf(prefix + plen, sizeof(prefix) - plen, "A-");
    if (mods & MOD_MASK_GUI) plen += snprintf(prefix + plen, sizeof(prefix) - plen, "G-");
    if (named && has_shift) plen += snprintf(prefix + plen, sizeof(prefix) - plen, "S-");

    if (named || prefix[0] != '\0') {
        snprintf(out, outlen, "<%s%s>", prefix, core);
    } else {
        snprintf(out, outlen, "%s", core);
    }
    return true;
}

/* Last 4 keys shown together as a short ticker, e.g. typing "this is a"
 * shows "is a" (oldest on the left), matching neovim/which-key style key
 * history rather than a single flashing keypress. */
static char     key_history[4][10]  = {{0}};
static uint8_t  key_history_idx     = 0;
static uint32_t last_key_press_time = 0;

/* Skips layer/momentary/combo-produced keycodes on purpose: the top of the
 * right OLED already shows the active layer, so the ticker only needs to
 * track keys that actually produce output. */
static void update_key_display(uint16_t keycode, keyrecord_t *record) {
    char text[sizeof(key_history[0])] = {0};

    /* LT(layer, kc)/MT(mod, kc) always deliver the *wrapping* keycode to
     * process_record_user, never the plain kc - so e.g. SPC_2 = LT(2, KC_SPC)
     * never satisfies IS_BASIC_KEYCODE below and got silently skipped even
     * when tapped (producing a real space). record->tap.count > 0 means this
     * particular press resolved to a tap, so pull the wrapped keycode back
     * out (LT/MT both pack it into the low byte, see quantum_keycodes.h) and
     * treat it like any other basic key. A tap.count of 0 means it's being
     * held for the layer/mod instead, which the layer name up top covers. */
    if (IS_QK_LAYER_TAP(keycode) || IS_QK_MOD_TAP(keycode)) {
        if (record->tap.count == 0) {
            return;
        }
        keycode = keycode & 0xFF;
    }

    /* Symbol aliases like KC_AT/KC_HASH/KC_TILD aren't their own keycode -
     * they're compile-time `LSFT(base_kc)` values (e.g. KC_AT == LSFT(KC_2)),
     * baked into the keymap rather than a physically-held shift. That fails
     * IS_BASIC_KEYCODE below just like LT/MT did, so unwrap it the same way:
     * pull the embedded mod and base keycode back out and let
     * basic_key_display's existing shift-aware tables (KC_2+shift='@',
     * KC_GRV+shift='~', ...) do the rest. */
    uint8_t extra_mods = 0;
    if (IS_QK_MODS(keycode)) {
        extra_mods = QK_MODS_GET_MODS(keycode);
        keycode    = QK_MODS_GET_BASIC_KEYCODE(keycode);
    }

    if (!f13_display_name(keycode, text, sizeof(text))) {
        if (!IS_BASIC_KEYCODE(keycode) || IS_MODIFIER_KEYCODE(keycode)) {
            return;
        }
        if (!basic_key_display(keycode, get_mods() | extra_mods, text, sizeof(text))) {
            return;
        }
    }

    /* If the ticker already faded out on screen (unicorne.c's
     * render_layer_and_key blanks it after the same 2000ms), don't glue the
     * new key onto the stale history sitting in the ring buffer - start
     * clean so only keys typed since the fade show up. */
    if (timer_elapsed32(last_key_press_time) > 2000) {
        memset(key_history, 0, sizeof(key_history));
        key_history_idx = 0;
    }
    last_key_press_time = timer_read32();

    snprintf(key_history[key_history_idx], sizeof(key_history[0]), "%s", text);
    key_history_idx = (key_history_idx + 1) % 4;

    key_display.text[0] = '\0';
    for (uint8_t i = 0; i < 4; i++) {
        uint8_t idx = (key_history_idx + i) % 4;
        size_t  len = strlen(key_display.text);
        snprintf(key_display.text + len, sizeof(key_display.text) - len, "%s", key_history[idx]);
    }

    key_display.seq++;
    key_display_dirty = true;
}

static void key_display_slave_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
    if (in_buflen == sizeof(key_display)) {
        memcpy(&key_display, in_data, sizeof(key_display));
        key_display_updated_at = timer_read32();
    }
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(RPC_ID_KEY_DISPLAY, key_display_slave_handler);
}

void housekeeping_task_user(void) {
#ifdef RGB_MATRIX_ENABLE
    if (timer_elapsed32(idle_timer) > 60000) {
        if (!rgb_sleeping) {
            rgb_sleeping = true;
            rgb_matrix_disable_noeeprom();
        }
    }
#endif

    /* transaction_rpc_send blocks on 4 back-to-back serial round-trips over the
     * same single-wire link the split transport uses to poll the right half's
     * matrix (see quantum/split_common/transactions.c: transaction_rpc_exec).
     * Firing it on every keystroke starved that polling and dropped keys from
     * the right half, so this is throttled per the QMK docs' recommendation
     * (docs/features/split_keyboard.md, "Custom data sync between sides"). */
    static uint32_t last_key_display_sync = 0;
    if (is_keyboard_master() && key_display_dirty && timer_elapsed32(last_key_display_sync) > 150) {
        /* Reset the throttle timer up front, on every attempt, not just on
         * success - if the send keeps failing (e.g. transport not connected
         * yet) and we only reset on success, this retries as fast as the
         * main loop spins instead of every 150ms, busy-looping on serial
         * I/O and starving matrix scanning for both halves. */
        last_key_display_sync = timer_read32();
        if (transaction_rpc_send(RPC_ID_KEY_DISPLAY, sizeof(key_display), &key_display)) {
            key_display_dirty = false;
        } else {
            dprint("[master] key_display RPC send failed\n");
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        idle_timer = timer_read32();
        update_key_display(keycode, record);
#ifdef RGB_MATRIX_ENABLE
        if (rgb_sleeping) {
            rgb_sleeping = false;
            rgb_matrix_enable_noeeprom();
        }
#endif
#ifdef OLED_ENABLE
        oled_on();
#endif
    }

    {
        uint8_t row         = record->event.key.row;
        uint8_t col         = record->event.key.col;
        bool    is_thumb_row = (row == 3 || row == 7);

        if (record->event.pressed) {
            if (get_highest_layer(layer_state) == layer11 && !is_thumb_row) {
                f13_active_for_key[row][col] = true;
                if (f13_hold_count == 0) {
                    register_code(KC_F13);
                }
                f13_hold_count++;
            } else {
                f13_active_for_key[row][col] = false;
            }
        } else if (f13_active_for_key[row][col]) {
            f13_active_for_key[row][col] = false;
            f13_hold_count--;
            if (f13_hold_count == 0) {
                unregister_code(KC_F13);
            }
        }
    }

    switch (keycode) {
        case F13_L:
            return process_f13_code(KC_L, record);
        case F13_UNS:
            return process_f13_code(KC_SCLN, record);
        case F13_K:
            return process_f13_code(KC_K, record);
        case F13_J:
            return process_f13_code(KC_J, record);
        case F13_H:
            return process_f13_code(KC_H, record);
        case F13_I:
            return process_f13_code(KC_I, record);
        case F13_Q:
            return process_f13_code(KC_Q, record);
        case F13_MIN:
            return process_f13_code(KC_MINS, record);
        case F13_SFL:
            return process_f13_code(KC_LBRC, record);
        case F13_SFR:
            return process_f13_code(KC_RBRC, record);
        case F13_X:
            return process_f13_code(KC_X, record);
        case F13_Y:
            return process_f13_code(KC_Y, record);
        case F13_LFT:
            return process_f13_code(KC_LEFT, record);
        case F13_DWN:
            return process_f13_code(KC_DOWN, record);
        case F13_UP:
            return process_f13_code(KC_UP, record);
        case F13_RGT:
            return process_f13_code(KC_RGHT, record);
        case F13_4:
            return process_f13_code(KC_4, record);
        case F13_3:
            return process_f13_code(KC_3, record);
        case F13_2:
            return process_f13_code(KC_2, record);
        case F13_1:
            return process_f13_code(KC_1, record);
        case F13_PM:
            return process_f13_shift_code(KC_ENT, record);
        case F13_PS:
            return process_f13_code(KC_P, record);
        case F13_TMN:
            return process_f13_shift_code(KC_F, record);
        case F13_TF:
            return process_f13_code(KC_T, record);
        case F13_RT:
            return process_f13_shift_code(KC_R, record);
    }

    return true;
}

#ifdef OLED_ENABLE
#include "ame.c"
#include "lib/oled.h"

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_anim();
    }
    return false;
}
#endif
