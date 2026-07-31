// /d/yuehou/tulu2.c

inherit ROOM;

void create()
{
        set("short", "土路尽头");
        set("long", @LONG
这里是崎岖的土路的尽头，远处似乎有什么，但是又看不清。
LONG
        );

       set("exits", ([
                "south"             : __DIR__"tulu",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

