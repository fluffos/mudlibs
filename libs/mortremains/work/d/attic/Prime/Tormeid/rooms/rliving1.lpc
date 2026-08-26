// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "The royal living quarters.");
  set("long", @ENDLONG
You stand in the northwest corner of an enormous, plush living area that
serves as the royal living quarters.  Every inch of this room is exquisitely
decorated; magnificient art that stirs emotions in you surrounds you at all
angles.  Plush furniture is abundant and some comfortable chairs rest near
the wall.  A large fountain in the center of the room gently showers water
over a small flower bed surrounding it.  The entire atmosphere of this room
is serene and calm.
ENDLONG
  );
  set("smell", ([
   "default" : "The faint smell of flowers lingers in the air.\n",
  "flowers" : "They smell wonderfully fresh and clean.\n",
  ]) ) ;
  set("listen", ([
  "default" : "You hear the light rush of water from the fountain.\n",
  ]) ) ;
  set("item_desc", ([
   "art": "There are many pieces of art surrounding you, but the thing that catches your\neye is the fountain the center of the room.\n",
  "furniture" : "The furniture all looks extremely comfortable.\n",
   "chairs" : "Even the chairs look extremely comfortable.\n",
   "wall" : "There are some chairs lined up near the wall.\n",
   "bed" : "The flower bed is filled with lilacs and snapdragons.\n",
   "flower bed" : "The flower bed is filled with lilacs and snapdragons.\n",
   "dirt" : "The dirt of the flowerbed is moist and clean.\n",
  "water" : "The water in the fountain looks clean and pure.\n",
  "fountain" : "Water shoots up from the fountain in a great arc and mists down onto the\nflower beds gently.\n",
  "room" : "You are in the northwestern part of the room.\n",
  ]) ) ;
  set("light", 1);
  set("exits", ([
   "north" : ROOMS(rbaby1),
    "west" : ROOMS(rhall4),
    "east" : ROOMS(rliving2),
    "south" : ROOMS(rliving3),
  ]) );
  create_door("west", "east", "An ornate gold door.",
    "locked", "royal_key", 24) ;
  create_door("north", "south", "A beautiful gold door.",
    "closed", "royal_key", 24) ;
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
    "east" : "$N moves towards the east side of the room.",
    "south" : "$N moves towards the south side of the room.",
  ]) );
  ::create();
}

void init() {
  add_action("swim", "swim") ;
  add_action("drink", "drink") ;
}

int drink(string str) {
  if (!str) {
    write("Drink what?\n") ;
   return 1 ; 
  }
  if (str != "water") return 0 ;
  write("You drink some water from the fountain.  It tastes pure and clean.\n");
  say(wrap(TPN+
  " drinks from the fountain in the center of the room.")) ;
  return 1 ; 
}

int swim(string str) {
  write("It doesn't seem like a good idea to swim here.\n");
  return 1;
}
