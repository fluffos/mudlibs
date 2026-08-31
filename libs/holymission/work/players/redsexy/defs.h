#define TPQN       TP->query_name()
#define FP         find_player()
#define TP         this_player()
#define TO         this_object()
#define PO         previous_object()
#define RNAME      query_real_name()
#define SNAME      query_short_name()
#define SHORT      short()
#define POS        query_possessive()
#define PRO        query_pronoun()
#define OBJ        query_objective()
#define CAP        capitalize
#define LOW        lower_case
#define LC         lower_case
#define MO         move_object
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
#define TPL        TP->LEVEL
#define ADDHP(x)   reduce_hit_point(-(x))
#define ADDSP(x)   restore_spell_points(x)
#define HIT(x)     hit_player(x)
#define HITP(x, y) hit_player(x, y)
#define MP         TP->MOVEP
#define AA          add_action
#define NAME       "redsexy"
#define E           environment
#define TELLR       tell_room
#define GLD          "/players/redsexy/guild/"
#define SUMM        9
