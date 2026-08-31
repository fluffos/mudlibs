
#define NAME this_player()->query_name() 
#define RNAME this_player()->query_real_name()
#define LVL this_player()->query_level() 
#define PPRON environment(this_object())->query_pronoun()
#define POSS this_player()->query_possessive() 
#define RACE this_player()->query_race()
#define OBJ this_player()->query_objective()
#define ACTION "/players/tatsuo/closed/paper/actions/actions.lpc"
#define TO this_object() 
#define PRON this_player()->query_pronoun() 
#define WHO environment(this_object())->query_real_name()
#define TP this_player()
#define CP(arg) capitalize(arg)
#define SERVER "/players/tatsuo/closed/paper/server.lpc"

#define MEMBERS ([ "tatsuo":"editor", "thumper":"reporter", "jewel":"self-help", \
  "turbo":"reporter", "tetsuhara":"reporter", "airborne":"cook", "tuppence":"society", \
  "demolian":"comedian", "wilbie":"boss", "rastan":"reporter", \
  "herp":"god" ])




