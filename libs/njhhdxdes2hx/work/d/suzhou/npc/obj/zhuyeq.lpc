// zhuyeq.c

#include <ansi.h>  

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(BLU"竹叶青"NOR, ({"zhuyeq jiu" }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", MAG"你拿着一瓶驰名天下的竹叶青，忍不住翩翩欲醉。\n"NOR);
		set("unit", "瓶");
		set("value", 1000);
		set("max_liquid", 25);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "竹叶青",
		"remaining": 25,
		"drunk_apply": 5,
	]));
}
