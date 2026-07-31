// Room: /d/taishan/.c

inherit ROOM;

void create()
{
        set("short", "回马岭");
        set("long", @LONG
此处又名天关，到了这里，马匹已不能再前进。据说当年唐玄宗上泰山封
禅，来到这里，因陡峭难攀，累死了白马，要改乘小轿上山。
LONG
        );

        set("exits", ([
                "northup" : __DIR__"ertian",
                "southdown" : __DIR__"shijin",
        ]));

        set("objects",([
		__DIR__"npc/jian-ke2" : 1,
        ]));
        set("outdoors", "泰山");
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir=="northup" ) {
		if(me->query("can_ride"))
			return 0;
	        if(me->query_temp("ride_horse"))
			return notify_fail("这位" + RANK_D->query_respect(me) + "还是请先下马，再上山吧！\n");
        }
        return ::valid_leave(me, dir);
}
