#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name(WHT"冰镐"NOR, ({ "bing gao", "gao", "staff" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把冰镐，攀登雪山之时的必备物品，也可用来防身。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N从身后拔出$n，紧紧握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回身后。\n");
	}
	init_staff(50);
	setup();
}