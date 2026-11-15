
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name(CYN "真丝" HIY "宝甲" NOR,  ({ "bao jia", "jia", "armor" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("icon","05043");
		set("unit", "件");
		set("long", "一件黑黝黝的甲，毫不起眼。\n");
		set("no_sell", "这样东西能值钱么。\n");
		set("value", 100000);
		set("material", "silk");
		set("armor_prop/armor", 200);
		set("stable", 100);
	}

	setup();
	move("/d/beijing/aofu_mishi");
}
