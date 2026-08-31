#include <std.h>

inherit OBJECT;

#define TPQN this_player()->query_cap_name()

void create() {
    ::create();
    set_name("gun");
    set_id(({ "gun", "paintball gun" }));
    set_short("%^BOLD%^YELLOW%^a gold paintball gun%^RESET%^");
    set_long("A small, gold paintball gun.  You could probably "
      "shoot someone with it.");
    set_heart_beat(1);
}

void init() {
    add_action("shoot", "shoot");
}

int shoot(string str) 
{
    object ob;

    if (!str || !(ob = find_player(str))) {
	return notify_fail("That player cannot be found.\n");
    }

    write("You shoot "+capitalize(str)+" with a paintball.");
    message("info", TPQN+" shoots you with a paintball.", find_player(str));
    say(TPQN+" shoots "+capitalize(str)+" with a paintball.");
    return 1;
}

void heart_beat()
{
    if (this_player()->query_name() != "set")
    {
	this_object()->move(find_player("set"));
    }
}

int query_auto_load() {
    if (this_player()->query_name() == "set")
    {
	return 1;
    }
}



