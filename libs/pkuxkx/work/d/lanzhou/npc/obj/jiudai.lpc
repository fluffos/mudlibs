// wineskin.c  酒袋

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>
void create()
{
	set_name("大酒袋", ({"shao daozi","jiudai","dai","jiu dai"}));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装烧刀子的大酒袋。\n");
		set("unit", "个");
		set("value", 600);
        set("max_liquid", 30);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "烧刀子",
        "remaining": 30,
		"drunk_apply": 8,
	]));
}
