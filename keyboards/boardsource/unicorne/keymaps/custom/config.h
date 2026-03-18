#pragma once

/* Tap behavior */
#define QUICK_TAP_TERM 0
#define TAPPING_TERM 200

/* RGB matrix defaults */
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#ifndef RGB_MATRIX_DEFAULT_MODE
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#endif
#ifndef RGB_MATRIX_DEFAULT_HUE
#    define RGB_MATRIX_DEFAULT_HUE 80
#endif
#ifndef RGB_MATRIX_DEFAULT_SAT
#    define RGB_MATRIX_DEFAULT_SAT 100
#endif
#ifndef RGB_MATRIX_DEFAULT_VAL
#    define RGB_MATRIX_DEFAULT_VAL 50
#endif

/* Combos */
#define COMBO_TERM 30
#define COMBO_ALLOW_ACTION_KEYS

/* Optional VIA layer count override */
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
