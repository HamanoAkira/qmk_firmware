// Copyright 2024 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"
#include "lib/oled.h"
#include <stdio.h>

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        /* 90/270 turn the panel a quarter turn to read horizontally without
         * tilting your head, but that also shrinks the usable width down to
         * ~5 characters (128x32 panel rotated a quarter turn) - too narrow.
         * Back to the wider 128-wide layout, just flipped 180 for mounting. */
        return OLED_ROTATION_180;
    }
    return rotation;
}

/* Not called by default anymore (see oled_task_kb) - kept around so the
 * daemon/frog art can be brought back later, e.g. bound to a key or used as
 * an idle screensaver. */
__attribute__((unused)) static void render_watson(void) {
    static const char PROGMEM watson[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,248,248,112,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,248,254, 62, 14,128,128,128,128,128,128,128,128,128,192,240,240,160,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,240,255,255, 31,  0,  0,  0,  0,128,224,240,224,  0,  0,  0,  0,  0,128,224,248,254, 31, 15,129,128,192,192,129,193,129,  1,  1,  1,129,241,255,255, 15,  3,  1,  1,129,193,225,241,241, 99,131,195,192,192,192,192,128,  0,  0,192,192,192,  0,  0,128,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,248,255,255, 15,  0,192,240, 60, 31,  7,  3,255,255,  0,128,224,248,254, 31, 15,  1, 56, 60,127, 55, 27, 29, 63, 63,127, 51, 48, 24, 28,127,127,239, 96, 48,216,204,254,255,127, 19, 24, 12, 30, 63,127, 97,112, 59, 31, 15,122,255,127, 55, 24, 12,  6, 31, 63,127, 55, 48, 24, 12,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 31, 63, 63, 30,  7,  3,  0,  0,  0,  0,  0, 31, 63, 62, 31,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };

    oled_write_raw_P(watson, sizeof(watson));
}

/* Mirrors keymaps/custom/global_vars.h's key_display_sync_t. This file lives
 * outside the active keymap and can't include that header, so the layout has
 * to be kept in sync by hand. */
typedef struct {
    char    text[24];
    uint8_t seq;
} key_display_sync_t;

extern key_display_sync_t key_display;
extern uint32_t           key_display_updated_at;

/* Ordinal-matched to keymaps/custom/keymap.c's `enum layers` - keep in sync. */
static const char *const oled_layer_names[] = {
    "Base", "Num", "Fn", "Nav", "Sym", "RGB", "Komo1", "Komo2", "Game", "Game+Num", "Game+Fn", "F13", "SymR",
};

static void render_layer_and_key(void) {
    char line[22];

    uint8_t layer = get_highest_layer(layer_state);
    snprintf(line, sizeof(line), "Layer: %s", layer < ARRAY_SIZE(oled_layer_names) ? oled_layer_names[layer] : "?");
    oled_set_cursor(0, 0);
    oled_write_ln(line, false);

    oled_set_cursor(0, 1);
    oled_write_ln("", false);

    bool key_expired = timer_elapsed32(key_display_updated_at) > 2000;
    oled_set_cursor(0, 2);
    oled_write_ln(key_expired ? "" : key_display.text, false);

    oled_set_cursor(0, 3);
    oled_write_ln("", false);
}

bool oled_task_kb(void) {
    if (is_keyboard_master()) {
        if (!oled_task_user()) {
            return false;
        }
        render_layer_state();
        return false;
    }

    static uint32_t     slave_idle_timer         = 0;
    static matrix_row_t prev_matrix[MATRIX_ROWS] = {0};
    static bool         oled_sleeping             = false;

    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix_row_t row = matrix_get_row(i);
        if (row != prev_matrix[i]) {
            prev_matrix[i] = row;
            slave_idle_timer = timer_read32();
        }
    }

    bool is_idle = timer_elapsed32(slave_idle_timer) > 60000;

    if (is_idle) {
        if (!oled_sleeping) {
            oled_sleeping = true;
            oled_off();
        }
        return false;
    }

    if (oled_sleeping) {
        oled_sleeping = false;
        oled_clear();
    }

    render_layer_and_key();

    return false;
}
#endif
