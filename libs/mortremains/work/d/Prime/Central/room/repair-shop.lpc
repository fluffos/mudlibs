#include <mudlib.h>
#include "central.h"

inherit ROOM;
inherit DOORS ;

void create () {
    object obj;

    ::create();
    seteuid(getuid());
    set("light", 1);
    set("short", "A small repair shop in "+CITY_NAME);
    set("long", @Endtext
You are in a small building that is barely standing. Many chips and
circuit boards lay on the work bench, waiting to be repaired. In the
corner, a computer screen is displaying the diagnostics of some machine.
A broken chassis is resting on one of the tables. This is where broken
machines are taken to be repaired.
A sign is taped to the work bench.
Endtext
    );
    set("exits", ([
      "south" : M_ROOM+ "road03",
    ]) ) ;
    set("item_desc", ([
      "chassis" :
      "It is badly damaged.  A good technician could probably repair it.\n",
      "circuit boards" :
      "They seem to be memory boards and other useful mechanical boards.\n",
      "chips" :
      "Micro-chips, IC chips, CPU chips, potato-chips... you name it.\n",
      "boards" :
      "They seem to be memory boards and other useful mechanical boards.\n",
      "bench" :
      "There is a toolbox on top of the work bench.\n",
      "toolbox" :
      "A few screwdrivers and socket plugs are on top of a pile of tools.\n",
      "screen" :
      "Output: 500 volts       Current: 20 amps\n"+
      "All systems operating at peak efficiency.\n",
      "sign" :
      "<list> - gives a list and costs of the skills which can be trained here.\n"+
      "<train [skill]> - trains you in a particular skill.\n",
    ]) ) ;
    obj=clone_object(M_MON+"technician");
    obj->move(this_object());
    reset();
}

void init() {
    add_action("revive_player", "body");
}

int revive_player() {

    int i;
    mapping skills;
    string *names;

    if(TP->query("race") != "machine") return 0;
    if(!present("priss"))
	return notify_fail("No one is here to fix anything!\n");
    if(!TP->query("ghost"))
	return notify_fail("You do not need a new body.\n");
    tell_object(this_player(),
      "The technician goes to work on you.\n");
    tell_room(environment(TP), "The technician goes to work on "+TPN+".\n", TP);
    this_player()->revive();
    return 1;
}

