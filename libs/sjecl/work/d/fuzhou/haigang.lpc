// Room: /d/fuzhou/haigang.c 海港
// Lklv 2001.9.10
// 2001.9.27 update 开放小岛，其他门派自由出入

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"海港"NOR);
	set("long", @LONG
这里是从福州出海的必经之地，港口上停着很多各式各样船只，往东边望
去，隐约可以看见一个更大的渔港。东边的方向不断传来一阵阵嘈杂声。天空
中偶尔还能看见一两只海鸥的身影。向东南方望去，可以看见离这里不远处有
一个小岛，距离岸边很近，看起来可以游(swim)过去。
LONG
	);
	set("outdoors", "福州");
	set("exits", ([
        	"east" : __DIR__"yugang",
                "west" : __DIR__"dongjie",
	]));

	set("objects", ([
                NPC_D("boy"):1,
                NPC_D("girl"):2,
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

        if (me->is_busy() || me->is_fighting())
                return notify_fail("你现在正忙着呢！");
        message_vision("$N一个俯冲，跳进海里，往浪里一钻就不见了。\n", me);
        tell_object(me,"你游了一会，看到离小岛不远，往礁石一按，跃了上去。\n");
        me->move(__DIR__"island1");
        tell_room(environment(me), me->name() +
                "抓着岸边礁石，噔噔噔地爬了上来。\n", me);
        return 1;
}
