// shanlu2.c 
// By River@sj 99.5.20
inherit ROOM;

void create()
{
        set("short", "山间小路");
        set("long", @LONG
你走在一条蜿蜒而上的山间小路上，这里十分荒凉，前面不远处就是一些
小树林，北面有条小路好象通向一条小溪流。
LONG
        );
        set("outdoors", "襄阳");

        set("exits", ([
                "north" : __DIR__"xibian",
                "southeast" : __DIR__"shanlu2",
        ]));

        setup();
        replace_program(ROOM);
}
