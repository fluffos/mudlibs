// /d/xingxiu/shamo1.c
// Jay 3/17/96
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","大草原");
       set("long", @LONG
你走进了这遍绵绵不绝的大草原，脚下是寸厚的青草，软绵绵的还
真不好走，看来买匹马来代步到是的好主意。
LONG);
        set("outdoors", "shamo");
        set("exits", ([
                "east" : __DIR__"shamo"+(1+random(4)),
                "west" : __DIR__"shamo"+(1+random(4)),
                "south" : __DIR__"shamo"+(1+random(4)),
                "north" : __DIR__"shamo"+(1+random(4)),
        ]));             
        setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "west") me->add_temp("mark/steps",1);
        if ( dir == "east") me->add_temp("mark/steps",-1);

     if (me->query_temp("mark/steps") == 8){
         me->move(__DIR__"dongchengmen");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"从东边的大草原走了过来。\n", ({ me }));
         return notify_fail("你累得半死，终於走出了大草原。\n");
         }  
     if (me->query_temp("mark/steps") == -8){  
         me->move("/d/dingxiang/caoyuan");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"从西边的大草原走了过来。\n", ({ me }));
         return notify_fail("你累得半死，终於走出了大草原。\n");
         }
        return ::valid_leave(me,dir);
}
