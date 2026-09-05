//tianyuebing  中秋月饼(加50精力)
//Made By jason@mudnow.com
//2000-5.-6
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("咸月饼",({"xian yuebing","yuebing"}));
        set("long","这是度每老先生亲自制作的中秋月饼,看上去就让人馋涎欲滴,还不赶紧尝尝(eat)?\n");
        set("unit","块");
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
    if((arg=="tian yuebing") || (arg=="yuebing")) 
    {
        if ( (int)me->query("zhongqiu/gift_yuebing" ) > 0 ) return notify_fail("你已经吃过月饼了，难道你想吃成肥猪吗？\n");
        me->add("max_jingli",50);
        message_vision(HIG"\n$N尝了一口月饼，顿时为它的味道所折服,三口两口把月饼吞下肚,心里充满了对度每师傅的感激之情！\n"NOR,me);
          tell_object(me,"\n你的精力增长了50点!\n\n");
        me->set("zhongqiu/gift_yuebing",1);
        destruct(this_object());
     }
     return 1;
}
