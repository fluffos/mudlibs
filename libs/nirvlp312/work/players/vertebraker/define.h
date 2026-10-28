#pragma combine_strings
#include <ansi.h>


#define DAE_DIR "players/vertebraker/daemons/"
#define ROOM "/players/vertebraker/closed/std/room"
#define WEAPON "obj/weapon"
#define ITEM "obj/treasure"
#define TREASURE ITEM
#define MONSTER "players/vertebraker/closed/std/monster"
#define ARMOUR "obj/armor"
#define NPC "players/vertebraker/closed/std/monster"
#define TP this_player()
#define tp this_player()
#define TO this_object()
#define ENV environment
#define TPN this_player()->query_name()
#define TPRN this_player()->query_real_name()
#define CAP capitalize
#define LOWER lower_case
#define POS TP->query_possessive()
#define MOCO move_object(clone_object
#define USER ENV()
#define OBJ TP->query_objective()
#define QN query_name()
#define RN query_real_name()
#define LEV query_level()
#define HP query_hp()
#define SP query_sp()
#define MO move_object
#define CO clone_object
#define MP move_player
#define LVL TP->query_level()
#define STRENGTH TP->query_attrib("str")
#define STAMINA TP->query_attrib("sta")
#define STEALTH TP->query_attrib("ste")
#define MAGIC TP->query_attrib("mag")
#define WILLPOWER TP->query_attrib("wil")
#define PIETY TP->query_attrib("pie")
#define INTELLIGENCE TP->query_attrib("int")
#define LUCK TP->query_attrib("luc")
#define ALIGNMENT TP->query_alignment()
#define FAIL notify_fail
#define Q BOLD+"\""+NORM
#define GUIDE "/players/vertebraker/closed/std/monster_guide.lpc"
#define QA query_attack()
#define GUIDE_HP GUIDE->get_value("hp")
#define PO previous_object()
#define TPL TP->query_level()
#define EUSER environment(USER)
#define GUIDE_WC GUIDE->get_value("wc")
#define GUIDE_AC GUIDE->get_value("ac")
#define CONTAINER "/obj/container"
#define DIRECTORY "/players/vertebraker/closed/std/xdir"
#define AO attacker_ob
#define TOU(x) if(USER) tell_object(USER, x);
#define TRU(x) if(USER && ENV(USER)) tell_room(ENV(USER), x, ({ USER }));
#define TRE(x) if(USER) tell_room(USER, x, ({ TO }));
