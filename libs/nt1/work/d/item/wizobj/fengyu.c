// fengyu.c  凤凰羽毛  武器原料，只能被 wizard 使用
// Written by Doing Lu 1998/11/3

inherit ITEM;

#include <ansi.h>

// 打造武器粗坯时需要的一种原料
// 根据 material_ attrib = x 为判断标志，其有效点数为:power_point
// 凤凰羽毛的有效点数是 1000

void create()
{
	set_name(HIY "凤凰羽毛" NOR, ({"fenghuang yumao", "yumao", "leaf", "fengyu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一根金黄色的凤凰羽毛，闪耀着奇异的光芒，传说真武大帝曾经用它炼制成" HIY "天羽神剑。\n" NOR);
		set("unit", "根");
		set("material_attrib", "x");
		set("power_point", 1000);
		set("value", 10000000);
	}
}
