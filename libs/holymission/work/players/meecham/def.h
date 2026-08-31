#define MON "/players/meecham/monsters/"
#define TP this_player()
#define CO clone_object
#define MO move_object
#define TO this_object()
#define PM "players/meecham/"
#define TPN TP->query_name()
#define env environment
#define cap capitalize
#define RR replace_program("room/room")
#define TPR TP->query_real_name()
#define TPL TP->query_level()
#define TPC TP->query_chr()
#define TPW TP->query_wis()
#define CLONE(str,file) if(!present(str,TO)) MO(CO(MON+file),TO);
#define APATH "/players/meecham/guild/abilities/"
#define clone_and_wear(str,id);\
{\
  MO(CO("/players/meecham/armours/"+str),TO);\
  init_command("wear "+id);\
}
#define clone_and_wield(str,id);\
{\
  MO(CO("/players/meecham/weapons/"+str),TO);\
  init_command("wield "+id);\
}
