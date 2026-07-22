// shutonggun.c

#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("铁棍", ({"tie gun", ",tiegun","gun","club"}));
	set_weight(2500);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long", "一杆十分灵便的铁棍。\n");
		set("value", 2000);
		set("material", "tie");
		set("wield_msg", "$N回手从身后抽出一杆$n。\n");
		set("unwield_msg", "$N手往后一扣，把$n放在身后。\n");
	}
	init_club(25);
	setup();
}
