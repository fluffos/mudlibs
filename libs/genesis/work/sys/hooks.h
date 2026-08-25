/*
 * /sys/hooks.h
 *
 * This file contains definition of the hooks the mudlib define which other
 * objects can hook into.
 *
 * Each hook definition should be accompanied with a comment block which
 * describes when the hook is called and with what arguments.
 *
 * The functions to register callbacks reside in /lib/hooks.c
 */
#ifndef HOOKS_DEFINED
#define HOOKS_DEFINED


#define HOOK_COOLDOWN_REFRESH       ("_cooldown_refresh")
#define HOOK_COOLDOWN_EXPIRED       ("_cooldown_expired")
#define HOOK_COOLDOWN_START         ("_cooldown_start")

/*
 * Triggered when a living kills something
 * From: do_die
 * Arguments: (object) - The killed enemy
 */
#define HOOK_LIVING_KILLED      "_hook_living_killed"

/*
 * Triggered in the enemies remaining behind when a living leaves combat.
 * From: cb_adjust_combat_on_move
 * Arguments: (object) - The fleeing enemy
 */
#define HOOK_LIVING_HUNTING     "_hook_living_hunting"

/*
 * Triggered when a living leaves combat and becomes hunted by other livings.
 * From: cb_adjust_combat_on_move
 * Arguments: (object *) - those hunting
 */
#define HOOK_LIVING_HUNTED      "_hook_living_hunted"

/*
 * Triggered when a living has moved into a new room or subloc.
 * From: move_living
 */
#define HOOK_LIVING_MOVED      "_hook_living_moved"

/*
 * Triggered by heart_beat when in combat.
 * From: heart_beat
 * Arguments: (object)   - me         - The living object
 *            (object *) - enemies    - Array holding all living I hunt
 *            (object)   - attack_ob  - Current enemy
 *            (float)    - speed      - The speed of the living object
 */
#define HOOK_HEART_BEAT_IN_COMBAT "_hook_heart_beat_in_combat"

/*
 * Triggered when a stat changes value.
 *
 * Arguments: int stat  - The stat
 *            int value - The new value
 */
#define HOOK_STAT_CHANGED        "_hook_stat_changed"

/*
 * Triggered when a skill changes value.
 *
 * Arguments: int skill  - The skill
 *            int value - The new value
 */
#define HOOK_SKILL_CHANGED       "_hook_skill_changed"

#endif
