//by : pipip
inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name(HIB "太极丹" NOR, ({"taiji dan", "dan"}));
        set("unit", "颗");
    set("long", "武当宋远桥送给张三丰的百岁大礼，不知为何会落到你手中。\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("你要吃什么？\n");
  if(this_player()->query("id")!=query("zhuren"))
  return notify_fail("这棵丹不是你练的,你吃个什么劲。\n");

   this_player()->set_skill("force",this_player()->query_skill("force",1) + 1 ); 
   message_vision(HIC "$N吞下太极丹，一股真气从单田升起，渐渐的渗入全身血脉。\n" NOR,this_player() );
    destruct(this_object());
    return 1;
}

