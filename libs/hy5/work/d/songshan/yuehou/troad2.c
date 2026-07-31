// /d/yuehou/troad2.c

inherit ROOM;

void create()
{
        set("short", "土路");
        set("long", @LONG
这里是一个小土路，小路周围长满野花。从这里往东走，
就能看见岳候镇的村口。
LONG
        );

       set("exits", ([
                "north"             : __DIR__"troad1",
                "east"             : __DIR__"wenter",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

