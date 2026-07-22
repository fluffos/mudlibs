// shutonggun.c

#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("木棍", ({"mu gun", ",mugun","gun","club"}));
	set_weight(1000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long", "一杆十分灵便轻巧的木棍。\n");
		set("value", 200);
		set("material", "mu");
		set("wield_msg", "$N回手从身后抽出一杆$n。\n");
		set("unwield_msg", "$N手往后一扣，把$n放在身后。\n");
	}
	init_club(5);
	setup();
}
