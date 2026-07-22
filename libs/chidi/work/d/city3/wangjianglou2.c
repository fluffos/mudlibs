//bye enter

inherit ROOM;

void create()
{
        set("short", "望江楼二楼");
        set("long",@LONG
你来到望江楼上，极目远眺，整个成都的美景尽收眼低。只
见府南河象条玉带似的环绕全城，太阳照在河面，发出缎子般的
光泽。旁边的竹林郁郁葱葱，空气竟也变得更加清新起来。楼的
墙上刻着前代文人墨客留下的诗句。
LONG
        );

        set("exits", ([
                "down" : __DIR__"wangjianglou1",
            ]));
        set("objects", ([
            __DIR__"npc/youke" : 2,
        ]));

        setup();
        replace_program(ROOM);       
}


