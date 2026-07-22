inherit ITEM;

void init();
void do_eat();

void create()
{
    set_name("龙井茶",({"longjing cha", "cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("long", "一杯热腾腾的香茶～～～\n");
        set("unit", "杯");
        set("remaining", 3);
        set("drink_supply", 25);
	}
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{
	int heal, recover, jing, e_jing, m_jing;
	recover = 5;

	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");
	if( (int)this_player()->query("water")
	   >= (int)this_player()->max_water_capacity() )
		return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

	set("value", 0);
	this_player()->add("water", (int)query("drink_supply"));


	if( this_player()->is_fighting() ) this_player()->start_busy(2);
	add("remaining", -1);
	if ( query("remaining") )
	{
        message_vision("$N端起龙井茶 ，有滋有味地品了几口。\n"+
        "一股凉气直入心脾，$N觉得精神好多了。\n", this_player());
	} else 
	{ 
        message_vision("$N把剩下的茶一饮而尽。\n"+
        "一股凉气直入心脾，$N觉得精神好多了。\n", this_player());
		destruct(this_object());
	}
	return 1;
}
