// wineskin.c  酒袋
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(WHT"水袋"NOR, ({"niu nai", "niunai"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装牛奶的大皮袋，大概装得八、九升的牛奶。\n");
		set("unit", "个");
		set("value", 1000);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "牛奶",
		"remaining": 60,
		"drunk_apply": 9,
	]));
}
