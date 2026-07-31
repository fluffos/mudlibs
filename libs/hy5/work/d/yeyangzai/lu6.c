// Room: /open/stst/sazai/lu6.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
        这是通往大厅的走廊，非常宽敞，再向北走就是大厅了。

LONG

        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianting",
  "north" : __DIR__"dating",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

