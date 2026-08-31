#include <std.h>

inherit OBJECT;


void create() {
    ::create();
    set_name("horn");
    set_short("%^YELLOW%^horn%^RESET%^");
    set_long("A little %^ORANGE%^gold%^RESET%^ horn. Looks like a childs toy. Try blowing it.");
    set_id(({"horn","gold horn"}));
    set_value(3);
    set_weight(2);
}
void init()
{
    ::init();
    if(!environment()) return;
    if(!this_player()) return;
    if(environment() == this_player())
	add_action("blow","blow");
}

int blow(string str)
{
    if(!str) return 0;
    if(str != "horn") return 0;
    message("info", "%^YELLOW%^"+this_player()->query_cap_name()+" blows on a horn.%^RESET%^",environment(this_player()));
    return 1;
}
