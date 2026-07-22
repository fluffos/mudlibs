// /d/xingxiu/shamo1.c
// Jay 3/17/96
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","大沙漠");
       set("long", @LONG
这是一片一望无际的大沙漠。你一进来就迷失了方向。
看来要走出这块沙漠并非易事。
LONG);
        set("outdoors", "shamo");
        set("exits", ([
                "east" : __DIR__"shamo"+(1+random(4)),
                "west" : __DIR__"shamo"+(1+random(4)),
                "south" : __DIR__"shamo"+(1+random(4)),
                "north" : __DIR__"shamo"+(1+random(4)),
        ]));             
        set("coor/x",-310);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-310);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-310);
 set("coor/y",100);
   set("coor/z",0);
   setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "west") me->add_temp("mark/steps",1);
        if ( dir == "east") me->add_temp("mark/steps",-1);

     if (me->query_temp("mark/steps") == 5){
         me->move("/d/hj/caoyuan");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"从东边的大沙漠走了过来。\n", ({ me }));
         return notify_fail("你累得半死，终於走出了沙漠。\n");
         }  
     if (me->query_temp("mark/steps") == -5){  
         me->move(__DIR__"silk9");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"从西边的大沙漠走了过来。\n", ({ me }));
         return notify_fail("你累得半死，终於走出了沙漠。\n");
         }
        return ::valid_leave(me,dir);
}
