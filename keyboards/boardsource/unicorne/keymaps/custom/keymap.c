#include QMK_KEYBOARD_H
#include "global_vars.h"

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
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   MO(5),                     PRNT_WIN, KC_PGDN,  ALT_F4,  CS_ESC, XXXXXXX, XXXXXXX,
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

void housekeeping_task_user(void) {
#ifdef RGB_MATRIX_ENABLE
    if (timer_elapsed32(idle_timer) > 60000) {
        if (!rgb_sleeping) {
            rgb_sleeping = true;
            rgb_matrix_disable_noeeprom();
        }
    }
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        idle_timer = timer_read32();
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
