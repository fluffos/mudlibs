#define NPC(x) "/d/ebene/dusty/orklichtung/npc/"+x
#define ROOM(x) "/d/ebene/dusty/orklichtung/room/"+x
#define LAMUERTEWALD(x) "/d/ebene/lamuerte/wwald/room/"+x
#define OBJ(x) "/d/ebene/dusty/orklichtung/obj/"+x
#define ARMOUR(x) "/p/armour"+x
#define WEAPON(x) "/p/weapon"+x
#define LOG(x) "/d/ebene/dusty/orklichtung/log/"+x

#define SUID seteuid(getuid(this_object()));

#define TP this_player()
#define TPN this_player()->name()
#define TPP this_player()->QueryPronoun
#define TPPP this_player()->QueryPossPronoun
#define PL this_player()
#define PLN this_player()->name()

#define TO this_object()
#define ME this_object()

#define BS(s) break_string(s,78)
#define bs(s) break_string(s)

#define CAP(x) capitalize(x)
#define UPPER capitalize
#define LOWER lower_case

#define ENV(x) environment(x)
#define MENV environment(this_object())
#define SUID seteuid(getuid(this_object()));
#define CLONEME(x) clone_object(x)->move(ME)
#define CLONEOB(x) clone_object(x)
#define CLONE(x,y) clone_object(x)->move(y);
#define DB(x) tell_object(find_player("dusty"),BS(x));
