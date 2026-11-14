#define ROOM(x) ("/d/polar/lamuerte/eishoehle/rooms/"+x)
#define NPC(x) ("/d/polar/lamuerte/eishoehle/npc/"+x)
#define OBJ(x) ("/d/polar/lamuerte/eishoehle/obj/"+x)
#define GIMME(x) clone_object(OBJ(x))->move(this_object()) 