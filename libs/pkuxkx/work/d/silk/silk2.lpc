// /d/xingxiu/silk2.c
// Jay 3/17/96
// Zine 2010 Dec 10 Add hswlb quest
inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是一条中原和西域之间的商道。南面连绵的祁连山脉在阳光的照射下
好像是一条玉带。东边是黄河，西面则通往西域。
LONG
        );
        set("outdoors", "silk");

        set("exits", ([
                "east" : __DIR__"silk1",
		"northwest" : __DIR__"silk3",
        ]));

        setup();
}

void init()
{
    object me=this_player();
    if (me->query_temp("silkjob/clue") && random(100)>70 &&!me->query("hswlbcanlearn"))
    {
        tell_object(me,"多次经过大沙漠，通向黄河，你突然想到了什么，也许可以去月儿泉整理一下自己的思绪……\n");
        me->delete_temp("silkjob/clue");
        me->set_temp("silkjob/found",1);
        return;
    }
    else
    {
        me->delete_temp("silkjob/clue");
        return;
    }
}
