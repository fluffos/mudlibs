 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "道路");
        set("long", @long
不远处就是白云山庄。山色青翠，翠绿色的草地上，一排排青灰色的屋顶在太
阳下闪着光。长长的云石大道两旁，都种满了古柏青松。不时经过一辆两辆漆黑的
马车，显然正是庄主请来的宾客。
long

        );
        set("exits", ([ 
                "east" : __DIR__"road1d",
                "north": __DIR__"yuanvillage",
        ]));
        set("objects", ([
                __DIR__"obj/grass": 1,
        ]) );
        set("outdoors", "eren");
set("coor/x",-1090);
        set("coor/y",160);
        set("coor/z",0);
        setup();
        //replace_program(ROOM);
}   
