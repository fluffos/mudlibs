#include "../defs.h"

inherit ROOM;

void bashed_open(int i); // need to prototype it.
int bashed;

void create() {
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set("short", "a Cramped Tunnel.");
  set("long", @ENDLONG
This place is very dismal, The walls in this room are completely except 
for the blood stains on each wall and the floor is covered with yellow dust.  
A corpse of a giant ant can be seen in the southeastern corner, rotting.    
There is a door to the north, but it looks impossible to open.
ENDLONG
   );
  set("item_desc", ([
    "walls" : "The walls appear to have been crafted with rough instruments,
as a result of what appears to be mining.\n",
    "wall" : "The walls appear to have been crafted with rough instruments,
as a result of what appears to be mining.\n",
    "corpse" : "You see no wounds of any kind on the corpse, it appears
that however this ant died, it was from internal reasons.\n",
    "dust" : "This is a pile of yellow dust with brown and black particles
scattered throughout it, you now assume this must be their excrement.\n",
    "door" : " The door would be impossible to open from here without
bashing it down.\n",
  ]) );
  set("search_desc", ([
     "wall" : "This wall is completely smooth.\n",
  ]) );
  set("smell", ([
    "default" : "You smell a sickly sweet smell in the air, and the smell of rotten
flesh.\n",
    "wall"  : "You smell nothing except for rock.\n",
    "air" : "It reminds you of something you can't quite place, a sweet, decaying
odor.\n",
    "ground" : "A sweet scent comes from the piles of dust, it appears to be
coated with a sugary substance.\n",
    "dust" : "It has a sweet scent, it appears to be a sugary substance.\n",
  ]) );
  set("listen", ([ "default" : "You hear a light clicking sounds.\n", ]) );
  set("exits", ([
    "east" : ROOMS(cave4),
    "west" : ROOMS(cave5),
  ]) );
  set("objects", ([ MON(slave) : 6, ]));
  ::create();
}

void init() {
  add_action("bash", "bash");
}

int bash(string str) {
  if (!str) {
    write("Bash what?\n");
    return 1;
  }
  if (bashed  || str != "door" && str != "rock" && str != "stone") {
    write("Bash what?\n");
    return 1;
  }
  if ((int)TP->query("stat/strength")<3) {


    write("You can't budge it, you weakling.\n");


    return 1;
 }
  call_other(ROOMS(cave7), "bashed_open", 1);
  bashed_open(0);
  write("You bash the door down with a mighty kick!\n");
    say(TPN + " bashes the door down with a mighty kick!\n");
  return 1;
}

void bashed_open(int i) {
  if (i) tell_object(this_object(),
    "The door to the west suddenly comes crashing down!\n");
  set("item_desc/door", "You see nothing special about the door.\n");
  set( "long", @ENDLONG
This place is very dismal, The walls in this room are completely bare
except for the blood stains on each wall and the floor is covered with 
yellow dust.  A corpse of a giant ant can be seen in the southeastern 
corner, rotting.    There is a door to the west, but it looks open.
ENDLONG
  );
  add_exit("north", ROOMS(cave7));
  bashed = 1;
}