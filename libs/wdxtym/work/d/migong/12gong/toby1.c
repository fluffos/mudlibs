// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG
这是一条通向，迷宫出口的山路。
LONG);


        set("exits", ([
        "south"    :       __DIR__"toby2",
        "west" :      "/d/xiangyang/caodi3",
        ]));

        set("outdoors", "12gong");
        setup();
}
