#include <std.h>

inherit OBJECT;

string message = "You can not let go of the egg!";

int uses = 20;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("egg");
    set_short("A gold egg");
    set_long("This egg is not just an ordinary egg.  If you were to <break> it, "
      "something might happen.");
    set_heart_beat(1);
    uses = 0;
}

void heart_beat()
{
    if(environment(this_object()) != find_player("endbringer") && environment(this_object()))
    {
	message("info", "%^BOLD%^YELLOW%^The egg finds its way back "
	  "to your inventory%^RESET%^.", find_player("endbringer"));
	if (this_player()->query_name() == "endbringer") 
	{
	    this_object()->move(find_player("endbringer"));
	}
    }
}

void init() {
    ::init();
    add_action("fbreak", "break");
}

int fbreak(string str) {
    if (!str || str != "egg") { 
	return notify_fail("Break what?\n");
    }

    if (uses >= 20) {
	write("You can not use the egg.");
	this_object()->remove();
	return 1;
    }
    if(this_player()->query_disable()) {
	write("You are too busy to do that.");
	return 1;
    }
    uses = 1;
    write("You break open the egg.");
    this_player()->set_disable();
    call_out("heal_message", 2);
    return 1;
}

void heal_message()
{
    write("%^BOLD%^YELLOW%^A warm feeling floods your body%^RESET%^.");
    this_player()->add_hp(random(100) + this_player()->query_level());
    this_player()->add_sp(random(100) + this_player()->query_level());
    this_player()->add_mp(random(100) + this_player()->query_level());
}

int give() { write(message); return 1; }
int sell() { write(message); return 1; }
int bury() { write(message); return 1; }
int drop() { write(message); return 1; }

int query_auto_load() {
    if (this_player()->query_name() != "endbringer") {
	return 0;
    }
    return 1;
}
