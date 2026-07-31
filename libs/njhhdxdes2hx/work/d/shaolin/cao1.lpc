// Room: cao.c

inherit ROOM;

void create()
{
        set("short", "草原");
        set("long", @LONG
        这是一片茫茫的大草原，一走进来，你仿佛迷失了方向。
LONG
        );

        set("exits", ([
                "east" : __DIR__"cao2",
                "west" : __DIR__"cao"+(random(6)+1),
                "south" : __DIR__"wherein",
                "north" : __DIR__"cao"+(random(6)+1),
        ]));
        setup();
        replace_program(ROOM);
}
