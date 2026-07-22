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
	set_name("正气丹", ({"zhengqi dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗正气丹。\n");
		set("value", 15000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	this_player()->add("shen", 1000);
	message_vision("$N吃下一颗正气丹，只觉得心中正气回荡 !\n", this_player());
	destruct(this_object());
	return 1;
}

