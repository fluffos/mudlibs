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
	set_name("上等金创药", ({"shangdeng jinchuangyao", "jin", "yao"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "瓶");
		set("base_unit", "粒");
		set("base_weight", 20);
		set("long", "这是一包武林人士必备的金创药。\n");
		set("value", 15000);
	}
	set_amount(1);
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return 0;

		this_player()->receive_curing("qi", 2000);
		message_vision("$N吃下一包上等金创药，略微调息，感觉好多了。\n", this_player());
		this_object()->add_amount(-1);
		return 1;

}


