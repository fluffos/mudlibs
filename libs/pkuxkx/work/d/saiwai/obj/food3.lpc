// wineskin.c  酒袋

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("羊肉汤", ({"yangrou tang", "tang"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一大碗漂着油花的羊肉汤。\n");
		set("unit", "碗");
		set("value", 0);
		set("max_liquid", 10);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "soup",
		"name": "肉汤",
		"remaining": 10,
		"drunk_apply": 30,
	]));
}
