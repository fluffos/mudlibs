// /d/yuehou/tulu.c

inherit ROOM;

void create()
{
        set("short", "土路");
        set("long", @LONG
这里是一段崎岖的土路，路的两旁栽有一些树木。因为没有
人修葺，路面非常的泥泞。从这里向北是路的尽头，向南是岳候
镇广场的北侧。
LONG
        );

       set("exits", ([
                "south"             : __DIR__"center_n",
                "north"             : __DIR__"tulu2",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

