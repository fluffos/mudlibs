// sl4.c
// Modify By River 98/09
inherit ROOM;
#include <ansi.h>
void create()
{ 
       set("short", HIB"黑林"NOR);
       set("long", @LONG
树林里参天古木，遮蔽了大部分日光，地上积了厚厚的落叶残木，加之不
少小动物的尸体，空气中透出腐臭和抑闷。你走着走着，便迷失了道路。
LONG
     );
    
        set("exits", ([
                "east" : __FILE__,
                "west" : __FILE__,
                "south" : __DIR__"sl2",
                "north" : __DIR__"sl3",
        ])); 

        set("outdoors","古墓");
     
        set("coor/x",10);
  set("coor/y",-30);
   set("coor/z",60);
   setup();
}

int valid_leave(object me, string dir)
{        
        if ( dir == "east")
            me->add_temp("mark/steps",1);
        if ( dir == "west")
            me->add_temp("mark/steps",-1);         
        if (me->query_temp("mark/steps") == 6){
            me->move(__DIR__"shulin2");
            me->delete_temp("mark/steps");
            return notify_fail("你精疲力尽，终於走出了黑林。\n");
        }  
        if (me->query_temp("mark/steps") == -6){  
            me->move(__DIR__"shulin1");
            me->delete_temp("mark/steps");
            return notify_fail("你累得半死，却仍是回到原地。\n");
        }
        return ::valid_leave(me,dir);
}
