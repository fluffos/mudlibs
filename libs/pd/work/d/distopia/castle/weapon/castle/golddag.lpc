#include <discastle.h>
inherit WEAPON;
create()
{
	::create();
	set_id(({"dagger","gold dagger","knife"}));
	set_name("gold dagger");
	set_short("%^ORANGE%^Gold Dagger");
	set_long("This looks more for ornate purposes then a weapon. But it'll do in a pinch.");
	set_weight(22);
	set_curr_value("gold",100+random(40));
        set_wc(11);
	set_type("knife");
	set_hands(1);
	set_ac(1);
}

int query_auto_load() 
{
if(this_player()->query_level() < 25) return 0;
 return 1; 
}

