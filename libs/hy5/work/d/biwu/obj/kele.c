inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("水袋", ({"quskin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个水袋。\n");
		set("unit", "个");
		set("value", 0);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "水",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
