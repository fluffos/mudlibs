 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "÷Ò¡÷");
        set("long", @LONG  
LONG
        );
        set("exits", ([ 
        "northwest" : __DIR__"vroad5",
        "south" : __DIR__"tree",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
