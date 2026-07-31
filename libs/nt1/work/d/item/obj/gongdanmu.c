// gongdanmu.c  汞丹母  道具配料
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// 打造道具粗坯时需要配料提高道具的有效点数
// 根据 material_ attrib = z 为判断标志，其倍数属性为:scale
// 可以 x2.5

void create()
{
	set_name(HIY "汞丹母" NOR, ({"gongdan mu", "mu", "dan"}));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是水银和金的混合物，可以与许多东西合炼，增加强度。\n");
		set("unit", "块");
		set("material_attrib", "z");
		set("scale", 5);
		set("value", 10000);
	}
}
