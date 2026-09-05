// Room: /clone/misc/jiaomen.c
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";
#include <ansi.h>

void create()
{
	set("short", "府衙角门");
	set("long", @LONG
这里是襄阳府衙的角门，平时并没有多少人从这里经过。也许从这里你可以
混(hun)入襄阳府衙。
LONG
	);
	set("exits", ([
		"southeast" : __DIR__"southstreet",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_hun", ({ "hun", }));
	::init();
}


int do_hun()
{
	object me = this_player();
	object guanfu=present("guan fu",me);
	object guanfu1=present("guanfu",me);
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }

    if(!present("guan fu", me))
		{
			if(present("guanfu",me))
				{
					if(guanfu1->query("equipped"))
				    {
                        tell_room(environment(me), me->name() + HIC"穿着皱巴巴朝廷官服大模大样地走了过来。\n"NOR, me);
                        tell_object(me,"你穿着皱巴巴的官服，企图混进去，心中略有忐忑。\n");
                        me->move(__DIR__"cityhall");
                        message_vision(HIR"$N刚进府衙就被人识破，乱棍打晕扔了出来。\n"NOR, me);
                        me->move(__DIR__"jiaomen");
                        me->unconcious();
					    return 1;
				    }
                    else 
                    {
                        return notify_fail(CYN"你把官服捧在手上，别人只会以为你是送衣服的小厮。\n"NOR);
                    }
				}
			else
				{
					return notify_fail("只有朝廷命官才可以进入府衙，你应该去乔装一下。\n");
				}
		}
    else 
		{  
			if(guanfu->query("equipped"))
				{
					me->move(__DIR__"cityhall");
					me->add_busy(random(2));
					tell_room(environment(me), me->name() + HIC"穿着朝廷命官的官服大模大样地走了过来。\n"NOR, me);
					tell_object(me,"你穿着崭新的官服，企图混进去，心中略有忐忑。\n");
					return 1;
				}
			else 
				{
					return notify_fail(CYN"你把官服捧在手上，别人只会以为你是送衣服的小厮。\n"NOR);
				}
        }
	
}