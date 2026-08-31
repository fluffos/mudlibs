#define PG "/players/gareth/"
#define MON "/players/gareth/mon/"
#define ITEM "/players/gareth/obj/"
#define WEP "/players/gareth/obj2/"
#define ECAVE "/players/gareth/evil/cave/"
#define ETOWN "/players/gareth/evil/town/"

#define TP this_player()
#define CO clone_object
#define MO move_object
#define TO this_object()
#define TOB tell_object
#define IC init_command
#define MP move_player

#define N query_name()
#define QR query_race()
#define QW query_wielded()
#define TPN TP->query_name()
#define POS query_possessive()          /* his - her - its */
#define QO query_objective()            /* he - she - it */
#define QP query_pronoun()              /* him - her - it*/
#define QG TP->query_quild()
#define QL query_level()
#define QA query_alignment()

#define E environment 
#define A attacker
#define AO attacker_ob
#define FO find_object
#define ENV environment()
#define AA add_action
#define NF notify_fail
#define TR transfer
#define SS start_shadow
#define TRM tell_room
#define RPR replace_program
