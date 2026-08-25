/*
 * wa_types.h
 *
 * This file defines the different types of weapons and armour
 * and thier damage modifers. Any weapon or armour int the game
 * must be of one these types. No other are accepted.
 */

#ifndef WA_TYPES_DEF
#define WA_TYPES_DEF

/*
 * GUIDANCE FOR WEAPONS and GUIDANCE FOR ARMOURS
 *
 * Can be found under /doc/man/general/weapon and /doc/man/general/armour
 *
 */

/*
 * Sublocations for tools
 */
#define SUBLOC_WIELD "wielded"
#define SUBLOC_WORNA "worn_a"
#define SUBLOC_WORN  "worn"
#define SUBLOC_HELD  "held"

/*
 * This defines the chance a recoverable weapon or armour has not to be
 * recovered. (/100)
 */
#define PERCENTAGE_OF_RECOVERY_LOST     0

/* Damage types
 *
 * The magic damage type MAGIC_DT is used to indicate that no ac will prevent
 * this type of attack.
 */

#define W_IMPALE    1
#define W_SLASH     2
#define W_BLUDGEON  4
#define MAGIC_DT    8 /* Not protected by armour. */

/* Number of regular damage types. */
#define W_NUM_DT    3

#define W_HAND_HIT  10
#define W_HAND_PEN  10
#define A_NAKED_MOD ({ 0, 0, 0 })

#define W_MAX_HIT   ({ 100, 50, 90, 30, 60, 30, 40 })
#define W_MAX_PEN   ({ 100, 50, 90, 30, 60, 30, 40 })

/*
 * Tool slots for humanoids.
 *
 * The armourtype is a bitwise combination of these slots. Some of the
 * slots correspond to hitlocations.
 *
 * There is also a magic flag that can be set in the armourtype, indicating
 * that the armour is magically enhanced.
 */

#define WA_BIT(x)  (1 << x)

#define TS_CHEST        WA_BIT(1)
#define TS_HEAD         WA_BIT(2)
#define TS_LEGS         WA_BIT(3)
#define TS_RARM         WA_BIT(4)
#define TS_LARM         WA_BIT(5)
#define TS_ROBE         WA_BIT(6)
#define TS_RHAND        WA_BIT(7)
#define TS_LHAND        WA_BIT(8)
#define TS_RWEAPON	WA_BIT(9)
#define TS_LWEAPON	WA_BIT(10)
#define TS_RFOOT        WA_BIT(11)
#define TS_LFOOT        WA_BIT(12)
#define TS_WAIST	WA_BIT(13)
#define TS_NECK		WA_BIT(14)
#define TS_LFINGER  	WA_BIT(15)
#define TS_RFINGER	WA_BIT(16)
#define TS_LWRIST       WA_BIT(17)
#define TS_RWRIST       WA_BIT(18)
#define TS_LANKLE       WA_BIT(19)
#define TS_RANKLE       WA_BIT(20)
#define TS_BACK         WA_BIT(21)
#define TS_REAR         WA_BIT(22)
#define TS_LEAR         WA_BIT(23)
#define TS_RHIP         WA_BIT(24)
#define TS_LHIP         WA_BIT(25)
#define TS_RSHOULDER    WA_BIT(26)
#define TS_LSHOULDER    WA_BIT(27)
#define TS_BROW         WA_BIT(28)
#define TS_EYES         WA_BIT(29)
#define TS_MOUTH        WA_BIT(30)

#define TS_HBODY        (TS_TORSO | TS_LEGS | TS_RARM | TS_LARM | TS_HEAD)
#define TS_TORSO        (TS_CHEST | TS_BACK)

/* Weapon hand, only applicable to humanoids
 *
 * Some of these are used as attack id's
 */
#define W_RIGHT     TS_RWEAPON
#define W_LEFT      TS_LWEAPON
#define W_BOTH      (W_RIGHT | W_LEFT)
#define W_FOOTR     TS_RFOOT
#define W_FOOTL     TS_LFOOT

#define W_ANYH      0               /* These mark that any hand is possible */
#define W_NONE      0

/*
 * Hitlocations for humanoids
 *
 * We need to define the A_ANY_ locations manually as it is not possible to
 * use such a complex calculation on the left hand side of a cast statement.
 */
#define A_BODY      	TS_TORSO
#define A_TORSO     	TS_TORSO
#define A_CHEST         TS_CHEST
#define A_HEAD      	TS_HEAD
#define A_NECK	    	TS_NECK
#define A_WAIST     	TS_WAIST

#define A_LEGS		TS_LEGS

#define A_R_ARM     	TS_RARM
#define A_L_ARM     	TS_LARM
#define A_ARMS     	(TS_RARM | TS_LARM)
#define A_ANY_ARM       (-48 /* -A_ARMS */)

#define A_R_HAND    	TS_RHAND
#define A_L_HAND    	TS_LHAND
#define A_HANDS    	(TS_RHAND | TS_LHAND)
#define A_ANY_HAND      (-384 /* -A_HANDS */)

#define A_R_FINGER  	TS_RFINGER
#define A_L_FINGER  	TS_LFINGER
#define A_FINGERS    	(TS_RFINGER | TS_LFINGER)
#define A_ANY_FINGER    (-98304 /* -A_FINGERS */)

#define A_R_FOOT    	TS_RFOOT
#define A_L_FOOT    	TS_LFOOT
#define A_FEET      	(TS_RFOOT | TS_LFOOT)
#define A_ANY_FOOT      (-6144 /* -A_FEET */)

#define A_R_WRIST       TS_RWRIST
#define A_L_WRIST       TS_LWRIST
#define A_WRISTS        (TS_RWRIST | TS_LWRIST)
#define A_ANY_WRIST     (-393216 /* -A_WRISTS */)

#define A_R_ANKLE       TS_RANKLE
#define A_L_ANKLE       TS_LANKLE
#define A_ANKLES        (TS_RANKLE | TS_LANKLE)
#define A_ANY_ANKLE     (-1572864 /* -A_ANKLES */)

#define A_R_EAR         TS_REAR
#define A_L_EAR         TS_LEAR
#define A_EARS          (TS_REAR | TS_LEAR)
#define A_ANY_EAR       (-12582912 /* -A_EARS */)

#define A_R_HIP         TS_RHIP
#define A_L_HIP         TS_LHIP
#define A_HIPS          (TS_RHIP | TS_LHIP)
#define A_ANY_HIP       (-50331648 /* -A_HIPS */)

#define A_R_SHOULDER    TS_RSHOULDER
#define A_L_SHOULDER    TS_LSHOULDER
#define A_SHOULDERS     (TS_RSHOULDER | TS_LSHOULDER)
#define A_ANY_SHOULDER  (-201326592 /* -A_SHOULDERS */)

#define A_BROW          TS_BROW
#define A_EYES          TS_EYES
#define A_MOUTH         TS_MOUTH
#define A_BACK          TS_BACK

#define A_ROBE      	TS_ROBE

#define A_SHIELD    	(-1536 /* -W_BOTH */)

/*
 * Magic flag, this is used in armourtypes in combination with tool slots.
 * Note that this is not a slot, any number of magic armours can be used.
 *
 * Magical combat tools can be used without allocating a tool slot.
 */
#define A_MAGIC     1

#define A_NO_T      16

#define A_UARM_AC   1

#define A_MAX_AC    ({ 100, 100, 100, 100, 100, 100, 100, 100, \
                       100, 100, 100, 100, 100, 100, 100, 100 })


/*
 * Hitloc Damage propagation Table
 */
#define HITLOC_PROPAGATION  ([ \
    A_TORSO:    (A_BODY | A_TORSO | A_R_HIP | A_L_HIP | A_BACK), \
    A_HEAD:     (A_NECK | A_R_EAR | A_L_EAR | A_BROW | A_EYES | A_MOUTH), \
    A_LEGS:     (A_WAIST | A_R_FOOT | A_L_FOOT | A_R_ANKLE | A_L_ANKLE), \
    A_R_ARM:    (A_R_HAND| A_R_FINGER | A_R_WRIST | A_R_SHOULDER), \
    A_L_ARM:    (A_L_HAND| A_L_FINGER | A_L_WRIST | A_L_SHOULDER) ])

/*
 * Hitloc Attack propagation Table
 */
#define ATTACK_TO_SLOT_PROPAGATION  ([ \
    W_BOTH:     (A_R_HAND | A_L_HAND), \
    W_FOOTR:    A_R_FOOT, \
    W_FOOTL:    A_L_FOOT, \
    W_RIGHT:    A_R_HAND, \
    W_LEFT:     A_L_HAND ])

#define SLOT_TO_ATTACK_PROPAGATION  ([ \
    (A_R_HAND | A_L_HAND):    W_BOTH, \
    A_R_FOOT:                 W_FOOTR, \
    A_L_FOOT:                 W_FOOTL, \
    A_R_HAND:                 W_RIGHT, \
    A_L_HAND:                 W_LEFT ])

/* Weapon types */

#define W_FIRST     (0)		/* The first weapon index */

#define W_SWORD     (W_FIRST + 0)
#define W_POLEARM   (W_FIRST + 1)
#define W_AXE       (W_FIRST + 2)
#define W_KNIFE     (W_FIRST + 3)
#define W_CLUB      (W_FIRST + 4)
#define W_MISSILE   (W_FIRST + 5)
#define W_JAVELIN   (W_FIRST + 6)
#define W_NO_T      (7)		/* The number of weapons defined */

/*
 * Drawbacks are arrange for each weapon type ({ dull, corr, break })
 * and types are ({ sword, polearm, axe, knife, club, missile, javelin })
 */
#define W_DRAWBACKS ({ ({ 5, 5, 7 }), ({ 5, 5, 7 }), ({ 5, 5, 7 }), \
                       ({ 5, 5, 7 }), ({ 5, 5, 7 }), ({ 5, 5, 7 }), \
                       ({ 5, 5, 7 }) })

#define W_WEIGHTS_OFFSET ({ 1000, 3000, 2000,  200, 1000,  500, 1500 })
#define W_WEIGHTS_FACTOR ({   40,   50,   50,   20,   25,   20,   30 })

#define W_NAMES ({ "sword", "polearm", "axe", "knife", "club", "missile weapon", "javelin" })

#endif
