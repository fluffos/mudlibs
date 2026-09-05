//厢房
//by icer
inherit ROOM;
void create()
{
        set("short", "厢房");        set("long", @LONG
这是山顶寺庙的一个厢房。屋里摆设十分俭朴，除了一张长桌，几把椅子
以外再没有什么了。
LONG
);
set("exits", ([
                "out" :__DIR__"shiliang1",
		"north":__DIR__"zhulin1",
]));
set("objects",([

      __DIR__"npc/shami" : 1,
     ]));


setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="north" && !(me->query_temp("marks/沙2",1)==1) )
	{        return notify_fail("未经人家许可就往里闯，不太好吧？\n");}
        return ::valid_leave(me, dir);
}
