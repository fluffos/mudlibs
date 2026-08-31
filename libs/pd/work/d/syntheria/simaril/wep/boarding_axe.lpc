#include <std.h>

inherit WEAPON;

void create() {
  ::create();

    set_name("boarding axe");
    set_id( ({ "axe", "boarding axe" }) );
    set_short("Boarding Axe");
    set_long("An axe made of tempered iron, with a long wooden handle. "
			 "It is used to fight in close quarters, and board ships. "
			 "The axe has been the weapon of choice for Thyas all his life. "
			 "No one knows where he obtained this axe, but it was surely a bloody affair."
			 );
    set_type("axe");
    set_wc(14);
	set_ac(2);
    set_weight(64);
    set_curr_value("gold", 70 + random(25));
}

int query_auto_load() 
{
	if(this_player()->query_level() < 40) return 0; 
	return 1; 
}

