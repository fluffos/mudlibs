// shanlu3.c 
// By River@sj 99.5.20
inherit ROOM;

void create()
{
        set("short", "山间小路");
        set("long", @LONG
你走在一条蜿蜒而上的山间小路上，这里十分荒凉，前面不远处就是一些
小树林，南面就是通往襄阳城的青石大道，北面有条小路不知通向哪里。
LONG
        );
        set("outdoors", "襄阳");

        set("exits", ([
                "northwest" : __DIR__"shanlu2",
                "southdown" : "/d/sdxl/conglin1",
        ]));

        setup();
        replace_program(ROOM);
}
