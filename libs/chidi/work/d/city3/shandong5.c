//shandong.c
//by mei

inherit ROOM;
void create()
{
        set("short", "山洞");
        set("long", @LONG
你壮起胆子，走进了山洞中，这里暗无天日，突然间，有
只蝙蝠在你面前飞过，你被惊出了一身冷汗。越往里走就越来
越黑，你好象迷失方向了。
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


