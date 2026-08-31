#define KPATH "/players/unuscione/area/"
#define MON "/players/unuscione/monsters/"
#define TP this_player()
#define TPN TP->query_name()
#define TO this_object()
#define env environment
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
#define MOVE TP->move_player
