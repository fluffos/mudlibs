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
        "south" : "/d/taiyuan/nroad3",	
        "west" : __DIR__"road2",
    ]));
    
set("roomif","$botten#护卫任务:huwei$#");    

    
    set("outdoors", "heimuya");
    set("objects",([
            "quest/menpaijob/riyue/zhike" : 1,
            "d/heimuya/npc/dizi" : 3,
        ]));


    setup();
}
void init()
{
        add_action("do_quit","quit");
        add_action("do_quit","halt");
        add_action("do_quit","learn"); 
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna"); 
        add_action("do_quit","persuade");
        add_action("do_quit","practice");
        add_action("do_quit","lian"); 
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
        add_action("do_quit","study");
        add_action("do_quit","yandu");        
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
}


int valid_leave(object me, string dir)
{
        if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
        if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");

        if (me->query_temp("in_guard") &&
                objectp(present("riyue hufa", environment(me))))
           return notify_fail("日月护法拦住你说：值守时辰未到，不能擅离职守。\n");

        me->delete_temp("in_guard"); 
        me->delete("guardry");
        remove_call_out("clone_meng");

        return ::valid_leave(me, dir);
}

int do_quit(string arg)
{
        write(this_player()->query("name")+"，安心的守护！\n");
        return 1;
}
