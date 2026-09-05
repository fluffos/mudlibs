// jieyao.c 冰魄银针解药

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("解药", ({"jie yao", "yao", "jieyao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包冰魄银针毒的解药。\n");
		set("value", 5000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return 0;
	if ((int)this_player()->query_condition("bing_poison") == 0)
		return notify_fail("你现在不需要用药。\n");
	else {
		this_player()->apply_condition("bing_poison", 0);
		message_vision("$N吃下一包解药，气色看起来好多了。\n", this_player());
		destruct(this_object());
		return 1;
	}
}

