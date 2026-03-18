#include QMK_KEYBOARD_H
#include "global_vars.h"

#define PRNT_WIN LGUI(LSFT(KC_S))
#define PRNT_UBU LCTL(KC_LBRC)
#define ALT_F4 RALT(KC_F4)
#define SFT_TAB LSFT(KC_TAB)
#define CS_C RCS(KC_C)
#define CS_ESC RCS(KC_ESC)
#define SPC_2 LT(2, KC_SPC)
#define ENT_KM1 LT(6, KC_ENT)
#define TSPCH10 LT(10, MO(9))

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
};

enum custom_keycodes {
    F13_L = SAFE_RANGE,
    F13_K,
    F13_J,
    F13_H,
    F13_MIN,
    F13_ENT,
    F13_I,
    F13_Q,
    F13_UNS,
    F13_PLU,
    F13_SFL,
    F13_SFR,
    F13_X,
    F13_Y,
    F13_LFT,
    F13_DWN,
    F13_UP,
    F13_RGT,
    F13_8,
    F13_7,
    F13_6,
    F13_5,
    F13_4,
    F13_3,
    F13_2,
    F13_1,
    F13_PM,
    F13_PS,
    F13_SMIN,
    F13_SPLU,
    F13_TMN,
    F13_TF,
    F13_RT,
    REDO,
    ENT_F13,
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
                                          KC_LALT, ENT_KM1,   MO(1),      MO(3),   SPC_2, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),

    [layer1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SPC, XXXXXXX,                      KC_COMM,    KC_9,    KC_8,    KC_7, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_RCTL, KC_LSFT, KC_MINS,                       KC_DOT,    KC_6,    KC_5,    KC_4, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH,                         KC_0,    KC_3,    KC_2,    KC_1, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_ENT, _______,      MO(4), XXXXXXX, KC_RCTL
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
       KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     PRNT_UBU, KC_PGUP, XXXXXXX,    CS_C, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_RCTL, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, SFT_TAB, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   MO(5),                     PRNT_WIN, KC_PGDN,  ALT_F4,  CS_ESC, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_ENT,   MO(4),    _______,  KC_SPC, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),
    [layer4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_CAPS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,   KC_LT,                        KC_GT, KC_LCBR, KC_RCBR, KC_MINS, KC_PLUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,  KC_DQT,                      KC_PIPE, KC_LPRN, KC_RPRN,  KC_EQL, KC_UNDS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TG(8), XXXXXXX, XXXXXXX, KC_TILD,  KC_GRV, KC_QUOT,                      KC_BSLS, KC_LBRC, KC_RBRC,   KC_LT,   KC_GT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_ENT, _______,    _______,  KC_SPC, KC_RCTL
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
      XXXXXXX,   F13_1,   F13_2,   F13_3,   F13_4, F13_TMN,                        F13_H,   F13_J,   F13_K,   F13_L,   F13_I, XXXXXXX,
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

  // gaming layers
    [layer8] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_HOME,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           MO(10), TSPCH10,   MO(9),    _______,   SPC_2, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),

    [layer9] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4, _______,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_HOME,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_5,    KC_6,    KC_7,    KC_8, _______,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_9,    KC_0, _______, _______,   TG(8),                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_SPC, _______,    _______,   SPC_2, KC_RCTL
                                      //`--------------------------'  `--------------------------'
    ),

    [layer10] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_HOME,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_SPC, _______,    _______,   SPC_2, KC_RCTL
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

combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(back_combo, KC_BSPC),
    COMBO(copy_combo, LCTL(KC_C)),
    COMBO(cut_combo, LCTL(KC_X)),
    COMBO(paste_combo, LCTL(KC_V)),
    COMBO(ent_combo, KC_ENT),
    COMBO(undo_combo, LCTL(KC_Z)),
    COMBO(del_combo, KC_DEL),
    COMBO(right_alt_combo, KC_RALT),
    COMBO(right_sft_combo, KC_RSFT),
    COMBO(spc_combo, KC_SPC),
};

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

static bool process_f13_code16(uint16_t base_keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_F13);
        register_code16(base_keycode);
    } else {
        unregister_code16(base_keycode);
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

static bool process_f13_shift_code16(uint16_t base_keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(KC_F13);
        register_code16(base_keycode);
    } else {
        unregister_code16(base_keycode);
        unregister_code(KC_F13);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        idle_timer = timer_read32();
#ifdef OLED_ENABLE
        oled_on();
#endif
    }

    switch (keycode) {
        case REDO:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_Z);
            } else {
                unregister_code(KC_Z);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            return false;
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
        case F13_PLU:
            return process_f13_code16(KC_EQL, record);
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
        case F13_8:
            return process_f13_code(KC_8, record);
        case F13_7:
            return process_f13_code(KC_7, record);
        case F13_6:
            return process_f13_code(KC_6, record);
        case F13_5:
            return process_f13_code(KC_5, record);
        case F13_4:
            return process_f13_code(KC_4, record);
        case F13_3:
            return process_f13_code(KC_3, record);
        case F13_2:
            return process_f13_code(KC_2, record);
        case F13_1:
            return process_f13_code(KC_1, record);
        case F13_ENT:
            return process_f13_code(KC_ENT, record);
        case F13_SMIN:
            return process_f13_shift_code(KC_MINS, record);
        case F13_SPLU:
            return process_f13_shift_code16(KC_PLUS, record);
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

void keyboard_post_init_user(void) {
    idle_timer = timer_read32();
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_anim();
        return false;
    }
    return true;
}
#endif
