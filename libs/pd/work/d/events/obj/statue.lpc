#include <std.h>

inherit OBJECT;

int done;

void create() {
    ::create();
    set_name("statue");
    set_short("a statue of Malfesto");
    set_long("The statue has been here for a long time.  "
      "Moss and vines have already began growing up the "
      "sides of the statue.  The demon statues eyes "
      "glow red from some unknown force.  It looks like "
      "it could hold something in its hand.");
    set_prevent_get("You may not take the statue.");
    set_id(({ "statue", "statue of malfesto" }));
}

void init() {
    ::init();
    add_action("fput", "put");
    add_action("fread", "read");
}

int fput(string str) {
    string tmp, tmp2;
    if(!present("book of demons", this_player())) return 0;
    if(!str) return notify_fail("Put book where?");
    if(sscanf(str, "%s on %s", tmp, tmp2) != 2) return notify_fail("Put book "
	  "where?\n");
    if(member_array(tmp, present("book of demons", this_player())->query_id()) == -1)
	return notify_fail("Put what where?\n");
    if(member_array(tmp2, this_object()->query_id()) == -1) return
	notify_fail("Put book on what?\n");
    say(this_player()->query_cap_name()+" places the book onto the statue.\n");
    write("You place the book onto the statue.\n");
    message("environment", "Something clicks on the statue.",
      environment(this_player()));
    present("book of demons", this_player())->remove();
    call_out("do_earthquake",3);
    return 1;
}

int do_earthquake() {
    message("info", "The ground begins to quake violently for a second.",
      users());
    call_out("con", 2);
    return 1;
}

int con() {
    if(!query_night())
	message("info", "The moon appears from the horizon.  It slides over "
	  "blocking the suns light causing an eclipse.", users());
    else message("info", "The moons begin to go dark.", users());
    call_out("con2", 3);
    return 1;
}

int con2() {
    message("info", "The statue's hand lifts up reveiling an insciption", 
      environment(this_object()));
    done = 1;
    return 1;
}

int fread(string str) {
    if(!str || str != "inscription") return notify_fail("Read what?\n");
    if(!done) return notify_fail("Read what?\n");
    say(this_player()->query_cap_name()+" reads over the inscription.");
    write("You read over the description.\n");
    write("It reads:   The first part of the event is over.\n");
    return 1;
}

