#include "../defs.h"
inherit ROOM;
inherit DOORS;
int done;
int do_it(){
  done = 1;
  return 1;
}
void end_fight(){
  tell_object(TO, "You hear a loud scream!\n");
     return;
}

void start_fight(){
  int kill_him;
  if(kill_him > 5)
 {
    end_fight();
 }
  if(!done==1)
  {
// Going to switch kill_him to sport cool ass messages, but for now, this will do
    tell_object(TO, "You hear a scuffle in the room to the south.\n");
    kill_him++;
   call_out("start_fight", 5);
 }
}

void create(){
seteuid(getuid());
set("light", 1);
set("author", "Gendor&Waxer");
set("short", "Town hall");
set("long", @ENDLONG
Bookshelves are along every wall here, filled with books.
A desk is here, cluttered and strewn with papers.  A door
is to the south, leading into the Mayor's office.
ENDLONG
   );

  set("item_desc", ([
  "bookshelves" : "Lawbooks, lawbooks, lawbooks!!!!\n",
  "desk" : "It would seem that the secretary is very busy.\n",
  "door" : "Just a plain wooden door, dude.\n",
   ]) );
call_out("start_fight", 5);
set("objects", ([
    												MON(frank) : 1,
  ]) );

set("exits", ([
    "south" : ROOMS(office),
    "down" : ROOMS(mayors1),
  ]) );
create_door("south", "north", "wooden door.",
    "closed", 5);
set("pre_exit_func", ([
     "south" : "guarded",
  ]) );
::create();
}
int guarded() {


  if (present("frank", TO)) {
    write("Frank knocks you away from the door!\n");
   return 1;
  }
}