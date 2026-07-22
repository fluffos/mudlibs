// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/juhao.c

inherit ROOM;

void create()
{
        set("short", "聚豪酒楼");
        set("long", @LONG
这里是长安城最大的酒楼，店主是城中的首富李员外。李员外为人豪爽，
广交天下豪杰，酒楼因此得名。楼上正中，挂着一块黑漆漆的横匾，上面的四
个绣金大字“聚豪酒楼”，是以“大隶”书成，笔力雄劲，气势磅礴。
LONG
        );

        set("exits", ([
                "up"   : __DIR__"juhao2",
                "west" : __DIR__"northjie1",
        ]));

	set("objects", ([
		__DIR__"npc/zhanggui" : 1,
]));

        set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
        if( dir=="up" && me->query_temp("getout")>0 )
                return notify_fail("你已经被人家赶出来了，他们不欢迎你再赴宴了！\n");
        return ::valid_leave(me,dir);
}