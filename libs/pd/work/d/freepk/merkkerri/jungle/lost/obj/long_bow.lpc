
#include <std.h>
inherit WEAPON;

void create() {
  ::create();

    set_name("long bow");
    set_id( ({ "bow", "long bow" }) );
    set_short("Long bow");
    set_long("A very large bow, it looks to be used for hunting big game.");
    set_type("ranged");
    set_wc(13);
    set_weight(20);
    set_curr_value("gold", 50 + random(20));

}
int query_auto_load() 
{ 
	if (this_player()->query_level() > 50)
		return 1;
	return 0;
}

