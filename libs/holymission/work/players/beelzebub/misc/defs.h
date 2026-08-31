/* Beelzebub's Macro File */ 

#define PATH      "/players/beelzebub/"
#define OBJ        PATH + "obj/"
#define WEAP       PATH + "weapons/"
#define MONS       PATH + "monsters/" 
#define PERS       PATH + "personal/" 
#define ROOM       PATH + "rooms/" 
#define MISC       PATH + "misc/" 
#define ARM        PATH + "armor/"
#define MWEAP      WEAP + "magic_weapons/"
#define NETH       ROOM + "netherworld/" 
#define CLAN       NETH + "c'lannesh/"
#define GALI       NETH + "galiphur/"
#define JATH       NETH + "jathnar/"
#define KOPA       NETH + "kopahk/"
#define PERI       NETH + "perilium/"
#define TKLO       NETH + "t'klom/"
#define TBP        NETH + "the_black_plains/"
#define ZYGG       NETH + "zyggogg/"
#define SERV       MONS + "servants/"
#define LORD       SERV + "demonlord/" 
#define GUILD      PATH + "guild/"
#define BIN        GUILD + "bin/"
#define SPELL      GUILD + "spells/"
#define AA         add_action
#define RPR        replace_program
#define TP         this_player()
#define TO         this_object()
#define NAME       query_name()
#define TPN        TP->NAME
#define RNAME      query_real_name()
#define TPRN       TP->RNAME
#define GLD        TP->query_guild()
#define HIT(x)     TP->hit_player(x)   
#define MPL        TP->move_player
#define SN         query_short_name()
#define SHT        short()
#define QPOS       query_possessive()  /*  his,  her,  its  */
#define QPRO       query_pronoun()     /*  he,   she,  it   */
#define QOBJ       query_objective()   /*  him,  her,  it   */
#define CAP        capitalize          
#define LOW        lower_case          
#define STR        query_str()
#define INT        query_int()
#define WIS        query_wis()
#define DEX        query_dex()
#define CON        query_con()
#define CHR        query_chr()
#define LVL        query_level()
#define SP         query_sp()
#define MAXSP      query_max_sp()
#define ADDSP(x)   restore_spell_points(x)
#define HP         query_hp()
#define GM         "guild/master"
#define CD         "sys/chatd"
#define MAXHP      query_max_hp()
#define ADDHP(x)   reduce_hit_point(-(x))
#define E          environment
#define ENV        environment()
#define TPL        TP->LVL
#define TRM        tell_room
#define TELL       tell_object
#define CLO        clone_object
#define MO         move_object
#define TR	   transfer
#define NFAIL      notify_fail

