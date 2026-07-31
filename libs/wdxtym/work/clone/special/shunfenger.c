// sunfenger.c

inherit COMBINED_ITEM;

void create()
{
	set_name("顺风耳", ({ "shunfeng er" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("long", "这是神奇的魔法道具，可以打探(locate)人的行踪。\n");
		set("no_sell", "这是什么东西？\n");
		set("base_value", 1);
		set("base_weight", 10);
		set("base_unit", "只");
	}
	set_amount(1);
	setup();
}

void init()
{
	add_action("do_locate", "locate");
}

int do_locate(string arg)
{
	object who;
	object env;

	if (! query_amount())
		return 0;

	if (! arg)
		return notify_fail("你想打探谁的行踪？\n");

	who = find_living(arg);
	if (! objectp(who))
		return notify_fail("没有这个人的消息啊！\n");

	if (! objectp(env = environment(who)))
		return notify_fail("这个人不知道在那里耶！\n");

	write(sprintf("%s据说是在%s...\n", who->name(1), env->short()));
	add_amount(-1);
	return 1;
}


string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}
