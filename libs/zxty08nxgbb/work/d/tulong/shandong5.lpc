//shandong.c
//by mei

inherit ROOM;
void create()
{
        set("short", "迷雾森林");
        set("long", @LONG
这里是精灵界的迷雾森林，到处烟雾弥漫，让你分不清分
不清楚前面的方向，一时间，你竟不知应往哪个方向行走，莫
非你将老死在这里。
LONG
        );
        set("exits", ([
                "north" : __DIR__"shandong"+random(8),
                "south" : __DIR__"shandong"+random(8),
                "east" : __DIR__"shandong"+random(8),
                "west" : __DIR__"shandong"+random(8),
        ]));
        setup();
}
void reset()
{
        ::reset();
        set("exits", ([
                "north" : __DIR__"shandong"+random(8),
                "south" : __DIR__"shandong"+random(8),
                "east" : __DIR__"shandong"+random(8),
                "west" : __DIR__"shandong"+random(8),
        ]));
}


