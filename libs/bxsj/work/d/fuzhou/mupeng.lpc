// mupeng 小木棚
// By Looklove for a Quest

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","小木棚");
	set("long", @LONG
这是一个当初用岛上的树木临时搭起来的小木棚，年代久远的已经没人知
道是什么时候什么人在这里建的了。木棚虽然很破旧，但是由于它是岛上唯一
可以避雨的地方，所以偶尔还有人光顾。角落里堆着一些杂物，几个酒坛散放
那里。
LONG
        );
	set("exits",([
		"out" : __DIR__"rock",
        ]));
        setup();
}
void init()
{
        add_action("do_find","find");
}

int do_find()
{
        object me = this_player();
        object gan;

	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

	if (!me->query_temp("find/yugan")){
		me->start_busy(random(2));
		return notify_fail("你找了半天，没发现什么对你有用的东西。\n");
	}

	if (present("yu gan", this_player()))
		return notify_fail("你身上不是有了鱼竿么！\n");

	if ( present("yu gan",  environment(me)) )
		return notify_fail("除了鱼竿，这里没什么对你有用的东西了。\n");

	if ((int)me->query("jingli") <50 ) {
		write("你还是歇歇把。\n");
		return 1;
	}
        message_vision("$N在角落的杂物堆里翻来翻去。\n", me);
        me->start_busy(random(2));
        me->add("jingli",-20);

        if(random(6)<1) {
		write("你找到了一把不知道谁放在这里的旧鱼竿。\n");
		gan=new("/d/gb/obj/yugan");
		gan->move(me);
		me->delete_temp("find/yugan");
	}
        return 1;
}
