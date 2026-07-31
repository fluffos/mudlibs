// changqiang.c 长枪

#include <weapon.h>
inherit CLUB;

void create()
{
	set_name("黑魂枪·神韵", ({ "heih syss" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long", "这是一杆黑魂枪。\n");
		set("value", 20000);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N掣出一杆根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n反别身后。\n");
	}
  	init_club(25000);
	setup();
}

