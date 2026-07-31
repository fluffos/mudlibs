// 黑龙鞭
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name(HIB"海潮沧浪鞭"NOR, ({ "canglang bian", "bian" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄海潮沧浪鞭，坚韧无比。有大海的力量。\n");
		set("value", 10000);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声抖出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n卷回腰间。\n");
	}
	init_whip(680);
	setup();
}
