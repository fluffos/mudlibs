
#define IZE "/players/izekiel/"
#define MON "/players/izekiel/mon/"
#define ARMOR "/players/izekiel/armor/"
#define ITEM "/players/izekiel/obj/"
#define WEP "/players/izekiel/weapon/"
#define AREA "/players/izekiel/room/"

#define TP this_player()
#define MP move_player
#define CO clone_object
#define MO move_object
#define TO this_object()
#define TEL tell_object
#define MP move_player

#define E environment
#define A attacker
#define AO attacker_ob
#define CAP capitalize
#define AA add_action
#define TRM tell_room

#define TPN TP->query_name()
#define QP query_possessive() // his her its
#define QO query_objective() // him her
#define QPRO query_pronoun() // he she

#define CON TP->query_con()
#define STR TP->query_str()
#define INT TP->query_int()
#define CHR TP->query_chr()
#define DEX TP->query_dex()
#define WIS TP->query_wis()
