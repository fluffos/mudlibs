// foothill.c
// by paladin
// modified by Zine for Tl newbie job
#include <ansi.h>
inherit ROOM;

void create()
{
set("short","天龙寺山脚");
        set("long", @LONG
天龙寺背负苍山，面临洱水，极占形胜。寺有三塔，建于唐初，大
者高二百余尺，十六级，塔顶有铁铸记云：“大唐贞观尉迟敬德造。”相传天龙寺
有五宝，三塔为五宝之首
LONG
        );
set("outdoors", "dali");

        set("exits", ([

"westup" : __DIR__"duanhe",
"northeast" : __DIR__"dlroad4",
"northwest" : __DIR__"sroad1",
        ]));
set("no_tianlong",1);
        setup();
        
}

int appear(object me)
{
    object lostone;
    if (me&&living(me)&&base_name(environment(me))==base_name(this_object()))
    {
        lostone=new(__DIR__"npc/lostone");
        lostone->set("owner",me->query("id"));
        lostone->move(this_object());
        message_vision("$N慌慌张张地走了过来，似乎迷了路。\n",lostone);
        message_vision("$N看着$n，似乎想问什么，但又欲言又止。\n",lostone,me);
    }
    return 1;
}

void init()
{
    object me=this_player();
    if (me->query_temp("tlnewbiejob/lead/start")&&!me->query_temp("tlnewbiejob/lead/appear"))
    {
        me->set_temp("tlnewbiejob/lead/appear",1);
        call_out("appear",35+random((int)me->query("kar")),me);
        return;
    }
}

int valid_leave(object me,string dir)
{
    if (me->query_temp("tlnewbiejob/lead/start")&&!me->query_temp("tlnewbiejob/lead/where"))
    {
        return notify_fail("要你来这里帮助别人，一个人都没出现，你就要走吗？\n");
    }
    return ::valid_leave(me,dir);
}
