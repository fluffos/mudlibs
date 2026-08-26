// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "The royal living quarters.");
  set("long", @ENDLONG
You stand in the southwest corner of an enormous, plush room that serves as
the royal living quarters.  The southwest side of the room is every bit as
exquisite as the rest of the room.  This part of the room has a decidedly
feminine feel to it, however.  The fountain in the center of the room
is still the most interesting thing about the room.
ENDLONG
  );
  set("item_desc", ([
   "fountain" : "Water spray up from the center of the fountain and mists gently down on the\ncarefully tended flower beds surrounding it.\n",
  "beds" : "Mostly lilacs and snapdragons.\n",
  "bed" : "Mostly lilacs and snapdragons.\n",
  "flower bed" : "Mostly lilacs and snapdragons.\n",
   "lilacs" : "They are pretty little flowers.\n",
  "snapdragons" : "There aren't as many snapdragons as there are lilacs.\n",
  "flowers" : "They are mostly lilacs and snapdragons.\n",
  ]) ); 
  set("smell", ([
   "default" : "The air smells faintly of flowers.\n",
   "flowers" : "They smell wonderfully clean and fresh.\n",
  ]) ) ;
  set("listen", ([
   "default" : "You hear the light rush of water from the fountain.\n",
  ]) ) ;
  set("light", 1);
  set("exits", ([
    "north" : ROOMS(rliving1),
    "east" : ROOMS(rliving4),
    "south" : ROOMS(queenroom1),
    "west" : ROOMS(liwhall3),
  ]) );

  create_door("west", "east", "An ornate gold door.", "locked",
   "royal_key", 24) ;
  create_door("south", "north", "An ornate gold door.", "open",
    "royal_key", 24) ;
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
    "north" : "$N moves towards the north side of the room.",
    "east" : "$N moves towards the east side of the room.",
  ]) );
  ::create();
}
