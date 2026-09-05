// zhuhu.c  竹壶

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("竹壶", ({"zhuhu", "hu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装清水的竹壶，用大竹做成。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 15);
	}

	
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 15,
		"drunk_apply": 15,
	]));
}
