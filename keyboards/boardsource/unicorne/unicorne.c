// Copyright 2024 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"
#include "lib/oled.h"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_kb(void) {
    if (is_keyboard_master()) {
        if (!oled_task_user()) {
            return false;
        }
        render_layer_state();
        return false;
    }

    static const char PROGMEM watson[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,248,248,112,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,248,254, 62, 14,128,128,128,128,128,128,128,128,128,192,240,240,160,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,240,255,255, 31,  0,  0,  0,  0,128,224,240,224,  0,  0,  0,  0,  0,128,224,248,254, 31, 15,129,128,192,192,129,193,129,  1,  1,  1,129,241,255,255, 15,  3,  1,  1,129,193,225,241,241, 99,131,195,192,192,192,192,128,  0,  0,192,192,192,  0,  0,128,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,248,255,255, 15,  0,192,240, 60, 31,  7,  3,255,255,  0,128,224,248,254, 31, 15,  1, 56, 60,127, 55, 27, 29, 63, 63,127, 51, 48, 24, 28,127,127,239, 96, 48,216,204,254,255,127, 19, 24, 12, 30, 63,127, 97,112, 59, 31, 15,122,255,127, 55, 24, 12,  6, 31, 63,127, 55, 48, 24, 12,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 31, 63, 63, 30,  7,  3,  0,  0,  0,  0,  0, 31, 63, 62, 31,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };

    static uint32_t slave_idle_timer = 0;
    static matrix_row_t prev_matrix[MATRIX_ROWS] = {0};
    static bool oled_sleeping = false;
    static bool watson_written = false;

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

    if (!watson_written || oled_sleeping) {
        oled_sleeping = false;
        watson_written = true;
        oled_write_raw_P(watson, sizeof(watson));
    }

    return false;
}
#endif
