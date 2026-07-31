// shulin.c 树林
// zly 99.7.28

#include <room.h>
inherit ROOM;

void create()
{
       set("short","树林");
       set("long", @LONG
这里是一片茂盛的树林，到处古木参天，你到了这里，怎么也看
不清楚周围的景象了。
LONG
     );

        set("exits", ([
                "northeast" : __FILE__,
                "southeast" : __FILE__,
                "southwest" : __FILE__,
                "northwest" : __FILE__,
                "west" : __FILE__,
                "east" : __FILE__,
                "south" : __FILE__,
                "north" : __FILE__,
        ]));
        setup();
}

void init()
{
        object ob;
        int jing, jing_cost;

        ob = this_player();
        jing = ob->query("jing");
        jing_cost = ob->query("kar");

        if(jing < jing_cost)
                ob->unconcious();
        ob->add("jing", -jing_cost);
}

int valid_leave(object me, string dir)
{
        if (random((int)me->query("kar")) > 15)
                me->add_temp("mark/steps",1);
        if (random((int)me->query("kar")) < 10)
                me->add_temp("mark/steps",-1); 
        
        if (me->query_temp("mark/steps") == 3)
        {
                me->move(__DIR__"houshan");
                me->delete_temp("mark/steps");
             return notify_fail("你到处乱走，忽然眼前一亮，不知不觉来到了后山。\n");
        }  

        if (me->query_temp("mark/steps") == -5 || me->query_temp("book145"))
        {
                me->move(__DIR__"houyuan");
                me->delete_temp("mark/steps");
                return notify_fail("你走来走去，不知不觉又回到了后院。\n");
        }
           
        return ::valid_leave(me, dir);
}
