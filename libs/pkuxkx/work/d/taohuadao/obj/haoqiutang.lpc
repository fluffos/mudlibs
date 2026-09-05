// haoqiutang.c 好逑汤

inherit ITEM;

void init();
void do_eat();

void create()
{
      set_name("好逑汤", ({"haoqiu tang","tang"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
      set("long","一碗香喷喷的好逑汤。 \n");
      set("unit","碗");
        set("remaining", 4);
      set("drink_supply", 35);
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

// No heal effect for "好逑汤"

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
     message_vision("$N端起一只景德镇瓷碗，喝了几口好逑汤。\n"+
     "一股香甜甜的味道直入口中，$N觉得舒服多了。\n", this_player());
	} else 
	{ 
     message_vision("$N端起景德瓷碗，将碗中的好逑汤一饮而尽。\n"+
    "一股香甜甜的味道直入口中，$N觉得舒服极了。\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
