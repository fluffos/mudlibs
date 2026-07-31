// jingangsha.c  金刚砂  道具配料
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// 打造道具粗坯时需要配料提高道具的有效点数
// 根据 material_ attrib = z 为判断标志，其倍数属性为:scale
// 可以 x3

void create()
{
	set_name(HIC "金刚砂" NOR, ({"jingang sha", "sha"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一种奇怪的矿石，据说可以与许多东西合炼，大大的增加强度。\n");
		set("unit", "粒");
		set("material_attrib", "z");
		set("scale", 6);
		set("value", 25000);
	}
}
