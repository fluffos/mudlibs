
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("白玉碗", ({"jiu3","nverhong", "baiyu"}));
	set_weight(900);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗女儿红,酒香扑鼻,真是好酒\n");
		set("unit", "个");
		set("value", 200);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "女儿红",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}
