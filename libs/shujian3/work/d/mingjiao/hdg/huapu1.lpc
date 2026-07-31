// 花圃 huapu1.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "花圃");
        set("long", @LONG
这里是蝴蝶谷的花圃，是“见死不救”胡青牛用来种各种各样药材的，里
面种满了诸般花草。
LONG
        );

        set("outdoors", "蝴蝶谷");

        set("exits", ([ 
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
        jing_cost = random(ob->query("kar")) * 2 + 10;

        ob->add("jing", -jing_cost);
        if(jing < jing_cost)
         ob->unconcious();
}

int valid_leave(object me, string dir)
{
        if (random(10) > 5)
              me->add_temp("mark/steps",1);
        if (random(10) < 5)
              me->add_temp("mark/steps",-1); 
        
        if (me->query_temp("mark/steps") >= 5){
            me->move(__DIR__"caojing");
            me->delete_temp("mark/steps");
              return notify_fail("你乱走一气，忽然眼前一亮，来到一处草径。\n");
        }  
        if (me->query_temp("mark/steps") <= 0){
            me->move(__DIR__"niupeng");
            me->delete_temp("mark/steps");
              return notify_fail("你累得半死，却颓然发现又走回了牛棚。\n");
        }      
        return ::valid_leave(me, dir);
}
