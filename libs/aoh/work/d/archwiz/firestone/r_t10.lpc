#include <moving.h>
#include <rooms.h>
#include "path.h"

inherit "/std/room";
object pl;
int rep;
 
int repair(string str) {
  if (str && str!="door" && str!="elevator") return 0;
  if (!this_player()) return 0;
  if (!present("screwdriver",this_player())) {
     write("You can't do this without a screwdriver.\n");
     return 1;
  }
  if (rep) {
     write("There is nothing to repair.\n");
     return 1;
  }
  write(
"You open the control box of the door with your screwdriver. Then you have "
"no problems in fixing the loose connection.\n");
  rep=1;
  pl=this_player();
  call_out("hallo",3);
  return 1;
}
 
reset() {
  ::reset();
  rep=0;
  if (find_call_out("chat") == -1)  /* Hanarra */
    call_out("chat",5);
}
 
 
hallo() {
  object ob,spock;
  tell_room(this_object(),"The door opens and Mr. Spock arrives.\n");
  spock=clone_object(FIRESTONE("spock"));
  spock->move(this_object(),M_GO);
  tell_room(this_object(),"Mr. Spock says: Thank you very much!\n"
"Mr. Spock says: 'Logical Choice.' While walking past you, he drops "
"a golden amulet.\n");
  if (present(pl)) {
     ob=clone_object("/d/archwiz/firestone/amulet");
     ob->move(this_object());
  }
  call_out("bye",4);
}
 
bye() {
   object spock;
   tell_room(this_object(),"Mr. Spock leaves to some place.\n");
   spock=present("spock");
   if (spock) spock->remove();
}
 
int west() {
  if (!this_player()) return 0;
  if (rep) {
      tell_room(this_object(),"The door opens.\n");
      this_player()->move(FIRESTONE("ecloset"),M_GO,"west");
      tell_room(this_object(),"The door closes.\n");
      tell_room(FIRESTONE("ecloset"),"The door closes.\n");
  }
  else 
    write("The door is closed. You can't go west.\n");
  return 1;
}
 
int open(string str) {
   if (str!="door") return 0;
   if (rep) {
      write(
"It is an automatic door. Normally it opens and closes by itself if someone "
"wants to go through the door.\n");
   } else {write("The automatic door is out of order. You have to repair it.\n"); }
   return 1;
}
 
int chat() {
   int x;
   if (rep) return 0;
   x=random(3);
   switch (x) {
     case 0: tell_room(this_object(),"Mr. Spock shouts: Please REPAIR the door! I can't open it.\n"); break;
  case 1: tell_room(this_object(),"Spock shouts: It is logical to let me out!\n"); break;
  default: tell_room(this_object(),"Spock shouts: Help! I am stuck in here!\n");
   }
   call_out("chat",50);
   return 1;
}

create() {
  ::create();
  SetIntShort("In a corridor");
  SetIntLong(
"You are in a corridor. You see a door in the West wall.\n");
  SetIndoors(1);
  AddDetail("door","The door is closed.\n");
  AddRoomCmd("open",#'open);
  AddRoomCmd("repair",#'repair);
  AddExit("west",#'west);
  HideExit("west",1);
  AddExit("north","./r_t1");
  AddExit("down","./r_sulu");
  reset();
}
