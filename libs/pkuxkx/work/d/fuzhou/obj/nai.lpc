// chui modify 
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
        set_name(HIG+"柰"+NOR, ({"nai", }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗绿色透亮的柰。这个盛产于南方水果，吃了听说对身体特别好。\n");
                    set("value", 200);
                           set_weight(50);
                   }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");
        
        if( (int)me->query("food") >= (int)me->max_food_capacity() )
        return notify_fail("你已经吃太饱了，再也吃不下柰了。\n");
        
        if( (int)me->query("water") >= (int)me->max_water_capacity() )
        return notify_fail("你已经喝太多了，再也吃不下柰了。\n");

        
      if ( random((int)me->query("kar")+(int)me->query("int")) > 45 )
        {
                  if (random(20)>15)
                {
                me->add("tianchi/nai", 1);
           message_vision(HIC "$N吃下一颗"+HIG+"柰"+HIC"，感觉好多了！\n" NOR, me);
                }
                
        }
        message_vision(HIC "$N吃下一颗"+HIG+"柰"+HIC"，觉得神清气爽，心旷神怡！\n" NOR, me);
            me->add("water", 4);
            me->add("food", 4);

        destruct(this_object());
        return 1;
}
