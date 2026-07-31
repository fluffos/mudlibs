// shutonggun.c

#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("木棍",({"mu gun","club"}));
	set_weight(1500);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long", "一杆十分灵便的木棍。\n");
		set("value",800);
		set("material", "bamboo");
		set("wield_msg", "$N回手从身后抽出一杆木棍。\n");
		set("unwield_msg", "$N手往后一扣，把木棍放在身后。\n");
	}
	init_club(20);
	setup();
}
