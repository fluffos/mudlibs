// gangzhang.c

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("钢杖", ({ "gangzhang" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄钢杖。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n背到背后。\n");
	}
	init_staff(20);
	setup();
}
