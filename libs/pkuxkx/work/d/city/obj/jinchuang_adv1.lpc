// jinchuang.c 金创药

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
	      add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
	set_name("极品金创药", ({"jipin jinchuangyao", "jin", "yao"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("base_unit", "粒");
		set("base_weight", 20);
		set("long", "这是一粒非常难得的极品金创药。\n");
		set("value", 40000);
	}
	set_amount(1);
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return 0;

		this_player()->receive_curing("qi", 3500);
		message_vision("$N吃下一粒极品金创药，瞬间恢复了很多气血。\n", this_player());
		this_object()->add_amount(-1);
		return 1;

}


