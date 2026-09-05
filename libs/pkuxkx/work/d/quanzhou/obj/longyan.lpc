#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}
void destguo()
{
	message_vision("$N慢慢渗出水来，一会就腐烂掉了。\n",this_object());
	destruct(this_object());
}

void create()
{
        set_name(HIY+"龙眼"+NOR, ({"long yan", "longyan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗圆润土黄的龙眼。这种盛产于南方水果，吃了听说补元气，让你睡的好。\n");
                     set("value", 100);
                   }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");
        
        if( (int)me->query("food") >= (int)me->max_food_capacity() )
        return notify_fail("你已经吃太饱了，再也吃不下龙眼了。\n");
        
        if( (int)me->query("water") >= (int)me->max_water_capacity() )
        return notify_fail("你已经喝太多了，再也吃不下龙眼了。\n");

        
/*
        if ( random((int)me->query("kar" )) > 20 )
        {
                if (random(20)>10)
                {
           message_vision(HIC "$N吃下一颗"+HIY+"龙眼"+HIC"，感觉好多了！\n" NOR, me);
                me->add("tianchi/longyan", 1);
                }
                
        }
*/
message_vision(HIC "$N吃下一颗"+HIY+"龙眼"+HIC"，觉得神清气爽，心旷神怡！\n" NOR, me);
          me->add("food", 5);
          me->add("water", 5);

        destruct(this_object());
        return 1;
}

