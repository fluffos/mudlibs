// /d/quanzhou/dahai_1.c
// Jay 3/17/96
#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","大海");
       set("long", @LONG
这是一片茫茫的大海，你的船一驶进来就迷失了方向，不知道现在
自己身在何处，看来要去到目的地要费一番气力。
LONG
     );
         set("outdoors", "diaoyudao");

    
        set("exits", ([
                 "east" : __DIR__"dahai_2",
                "south" : __DIR__"dahai_"+(random(10)+2),
               "west" : __DIR__"matou0",
                "north" : __DIR__"dahai_"+(random(10)+2),        ]));             
        setup();
      //  set("outdoors", "quanzhou");
      //  replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if ( dir == "west"){       
     me->move("/d/diaoyudao/matou"+(random(3)));
return notify_fail("经过几天与风浪的搏斗之后，你终于安全的登上了陆地，到了泉州码头！\n");
                           }
        
return::valid_leave(me,dir);}

       
