#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIG"少林秘制百草丹"NOR, ({"baicao dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗用数百种药物精制而成的丹药，有神奇药效，只能在少林寺藏经阁副本使用。\n");
                set("value", 5000);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        object me = this_player();

	if (!id(arg))  return notify_fail("你要吃什么？\n");
          if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	
	if (time()-me->query_temp("last_eat_dan")<300)
              {
               tell_object(me,"等等再吃吧，你以为吃萝卜呢。\n");
               return 1;
               }
                   
	if ( environment(me)->query("outdoors")!="shaolin/cjg" )
		return notify_fail("百草丹只能在藏经阁任务副本中使用。\n");
	
	//if(arg=="dan") 
	{
                me->set_temp("last_eat_dan",time());  
                fw = (int)me->max_food_capacity();
                me->set("food", fw);
                fw = (int)me->max_water_capacity();
                me->set("water", fw);
	 	            me->set("neili",me->query("max_neili")*2);
                message_vision(HIG"$N吃下一颗百草，顿时只觉丹田充满了内力！\n"NOR,me);
		            me->start_busy(1);
        	      destruct(this_object());
	}
	return 1;
}

