// lianzi-wan.c

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("莲子丸", ({"lianzi wan", "lianzi", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗苏州名贵的莲子丸药。\n");
		set("value", 5000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("你现在不需要用莲子丸。\n");
	else {
		this_player()->receive_curing("qi", 50);
		message_vision("$N吃下一颗莲子丸，气色看起来好多了。\n", this_player());
		destruct(this_object());
		return 1;
	}
}

