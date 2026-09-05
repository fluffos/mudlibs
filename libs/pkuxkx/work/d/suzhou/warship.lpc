#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", HIW"大宋战舰"NOR);
	set("long", @LONG
这是一艘大宋的战舰，代表了当代造船工艺的巅峰。
LONG );

    set("no_task",1);
	set("real_dark",1);
	set("outdoors", "suzhou");
	setup();

}

void init()
{
    object me=this_player();
    if (me->query_temp("songtasks/shuishi/warship"))
    {
        me->delete_temp("songtasks/shuishi/warship");
        remove_call_out("story1");
        call_out("story1",10,me);
        return;
    }
}

int story1(object me)
{
    tell_object(me,"战舰乘风破浪，转眼已到太湖南岸了。\n");
    remove_call_out("story2");
    call_out("story2",5,me);
    return 1;
}

int story2(object me)
{
    tell_object(me,"战舰已顺大运河而下抵达临安府了。\n");
    tell_object(me,HIC"你下了战船，赶紧回水师驻地复命吧。\n"NOR);
    me->set_temp("songtasks/shuishi/1/finish",1);
    me->move("/d/hangzhou/nanmen");
    return 1;
}