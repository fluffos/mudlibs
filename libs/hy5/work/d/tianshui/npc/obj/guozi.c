// guozi.c

inherit ITEM;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("果子", ({"guozi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗红红的小果子，不知道能不能吃。\n");
        }
        setup();
}

int do_eat(string arg)
{
	int sen,efsen,max;

	object me = this_player();
	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	sen = me->query("sen");
	efsen = me->query("eff_sen");
	max = me->query("max_sen");

	if( sen >= max && efsen >= max)
	{
		message_vision("$N把小果子吃了下去，什么感觉也没有。\n", me);
		destruct(this_object());
		return 1;
	}

	if(efsen < max)
		me->add("eff_sen",(efsen+20)>max? max-efsen : 20);
	if(sen < max)
		me->add("sen",(sen+20)>max? max-sen : 20);

	message_vision("$N把小果子吃了下去，感觉精神好多了。\n", me);
	destruct(this_object());
	return 1;
}