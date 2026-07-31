// /d/yuehou/troad1.c

inherit ROOM;

void create()
{
        set("short", "土路");
        set("long", @LONG
这里是一个小土路，小路周围长满野花。从这里往南走，
就是通往岳候镇的村口了。
LONG
        );

       set("exits", ([
                "west"             : __DIR__"hroad2",
                "south"             : __DIR__"troad2",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}


