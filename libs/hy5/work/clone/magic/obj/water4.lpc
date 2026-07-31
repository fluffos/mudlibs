// wineskin.c  酒袋
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIC"风神之水"NOR, ({"ice water", "icewater"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装风神之水的大皮袋，大概装得八、九升的风神之水。\n");
		set("unit", "个");
		set("value", 2000);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "风神之水",
		"remaining": 160,
		"drunk_apply": 20,
	]));
}
