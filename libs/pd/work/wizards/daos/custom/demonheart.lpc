#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("demonheart");
    set("id", ({"demonheart"}) );
    set_short("%^RED%^Demonheart%^RESET%^");
    set_long("This is the heart of the demon, Sasayaki.  It throbs and "
      "beats with the life force of its owner, a strong and steady pace.  It "
      "feeds from Sasayaki's passion, strength, and power.");
}

int drop() {
    write("What?\n");
    return 1;
}

int sell() {
    write("What?\n");
    return 1;
}

int bury() {
    write("What?\n");
    return 1;
}

int query_auto_load() {
    if(this_player()->query_name() == "sasayaki")
	return 1;
}

