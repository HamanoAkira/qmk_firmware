#pragma once

#include <stdint.h>

extern uint32_t idle_timer;

/* Synced master -> slave over the split RPC so the right OLED can show
 * the last key pressed. Mirrored (not shared via this header) in unicorne.c
 * since that file lives outside the keymap and can't include this header. */
typedef struct {
    char    text[24];
    uint8_t seq;
} key_display_sync_t;

extern key_display_sync_t key_display;
extern uint32_t           key_display_updated_at;
