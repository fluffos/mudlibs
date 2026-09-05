/* 08/16/06 Earwax: Added some definitions */

#define WA_FACTOR       3
#define EXP_DIVISOR                     190
#define INTERVAL_BETWEEN_HEALING        10
#define WEAPON_CLASS_OF_HANDS           (3)
#define ARMOUR_CLASS_OF_BARE            0
#define MAX_LIST                        20
#define NAME_OF_GHOST                   "some mist"
#define MAXLEVEL_LOSS                   2
#define MAXEXP_LOSS                     3000000
#define MAXCOINS                        80000

/* Alignment Definitions */
#define ALIGN_EXP_DIVISOR               1800
#define KILL_NEUTRAL_ALIGNMENT          10
#define CAP_GOOD_ALIGN  1800
#define CAP_EVIL_ALIGN  -1800
#define ADJ_ALIGNMENT(al)               ((-al - KILL_NEUTRAL_ALIGNMENT)/4)

/* These are just used for alignment titles */
#define ALIGN_WHITE_LORD 640
#define ALIGN_PALADIN 320
#define ALIGN_CRUSADER 160
#define ALIGN_GOOD 80
#define ALIGN_HONORABLE 40
#define ALIGN_NEUTRAL -40
#define ALIGN_MALICIOUS -80
#define ALIGN_EVIL -160
#define ALIGN_INFAMOUS -320
#define ALIGN_BLACK_KNIGHT -640

/** hacked by verte 12-13-06 */
#define MAX_SOAK  (level * 8 + ex_lv * 2)
#define MAX_STUFF (level * 8 + ex_lv * 2)
#define MAX_INTOX ((level + 3) + (ex_lv / 5 + 1)) 
#define INFUSE_LIMIT (((9*level) + (9*ex_lv/4))/2)
#define SAVE_INTERVAL 400
#define IDLELIMIT 1800
#define NUMOBS_STOR 20
/** end */
