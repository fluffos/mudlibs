#define PATH      "/players/jug/"
#define ROOM       PATH + "room/"
#define OBJS       PATH + "obj/"
#define MNST       PATH + "monster/"
#define WEAP       PATH + "weapons/"
#define GARDEN     PATH + "garden/"
#define PALACE     PATH + "palace/"

#define TP         this_player()
#define TO         this_object()
#define NAME       query_name()
#define PNAME      TP->query_name()
#define RNAME      query_real_name()
#define SNAME      query_short_name()
#define SHORT      short()
#define POS        query_possessive()
#define PRO        query_pronoun()
#define OBJ        query_objective()
#define CAP        capitalize
#define LOW        lower_case

#define STR        query_str()
#define INT        query_int()
#define WIS        query_wis()
#define DEX        query_dex()
#define CON        query_con()
#define CHA        query_cha()
#define LEVEL      query_level()
#define SP         query_sp()
#define MAXSP      query_max_sp()
#define HP         query_hp()
#define MAXHP      query_max_hp()
#define E     environment
#define ENV        environment()
#define GUILD      TP->query_guild()

#define TELL       tell_object
#define TELLR      tell_room
#define MOVE       move_object
#define MOVEP      TP->move_player

#define ADDHP(x)   reduce_hit_point(-(x))
#define ADDSP(x)   restore_spell_points(x)
#define HIT(x)     hit_player(x)
#define HITP(x, y) hit_player(x, y)

#define NF        notify_fail
