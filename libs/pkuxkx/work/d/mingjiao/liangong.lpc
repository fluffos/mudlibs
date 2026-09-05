// liangongfang.c 练功房
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "练功房");
        set("long", @LONG
        这里是练功房，地下凌乱地放着几个蒲团，几位明教弟子正盘膝坐在上
面打坐。
LONG
        );
        set("exits", ([
                "west" : __DIR__"zoulang2",
        ]));
        set("objects", ([
                "/d/village/obj/zhujian" : 3,
                "/d/mingjiao/npc/obj/mudao" : 3]));
        
        set("lingwu_family", "明教");
        set("no_fight", 1);
        setup();
        //replace_program(ROOM);
}

void init()
{
    add_action("do_zhao","zhao");
    add_action("do_zhao","find");
}

int found(object me)
{
    object weapon;
    if (random(1000)>499)
    {
        weapon=new(__DIR__"obj/quest_dao");
        message_vision("$N找到一柄$n。\n",me,weapon);
        weapon->move(me);
        return 1;
    }
    else
    {
        weapon=new(__DIR__"obj/quest_jian");
        message_vision("$N找到一柄$n。\n",me,weapon);
        weapon->move(me);
        return 1;
    }
    
}

int do_zhao()
{
    object me=this_player();
    if (me->query_temp("mingjiao/tasks/taskno")!=2)
    {
        tell_object(me,"没有鹰王手令，不得擅自领取兵器。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    message_vision("$N开始在兵器架上找寻称手的刀剑。\n",me);
    remove_call_out("found");
    call_out("found",1,me);
    me->add_busy(1);
    return 1;
}