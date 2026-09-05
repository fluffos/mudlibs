//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "西大街");
        set("long", @LONG
这是一条略窄的青石板街道，向东西两头延伸。在往东就是洛阳的中
心广场了。居住在这条街上的大都是一些武林人士，因此习武之风而极胜，
到处可见练武之人，武馆，武场，镖局也比比皆是，为了安全，官府在这
里布置了官兵。北边是一家书店，向南是赫赫有名的四海钱庄。
LONG
        );

        set("exits", ([
               "east" : __DIR__"center",  
               "south" : __DIR__"qianzhuang",  
               "north" : __DIR__"shudian", 
               "west" : __DIR__"xidajie2",   
        ]));
        set("objects", ([
        ]));
        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

