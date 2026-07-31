// mian.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("粗瓷碗", ({ "wan" }));
	set_weight(900);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用土窑烧制的花边瓷碗。\n");
		set("unit", "个");
		set("value", 50);
		set("food_supply", 10);
		set("water_supply", 25);
		set("max_liquid", 10);
		set("only_do_effect", 1);
	}

	set("liquid", ([
		"type": "water",
		"name": "米粥",
		"remaining": 6,
		"drunk_supply": 10,
	]));

	setup();
}

int do_effect(object me)
{
	if (! (int)query("liquid/remaining") ||
	    query("liquid/name") != "米粥")
		return 0;

	if (me->query("food") >= me->max_food_capacity())
		return notify_fail("你已经吃太饱了，再也吃不下了。\n");

	me->add("food", query("food_supply"));
	if (me->query("water") < me->max_water_capacity())
		me->add("water", query("water_supply"));

	add("liquid/remaining", -1);
	if (query("liquid/remaining"))
   		 message_vision("$N端起碗来，猛喝了几口粥。\n", me);
	else
   		 message_vision("$N端起碗来，把剩下的粥喝得干干净净。\n", me);

	return 1;
}
