// Room: /d/heimuya/pingdingzhou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
    set("short", "平定州");
    set("long", @LONG
平定州在河北境内，州府不大，但地处要冲，十分重要。
往来京城的客商穿梭频繁。但大街上日月教徒横冲直撞，出手
抓人，虽近在京畿，却丝毫没将官府放在眼里。
LONG );

    set("exits", ([
        "east" : __DIR__"road3",
        "west" : __DIR__"road2",
    ]));
    set("outdoors", "heimuya");
    set("objects",([
            "quest/menpaijob/riyue/zhike" : 1,
            "d/heimuya/npc/dizi" : 3,
        ]));


    setup();
}

int valid_leave(object me, string dir)
{
        if (me->query_temp("in_guard") &&
                objectp(present("riyue hufa", environment(me))))
           return notify_fail("日月护法拦住你说：值守时辰未到，不能擅离职守。\n");

        me->delete_temp("in_guard"); 
        me->delete("guard");
        remove_call_out("clone_meng");

        return ::valid_leave(me, dir);
}
