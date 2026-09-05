#pragma save_binary
// ginseng.c

inherit COMBINED_ITEM;

void create()
{
	set_name("人参",({"ginseng"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
		"这是一根黄灿灿的大人参。\n");
	set("unit","根");
	set("value", 5000);
	set("base_value", 5000);
	set("base_unit", "根");
	set("base_weiht",50);
	}
	set_amount(1);
}

void init()
{
	add_action("eat_ginseng","eat");
}


int eat_ginseng(string arg)  
{
       object me;

       if( !this_object()->id(arg) ) return 0;

       me = this_player();
	if( me->query("food") >= me->max_food_capacity() )
		return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");
	
       me->add("food", 50);
	add_amount(-1);	
	message_vision("$N将剩下的" + name() + "吃得乾乾净净。\n", me);

       me->add("force", 50);
       if( (int)me->query("force") > (int)me->query("max_force") * 2) 
       {
                if( (int)me->query("max_force") >= ((int)me->query_skill("force", 1) + 
                         me->query_skill("force")/5) * 10 + 10 ) 
                {
                        
                       write("内力修为似乎已到了极限。\n");
                } 
                else 
                {
                        write("你的内力增强了！\n");
                        me->add("max_force", 1);
                }
        }       
        return 1;
}
