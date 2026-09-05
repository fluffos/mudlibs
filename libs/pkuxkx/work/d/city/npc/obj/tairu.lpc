// tairu.c  人参三肽乳

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
	set_name(HIW"人参三肽乳"NOR, ({"tairu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "全世界第一家有机肽乳,对身体健康有全方位作用。\n");
		set("unit", "个");
                set("value", 4000);
		set("max_liquid", 30);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "人参三肽乳",
		"remaining": 30,
		"drunk_apply": 3,
	]));
}

