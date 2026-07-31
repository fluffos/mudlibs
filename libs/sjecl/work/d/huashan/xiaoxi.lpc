// Room: /d/huashan/xiaoxi.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",  HIW "小溪" NOR );
	set("long", @LONG
这里是峰下的一条小溪，每年雨季的时候，这里的水流就很急。其余的时
候，只能看见被水冲刷的一条深沟.
LONG
);
	set("exits", ([ /* sizeof() == 1 */
		"northeast" : __DIR__"shanlu2",
	]));

	set("no_clean_up", 0);

	set("outdoors", "华山" );
	set("coor/x",70);
  set("coor/y",0);
   set("coor/z",60);
   setup();
}

void init()
{
//        add_action("do_tiao", "tiao");
}

int do_tiao(string arg)
{
        object me = this_player();
	if (arg != "xiaoxi")
                return notify_fail("你要往哪里跳？\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢。\n");
	if ((int)me->query("max_neili") < 401)
		return notify_fail("你尝试着跳过小溪。却发现自己跳不过去。\n");
	message_vision("$N一个纵身，向对岸跳过去。\n", me);
	tell_object(me, "你跳过小溪，发现自己来到了一个山崖下。\n");

        me->receive_damage("jing", 30);
	me->move(__DIR__"shanya");
	message_vision("$N从小溪那边跳了过来。\n", me);

        me->start_busy(random(2));
        return 1;
}

