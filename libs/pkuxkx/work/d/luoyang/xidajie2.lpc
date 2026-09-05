//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条略窄的青石板街道，向东西两头延伸。居住在这条街上的大
都是一些武林人士，因此习武之风极胜，到处可见练武之人，武馆，武场，
镖局也比比皆是，为了安全，官府在这里布置了官兵。北边是威震武林的
金刀王家，王家乃是洛阳的大户人家，在武林中又声名显赫，因此门前总
是有许多武林人士等候拜访。
LONG
        );

        set("exits", ([
               "east" : __DIR__"xidajie1",  
               "south" : __DIR__"hutong4",  
               "north" : __DIR__"damen", 
               "west" : __DIR__"ximen",   
        ]));
        set("objects", ([
        ]));
        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
