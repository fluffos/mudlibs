// shedangao.c

inherit ITEM;

void create()
{
	set_name("蛇胆膏", ({"shedan gao", "gao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "这是珍贵补品『蛇胆膏』。\n");
		set("value", 1000);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	if (me->query("max_jingli") < me->query_jingli_limit())
		message_vision( "$N吃下一块蛇胆膏，顿觉一股浩荡真气直涌上来，精力大增...\n" , me);
	else
		return notify_fail("你服用蛇胆膏已无效用。\n");

	me->add("max_jingli", 2);
	if (me->query("max_jingli") > me->query_jingli_limit())
		me->set("max_jingli", me->query_jingli_limit());

	destruct(this_object());
	return 1;
}
