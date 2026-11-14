#define PATH "/d/astral/lamuerte/brunnen/"
#define STD(x) PATH+"std/"+x
#define ROOM(x) PATH+"rooms/"+x
#define OBJ(x) PATH+"obj/"+x
#define NPC(x) PATH+"npc/"+x
#define NEWS(x) PATH+"news/"+x
#define LOG(x) PATH+"log/"+x
#define WEAPON(x) PATH+"weapon/"+x
#define ARMOUR(x) PATH+"armour/"+x
#define Q_ROOM(x) PATH+"room/quest/"+x
#define Q_OBJ(x) PATH+"obj/quest/"+x

#define LNEWSD STD("newsd")

#define CAP capitalize
#define TO this_object()
#define TP this_player()
#define PO previous_object()
#define TPN TP->QueryProp(P_NAME)
#define TI this_interactive()
#define BS(x) break_string(x, 78)
#define ENV environment

#define P_ZONE "zone"
#define P_SUBDOMAIN "subdomain"
