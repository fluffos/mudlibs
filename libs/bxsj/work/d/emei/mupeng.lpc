// mupeng.c
// 木棚
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "木棚" );
        set("long",@long
这里是峨嵋派的男弟子们自己动手搭建的安身之所。峨嵋派自郭襄建派以
来，以女弟子居多，因此男弟子们把它们建到了这么偏僻的地方。里面的东西
都很朴素，除了几张木板床以外就没有什么别的东西了。
long);
        set("sleep_room", 1);
        set("exits",([
             "south":__DIR__"wanfoding",
]));
        setup();
}

void init()
{
    add_action("do_xian", ({"xian", "move"}));
    add_action("do_zuan", ({"zuan", "enter"}));
}             

int do_xian(string arg)
{
    object me = this_player();
    if (me->query_temp("marks/zuan"))
	return notify_fail("你吃饱了撑的？床不是掀开了吗？\n");
    if (!arg) return 0;
    if (arg != "木板床" && arg != "床" && arg != "chuang" && arg != "bed")
	return 0;
    message_vision("$N掀开了床板。\n", me);
    tell_object(me, "你发现床下面有一个洞口可以钻进去。\n");
    me->set_temp("marks/zuan", 1);
    return 1;
}

int do_zuan(string arg)
{
    object me = this_player();
    if (!arg) return 0;
    if ( arg != "hole" && arg != "洞" && arg != "dong" && arg != "洞口" && arg != "dongkou")
	return 0;
    if (!me->query_temp("marks/zuan"))
	return 0;
    message_vision("$N一头钻进了床下的洞口。\n", me);
    me->delete_temp("marks/zuan");
    me->move(__DIR__"houshanxl");
    return 1;
}

