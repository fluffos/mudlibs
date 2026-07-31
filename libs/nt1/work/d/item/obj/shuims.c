// shuimusi.c  水母丝  防具原料
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// 打造防具粗坯时需要的一种原料
// 根据 material_ attrib = y 为判断标志，其有效点数为:power_point
// 有效点数是 50

void create()
{
	set_name(HIW "水母丝" NOR, ({"shuimu si", "si"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是由东海一种水母炼成的丝，很有韧性。\n" NOR);
		set("unit", "束");
		set("material_attrib", "y");
		set("power_point", 50);
		set("value", 18000);
	}
}
