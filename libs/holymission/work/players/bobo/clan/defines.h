#define ACTION "/players/bobo/clan/actions/actions.lpc"
#define CP(arg) capitalize(arg)
#define LVL this_player()->query_level()
#define NAME this_player()->query_name()
#define OBJ this_player()->query_objective()
#define POSS this_player()->query_possessive()
#define PPRON environment(this_object())->query_pronoun()
#define PRON this_player()->query_pronoun()
#define QNAME query_name()
#define QOBJ query_objective()
#define QPOSS query_possessive()
#define QPRON query_pronoun()
#define RACE this_player()->query_race()
#define RNAME this_player()->query_real_name()
#define RNAME2 query_real_name()
#define SERVER "/players/bobo/clan/server.lpc"
#define TO this_object()
#define TP this_player()
#define WHO environment(this_object())->query_real_name()

#define MEMBERS ([ "fodder":"master", "bobo":"schmuck", \
   "demolian":"slayer","beukeboom":"neophyte","schpankay":"High Priestess", \
   "bolborn":"The Toad", "daniella":"superfly" ])
