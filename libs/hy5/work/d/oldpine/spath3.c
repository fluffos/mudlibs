 // Room: /d/oldpine/spath3.c
inherit ROOM; 
void create()
{
        set("short", "下坡道");
        set("long", @LONG
这是一条笔直的坡道，北高南低，道路两旁长满了许多松树，从松
林间隐约可以听到东边传来流水的声音。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"spath4",
  "north" : __DIR__"spath2",
]));
        set("no_clean_up", 0);
        set("outdoors", "oldpine"); 
        set("coor/x",520);
        set("coor/y",2340);
        set("coor/z",100);
        setup();
        replace_program(ROOM);
}   
