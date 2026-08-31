#include <std.h>
#include <sindarii.h>
inherit VAULT;
  object coffin;
int pull;

void init() {
::init();
}

int passage() {
write("All guilds are currently suspended!  Please talk to whit for more info.");
return 1;
}

void create() {
   ::create();
     set_property("light", 0);
     set("short", "The grave");
    set("long",
	"You have foolishly climbed down into the ancient grave of one of "
      "the founders of Nightmare. You are standing on the closed lower door "
      "of a coffin. The upper door is open and gruesomely inviting. The "
      "soil presses in around you claustrophobicly.  A small light "
      "hangs in the center of the ceiling dimmly lighting the room.");
    set_items(
	(["under" : "You can't look under the coffin, you're "
	    "standing on it.",
	  "soil" : "The dirt walls of the grave are soft and "
	    "smell of the earth.",
	  "grave" : "The grave is horribly empty and sad."]) );
    set_exits(([
                 "up" : ROOMS+"cemetary/gravyar2",
                 "enter" : ROOMS"cemetary/coffin1" ]));
   coffin = new("std/object");
   coffin->set_name("coffin");
   coffin->set_short("an old coffin");
   coffin->set_id(({ "coffin" }));
   coffin->set_long("The old coffin has been here for quite some time.");
   coffin->set_prevent_get("You cannot get that!");
   coffin->move(this_object());
   set_door("coffin", ROOMS"cemetary/coffin1", "enter", "");
}

int pull(string str) {
if(pull==0) {
if(!str) return notify_fail("Pull what?\n");
if(str != "light") return notify_fail("Pull what?\n");
write("The light pulls down easily opening a secret passage.");
say(this_player()->query_cap_name()+" pulls on the light opening a "
"passage");
add_exit("/d/guilds/darksouls/entrance", "passage");
pull=1;
return 1;
}
if(pull==1) {
if(!str) return notify_fail("Pull what?");
if(str != "light") return notify_fail("Pull what?\n");
write("You may pull it out!");
return 1;
}
}

void reset() {
::reset();
pull=0;
if(!present("ghost"))
      new(ROOMS "cemetary/mon/ghost")->move(this_object());
remove_exit("passage");
}
