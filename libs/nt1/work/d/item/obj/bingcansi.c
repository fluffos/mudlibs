// bingcansi.c  冰蚕丝  防具原料
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// 打造防具粗坯时需要的一种原料
// 根据 material_ attrib = y 为判断标志，其有效点数为:power_point
// 有效点数是 100

void create()
{
	set_name(HIG "冰蚕丝" NOR, ({"bingcan si", "si"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一种极毒的冰蚕吐出的丝，极有韧性，就是武林高手也扯不断。\n" NOR);
		set("unit", "束");
        set("material_attrib", "silk");
		set("power_point", 100);
		set("value", 40000);
	}
}
