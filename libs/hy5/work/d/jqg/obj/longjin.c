// longjin.c

#include <ansi.h>

inherit ITEM;

void init()
{
     add_action("do_drink", "drink");
}

void create()
{
       set_name(HIY "龙井茶" NOR, ({"longjin cha", "lingjin", "cha", "tea"}));
       set_weight(700);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long", "这是雨后采集的西湖龙井极品茶。\n");
               set("unit", "杯");
               set("value", 1000);
               }
}

int do_drink(string arg)
{
       object me = this_player();
       if (!id(arg)) return 0;
       if ( me->query("water") >= me->max_water_capacity())
         return notify_fail("你都喝饱了，怎么还要喝？\n");       
       message_vision(HIG "$N品了一口"
       +this_object()->query("name")+
       HIG "，顿时觉得精神为之一振。\n"
       NOR,me);
       me->set("water", me->max_water_capacity());
       destruct(this_object());
       return 1;
}
