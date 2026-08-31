#define PATH       "/players/topaz/"
#define ROOM       PATH + "rooms/"
#define OBJS       PATH + "obj/"
#define MNST       PATH + "monsters/"
#define WEAP       PATH + "weapons/"
#define ARMR       PATH + "armours/"
#define DEMONS     ROOM + "demons/"
#define TOWER      ROOM + "tower/"
#define GALL       ROOM + "galleria/"
#define ATTACH     ROOM + "attach/"
#define MAZE1      ROOM + "maze1/"
#define TRAIN      ROOM + "train/"
#define CONT       ROOM + "cont/"
#define GUILDS     ROOM + "guilds/"
#define RIVER      ROOM + "river/"
#define FOREST     ROOM + "forest/"
#define MOUNT      ROOM + "mountain/"
#define MDEMONS    MNST + "demons/"
#define MTOWER     MNST + "tower/"
#define MGALL      MNST + "galleria/"


#define TP         this_player()
#define TPN        TP->query_name()
#define TO         this_object()
#define NAME       query_name()
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
#define ALIGN      TP->query_alignment()
#define SP         query_sp()
#define MAXSP      query_max_sp()
#define HP         query_hp()
#define MAXHP      query_max_hp()
#define ENV        environment

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
#define RR\
{\
  ::reset();\
  replace_program("room/room");\
}
