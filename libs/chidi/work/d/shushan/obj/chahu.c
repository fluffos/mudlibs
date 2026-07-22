// chahu.c 茶壶 
inherit F_LIQUID;
inherit ITEM;
void create()
{
	set_name("茶壶", ({"kettle", "cahhu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装水的茶壶，由于经济使用、携带方便，所以深得江湖人士喜爱。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 150);
	}
	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "water",
		"name": "水",
		"remaining": 15,
//		"drunk_apply": 3,
	]));
}
