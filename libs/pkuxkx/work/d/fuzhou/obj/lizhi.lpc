// chui modify 
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
        set_name(HIM+"荔枝"+NOR, ({"li zhi", "lizhi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗紫红晶亮的荔枝。这个盛产于南方水果，吃了听说对皮肤特别好，让你光彩照人。\n");
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
        return notify_fail("你已经吃太饱了，再也吃不下荔枝了。\n");
        
        if( (int)me->query("water") >= (int)me->max_water_capacity() )
        return notify_fail("你已经喝太多了，再也吃不下荔枝了。\n");

        
/*
        if ( random((int)me->query("kar" )+(int)me->query("per")) > 35)
        {
                  if (random(20)>15)
                {
//                me->add("tianchi/lizhi", 1)
                }
                
        }
*/
        message_vision(HIG "$N吃下一颗"+HIM+"荔枝"+HIG"，觉得神清气爽，心旷神怡！\n" NOR, me);
            me->add("water", 2);
            me->add("food",2);

        destruct(this_object());
        return 1;
}
