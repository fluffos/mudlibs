//Cracked by Roath
// pishui-zhu.c 辟水灵珠

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
	add_action("do_han", "han");
}

void create()
{
	set_name("辟水灵珠", ({"pishui zhu", "zhu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗由碧水金睛兽兽角制成的辟水灵珠，能让佩戴者寒毒不侵，洪波辟易。\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg)) return notify_fail("你要吃什么？\n");

	message_vision("\n$N咕噜一声，把辟水珠吞下肚里，似乎什么味道也没尝到 ... \n", this_player());
	this_player()->set_temp("zhu_eat", 1);

	destruct(this_object());
	return 1;
}

int do_han(string arg)
{
	if (!id(arg)) return notify_fail("你要含什么？\n");

	message_vision("\n$N小心翼翼地拈起辟水灵珠，含在嘴里。\n", this_player());
	this_player()->set_temp("zhu_han", 1);

	return 1;
}
