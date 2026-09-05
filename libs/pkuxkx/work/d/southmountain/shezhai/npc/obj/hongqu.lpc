// wineskin.c  酒袋
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(RED"红曲酒瓶"NOR, ({"hong qu", "hongqu", "wine"}));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是装着畲族自酿红曲的酒瓶。\n");
		set("unit", "瓶");
		set("value", 500);
        set("max_liquid", 5);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "红曲",
        "remaining": 5,
		"drunk_apply": 4,
	]));
}
