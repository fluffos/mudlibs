 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "竹林");
        set("long", @LONG
这株树根粗、很大，叶子特别绿。下半截的树皮，竟和上半截
不同，上半截的树皮粗糙，下半截的树皮却光滑得很。  
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"groad6",
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
