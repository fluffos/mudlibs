// Room : /d/wudang/clbinyuan2.c 丛林边缘
// By lius 99/8

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","丛林边缘");
        set("long", @LONG
你终于走出了丛林，前面是一座高耸的山峰，一条溪流环山而过，两面是
峭壁，你不禁看作后面的丛林和眼前的山溪出神，不知如何才能找到出山的路
径。
LONG                           
        );
        set("exits", ([               
                 "south" : __DIR__"conglin"+(random(4)+13),
                 "north" : __DIR__"conglin"+(random(4)+13),
                 "northeast" : __DIR__"conglin"+(random(4)+13),
                 "northwest" : __DIR__"conglin"+(random(4)+13),
        ]));
        set("outdoors", "武当");
        setup();
}

void init()
{
         add_action("do_tiao", ({"tiao","jump"}));
}

int do_tiao(string arg)
{
        object me;
        me = this_player(); 
        if (!arg || arg != "river" ) return 0;
 
        message_vision(WHT"$N不再犹豫，纵身跳入溪流。\n"NOR, me);
        me->move(__DIR__"shuizhong");
        call_out("swim", 5, me);
        return 1;
}

int swim(object me)
{
        message_vision("$N只觉耳旁哗哗流响，水冷刺骨，忙用内力相抗。\n", me);
        if ((int)me->query_skill("force",1) < 100 ){
          tell_object(me, BLU"寒气阵阵逼来，一阵强似一阵，渐渐不能抵抗，四肢开始麻木。\n"NOR);
          me->unconcious();
          me->move("/d/xiangyang/hanshui2");
          tell_room(environment(me), "一个浪涛打来将昏迷中的"+me->name()+"推上岸来。\n", ({ me }));
          return 1;
        }
        else
         me->move("/d/xiangyang/hanshui2");
        tell_object(me, HIY"你随波逐流，终于发现了岸边，浑身湿漉漉的爬上了汉水西岸。\n"NOR);
        tell_room(environment(me), me->name() + "从上游冲了下来，随即湿漉漉地爬上岸来。\n", ({ me }));
        return 1;
}
