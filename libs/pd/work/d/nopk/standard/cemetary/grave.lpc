#include <std.h>
#include <sindarii.h>
inherit VAULT;
object coffin;

void create() {
   ::create();
     set_property("light", 0);
     set("short", "The grave");
    set("long",
	"You have foolishly climbed down into the ancient grave of one of "
      "the founders of Nightmare. You are standing on the closed lower door "
      "of a coffin. The upper door is open and gruesomely inviting. "
      "A small dark tunnel leads away to the south.");
    set_items(
	(["under" : "You can't look under the coffin, you're "
	    "standing on it.",
	  "grave" : "The grave is horribly empty and sad."]) );
    set_exits(([
                 "up" : ROOMS+"cemetary/gravyar2",
                 "south" : ROOMS+"cemetary/tunnel1",
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

void reset() {
::reset();
if(!present("ghost"))
      new(ROOMS "cemetary/mon/ghost")->move(this_object());
}
