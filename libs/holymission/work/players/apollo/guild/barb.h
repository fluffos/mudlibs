
#define GPATH "/players/apollo/guild/"
#define GROOMS "/players/apollo/guild/rooms/"
#define GOBJS "/players/apollo/guild/objs/"
#define GWEAPONS "/players/apollo/guild/weapons/"
#define GMONSTERS "/players/apollo/guild/monsters/"
#define GARMOUR "/players/apollo/guild/armour/"
#define BIN		"/players/apollo/guild/bin/"
#define GLOGS "/players/apollo/guild/logs/" 
#define GTEXT "/players/apollo/guild/TEXT/"

#define CHAT		"sys/chatd"->do_chat
#define GM "guild/master"
#define GS(x) (int)this_player()->get_skills(x)[0]
#define COST(x) x==100 ? "Already Bestest" : x*95 + x*5+400

#define NORM_STORE_WEA ("/players/apollo/guild/weapons/" + "guild_weap")
#define NORM_STORE_ARM ("/players/apollo/guild/armour/" + "guild_armour")

#define TPOBJ this_player()->query_objective()
#define TPPOS this_player()->query_possessive()

#define AO attacker_ob
#define EQN	(string)environment()->query_name()
#define NF	notify_fail
#define E	environment()
#define ENV	environment


#define RLM "religion/master"
#define RELIGION this_player()->query_religion()

#define MP move_player
#define TP this_player()
#define TPN TP->query_name()

#define TO this_object()
#define env environment

#define ROOMRESET reset(arg){ \
                  if(arg)\
	          set_light(1);
#define cap capitalize
#define CO clone_object
#define MO move_object
#define AA add_action
#define BREAKSTR #include "/players/apollo/guild/sys/break_string.h"

#define RACE query_race()
#define LEVEL	query_level()
#define LEGEND		query_legend_level()
#define RNAME	query_real_name()
#define CAP	capitalize
#define NAME	query_name()
#define QI	query_immortal()
#define QG	query_guild()
#define LF	log_file

#define MOVE TP->move_player
