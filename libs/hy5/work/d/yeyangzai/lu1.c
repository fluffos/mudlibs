// Room: /open/stst/sazai/lu1.c

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
        这是通往练武场的路，到了这里，你还是别乱跑为好。北边有一条
小路，往南就是寨门了。

LONG

        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lu2",
  "south" : __DIR__"men",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

