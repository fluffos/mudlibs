// yaocao.c
// By jpei

inherit ITEM;

void create()
{
	set_name("药草", ({ "yao cao", "yao", "cao" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵药草，大概有疗伤的作用吧。\n");
		set("value", 30);
		set("material", "grass");
	}
	setup();
}

void init()
{
	add_action("do_eat", ({"eat", "chi"}));
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("你想吃什么？\n");

	if (me->query("eff_qi") ==  me->query("max_qi"))
		return notify_fail("你现在不需要用药草。\n");
	else {
		me->receive_curing("qi", 20);
		message_vision("$N吃下一棵药草，气色看起来好了一些。\n", me);
		destruct(this_object());
		return 1;
	}
}
