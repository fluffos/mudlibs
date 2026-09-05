//半山2
//by icer
inherit ROOM;
void create()
{
        set("short", "半山");        set("long", @LONG
那山峰顶上是块平地，开垦成二十来亩山田，种着禾稻，一柄锄头抛在田边。
一个农夫正在耘草。
LONG
);
set("exits", ([
                "down" :__DIR__"banshan1",
		"up"   :__DIR__"shiliang",
]));
set("objects",([

      __DIR__"npc/geng" : 1,
     ]));
setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !(me->query_temp("marks/耕3",1)) )
	{        return notify_fail("耕夫一侧身挡在你面前：干什么的？\n");}
        return ::valid_leave(me, dir);
}
