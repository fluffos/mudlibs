// chanhunsi.c  缠魂丝  防具原料
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// 打造防具粗坯时需要的一种原料
// 根据 material_ attrib = y 为判断标志，其有效点数为:power_point
// 有效点数是 30

void create()
{
	set_name(HIG "缠魂丝" NOR, ({"chanhun si", "si"}));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是雪山毒蛛织的丝，非常有韧性，有人用它来制作护甲。\n" NOR);
		set("unit", "束");
		set("material_attrib", "y");
		set("power_point", 30);
		set("value", 10000);
	}
}
