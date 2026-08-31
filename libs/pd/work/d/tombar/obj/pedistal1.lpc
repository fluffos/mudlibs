//  Pedistal

#include <std.h>

inherit OBJECT;
object o;

void create() {
    ::create();
    set_name("a stone pedistal");
    set_short("a stone pedistal");
    set_long("The stone pedistal is sitting in the center of the room.  Arcane "
      "symbols are written on the sides of the pedistal.  An indention in "
      "the top of the pedistal looks like something can be placed there.");
    set_id(({ "pedistal", "stone pedistal", "pedistal_1_tombar" }));
    set_prevent_get("You cannot take that.  It is fastened to the floor.");
}

void init() {
    ::init();
    add_action("take", "take");
    add_action("place", "place");
}

int take(string s) {
    if(!s || s == "" || s != "orb") return notify_fail("Take what?\n");
    if(!o) return notify_fail("There is nothing "
	  "in the indention.");
    write("You take the orb from the pedistal.");
    say(this_player()->query_cap_name()+" takes the orb from the pedistal.\n");
    o->move(this_player());
    return 1;
}

int place(string s) {
    string what, where;
    if(!s || s == "") return notify_fail("Place what?\n");
    if(sscanf(s, "%s in %s", what, where) != 2) return 
	notify_fail("Place what in what?\n");
    if(what != "orb" || where != "indention") return 
	notify_fail("Place what in what?\n");
    if(!present("orb_quest_tombar", this_player())) return
	notify_fail("You do not have an orb.");
    write("You place the orb in the indention.");
    say(this_player()->query_cap_name()+" places the orb in the indention.\n");
    o=present("orb_quest_tombar", this_player());
    o->move("/d/nopk/standard/void");
    call_out("do_orb_change", 1);
    return 1;
}

int do_orb_change() {
    if(!o) return 0;
    switch(o->query_color()) {
    case "green":
       message("", "The orb changes to a bright blue color.", environment(this_object()));
       o->set_color("blue");
	return 1;
	break;
    default:
	return 0;
	break;
    }
}

