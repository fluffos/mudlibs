
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("水晶瓶", ({"jiu2","zhuyeqing", "ping"}));
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗竹叶青,酒香扑鼻,真是好酒\n");
		set("unit", "个");
		set("value", 150);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "竹叶青",
		"remaining": 15,
		"drunk_apply": 4,
	]));
}
