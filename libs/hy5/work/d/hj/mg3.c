// mg3.c 迷宫
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "高昌迷宫" NOR);
        set("long", @LONG
你越走越害怕，不知道前面会出现什么东西，你手上提着武器，
慢慢的摸索着前进。
LONG);
        set("no_sleep_room", 1);
        set("exits", ([
              "eastdown" : "/d/gaochang/zoulang2",
              "east" : __DIR__"mg4",
              "west" : __DIR__"mg4",
              "south" : __DIR__"mg4",
              "north" : __DIR__"mg4",            
        ]));        
        setup(); 
}
int valid_leave(object me, string dir)
{
       if (dir == "west") me->add_temp("mark/steps",1);
       if (dir == "east") me->add_temp("mark/steps",-1);         
       if (me->query_temp("mark/steps") == 5){
            me->move(__DIR__"mg-indoor");
            me->delete_temp("mark/steps");
             return notify_fail("你正走着，突然发现前面好象有了一些光亮。\n");
return 1;
         }  
       if (me->query_temp("mark/steps") == -5){  
           me->move(__DIR__"mg2");
           me->delete_temp("mark/steps");
             return notify_fail("你正走着，突然发现前面好象有了一些光亮。\n");
return 1;
        }           
        return ::valid_leave(me, dir);
}
