#define PATH      "/players/helmut/"

#define AA         add_action
#define RPR        replace_program
#define TP         this_player()
#define TO         this_object()
#define NAME       query_name()
#define TPN        TP->NAME
#define RNAME      query_real_name()
#define TPRN       TP->RNAME
#define GLD        TP->query_guild()
#define MPL        TP->move_player
#define SN         query_short_name()
#define SHT        short()
#define QPOS       query_possessive()  /*  his,  her,  its  */
#define QPRO       query_pronoun()     /*  he,   she,  it   */
#define QOBJ       query_objective()   /*  him,  her,  it   */
#define CAP        capitalize          /*  e.g  He,  Tamina,  Its   */
#define LOW        lower_case          /*  e.g. he,  tamina,  its   */

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
#define MAXHP      query_max_hp()
#define ADDHP(x)   reduce_hit_point(-(x))
#define E          environment
#define ENV        environment()

#define TRM        tell_room
#define TOBJ       tell_object
#define CO         clone_object
#define MO         move_object
#define TR	   transfer
