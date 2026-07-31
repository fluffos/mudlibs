// bosijiu.c

#include <ansi.h>  

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(CYN"波斯酒"NOR, ({"bosi jiu" }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", WHT"一大瓶芳香四溢的异域美酒－波斯酒，你忍不住流口水。\n"NOR);
		set("unit", "瓶");
		set("value", 1000);
		set("max_liquid", 25);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "波斯酒",
		"remaining": 25,
		"drunk_apply": 5,
	]));
}
