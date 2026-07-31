// jiudai.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("水壶", ({ "shui hu", "hu","shui","shuihu" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个用羊皮缝制的水壶，可以用来装水喝。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
}
