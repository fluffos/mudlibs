// milk.c 牛奶瓶

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("纯牛奶", ({"chun niunai", "milk"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个玻璃瓶，里面装着八分满的牛奶。\n");
		set("unit", "瓶");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "milk",
		"name": "牛奶",
		"remaining": 15,
		"drunk_apply": 100,
	]));
}
