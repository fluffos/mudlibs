#include <defines.h>
#include <moredef.h>
#include <properties.h>
#include <wizlevels.h>
#include <moving.h>
#include <new_skills.h>
#include <ansi.h>
#include <combat.h>
#include <class.h>


#define AMAZONEN "/gilden/amazonen/"
#ifndef NPC
#define NPC     AMAZONEN "npc/"
#endif
#ifndef OBJ
#define OBJ     AMAZONEN "obj/"
#endif
#ifndef ARMOUR
#define ARMOUR  AMAZONEN "armour/"
#endif
#ifndef WEAPON
#define WEAPON  AMAZONEN "weapon/"
#endif
#ifndef LOG
#define LOG     AMAZONEN "log/"
#endif
#ifndef ROOM
#define ROOM    AMAZONEN "room/"
#endif

#define AMASTER      AMAZONEN "master/amazonenmaster"
#define MEMBERLIST   AMAZONEN "members/members"
#define MEMBERBACKUP AMAZONEN "members/members_backup"
#define SAVEMASTER   "/gilden/obj/savefilemaster"
#define TOPLIST      AMAZONEN "members/toplist"
#define REALTOPLIST  AMAZONEN "members/toplist.read"

// Spell-Talentpunkte (Verbesserungen einzelner Spells)
#define AMAZONEN_TALENTMASTER   AMAZONEN "master/talentmaster"
#define AMAZONEN_TALENT_SAVE    AMAZONEN "members/spell_talents"
#define AMAZONEN_TALENT_BACKUP  AMAZONEN "members/spell_talents_backup"

#define GUILD_NPC_ID "amazonenkoenigin"
#define GUILD_ITEM "\namazonen_guild_item"
#define GUILD_ITEM_FILENAME ARMOUR "guilditem.lpc"
#define GUILD_NPC_SHORT "Hippolyte, die Amazonenkoenigin"
#define GUILD_NPC_NAME "Hippolyte"
#define GUILD_NPC NPC "hippolyte"
#define GUILDNAME "amazonen"
#define SPELLBOOK "/spellbooks/amazonen_spells"
#define SPELLBOOK_FILE "amazonen_spells"
#define GUILD "/gilden/amazonen"
#define GUILD_UID "GUILD.amazonen"
#define SPELL_UID "GUILD.amazonen_spells"

#define POS_GLVL 0
#define POS_XP 1
#define POS_LEVEL 2
#define POS_ALIGN 3
#define POS_TASKS 4
#define POS_RACE 5
#define POS_WEAPON 6
#define POS_REPORT 7
#define POS_REPCOLOR 8
#define POS_ARMOUR 9
#define POS_EMPTY1 10
#define POS_EMPTY2 11
#define POS_EMPTY3 12
#define POS_EMPTY4 13
#define POS_EMPTY5 14
#define POS_ORDER  15

#ifndef DB
#define DB(x) if( find_player("feyaria") ) tell_object(find_player("feyaria"),x)
#endif

#define pDebug(a, b) if(a->QueryProp(P_TESTPLAYER) || IS_WIZARD(a)) tell_object(a, ANSI_GREEN+b+ANSI_NORMAL);

#define XP_PER_LEVEL\
  ({10000, 25000, 50000, 100000, 150000, 250000, 300000, 350000,\
	400000, 450000, 500000, 1000000, 2000000, 3500000, 5000000})

#define RES_CHECKER "/gilden/obj/restriction_checker"

#define LATEST_GUILDITEM_VERSION "25.1.2005"  

#define GUILD_WIZARDS ({"feyaria", "aaliyah"})  

#define STRAHLENKRANZ "\namanzonen_strahlenkranz"
#define AMAZON_SPEED "\namazonen_speed"
#define AMAZON_LIFE "\namazonen_life"
#define AMAZON_SELF "\namazonen_self"
#define AMAZON_PROVOZIEREN "\namazonen_provozieren"
#define AMAZON_STANDHAFTIGKEIT "\namazonen_standhaftigkeit"

#define gem2dt ([\
    "diamant": DT_EXPLOSION; "explosiven",\
    "rubin": DT_FIRE; "feurigen",\
    "saphir": DT_COLD; "eisigen",\
    "smaragd": DT_POISON; "giftigen",\
    "aquamarin": DT_WATER; "waessrigen",\
    "granat": DT_LIGHTNING; "blitzenden",\
    "topas": DT_AIR; "luftigen",\
    "zirkon": DT_ELECTRIC; "geladenen",\
    "onyx": DT_TERROR; "schrecklichen",\
    "lapislazuli": DT_ACID; "saeuretriefenden",\
    "opal": DT_MAGIC; "magischen",\
    "bernstein": DT_LIGHT; "hellen",\
    "amethyst": DT_SOUND; "lauten",\
    "tigerauge": DT_MIND; "geistigen",\
    "bergkristall": DT_HOLY; "heiligen",\
    "turmalin": DT_UNHOLY; "daemonischen",\
    ])

#define BSC(x) break_string(x, caster->QueryProp(P_SCREENWIDTH))
 
#define XP_RATIO 66

#include "./amazonen_extern.h"  

#include "./directions.h"  

#include "./quests.h"

#define SK_PRECOGNITION "vorahnung"

#define SI_SKILLPOINTS "Skillpoints"
