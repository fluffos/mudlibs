
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("小金丹", ({"xiao jindan", "xiao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一粒日月教徒必备的疗伤丹。\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("你现在不需要用小金丹。\n");
	else {
		this_player()->receive_curing("qi", 100);
		message_vision("$N吃下一粒小金丹，气色看起来好多了。\n", this_player());
		destruct(this_object());
		return 1;
	}
}

