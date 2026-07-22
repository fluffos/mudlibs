// bottle.c
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(GRN"清水葫芦"NOR, ({"qingshui hulu", "hulu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来盛水的葫芦。\n");
		set("unit", "个");
		set("value", 100);
		set("max_water", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
