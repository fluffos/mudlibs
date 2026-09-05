// caoyao.c 草药

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_fu", "fu");
}

void create()
{
	set_name("草药", ({"caoyao", "yao"}));
    set("is_caoyao",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "这是一片普通的草药。\n");
		set("value", 100);
	}
	setup();
}

int do_fu(string arg)
{
	if (!arg || (arg != "caoyao" && arg != "yao" ) )
		return notify_fail("你要敷什么药？\n");
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("你现在不需要敷草药。\n");
	else {
		this_player()->receive_curing("qi", 5);
		message_vision("$N敷了一片草药在伤口上，感到伤势好多了。\n", this_player());
		destruct(this_object());
		return 1;
	}
}

