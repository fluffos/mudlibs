
/*============================================================================
	BARBARIAN DEFINES
============================================================================*/

#define GPATH 		"/players/apollo/guild/"
#define GROOMS 		"/players/apollo/guild/rooms/"
#define GOBJS 		"/players/apollo/guild/objs/"
#define GWEAPONS 	"/players/apollo/guild/weapons/"
#define GMONSTERS 	"/players/apollo/guild/monsters/"
#define GARMOUR 	"/players/apollo/guild/armour/"
#define BIN		"/players/apollo/guild/bin/"
#define NORM_STORE_WEA	"/players/apollo/guild/weapons/guild_weap"
#define NORM_STORE_ARM	"/players/apollo/guild/armour/guild_armour"
#define GLOGS		"/players/apollo/guild/logs/"
#define GTEXT 		"/players/apollo/guild/TEXT/"
#define MEMBERS		"/players/apollo/guild/logs/guild_members/"

#define FS		file_size
#define LF		log_file
#define CAP		capitalize
#define NF		notify_fail

#define CHAT		"/sys/chatd.lpc"->do_chat

#define GM 		"guild/master"
#define RLM		"religion/master"

#define AA		add_action
#define MO		move_object
#define TO		this_object()
#define CO		clone_object
#define TP		this_player()

#define NAME		this_player()->query_name()
#define RNAME		this_player()->query_real_name()
#define QI		this_player()->query_immortal()
#define GUILD		this_player()->query_guild()
#define RACE		query_race()
#define LEVEL		query_level()
#define LEGEND		this_player()->query_legend_level()
#define RELIGION	this_player()->query_religion()
#define MOVE		this_player()->move_player
#define TPOBJ 		this_player()->query_objective()
#define TPPOS 		this_player()->query_possessive()

#define AO 		attacker_ob
#define EQN		(string)environment()->query_name()
#define ENV		environment
