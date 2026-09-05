//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河北岸"NOR);
        set("long", @LONG
这里是黄河北岸，滚滚黄河一刻不停地奔腾东去。黄河在这里变得较为狭窄。
LONG
        );
        set("exits", ([
             "northeast" : __DIR__"dkb4",
             "southwest" : __DIR__"dkb4f",
             "west" : "/d/silk/silk1",
        ]));
       

        set("couldfish",1);

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");

        setup();
}

void init()
{
    add_action("do_sheshui","sheshui");
}
int valid_leave(object me,string dir)
{  
	if (dir=="west")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}

int do_sheshui()
{
    object me=this_player();
    object camel;
	if(me->query("family/family_name")!="白驼山")
    {
        return 0;
    }
    if ( !objectp(camel = me -> query_temp("riding"))
		|| camel->name() != HIW"白骆驼"NOR)
    {
        tell_object(me,"你必须骑着白骆驼才能涉水而过。\n");
        return 1;
    }
    else
    {
        camel=me->query_temp("riding");
        message_vision(HIW+"$N"+HIW+"骑着"+camel->name()+HIW+"在黄河狭窄处涉水而过，飘逸无比。\n"+NOR,me);
        me->move("/d/huanghe/hezhong");
        camel->move("/d/huanghe/hezhong");
        me->add_busy(7);
        me->set_temp("白驼过黄河",0);
        call_out("pass",1,me);
        return 1;
    }
}

int pass(object me)
{
    object camel=me->query_temp("riding");
    if (!me)
    {
        return 1;
    }
    if (!living(me))
    {
        me->move(this_object());
        return 1;
    }
    tell_object(me,"白骆驼神骏无比，涉水前行。\n");
    me->add_temp("白驼过黄河",1);
    if (me->query_temp("白驼过黄河")>=4)
    {
        tell_object(me,"半晌，白骆驼终于带着你游到了对岸。\n");
        me->delete_temp("明教过黄河");
        me->move("/d/huanghe/hhn19");
        camel->move("/d/huanghe/hhn19");
        return 1;
    }
    else
    {
        call_out("pass",2,me);
        return 1;
    }
}