#include <std.h>
#include <tirun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("read", "read");
}
void create() {
    ::create();
    set_short("A weaponsmith's shop.");
    set_long(
      "A Weaponsmith's shop.\n"
      "A large forge sits behid the counter. Shelves line the walls with "
      "different supplies on them that are used in making and repairing weapons. "
      "A sign on the wall lists the services of the weaponsmith.");
    set_exits( (["north" : ROOMS"swganthus",
	"south"  : ROOMS"wfallor3",
      ]) );
    set_property("light", 3);
    set_property("night light", 2);
    set_items(
      (["forge" : "A large pit in wich weapons are heated and repaired in.",
	"shelves" : "They are oak shelves willed with items used to repair weapons with.",
	"sign"  :  "You should try reading it.",
	"counter" : "An old well worn counter."
      ]) );
}
void reset() {
    ::reset();
    if(!present("jalix"))
	new(MOB"jalix")->move(this_object());
}
int read(string str) {
    object ob;
    ob = present("jalix");
    if(!ob) {
	write("You cannot read the sign, as it is splattered with blood.");
	return 1;
    }
    message("info", "The following services are availible:",
      this_player());
    message("info",
      "-----------------------------------------------------------", this_player());
    message("info", "[fix <weapon>] will allow the weaponsmith to repair your weapon.\n", this_player());
    message("info", "It is 100 gold per level of disrepair.\n", this_player());
    message("info",
      "-----------------------------------------------------------", this_player());
    return 1;
}
