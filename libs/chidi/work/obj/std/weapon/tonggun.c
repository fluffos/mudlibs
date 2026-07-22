// shutonggun.c

#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("铜棍", ({"tong gun", ",tonggun","gun","club"}));
	set_weight(2000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long", "一杆十分灵便的铜棍。\n");
		set("value", 1000);
		set("material", "tong");
		set("wield_msg", "$N回手从身后抽出一杆$n。\n");
		set("unwield_msg", "$N手往后一扣，把$n放在身后。\n");
	}
	init_club(15);
	setup();
}
