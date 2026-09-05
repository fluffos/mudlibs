//tianyuebing  中秋月饼(加50内力)
//Made by yom  24/12/2003
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("圣诞礼物",({"chrisgift"}));
        set("long","这是Yom亲自制作的圣诞礼物,盼望大家吃(eat)了以后别欺负我，55  :) \n");
        set("unit","件");
	set("no_drop",1);
        set("no_get",1);
        set("value",0);
        set("no_store",1);
       setup();
}

void init()
{
    add_action("do_eat","eat");
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if (!arg)  return notify_fail("你要吃什么？\n");
    if(arg=="chrisgift") 
    {
        if ( (int)me->query("chris/gift" ) > 0 ) return notify_fail("你已经吃过礼物了，不要再吃了吧，小心撑着了\n");
        me->add("max_neili",100);
        me->add("max_jingli",100);
        message_vision(HIG"\n$N吃了礼物，只觉得浑身上下舒服极了\n"NOR,me);
        me->set("chris/gift",1);
          tell_object(me,"\n你的内力、精力各增长了100点! \n\n");
        destruct(this_object());
     }
     return 1;
}
