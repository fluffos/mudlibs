inherit ITEM;
#include <ansi.h>
#include <condition.h>

string *cant_list=({"drunk","unchblk","wannianzui"});

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIR"朱"NOR"睛"HIC"冰"NOR"蟾"NOR, ({"chan"}));
    set_weight(50);
	set("unit", "只");
	set("value", 100000);
	set("long", "这是一千年难得一见的朱睛冰蟾, 通体透明，惟眼呈赤色, 能解百毒。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	string cond;
	
	if (!id(arg))  return notify_fail("你要吃什么？\n");

	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");

	if(arg=="chan") 
	{
    message_vision(HIG"$N吃下一只朱睛冰蟾，只觉一股清香沁入心肺，顿时灵台一片空明，神意清爽！\n" NOR, me);
    foreach( cond in keys(cond_def) )
	  {
		  if ( cond_def[cond]["type"]!="poison" )
			  continue;
		
		  if ( member_array(cond, cant_list)>=0 )
			  continue;
		
		  if ( me->query_condition(cond)>0 )
			  me->apply_condition(cond,0);
	  }

		destruct(this_object());
	}
	
	me->start_busy(2);
	return 1;
}
