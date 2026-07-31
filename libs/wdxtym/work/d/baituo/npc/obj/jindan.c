// more work needed to use this object to make poison

inherit ITEM;

void create()
{
	set_name("金蛇胆", ({"jin dan", "jin"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "这是一只黄灿灿的金蛇胆。\n");
		set("value", 200);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision("$N一仰头，吃下了$n。\n", me, this_object());
	me->set_temp("die_reason", "吃了一枚蛇胆，中毒死了");
	me->die();
	destruct(this_object());
	return 1;
}
