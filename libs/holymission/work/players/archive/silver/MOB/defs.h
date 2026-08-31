// defs.h 
// these are the definitions I mean to use
// I'll probably find some others on my way coding but these came first
// to my mind

// some dirs
#define ROOM    "/players/silver/MOB/rooms/"
#define MONSTER "/players/silver/MOB/"
#define MOB_OK  "mob_ok" // or whatever the property will be

// room functions 
#define SS  set_short
#define SL  set_long
#define AA  add_action
#define CM  clone_object   // from clone_monster

// monster functions
#define SN   set_name 
#define SA   set_alias
#define SAN  set_alt_name 
#define SG   set_gender
#define SLVL set_level
#define SAGG set_aggressive
#define SW   set_whimpy
#define SR   set_race
#define SAL  set_al
#define SWC  set_wc
#define SAC  set_ac
#define SHP  set_hp
#define SSP  set_sp
#define SSM1 set_spell_mess1
#define SSM2 set_spell_mess2
#define SSD  set_spell_damage
#define SCH  set_chance
#define LCH	 load_chat
#define LACH load_a_chat
#define AM   add_money

// player general
#define QNAME      query_name()
#define QRNAME     query_real_name()
#define QSNAME     query_short_name()
#define QPOS       query_possessive()
#define QPRO       query_pronoun()
#define QOBJ       query_objective()

#define TP         this_player()
#define TPN        TP->QNAME
#define TPRN       TP->QRNAME
#define TPSN       TP->QSNAME
#define TPPOS      TP->QPOS   
#define TPPRO      TP->QPRO   
#define TPOBJ      TP->QOBJ   

// player stats
#define TPSTR        TP->query_str()
#define TPINT        TP->query_int()
#define TPWIS        TP->query_wis()
#define TPDEX        TP->query_dex()
#define TPCON        TP->query_con()
#define TPCHA        TP->query_chr()
#define TPLVL        TP->query_level()
#define TPALIGN      TP->query_alignment()
#define TPSP         TP->query_sp()
#define TPHP         TP->query_hp()
#define TPMAXSP      TP->query_max_sp()
#define TPMAXHP      TP->query_max_hp()

// sometimes you might care about other then this_player
#define QSTR        query_str()
#define QINT        query_int()
#define QWIS        query_wis()
#define QDEX        query_dex()
#define QCON        query_con()
#define QCHA        query_chr()
#define QLEVEL      query_level()
#define QALIGN      query_alignment()
#define QSP         query_sp()
#define QMAXSP      query_max_sp()
#define QHP         query_hp()
#define QMAXHP      query_max_hp()

// change stats
#define ADDHP(x)    reduce_hit_point(-(x))
#define ADDSP(x)    restore_spell_points(x)

#define HIT         hit_player

// objects 
#define TO this_object()

// commands 
#define ENV environment
#define CAP capitalize
#define LOW lower_case
#define TRF transfer
#define DEST destruct
#define CO call_out

#define SAY(x) tell_room(environment(),x)

// and many others on its way ...
