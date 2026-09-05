// mudancha.c 牡丹茶

inherit ITEM;

void init();
void do_eat();

void create()
{
        set_name("牡丹茶", ({"mudan cha","cha","tea"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long","一杯热腾腾的牡丹茶。 \n");
		set("unit", "杯");
        set("remaining", 4);
        set("drink_supply", 30);
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
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

	set("value", 0);
    this_player()->add("water", (int)query("drink_supply"));
    jing = (int)this_player()->query("jing");
    e_jing = (int)this_player()->query("eff_jing");
    m_jing = (int)this_player()->query("max_jing");

// No heal effect for 牡丹茶

    if ( e_jing < m_jing )
	{ 	
		if ( (e_jing + heal) >= m_jing )
		{
			this_player()->set("eff_jing", m_jing);
		} else
		{	
			this_player()->set("eff_jing", e_jing+heal);
		}	
	} 

	if (jing < e_jing )
	{
        if ( (jing + recover) >= e_jing )
        {
            this_player()->set("jing", e_jing);
        } else
        {   
            this_player()->set("jing", jing+recover);
        }   
	}

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
      message_vision("$N端起九龙玉杯，有滋味地品了几口牡丹茶。 \n"+
     "一股香气直入心脾，$N觉得精神好多了。 \n", this_player());
	} else 
	{ 
      message_vision("$N端起九龙玉杯，把剩下的牡丹茶一饮而尽。 \n"+
    "一股香气直入心脾，$N觉得精神好多了。\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
