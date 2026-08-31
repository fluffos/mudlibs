#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("a shard of crystal");
    set_id( ({ "shard", "crystal shard"}) );
    set_short("a shard of crystal");
    set_long("This sliver of crystal is but a fraction of the whole piece, rightly earned by Team Illuminati. It can be 'invoked' to grant the user power.");
    set_mass(1);
    set_value(0);
}
void init() 
{
    ::init();
    add_action("invoke", "invoke");
}

int invoke(string str)
{
    if (str != "shard")
    {
	return 0;
    }
    write("%^BOLD%^%^BLUE%^You invoke the power of the shard.%^RESET%^");
    this_player()->add_stat_bonus("strength",5,500);
    this_player()->add_stat_bonus("dexterity",5,500);
    this_player()->add_stat_bonus("intelligence",5,500);
    this_player()->add_stat_bonus("wisdom",5,500);
    this_player()->add_stat_bonus("charisma",5,500);
    this_player()->add_stat_bonus("constitution",5,500);
    this_object()->remove();
    return 1;
}

mixed query_auto_load() {
    return 1;
}
