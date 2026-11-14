/*
  files.h
  
  Fuer die Gilde des elfenbeinernen Tigers.
*/

#define DEBUG(x,y) if (find_player("creative")) tell_object(find_player("creative"), "|**"+x+"**| "+y+"\n")

#define PATH "/d/ebene/creative/ebony_tiger/"
#define STD(x) PATH+"std/"+x
#define ROOM(x) PATH+"room/"+x
#define OBJ(x) PATH+"obj/"+x
#define NPC(x) PATH+"npc/"+x
#define LOG(x) PATH+"log/"+x
#define WEAPON(x) PATH+"weapon/"+x
#define ARMOUR(x) PATH+"armour/"+x


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
#define P_HELP_ROOMS "help_rooms"
#define P_HELPING "helping"
#define P_MAX_HELPERS "max_helpers"
#define P_HELPERS "helpers"
#define P_2ATTACK "2attack"

#define UMSTR "/d/ebene/creative/ebony_tiger/std/umaster"

#define EQUEST "Das Vermaechtnis der Tigergilde"
#define EQLOG "/d/ebene/creative/ebony_tiger/log/quest.log"

