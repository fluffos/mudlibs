// Room: /d/shaolin/hantan1.c
// Date: YZC 96/02/06

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "洪荒古洞");
        set("long", @LONG
这是古洞之中。四周风声哗哗，似乎有一股力量在极力吸
着你进古洞。身上却仍然感觉到丝丝寒意侵入肌肤，而且越
是往前，风力越强，寒意更甚。
LONG
        );
        set("no_task", 1);
        setup();
}

void init()
{
        call_out("down", 10, this_player());
}

void down(object me)
{
        tell_object(me, "只觉周身盘旋，一股强大的吸力把你往前拉去...\n");
        me->move(__DIR__"hantan3");
}
