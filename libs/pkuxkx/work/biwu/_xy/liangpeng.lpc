// Room: /clone/misc/liangpeng.c
// create: by zine Aug 21 2010

inherit "/biwu/biwuroom2";
#include <ansi.h>

void create()
{
	set("short", HIW"凉棚"NOR);
	set("long", @LONG
这是一个很大的凉棚，几个大柱子(pillar)支撑着顶棚。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"northwest" : __DIR__"grass",
	]));
    set("item_desc", (["pillar" : "柱子已经烂掉了一半，如果你猛劈(pi)的话，也许整个顶棚会塌下来。\n", 
	]));
	set("no_clean_up", 0);
	set("pillar_hp", 3);
	setup();
}

void init()
{
	add_action("do_pi", ({ "pi" }));
	::init();
}

int pi2(object me)
{	
	int i; 
	object* allp;
	object room= load_object(__DIR__"grass");
	if(me->is_busy())
		{
			return notify_fail("你正忙着呢。\n");
		}
	else 
		{
			if(query("pillar_hp") - 1 <= 0)
				{   
					allp = all_inventory();
					for(i=0;i<sizeof(allp);i++)
						{	
							allp[i]->add_busy(15);
						}
					message_vision("$N大喝一声，把所有柱子砍断，凉棚塌了下来，把所有人埋在里面。\n", me);
					room->delete("exits/southeast");
					message("vision", "东南面一声巨响，凉棚已经完全塌陷，底下的人恐怕难以幸免。\n", room );
					message_vision(HIW"$N心里早有准备，在凉棚倒塌前一刻，已经逃出生天。\n"NOR,me);
					delete("exits/northwest");
					set("long","凉棚的顶棚已经完全塌了下来。\n");
					message("vision", "一个人影从废墟中急掠出来。\n", room );
					call_out("breakout", 16);
					me->move(__DIR__"grass"); 
					me->add_busy(1);
					
				}
			else
				{	
					add("pillar_hp",-1);
					me->add_busy(random(2));
					message_vision("$N用力砍断了一根柱子。\n", me);
				}	
		}
	return 1;
}

int do_pi()
{
	object me = this_player();
	object gangfu=present("gang fu",me);
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
	if(!present("gang fu", me))
		{
			{
				message_vision("$N大喝一声，一头向柱子撞了过去。\n", me);
				me->add_busy(random(3));
			}
			if((int)me->query("qi")<200)
				{
					me->unconcious();
				}
			else
				{
					me->add("qi",-200);
				}
			return 1;
		}
	else
		{
			if(gangfu->query("equipped"))
				{
					message_vision("$N大喝一声，抓起钢斧，向柱子劈去。\n", me);
					pi2(me);    
				}
			else
				{		
					tell_object(me,"你不把斧头拿到手上怎么劈？\n");
				}
			return 1;
		}
}

int breakout()
{   
	int j;
	object* allvictim = all_inventory();
	object room= load_object(__DIR__"grass");
	for(j=0;j<sizeof(allvictim);j++)
		{
			if(!objectp(allvictim[j])) continue;
			if(!living(allvictim[j])) continue;
			allvictim[j]->move(__DIR__"grass"); 
			tell_object(allvictim[j],HIG "良久之后，被埋着的众人终于脱困而出。\n"NOR);
			tell_object(allvictim[j],HIW "大劫余生，众人都不禁心有余悸。\n"NOR);
		}
	tell_room(room,"一群人从坍塌的凉棚中爬了出来。\n");
	return 1;
}