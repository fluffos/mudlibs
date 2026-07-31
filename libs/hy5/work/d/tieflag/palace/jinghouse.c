#include <room.h>
inherit ROOM; 
void create()
{
        set("short", "精舍");
        set("long", @LONG
小巧玲珑的精舍，坐落在翠竹之间。雪白的墙壁衬托著翠绿，给人一种宁
静的感觉。几个丫环，正在房中下棋。房中的布置虽然简单，却异常的精致。
微风透过纱窗徐徐吹来，带来了阵阵花香。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bookhouse",
  "west" : __DIR__"bamboo",
]));
        set("objects", ([
        __DIR__"npc/playinggirl" : 8,
                        ]) ); 
        set("coor/x",300);
        set("coor/y",-50);
        set("coor/z",10);
        setup();
        replace_program(ROOM); 
}    
