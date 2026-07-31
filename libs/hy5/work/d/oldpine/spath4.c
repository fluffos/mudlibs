 // Room: /d/oldpine/spath4.c
inherit ROOM; 
void create()
{
        set("short", "下坡道");
        set("long", @LONG
一条笔直的坡道，到这里已经到了尽头。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"spath3",
]));
        set("no_clean_up", 0);
        set("outdoors", "oldpine"); 
        set("coor/x",520);
        set("coor/y",2330);
        set("coor/z",100);
        setup();
        replace_program(ROOM);
}   
