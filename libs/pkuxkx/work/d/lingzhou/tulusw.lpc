// 大轮寺
//by kiden

inherit ROOM;

void create()
{
        set("short", "土路");
        set("long", @LONG
这里是一条黄土路，东南面通向灵州，西北面边通向黄河渡口。
LONG
        );

        set("exits", ([
                "northwest" : "/d/huanghe/dkn3",
                "southeast" : __DIR__"biaoqiyin",
        ]));

        set("outdoors", "lingzhou");
        setup();
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me,string dir)
{  
	if (dir=="northwest")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}