 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "道路");
        set("long", @LONG
道路渐渐宽敞了起来，可以容得下一辆四轮马车驰过。道路两旁的树木似是有
人精心护理。山色青翠，翠绿色的山坡上，一排排青灰色的屋顶在太阳下闪着光。
前面青砖红瓦，有一座庄园，是远近八百里闻名的袁家的白云庄。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"road1c",
                "west": __DIR__"road1e",
        ]));
        set("objects", ([
                __DIR__"obj/grass": 1,
        ]) );
        set("outdoors", "eren");
set("coor/x",-1080);
        set("coor/y",160);
        set("coor/z",0);

        setup();
        replace_program(ROOM);
}   
