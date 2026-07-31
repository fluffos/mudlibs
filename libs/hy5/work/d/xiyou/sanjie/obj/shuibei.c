// hulu.c  水杯

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(WHT"水杯"NOR, ({"shui bei","bei"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个装水的杯子。\n");
		set("unit", "个");
		set("value", 10);
		set("max_liquid", 50);
	}

	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 40,
		"drunk_apply": 20,
	]));
}
