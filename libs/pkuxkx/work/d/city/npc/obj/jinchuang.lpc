// jinchuang.c 金创药

inherit ITEM;

void setup()
{}

void init()
{
	      add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
	set_name("金创药", ({"jinchuang yao", "jin", "yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包武林人士必备的金创药。\n");
		set("value", 1500);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return 0;

		this_player()->receive_curing("qi", 200);
		message_vision("$N吃下一包金创药，气色看起来好多了。\n", this_player());
		destruct(this_object());
		return 1;

}


