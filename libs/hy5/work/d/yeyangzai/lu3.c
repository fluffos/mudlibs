// Room: /open/stst/sazai/lu3.c

inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
        这是通往前厅的走廊，非常宽敞，再向北走就是前厅了。

LONG

        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lianwu",
  "north" : __DIR__"qianting",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
