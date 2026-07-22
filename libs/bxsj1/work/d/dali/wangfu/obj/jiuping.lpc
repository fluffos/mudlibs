//   jiuping.c
// Modify By River 98/12
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("细磁酒瓶", ({"jiu ping", "jiu", "ping"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装米酒的酒瓶。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "米酒",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
