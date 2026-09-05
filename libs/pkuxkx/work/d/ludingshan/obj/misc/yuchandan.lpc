inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("雪参玉蟾丹", ({"yuchan dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "颗");
		set("long", "\n这是高丽进贡的灵药，服后解毒疗伤，灵验非凡。\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg))
		return notify_fail("你要吃什么？\n");
	if(me->query("max_jingli") < 500)
	   {
	   	me->add("max_jingli", 2);
	    	me->add("jingli", 2);
	   }
	else
	   {
	   	me->add("max_jingli",1);
	    	me->add("jingli", 1);
	    }
	message_vision( "$N吃下一粒雪参玉蟾丹，只觉真气上涌，急忙盘膝而坐，闭目运功...\n" , me);
	destruct(this_object());
	return 1;
}
