/* Taniwha 1995
 * This file contains the GP cost and lockouts  for various guild commands
 * It's arranged this way to make it easy to tweak things
 *
 */
// Backstab
#define BACKSTAB_LOCKOUT 10
#define HIDE_COST 1
#define SNEAK_COST 1
#define STEAL_COST 7
// lock on steal, relative level * this if you fail against a plyer
#define CAUGHT_LOCK 5
// peek
#define PEEK_GP_COST 2

// Berserk
#define BERSERK_LOCKOUT 10

//Ambush
#define AMBUSH_LOCKOUT 10
#define AMBUSH_COST -5

#define SLICE_LOCKOUT 150
#define SLICE_DIV 10
#define SLICE_COST 7


// Disarm
#define GPCOST_DISARM 10
#define HBLOCKOUT_DISARM 30

// Turn (clerical)
#define TURN_GP_COST 5
#define TURN_BASE 0
#define TURN_DESTROY_XP 5
#define TURN_AWAY_XP 10
#define TURN_LOCKOUT 50
