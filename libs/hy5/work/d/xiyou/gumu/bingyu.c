
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"冰玉寒潭"NOR);
        set("long", @LONG

映入你眼帘的是一潭散发着寒气的清水，一条石阶
悠悠的像潭水深处伸去，这种水温，别说是全身入
水，就是手指碰一下水面都觉得好像冻成了冰块一
样......

LONG);
  set("exits", ([
         "out" : __DIR__"houting.c",
        ]));
  set("outdoors","hfd");
  setup();
}
void init()
{
        add_action("do_dive","dive");
}

int do_dive()
{
        object me = this_player();
        object zhou;
       if(( !(zhou=present("bishui zhou", me))
       ||(string)zhou->query("unit")!="张" ) )
       return notify_fail("你一个猛子扎到冰冷的水中．．．\n"+
       "\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");

        message_vision(HIY "$N纵身一跃，跳进了寒潭之中。\n" NOR, me);
        me->move(__DIR__"shuidi1");
        message_vision(HIY "$N从潭边跳了下来。\n"NOR,me);
        return 1;
}

