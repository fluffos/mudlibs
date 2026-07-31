// jixuechao.c  鸡血草  道具配料
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// 打造道具粗坯时需要配料提高道具的有效点数
// 根据 material_ attrib = z 为判断标志，其倍数属性为:scale
// 可以 x1.5

void create()
{
	set_name(RED "鸡血草" NOR, ({"jixue cao", "cao"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是生长在雪山上的一种草，由于里面含有矿物，因此是暗红色的。\n");
		set("unit", "颗");
		set("material_attrib", "z");
		set("scale", 3);
		set("value", 1000);
	}
}
