 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "回春阁");
        set("long", @LONG
这是间极大的房子，四面堆满各式各样的药草，占据了屋子十之五
大，其余地方，放了十几具火炉，炉火俱都烧得正旺，炉子上烧着
的有的是铜壶，有的是用锅，还有的是奇形怪状，说不出各自的紫
铜器，每一件铜器中，都有一阵阵浓烈的药香传出。 
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"groad4",
        "north" : __DIR__"chuliuju2",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
