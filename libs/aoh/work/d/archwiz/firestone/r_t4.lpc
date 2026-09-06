#include <rooms.h>
#include <moving.h>
#include <properties.h>
#include "path.h"

inherit "/std/room";

int flag;
 
reset() {
   ::reset();
   flag=0;
}
 
look(string str) {
   string s1,s2;
   if (!str) return;
   if (sscanf(str,"%s %s",s1,s2)==2) {
      if (s1!="at") return;
      if (s2=="mccoy") call_out("acti",2);
      flag=1;
   } else {
     if (str=="mccoy") call_out("acti",2);
     flag=1;
   }
   return;
}
 
acti() {
   if (present("mccoy")) {
      say(
"Dr. McCoy says: Could you tell me where I can find Mr. Scott? I've heard he "
"needs a coffeine injection.\n");
   }
}
 
say() {
  if (flag) call_out("acti2",2);
  return;
}
 
int acti2() {
   object mc;
   if (!present("mccoy")) return 0;
   tell_room(this_object(),"Dr. McCoy says: Hmmmm...\n"
"Then he leaves to some place.\n");
   mc=present("mccoy");
   mc->remove();
   return 1;
}

create() {
  ::create();
  SetIntShort("In a corridor");
  SetIntLong("You are in a corridor.\n");
  SetIndoors(1);
  AddRoomCmd(({"say","'"}),#'say);
  AddRoomCmd("look",#'look);
  AddExit("west","./r_t6");
  AddExit("east","./r_t9");
  AddExit("north","./r_t3");
  AddItem("/std/npc",REFRESH_HOME,
    ([P_NAME: "McCoy",
      P_SHORT: "Dr. Leonard McCoy",
      P_LONG: "He's the doctor of this ship.\n",
      P_IDS: ({"doctor","mccoy","leonard"}),
      P_ADS: ({"dr.","dr","leonard"}),
      P_RACE: "human",
      P_LEVEL: 3,
      P_HANDS: ({ ({"left hand",0,6}),({"right hand",0,6}) }),
      P_AC: 1,
      P_GENDER: 1,
      P_ALIGN: 1000]) );
  reset();
}
