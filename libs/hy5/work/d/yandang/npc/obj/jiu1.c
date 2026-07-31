
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("青磁碗", ({"jiu1","huadiao", "wan"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗花雕酒,酒香扑鼻,真是好酒\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "花雕酒",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
