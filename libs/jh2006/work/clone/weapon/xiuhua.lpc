// 针
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name("绣花针", ({ "xiuhua zhen", "zhen", "needle" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "一枚绣花用的细针。\n");
		set("value", 200);
                set("needle", 1);
		set("material", "steel");
		set("wield_msg", "$N用右手大拇指和食指捻起一枚绣花针。\n");
		set("unwield_msg", "$N将绣花针插回绣花绷架。\n");
	}
	init_sword(10);
	setup();
}