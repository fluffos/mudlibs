// wineskin.c  酒袋

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("酒杯", ({"jiubei", "glass", "bei"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个装满上等西域葡萄美酒的酒杯。\n");
		set("unit", "个");
		set("value", 0);
        set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "葡萄酒酒",
        "remaining": 20,
		"drunk_apply": 30,
	]));
}
