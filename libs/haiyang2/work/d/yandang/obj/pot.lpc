// pot.c  by ksusan 7/12/97

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大水缸", ({ "pot", "shuigang" , "big shuigang" }) );
	set_weight(1000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个可以装八、九十升清水的大水缸，如果你口渴，可以舀水来喝(drink)。\n");
		set("unit", "个");
		set("value", 20);
		set("max_liquid", 200);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"remaining": 200,
//		"drunk_apply": 6,
	]) );
}
