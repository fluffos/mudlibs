// Room: /open/stst/sazai/lu2.c

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
        这是通往练武场的路，到了这里，你还是别乱跑为好。南边有一条
小路，往北就是练武场了。

LONG

        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lianwu",
  "south" : __DIR__"lu1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
