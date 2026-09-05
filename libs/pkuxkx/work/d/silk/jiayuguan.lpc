// Room: /d/xingxiu/jiayuguan.c
// Jay 3/17/96
// Zine 2010 Dec 10 Add hswlb quest
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "嘉峪关");
        set("long", @LONG
这是长城最西的关隘。岁月沧桑，仍掩不住它的风采。群山环抱之下，更显它
的雄浑。由于西域安定，久无战事，边关守军已大为减少。一条大道向东延伸通向
中原。出关向西，是一片大沙漠。
LONG
        );
        set("outdoors", "silk");
        set("exits", ([

                "southeast" : __DIR__"silk4",
                "west" : __DIR__"shamo1",
        ]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
//暂时用一下
                object camel;
        if( dir=="west"&& (int)me->query("combat_exp")<3000000 && userp(me) && (!objectp(camel = me -> query_temp("riding"))

            || camel->name() != HIW"白骆驼"NOR ) )
    return notify_fail(HIR"你没有骑骆驼，去沙漠太危险了！\n"NOR);
    return ::valid_leave(me, dir);
}

void init()
{
    object me=this_player();
    if (!me->query("hswlbcanlearn"))
    {
        if (me->query("jobs/completed/xiaofeng")>me->query("silkjob/xf")|| me->query("jobs/completed/husong")>me->query("silkjob/hs") || me->query("jobs/completed/hubiao")>me->query("silkjob/hb") || me->query("jobs/completed/task")> me->query("silkjob/ts") || me->query("jobs/completed/huyidao") > me->query("silkjob/yd"))
        {
            me->set_temp("silkjob/clue",1);
        }
    }
    return;
}