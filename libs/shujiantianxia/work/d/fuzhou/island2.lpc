// island2.c 沙滩
// Looklove rebuild at 2k/5/18
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;


void create()
{
        set("short",HIM"沙滩"NOR);
        set("long", @LONG
这是小岛上一片美丽的沙滩，西北方向可以望见福州的港口，看起来离得
很近，似乎游(swim)也游得回去。岸边沙滩上布满了贝壳，还有不少螃蟹在岩
石的洞里吐着泡沫。前面处不远是块大岩石，旁边搭有一个小木棚。
LONG
        );
        set("outdoors","福州");
        set("exits",([
		"west" : __DIR__"island1",
		"east"  : __DIR__"island"+(1+random(3)),
		"north" : __DIR__"island"+(1+random(3)),
		"south" : __DIR__"island"+(1+random(3)),
        ]));
        setup();
}

void init()
{
        add_action("do_swim","swim");
        add_action("do_swim","youyong");
}

int do_swim()
{
        object me = this_player();

        if (me->is_busy())
                return notify_fail("你现在正忙着呢！");
        message_vision("$N一个俯冲，跳进海里，往浪里一钻就不见了。\n", me);
        tell_object(me,"你游了一会，看到离岸边不远，往礁石一按，跃了上去。\n");
        me->move(__DIR__"yugang");
        tell_room(environment(me), me->name() +
                "抓着岸边礁石，噔噔噔地爬了上来。\n", me);
        return 1;
}