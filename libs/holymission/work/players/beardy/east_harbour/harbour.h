#define TP this_player()
#define TO this_object()
#define ROOM "/players/beardy/east_harbour/room/"
#define OBJ "/players/beardy/east_harbour/obj/"
#define MONST "/players/beardy/east_harbour/monster/"
#define CO(x) move_object(clone_object(OBJ + x),this_object())
#define CM(x) move_object(clone_object(MONST + x),this_object())
