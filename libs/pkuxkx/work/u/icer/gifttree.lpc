// item: /d/xingxiu/npc/obj/fire.c
// Jay 3/17/96

#include <ansi.h>
inherit ITEM;
void setup()
{}

void init()
{
    add_action("do_pick","pick");
}

void create()
{ 
                
       set_name(HIG"开站礼品树"NOR,({"gift tree","tree"}));
        set_weight(9999999);
           set("no_get",1);
        set_max_encumbrance(0);
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("unit","棵");
           set("long",RED"这是一棵庆祝开站的礼品树,上面悬挂着许多礼物.\n 不想摘(pick)个看看吗？\n"NOR);
                                                  
        }
        
}

int do_pick(string arg)
{
        object p;
     object me= this_player();

     if (me->query("kaizhan/got"))
     {
        tell_object(me,"你已经摘过一个果子啦！要成为高手主要还得靠自己努力啊！\n");
        return 1;
     }
     p = new("/u/icer/obj/giftguo");
     p->move(me);
     tell_object(me,HIB"你从树上摘下一个神奇果子。\n"NOR);
     me->set("kaizhan/got",1);
     return 1;
}

