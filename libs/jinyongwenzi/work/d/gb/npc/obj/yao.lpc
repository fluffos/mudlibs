//  gaibang-shangyao by dubei

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_fu", "fu");
}

void create()
{
	set_name("丐帮伤药", ({"gaibang shangyao", "shangyao"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包不起眼的丐帮伤药，但据说功效卓著。\n");
		set("value", 100);
		set("no_drop", 1);
		set("no_give",1);
		set("no_put",1);
	}
	setup();
}

int do_fu(string arg)
{
	object me;
	me = this_player();
	if (!id(arg))
		return notify_fail("你要吃什么？\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("战斗中不能吃药疗伤！\n");
	if (me->query("eff_qi") >= me->query("max_qi"))
		return notify_fail("你现在没伤，瞎吃什麽药？\n");
	me->receive_curing("qi", 100);
	message_vision("$N服下一包伤药，伤势减轻了许多。\n", me);
	me->start_busy(2);
	destruct(this_object());
	return 1;
}

