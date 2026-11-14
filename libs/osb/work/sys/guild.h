#ifndef _GUILD_
#define _GUILD_

#include "properties.h"

#define G_GUILDOFFICE "/std/guild"
#define G_GUILDOBJ "/obj/lib/guildobj"

// Mageguild supports advanceing of Wisdom and Stamina and similar Attrs
#define G_MAGEGUILD "/p/magic/std/mageguild"

// Guilds which got implemented and approved:
#define GC_ABJURER "abjurer"  // for the new mages
#define GC_ADVENTURER "adventurer"
#define GC_ARCHMAGE "archmage"  // to be removed when the new mages are ready
#define GC_BARD "bard"
#define GC_CONJURER "conjurer"
#define GC_DRUID "druid" 
#define GC_ENCHANTER "enchanter"  // for the new mages
#define GC_ILLUSIONIST "illusionist"  // for the new mages
#define GC_JEDI "jedi"  // Cormallon is working on them
#define GC_JESTER "jester" // Thragor is working on it
#define GC_NECROMANCER "necromancer" // Joerns old necromancer project
#define GC_PALADIN "paladin"
#define GC_PSIONIC "psionic"
#define GC_SORCERER "sorcerer"
#define GC_THIEF "thief"  // not ready so far
#define GC_TRANSMUTER "transmuter"  // for the new mages
#define GC_VAMPIRE "vampire"
#define GC_WARRIOR "warrior"

#define GC_APPROVED ({GC_ADVENTURER,GC_BARD,GC_CONJURER,GC_VAMPIRE,\
                      GC_WARRIOR,GC_ARCHMAGE,GC_PALADIN,GC_SORCERER,\
                      GC_DRUID,GC_PSIONIC})

#define G_LEADER     "gl"
#define G_VICELEADER "vgl"
#define G_MEMBER     "mb"
#define G_CREATOR    "cr"
#define G_MINSTATS ([P_CON:1,P_STR:1,P_DEX:1,P_INT:1])
#define G_MAXSTATS ([P_CON:20,P_STR:20,P_DEX:20,P_INT:20])
#define G_LLP_LIMIT  80  // Sum of race modified LLP MaxStats
#define G_HLP_LIMIT  120 // Sum of race modified HLP MaxStats
#define G_COSTS ([50:508000000,\
        49:476000000, 48:445000000, 47:415000000, 46:386000000, 45:358000000,\
        44:331000000, 43:305000000, 42:280000000, 41:256000000, 40:233000000,\
        39:211000000, 38:190000000, 37:170000000, 36:151000000, 35:133000000,\
        34:116000000, 33:100000000, 32: 85000000, 31: 71000000, 30: 58000000,\
        29: 46000000, 28: 35000000, 27: 25000000, 26: 17085937, 25: 11390625,\
        24:  7593750, 23:  5062500, 22:  3375000, 21:  2250000, 20:  1500000,\
        19:   998506, 18:   665671, 17:   443781, 16:   295854, 15:   197236,\
        14:   131491, 13:    87661, 12:    58441, 11:    38961, 10:    25974,\
         9:    17316,  8:    11544,  7:     7696,  6:     5131,  5:     3421,\
         4:     2281,  3:     1521,  2:     1014,  1:        0])

#define CALC_DEC(x) (x/5)  // how much XP to reduce when leaving the guild
#define MAX_DEC_XP 10000000 // how much XP to loose at max.

#define Q_LEVEL   0
#define Q_CREATOR 1
#define Q_SHORT   2
#define Q_LONG    3

#define MEMBER_TIME 0
#define MEMBER_LEVEL 1
#define MEMBER_STAT 2
#define MEMBER_MSGS 3
#define MEMBER_EXTRA 4
#define MEMBER_ENTRIES 5 // Number of entries in the mapping

#define BANISH_TIME 0
#define BANISH_BANISHER 1
#define BANISH_REASON 2

#define ERR_NOPLAYER "No such player.\n"
#define ERR_NONAME "No name given.\n"
#define ERR_NOALLOW "You're not allowed to banish someone.\n"
#define ERR_ALREADY "This player is already banished.\n"
#define ERR_NOT_BANISHED "This player isn't banished.\n"
#define NO_ERR "Ok.\n"

#define ADV_OK 0
#define ADV_NOT_XP 1
#define ADV_NOT_LEVEL 2
#define ADV_OTHER_FIRST 3
#define ADV_TOO_HIGH 4
#endif
