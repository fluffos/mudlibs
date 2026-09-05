// /d/xingxiu/silk1.c
// Jay 3/17/96
// Zine 2010 Dec 10 Add hswlb quest
inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是一条中原和西域之间的商道。东面是黄河岸边，西面通往西域。
LONG
        );
        set("outdoors", "silk");

        set("exits", ([
                "east" : "/d/huanghenorth/hhb19",
		"west" : __DIR__"silk2",
        ]));

        setup();
}

void init()
{
    object me=this_player();
    if (!me->query("hswlbcanlearn"))
    {
    
    me->set("silkjob/xf",me->query("jobs/completed/xiaofeng"));
    me->set("silkjob/hs",me->query("jobs/completed/husong"));
    me->set("silkjob/hb",me->query("jobs/completed/hubiao"));
    me->set("silkjob/ts",me->query("jobs/completed/task"));
    me->set("silkjob/yd",me->query("jobs/completed/huyidao"));
    }
    return;
}

int valid_leave(object me,string dir)
{  
	if (dir=="east")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}