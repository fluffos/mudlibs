// changlang2.c
#include <ansi.h>
inherit ROOM;
#include "/d/tianlong/bonus.h"
void create()
{
    set("short", "长廊");
    set("long", @LONG
天龙寺后殿的长廊，这里相当的幽静。长廊边上有一些简陋的
木头椅子，上边还有一层薄薄的灰尘，显然很少有人来坐。
LONG
       );
    set("outdoors", "dali");

    set("exits", ([
                "west" : __DIR__"muwu",
                "south" : __DIR__"yuan",
                "east" : __DIR__"zhonglou",
                "north" : __DIR__"houyuan",
                "enter" : __DIR__"restroom2",
                ]));
    set("objects", ([
                __DIR__"npc/bencan" : 1,

                __DIR__"npc/shami" : 2 ]) );
    set("no_clean_up", 0);
    set("bonus",18+random(4));
    setup();
}

void init()
{
    object me=this_player();
    int limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)-5;
    if (me->query("combat_exp")<10000
        &&me->query("family/family_name")=="天龙寺"
        &&userp(me)
        &&me->query_temp("tlnewbiejob/newbie/nian")==2
        &&me->query_temp("tlnewbiejob/newbie/qiao")==2
        &&me->query_temp("tlnewbiejob/newbie/dazuo")==2
        &&me->query_temp("tlnewbiejob/newbie/bangchu")==2
        &&me->query_temp("tlnewbiejob/newbie/tiaoshui")==2
        &&me->query_temp("tlnewbiejob/newbie/sleep")==2)
    {
        me->delete_temp("tlnewbiejob/newbie");
        bonus(me);
        tell_object(me,HIG"规律生活中，你的内功和实战经验都获得了进步。\n"NOR);
        if (me->query_skill("force",1)<limit_sk)
        {
            me->set_skill("force",me->query_skill("force",1)+2+random(2));
            tell_object(me,HIC"你的『基本内功』进步了！\n"NOR);
        }
        if (me->query_skill("kurong-shengong",1)<limit_sk&&random(2))
        {
            me->set_skill("kurong-shengong",me->query_skill("kurong-shengong",1)+3+random(3));
            tell_object(me,HIC"你的『枯荣禅功』进步了！\n"NOR);
        }
    }
}