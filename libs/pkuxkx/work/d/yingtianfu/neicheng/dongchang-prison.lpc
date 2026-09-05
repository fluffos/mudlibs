//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", WHT"东厂诏狱"NOR);
        set("long", 
"这里是东厂的诏狱，进来的人都要脱层皮。\n"

        );
        set("exits", ([
                
              
                "east" : __DIR__"dongchang",
                
                
        ]));
        
        set("real_dark", 1);
        setup();
   
}

void init()
{
    object me=this_player();
    add_action("do_kaoda","kaoda");
    if (me->query_temp("mingtasks/dongchang/task2"))
    {
        me->delete_temp("mingtasks/dongchang/task2");
        tell_object(me,"几个番子把一个不似人形的人推了出来，你可以开始拷打(kaoda)他了。\n");
        return;
    }
}

int after(object me)
{
    if (me->query_temp("mingtasks/dongchang/kaoda_degree")>50)
    {
        tell_object(me,HIG"犯人抵受不住各种酷刑，决定招供了。\n"NOR);
        return 1;
    }
    else
    {
        tell_object(me,WHT"犯人咬了咬牙，道：死太监，我不会屈服的。\n"NOR);
        return 1;
    }
}

int do_kaoda()
{
    object me=this_player();
    int n=1+random(3);
    string *xingju=({"夹棍","老虎凳","辣椒水","铁烙","皮鞭"});
    if (me->query_temp("mingtasks/dongchang/task")!=2)
    {
        return notify_fail("没有曹厂公的手令，任何人不得接触钦犯。\n");
    }
    if (!me->query_temp("mingtasks/dongchang/start"))
    {
        return notify_fail("没有曹厂公的手令，任何人不得接触钦犯。\n");
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    if (me->query_temp("mingtasks/dongchang/kaoda_degree")>50)
    {
        tell_object(me,"犯人已经招供了，你回去复命吧。\n");
        return 1;
    }
    me->add_busy(3+random(2));
    me->set_temp("mingtasks/dongchang/kaoda_degree",(int)me->query_temp("mingtasks/dongchang/kaoda_degree")+n);
    tell_object(me,HIM"你开始用"+xingju[random(sizeof(xingju))]+"逼供。\n"NOR);
    remove_call_out("after");
    call_out("after",1,me);
    return 1;
}