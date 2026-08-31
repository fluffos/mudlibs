#define GPATH "/players/wilbie/graveyard/"
#define NIN "/players/patience/guild/nweap/ninja_weapon.lpc"
#define APATH "/players/wilbie/asylum/"
#define FPATH "/players/wilbie/fishing/"
#define FMON "/players/wilbie/fishing/monsters/"
#define FEQ "/players/wilbie/fishing/eq/"
#define MOB "/players/wilbie/graveyard/monsters/"
#define WEAP "/players/wilbie/graveyard/weapons/"
#define CPATH "/players/wilbie/citadel/"
#define ARM "/players/wilbie/graveyard/armor/"
#define PRI "/players/wilbie/private/"
#define TP this_player()
#define TPN TP->query_name()
#define TO this_object()
#define ENV environment
#define ROOMRESET reset(arg){ \
                  if(arg)\
	          set_light(1);
#define TPOSS TP->query_possessive()
#define TPOBJ TP->query_objective()
#define cap capitalize
#define CO clone_object
#define MO move_object
#define CLONE(str,file) if(!present(str,TO)) MO(CO(NPC+file),TO);
#define AA add_action
#define BREAKSTR #include "/players/whisky/genesis/sys/break_string.h"
#define MOVE TP->move_player
#define TELL tell_object
#define NAME query_name()
