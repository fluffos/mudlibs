// tea.c 龙都香茗


inherit ITEM;

void init();
void do_eat();

void create()
{
	set_name("龙都香茗",({"longdu xiang", "xiang", "tea"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "汤色淡黄，其味幽幽，这是蜀中名茶「龙都香茗」！\n");
		set("unit", "杯");
		set("value", 800);
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
	
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

	set("value", 0);
    this_player()->add("water", (int)query("drink_supply"));

    m_jing = (int)this_player()->query("max_jing");
	heal = (int)this_player()->query_con();
    e_jing = (int)this_player()->query("eff_jing");
	
    if ( e_jing < m_jing )
	{ 	
		if ( (e_jing + heal) >= m_jing )
		{
			this_player()->set("eff_jing", m_jing);
		} else
		{	
			this_player()->add("eff_jing", heal);
		}	
	} 

    e_jing = (int)this_player()->query("eff_jing");
    jing = (int)this_player()->query("jing");
	recover = 30+heal;
    
	if (jing < e_jing )
	{
        if ( (jing + recover) >= e_jing )
        {
            this_player()->set("jing", e_jing);
        } else
        {   
            this_player()->add("jing", recover);
        }   
	}

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N端起杯香茶，有滋有味地品了几口。\n"+
      		"一股香气直入心脾，$N觉得精神好多了。\n", this_player());
	} else 
	{ 
   		 message_vision("$N端起雕花小杯，把里面的「龙都香茗」一饮而尽。\n"+
      		"一股幽香直入心脾，$N顿时觉得精神大振。\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
