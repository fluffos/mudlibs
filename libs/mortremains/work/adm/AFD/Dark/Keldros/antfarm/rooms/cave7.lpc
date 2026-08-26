inherit ROOM;
#include "../defs.h"

void bashed_open(int i); // need to prototype it.
int bashed;

void create(){
seteuid(getuid());
set("author", "Waxer");
set("light", 1);
set("short", "in a gruesome passage");
set("long", @ENDLONG
The underground cave is musty with the foul stench of stale
water and the sickly sweet smell that permeates nearly everything
here.  The walls have remained cut smooth, but very solid. A
solid wooden door protects southward travel. The corridor continues
to the north.
ENDLONG
);
set("item_desc", ([
  "walls" : "The walls are made of thick granite.\n",
  "door" : "The key hole has rusted through, you are going to have to bash it down.\n",
]));
set("smell", ([
   "water" : "Perhaps there is an underground river near here, it is quite humid,\nand this water smells old and stale, perhaps trapped here.\n",
   "default" : "The stale water smell does nothing for the sickly sweet smell.\n",
]));
set("exits", ([ "north" : ROOMS(cave8), ]));
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
  call_other(ROOMS(cave6), "bashed_open", 1);
  bashed_open(0);
  write("You bash the door down with a mighty kick!\n");
    say(TPN + " bashes the door down with a mighty kick!\n");
  return 1;
}

void bashed_open(int i) {  // send an argument if the other room is calling
  if (i) tell_object(this_object(),
    "The door to the east suddenly comes crashing down!\n");
  set("item_desc/door", "The door has been bashed down.\n");
  set( "long", @ENDLONG
The underground cave is musty with the foul stench of stale
water and the sickly sweet smell that permeates nearly everything
here.  The walls have remained cut smooth, but very solid. A door
has been bashed down to the south. The corridor continues to the
north.
ENDLONG
);
  add_exit("south", ROOMS(cave6));
  bashed = 1;
}