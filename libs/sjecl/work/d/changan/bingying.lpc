// Write By Yanyang@SJ 2001.9.28
// ROOM : /d/changan/bingying.c

inherit ROOM;

void create()
{
        set("short", "兵营大门");
        set("long", @LONG
这里是长安城临街而建的兵营，距离长安的东城门只有几步之遥。兵营门
口旌旗飘扬，守门的兵士不动声色地寻视着四周。兵营里面到处都有官兵来回
走动，有两名武将正在指挥士兵操练，不时地传来呐喊声。老百姓是不允许在
此观看的，你最好赶快走开。
LONG
        );

        set("exits", ([
                "south" : __DIR__"bingying2",
                "north" : __DIR__"eastjie4",
        ]));

        set("objects", ([
        __DIR__"npc/bing" : 2,
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
                dir == "south")
                return notify_fail("官兵拦住了你的去路。\n");
        return ::valid_leave(me, dir);
}