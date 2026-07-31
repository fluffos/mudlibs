// jinchuang.c 金创药
inherit COMBINED_ITEM;

void init()
{
	add_action("do_eat", "eat");
        add_action("do_eat", "fu");
}

void create()
{
	set_name("玉真散", ({"yuzhen san", "yuzhen","san"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "些");
      set("value", 5000);
                set("heal_up", 1);
                set("base_unit", "包");
                set("base_weight", 100);
 		set("long","这是一份华山派的玉真散，是疗伤的药物。\n");
		set("base_value", 5000);
	}
	set_amount(1);
}

int do_eat(string arg)
{
           
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
     if (this_player()->is_busy() || this_player()->is_fighting())
        return notify_fail("你正忙着呢。\n");
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("你现在不需要用玉真散。\n");
	else {
		this_player()->receive_curing("qi", 90);
		message_vision("$N的脸色渐渐开始好转了。\n", this_player());
		destruct(this_object());
                        this_player()->start_busy(1);
		return 1;
	}
}

