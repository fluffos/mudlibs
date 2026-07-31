// sl_cloth.c

#include <ansi.h>

inherit ITEM;


void create()
{
        set_name(HIW"小"HIW"白"HIW"石"NOR, ({"potcard"}));
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
		set("text" , "这是一颗老魔石，能存贮潜能（每次存取5万点，最多2000万，加收5%手续费）有"ZJURL("cmds:zhuru potential")+ZJSIZE(20)+"注入"NOR"(zhuru potential)和"ZJURL("cmds:xi potential")+ZJSIZE(20)+"汲取"NOR"(xi potential)的功效。"NOR"\n");
		set("long",HIW+query("text") );
                set("value", 8000);
            set("yuanbao", 24);
			  set("no_give",1);
    set("no_sell",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_sell", 1);
                set("material", "stone");
        }
        setup();
}

void init()
{
	add_action("do_zhuru","zhuru");
	add_action("do_xiqu","xi");
}

int do_zhuru(string arg)
{
	int cost,max_potential;
	object me = this_player();


	if  
		(arg!="potential")
		 {
		return notify_fail("你要蓄入什么?\n");
       }
 
    else if((me->query("potential")) <= 52500 )
			   {
		return notify_fail("你的潜能不足（1%的手续费）！\n");
	 }
	 
	else if((me->query("potential1"))>= 20000000 )
			 {
		return notify_fail("已经充盈，你无法蓄入更多潜能！\n");
	 }
  


	
	me->add("potential" , -52500);//百分之4手续费
        me->add("potential1" , 50000);
	//message_vision(HIC"$N"HIC"你，将潜能蓄入其中。"NOR"\n",me);
      tell_object(me,HIC"你，将潜能蓄入其中。"NOR"\n");
tell_object(me,HIR"目前老魔石中存贮"+me-> query("potential1")+"点潜能。"NOR"\n");
  	
me->save();	

	return 1;
}

int do_xiqu(string arg)
{

	object me = this_player();

	if (arg!="potential")
		return notify_fail("你要吸取什么?\n");

   else   
	if( (me->query("potential1"))<50000 )
		return notify_fail("储存的潜能已经消耗光了！\n");

	

	
	me->add("potential1" , -50000);
	me->add("potential" , 50000);//百分之4手续费


     

        tell_object(me,HIC"你双手虚按潜能卡，从中吸取潜能。"NOR"\n");	

      
tell_object(me,HIR"目前老魔石中存贮"+me-> query("potential1")+"点潜能。"NOR"\n");
me->save();
	return 1;
}


int query_autoload() { return 1; }