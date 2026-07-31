// /d/yuehou/center_n.c

inherit ROOM;

void create()
{
        set("short", "广场北侧");
        set("long", @LONG
这里是岳候镇的广场的北侧，向东走是一段崎岖的土路。
LONG
        );

       set("exits", ([
                "south"             : __DIR__"tcenter",
                "north"             : __DIR__"tulu",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

