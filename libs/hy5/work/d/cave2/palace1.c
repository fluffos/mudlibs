 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "甬道出口");
        set("long", @LONG
那“筒子”终于停了，眼前一亮，又出现一道门，一片青蒙蒙的光线，自门外洒
了进来。 
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"palace2",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   
