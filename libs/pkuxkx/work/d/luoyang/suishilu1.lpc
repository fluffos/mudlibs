//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "碎石路");
        set("long", @LONG
一条碎石小路，刚下过雨，路面看起来还满干净的．路两旁的草地上开放
了一些野花，一片安静祥和的气氛。
LONG
        );

        set("exits", ([
               "south" : __DIR__"dongdajie2",  
               "northeast" : __DIR__"xiaoxiang",  
//               "north" : __DIR__"luoshui",         
        ]));
        set("objects", ([
//              __DIR__"npc/randomnpc" : 1,
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
