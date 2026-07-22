//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
人说蜀道难,难于上青天,你现在肯定有所体会了.
LONG
        );

        set("exits", ([
                "eastup" : __DIR__"shanlu3",
                "westdown" : __DIR__"shanlu5",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


