#define PATH       "/players/mangla/"
#define ROOM       PATH + "rooms/"
#define OBJS       PATH + "objects/"
#define MNST       PATH + "monsters/"
#define WEAP       PATH + "weapons/"
#define ARMR       PATH + "armour/"
#define OGRES      ROOM + "ogres/"
#define CASTLE     ROOM + "castle/"
#define LAKE       ROOM + "lake/"
#define CAMP       ROOM + "camp/"
#define UNDER      ROOM + "underdark/"
#define NEW        "/players/mangla/rooms/newbie/"


#define TP         this_player()
#define TO         this_object()
#define PO         previous_object()
#define NAME       query_name()
#define RNAME      query_real_name()
#define SNAME      query_short_name()
#define SHORT      short()
#define POS        query_possessive()
#define PRO        query_pronoun()
#define OBJ        query_objective()
#define CAP        capitalize
#define LOW        lower_case
#define LC         lower_case

#define STR        query_str()
#define INT        query_int()
#define WIS        query_wis()
#define DEX        query_dex()
#define CON        query_con()
#define CHA        query_chr()
#define LEVEL      query_level()
#define ALIGN      TP->query_alignment()
#define SP         query_sp()
#define MAXSP      query_max_sp()
#define HP         query_hp()
#define MAXHP      query_max_hp()
#define ENV        environment
#define ALL        all_inventory

#define TELL       tell_object
#define TELLR      tell_room
#define MOVE       move_object
#define MOVEP      move_player
#define TPL        TP->LEVEL

#define ADDHP(x)   reduce_hit_point(-(x))
#define ADDSP(x)   restore_spell_points(x)
#define HIT(x)     hit_player(x)
#define HITP(x, y) hit_player(x, y)

#define MP         TP->MOVEP

#include "/players/mangla/mentor/ansi.h"
