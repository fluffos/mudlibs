// yfzhen.c

#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
	set_name(HIG "玉蜂针" NOR, ({ "yufeng zhen", "zhen" }) );
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("value", 0);
		set("base_unit", "根");
		set("base_weight", 10);
		set("base_value", 0);
		set("material", "iron");
		set("long", HIG "这是一些细长的针，长寸许。"NOR"\n");
	}
	set_amount(50);
	init_throwing(50);
	setup();
}
