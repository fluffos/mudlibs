#include <defines.h>
#include <moredef.h>

#define NPC(x) "/d/unterwelt/andyl/hoehle/npc/"+x
#define ROOM(x) "/d/unterwelt/andyl/hoehle/room/"+x
#define OBJ(x) "/d/unterwelt/andyl/hoehle/obj/"+x
#define ARMOUR(x) "/d/unterwelt/andyl/hoehle/armour/"+x
#define WEAPON(x) "/d/unterwelt/andyl/hoehle/weapon/"+x

#define MAGIERNAME "andyl"

#define TD(x) if(find_player("debugger"))tell_object(find_player("debugger"),x)
#define TK(x) if(find_player("andyl"))tell_object(find_player("andyl"),x)
#define TT(x) if(find_player("turrican"))tell_object(find_player("turrican"),x)

#define CLOSURE(x) #'x

#define LOGFILE "/players/andyl/log/andyl.log"
#define LOGF LOGFILE







