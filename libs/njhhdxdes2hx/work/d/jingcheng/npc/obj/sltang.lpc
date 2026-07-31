#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(YEL"酸辣汤"NOR, ({"suanla tang", "suanla", "tang"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗酸辣汤。\n");
		set("unit", "碗");
		set("value", 500);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "汤",
		"remaining": 15,
		"drunk_apply": 4,
	]));
}
