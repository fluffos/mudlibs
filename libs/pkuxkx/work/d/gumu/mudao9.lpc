// Room: /d/gumu/mudao9.c
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "墓道");
        set("long", @LONG
        你走在墓道里，四周回响着“咚咚”的脚步声。
左边和右边各有一个石室。不时地有人出入。前面依然
是黑黑的墓道。
LONG
        );
        set("no_sleep_room", 1);
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"mudao8",
  "north" : __DIR__"mudao10",
  "west"  : __DIR__"shishi",
  "east"  : __DIR__"shishi2",
//"northeast" : __DIR__"midao3",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
 
