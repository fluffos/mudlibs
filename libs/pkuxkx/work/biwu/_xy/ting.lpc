// Room: ting.c
// Create by zine 29 Aug 2010
inherit "/biwu/biwuroom1";
#include <ansi.h>

void create()
{
	set("short", "八角亭");
	set("long", @LONG
这里是一座八角亭，供游人歇脚之用，很奇怪它并没有毁于当年的战火。亭中
的石桌(table)似乎有些古怪。东面(east)有一条小路。
LONG
	);
	set("item_desc", ([ /* sizeof() == 3 */
		"table" : "一个石桌，似乎十分松动，你可以移动(move)一下。\n", 
	]));
	set("exits", ([ 
		"west" : __DIR__"grass",
	]));
	set("no_clean_up", 0);
	setup();
}


void init()
{ 
	add_action("do_move","move"); 
	add_action("do_east", "east");
	::init();
}

int do_move(string arg)
{
	 object me=this_player();
	 if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
	 me->add_busy(random(2));
	 return notify_fail("很显然，你搬不动这个石桌。\n");
}

int do_east()
{
	object me;
    me = this_player();
    if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
		}
	else
		{
			tell_object(me,HIY"你继续向东面的小路走去，不一会来到一处练兵场。\n"NOR);
			me->add_busy(random(2));
			tell_room(environment(me), me->name() + "一闪身就不见了，似乎你眼花了一下。\n"NOR, ({ me }));
			me->move(__DIR__"court");
			return 1;
		}
}