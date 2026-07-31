//shugan3.c		四川唐门—裂星崖古树

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "参天古树");
	set("long",
"333333333333333333333333333333333333\n"
);
	set("area", "蜀中");
	setup();
}

void init()
{
	add_action("do_climb","climb");
	add_action("do_climb","pa");
}

int do_climb(string arg)
{
	object ob, room;

	ob = this_player();

	if ( arg && arg=="up" )
	{
		message_vision(HIC "$N攀着繁茂的树枝一步步爬了上去。\n" NOR, ob);

		if ( (int)ob->query_skill("dodge", 1) < 51 && (int)ob->query_skill("finger", 1) < 51 )
		{
			message_vision(HIR "$N脚下一滑，手上没抓紧，仰天摔了下来。\n" NOR, ob);
			ob->add("qi",-10);
			return 1;
		}

		ob->move(__DIR__"shuding");
		return 1;
	}
	else
		if ( arg && arg=="down" )
		{
			message_vision(HIC "$N攀着繁茂的树枝小心翼翼的爬了下去。\n" NOR, ob);
			ob->move(__DIR__"shugan2");
			return 1;
		}
		else
			return notify_fail("你要向哪里爬？\n");
}
