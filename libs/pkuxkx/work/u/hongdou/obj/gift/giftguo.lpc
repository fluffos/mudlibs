#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

string *names = ({
      HIW"元宵"NOR,
});


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name( names[random(sizeof(names))] , ({ "gift guo","guo" }) );
      set("no_drop","这可是巫师的礼物呀，丢了多可惜！\n");
        set("unit", "枚");
      set("long", HIC"这是一枚充满芳香气味的元宵，吃(eat)下去一定有意想不到的效果。\n"NOR);
	set("value",0);
        set("no_store",1);
        setup();
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if (!arg)  return notify_fail("你要吃什么？\n");
    if((arg=="gift guo") || (arg=="guo")) 
    {
        if ( (int)me->query_condition("gift_guo" ) > 0 ) return notify_fail("你已经吃过仙果了，难道还想成仙吗？\n");
// me->add("score",100);
     tell_object(me,"你的师门忠诚度增长了100点!\n");
//      me->apply_condition("gift_guo", 2000);
        destruct(this_object());
     }
     return 1;
}
