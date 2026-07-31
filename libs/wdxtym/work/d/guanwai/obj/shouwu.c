// shouwu.c 何首乌

inherit ITEM;

void create()
{
	set_name("何首乌", ({"heshou wu", "wu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵初具人形的何首乌。\n");
		set("value", 10000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if (me->query("eff_qi") >= me->query("max_qi"))
		return notify_fail("你现在没有必要服用何首乌。\n");

	me->receive_curing("qi", 500);

	message_vision("$N吃下一棵何首乌，顿时间觉得通体舒泰！\n", me);
	destruct(this_object());
	return 1;
}
