// /d/yuehou/hroad2.c

inherit ROOM;

void create()
{
        set("short", "黄土路");
        set("long", @LONG
这里是一个泥泞的黄土路，由于刚刚下过雨，所以空气还是
非常湿润，路上的行人匆匆忙忙的赶路，似乎没有人注意到你。
LONG
        );

       set("exits", ([
                "north"             : __DIR__"hroad1",
                "east"             : __DIR__"troad1",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}

