// Room: caodi.c

inherit ROOM;

void create()
{
        set("short", "草地");
        set("long", @LONG
这是一片郁郁葱葱的青草地，四周云雾缭绕的青山。草丛中夹杂
着一些白色的野花，象洒落的珍珠一般。时而传来些许小虫的轻鸣。不
远处有几头小牛在那里悠闲地吃草。几个放牛小童正在一边追逐嬉戏。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shanpo2",
  "east" : __DIR__"caodi1",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

