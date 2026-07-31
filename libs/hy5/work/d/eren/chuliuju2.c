 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "回春阁后房");
        set("long", @LONG
掀起一道薄薄的竹帘，就到了后房。一张竹榻，一个竹枕，四壁都
是书架，竟也是竹子做的。书架上堆满了自五代十国以来的药经，
药典。 
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"chuliuju1",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
