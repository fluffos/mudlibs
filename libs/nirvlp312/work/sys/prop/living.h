#ifndef _sys_prop_living_h
#define _sys_prop_living_h

#define P_MMSGIN  "mmsgin"      /* income teleport message */
#define P_MMSGOUT "mmsgout"     /* leave teleport message */
#define P_MSGIN   "msgin"       /* arrive message */
#define P_MSGOUT  "msgout"      /* leave message */

#define P_MSGINVIS "msginvis"   /* disappearance message */
#define P_MSGVIS   "msgvis"     /* reappearance message */

#define P_NOT_FIGHTABLE "not_fightable"
#define P_CAN_FLY       "can_fly"

#define P_SKELETON "skeleton"
#define P_UNDEAD   "undead"
#define P_GHOST    "ghost"

//////////
// defines for the PROPERTIES mapping in LIB_RACE
// the next defines for more flexible autoheal

// how fast we heal
#define P_INTERVAL_BETWEEN_HEALING      "interval_between_healing"

// for how much we heal (in percent: 100 == 1 hp/sp)
#define P_REGENERATION_RATE             "regeneration_rate"

// "both": hp/sp are handled equally,
// "hp"  : all goes to hp
// "sp"  : all goes to sp
#define P_REGENERATION_MODE             "regeneration_mode"

// for the stats a player of a particular race can have
#define P_MAX_STR      "max_str"
#define P_MAX_DEX      "max_dex"
#define P_MAX_INT      "max_int"
#define P_MAX_MAG      "max_mag"
#define P_MAX_STA      "max_sta"
#define P_MAX_CHA      "max_cha"
#define P_MAX_LUC      "max_luc"
#define P_MAX_PIE      "max_pie"
#define P_MAX_STE      "max_ste"
#define P_MAX_WIL      "max_wil"

#endif /* _sys_prop_living_h */


