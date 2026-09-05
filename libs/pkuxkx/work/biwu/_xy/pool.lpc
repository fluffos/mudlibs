// Room: /clone/misc/pool.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 26 2010
#include <ansi.h>
inherit "/biwu/biwuroom1";

void create()
{
	set("short", HIW"池塘"NOR);
	set("long", @LONG
这里位于襄阳城的北部，一个大池塘，池底(di)很浑浊，你看不清什么，池
边有几块石头(stone)。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"southwest" : __DIR__"northstreet",
	]));
	set("item_desc", ([
		"stone" : "几块大石头，你可以把它拿(na)起来，也许抱着石头你可以潜(qian)入池底。\n", 
	    "di" : "池水很浑浊，你看不清池底，似乎有什么东西在缓缓移动。\n", 
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_na", ({ "na", }));
	add_action("do_qian", ({ "qian", "dive" }));
	::init();
}

int found(object me)
{
	object ob = new("/biwu/xy/obj/stone");
	if (ob) 
		{
			ob->move(me);
			message_vision("$N很满意地抱起了一块巨大的石头。\n", me);
			me->add_busy(random(2));
		}
    return 1;
}

int do_na()
{
	object me = this_player();
    if(present("stone",me)) 
		{ 
			return notify_fail("你已经搬起了一块石块了，要那么多石头，你有手拿吗？\n");
		}
    else 
		{      
			message_vision("$N在一堆石头中拔来拔去，似乎疯了一样。\n", me);
            found(me);    
        }
    return 1; 
}

int do_qian(string arg)
{
	object me;
	me = this_player();
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
	if(!present("stone", me))
		{
			return notify_fail("你身上没有石块，很难潜入池底。\n");
		}
	else 
		{
	if (random(10)>8) 
		{
			message_vision(HIB"$N屏住呼吸，一举潜入池底。\n"NOR, me);
			message_vision("$N被呛了几口浑浊的水。\n", me);
			me->set_temp("last_damage_from", "$N惊恐地发现，这里有一只大鳄鱼在看着你。");
			me->receive_wound("qi", random(500));
			me->add_busy(random(2));
			me->move(__DIR__"pool2");
			return 1;
		}
	else 
		{
			if (random(10)>7)
				{
			message_vision(HIB"$N屏住呼吸，一举潜入池底。\n"NOR, me);
			message_vision("$N被呛了几口浑浊的水。\n", me);
			me->set_temp("last_damage_from", "$N被池底潜流不知冲向哪里。");
			me->receive_wound("qi", random(500));
			me->move(__DIR__"hudi2");
			me->add_busy(1+random(2));
			tell_room(environment(me), me->name() + "被水冲了过来。\n", ({ me }));
			return 1;
				}
			else
				{
					message_vision(HIW"$N尝试潜下湖底，但似乎有些危险，你心有余悸，裹足不前。\n"NOR, me);
					message_vision(HIW"你似乎回到了刚才的地方。\n"NOR, me);
					me->add_busy(random(2));
					return 1;
				}
		}
		}
}