//鳄鱼皮
//created by zine 28 Aug 2010

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL"鳄鱼皮"NOR, ({ "eyu pi", "pi", "skin" }));
	set_weight(14000);
	if( clonep() )
                set_default_object(__FILE__);
    else
		{
			set("long", "一块鳄鱼的皮，也许你可以把它撕(tear)开。\n");
			set("material", "cloth");
			set("unit", "块");
			set("value", 1);
			set("armor_prop/armor", random(800));
		}
	setup();
}

void init()
{
	add_action("do_tear", ({ "tear", "si"}));
}

int si(object me)
{
	object eyp,ob;
	
			if(me->is_busy() || me->is_fighting())
			return notify_fail("你正忙着哪！\n");
			else 
				{
                    ob = new("/biwu/xy/obj/map");
					ob->move(me);
					eyp=present("eyu pi",me);
					if(objectp(eyp)) 
					destruct(eyp);
                    return 1;
				}	
}

int do_tear()
{
	object me = this_player();
	if(!present("eyu pi", me))
		{
		return notify_fail("你要撕什么东西？\n");
		}
    else if (me->query("max_neili") > 8000)
			{
				message_vision("你是武林高手，没事做这些小孩子的事干嘛？\n", me);
			}
		 else	 
			{	
				message_vision("$N使出吃奶的劲，把鳄鱼皮撕开两片。\n", me);
				si(me);  
			}
   return 1; 
}

