// heizhenshi.c  黑珍石  武器原料
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// 打造武器粗坯时需要的一种原料
// 根据 material_ attrib = x 为判断标志，其有效点数为:power_point
// 有效点数是 30

void create()
{
	set_name(YEL "黑珍石" NOR, ({"heizhen shi", "shi"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一块黑黝黝的石头，苗疆人用它来炼锋利的刀。\n" NOR);
		set("unit", "块");
		set("material_attrib", "x");
		set("power_point", 30);
		set("value", 6000);
	}
}
