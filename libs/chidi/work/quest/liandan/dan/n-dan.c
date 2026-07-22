// z-dan.c
// 星星(lywin)炼丹任务附属道具

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("戾气丹", ({"niqi dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗戾气丹。\n");
		set("value", 15000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	this_player()->add("shen", -1000);
	message_vision("$N吃下一颗戾气丹，只觉得心中戾气充塞 !\n", this_player());
	destruct(this_object());
	return 1;
}

