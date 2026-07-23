// youcha.c  酥油茶

inherit ITEM;

void init();

void create()
{
	set_name("酥油茶", ({"suyou cha","tea","cha"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗混合着酥油，马奶和茶砖的酥油茶，是西藏地区的特产食品。\n");
		set("unit", "碗");
		set("value", 80);
	        set("drink_supply", 10);
		set("food_supply", 10);
	        set("remaining", 3);
	}
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me = this_player();

	if (!id(arg)) return 0;
	if (me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢。\n");
	if (me->query("water") >= me->max_water_capacity())
		return notify_fail("你已经喝得太多了，再也灌不下一滴水了。\n");

	set("value", 0);
	me->add("water", query("drink_supply"));
	if (me->query("food") < me->max_food_capacity())
		me->add("food", query("food_supply"));
	if (add("remaining", -1))
		message_vision("$N端起一碗酥油茶喝了一大口，长出了口气，满意的点了点头。\n", me);
	else { 
		message_vision("$N仰脖把剩下的酥油茶一饮而尽，顺手用衣袖在嘴边抹了抹。\n", me);
		destruct(this_object());
	}
	return 1;
}
