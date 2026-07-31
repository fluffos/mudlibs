// chiwusha.c  赤乌沙  道具配料
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// 打造道具粗坯时需要配料提高道具的有效点数
// 根据 material_ attrib = z 为判断标志，其倍数属性为:scale
// 可以 x2

void create()
{
	set_name(HIR "赤乌沙" NOR, ({"chiwu sha", "sha"}));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一种赤红的矿物颗粒，可以与许多东西合炼，增加韧性。\n");
		set("unit", "粒");
		set("material_attrib", "z");
		set("scale", 4);
		set("value", 2000);
	}
}
