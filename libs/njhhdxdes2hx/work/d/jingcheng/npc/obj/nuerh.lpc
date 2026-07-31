// nuerh.c

#include <ansi.h>  

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(RED"女儿红"NOR, ({"nerh jiu" }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", BLU"这是三十年陈的女儿红，芳香四溢，你已经醉了。"NOR);
		set("unit", "瓶");
		set("value", 1000);
		set("max_liquid", 25);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "女儿红",
		"remaining": 25,
		"drunk_apply": 5,
	]));
}
