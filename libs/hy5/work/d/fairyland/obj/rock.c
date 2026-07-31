// rock.c
// By jpei

inherit ITEM;

void create()
{
	set_name("岩石", ({ "rock", "yanshi", "yan shi", "shi" }));
	set_weight(8000);
	set("unit", "块");
	set("long", "这是一块岩石，棱角并不分明。\n");
	set("value", 0);
	set("no_get", "这块岩石又重又没用，你拿它做甚？");
	set("material", "rock");
	setup();
}

void init()
{
	if (query("no_get"))
		add_action("do_break", ({"break", "throw", "zhi", "za", "sui", "reng", "po", "shuai"}));
}

int do_break(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("你想掷什么？\n");

	if (query("no_get")) {
		message_vision("$N将一块岩石对准另一块岩石掷去，岩石碎成了一堆碎片，其中有一片有锋锐棱角。\n", me);
		set_name("尖石", ({ "sharp rock", "rock", "jian shi", "shi" }));
		set("long", "这是一块岩石上的碎片，有着锋利的棱角。\n");
		set("unit", "片");
		delete("no_get");
		remove_action("do_break", "break");
		remove_action("do_break", "throw");
		remove_action("do_break", "zhi");
		remove_action("do_break", "za");
		remove_action("do_break", "sui");
		remove_action("do_break", "reng");
		remove_action("do_break", "po");
		remove_action("do_break", "shuai");
		return 1;
	}
	return 0;
}
