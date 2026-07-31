// /d/heifeng/corr.c

inherit ROOM;

void create()
{
        set("short", "过道");
        set("long", @LONG
你走进了寨门，只见两边分别高耸着一个竹塔，上面都站着
哨兵。一条小道向北延去。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"gate",
            "north"  : __DIR__"corr02",
            "east"   : __DIR__"sentry1",
            "west"   : __DIR__"sentry2",
]));
        set("outdoors", "heifeng");
        setup();
        replace_program(ROOM);
}

