
#define MAINTAINERS ({ "iwo", "angrox" })

#define IS_MAINTAINER(x) (member(MAINTAINERS, x)>-1)

#define GUILD_RESTRICTION_QP 30
#define GUILD_RESTRICTION_INT 10

#define HR "--------------------------------------------------\n"

#define MAX_SKILL 10000

#define Z_DIR "/gilden/zauberer/"
#define Z_WEAPON Z_DIR "weapon/"
#define Z_ARMOUR Z_DIR "armour/"
#define Z_OBJ Z_DIR "obj/"
#define Z_NPC Z_DIR "npc/"
#define Z_ROOM Z_DIR "room/"

#define Z_STICK Z_WEAPON "stab.lpc"
#define P_Z_COMBAT_STICK "z_combat_stick"
#define Z_COMBAT_STICK_TS "z_combat_stick_ts"
#define Z_COMBAT_STICK_FACTOR "z_combat_stick_factor"
#define Z_COMBAT_STICK_DT "z_combat_stick_dt"
#define Z_STICK_SKILLBONUS 100

#define Z_SHIELD_GENERATOR Z_OBJ "schildgenerator.lpc"
#define Z_SHIELD Z_ARMOUR "schild.lpc"
#define P_Z_SHIELD "z_shield"

#ifndef SI_SPELLNAME
#define SI_SPELLNAME "spellname"
#endif

#ifndef GUILD_LEVELS
#define GUILD_LEVELS 10
#endif

#ifndef GUILD_CIRCLES
#define GUILD_CIRCLES 3
#endif

#ifndef P_GUILD_CIRCLE
#define P_GUILD_CIRCLE "guild_circle"
#endif

#ifndef Z_FORMULA(x)
#define Z_FORMULA(x) (10000*x/(GUILD_LEVELS*GUILD_CIRCLES)) \
           - ((GUILD_LEVELS*GUILD_CIRCLES - x)*100) \
           + 10000-(10000*x/30)
#endif


