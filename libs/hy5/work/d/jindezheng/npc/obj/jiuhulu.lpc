#include <weapon.h>
inherit HAMMER;
inherit F_LIQUID;

void create()
{
	set_name("酒葫芦", ({"jiuhulu", "hulu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个颜色微黄的装酒葫芦。\n");
		set("unit", "个");
		set("value", 500);
		set("max_liquid", 20);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "烧刀子",
		"remaining": 20,
		"drunk_apply": 20,
	]));
init_hammer(110);
setup();
}
