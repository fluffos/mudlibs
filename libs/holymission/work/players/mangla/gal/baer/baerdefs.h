#define PATH       "/players/baer/"
#define ROOM       PATH + "room/"
#define OBJS        PATH + "obj/"
#define MONSTER    PATH + "monster/"

#define TP         this_player()
#define TO         this_object()
#define NAME       query_name()
#define RNAME      query_real_name()
#define SNAME      query_short_name()
#define SHORT      short()
#define POS        query_possessive()
#define PRO        query_pronoun()
#define OBJ        query_objective()
#define CAP	   capitalize
#define LOW	   lower_case

#define STR        query_str()
#define INT 	   query_int()
#define WIS	   query_wis()
#define DEX	   query_dex()
#define CON	   query_con()
#define CHR	   query_cha()
#define LEVEL	   query_level()
#define SP	   query_sp()
#define MAXSP 	   query_max_sp()
#define HP	   query_hp()
#define MAXHP  	   query_max_hp()
#define ENV	   environment

#define TELL       tell_object
#define TELLR      tell_room
#define MOVE       move_object
#define MOVEP      move_player
#define FP         find_player
#define CLONE      clone_object
#define ALLINV     all_inventory

#define ADDHP(x)   reduce_hit_point(-(x))
#define ADDSP(x)   restore_spell_points(x)
#define HIT(x)     hit_player(x)
#define HITP(x, y) hit_player(x, y)

#include "/players/baer/ansi.h"

