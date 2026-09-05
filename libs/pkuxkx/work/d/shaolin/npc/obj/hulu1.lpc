// hulu1.c 
//by skywolf 2009-2-12 for bingcan-cloth
#include <ansi.h> 
inherit ITEM;
inherit F_LIQUID;

int can_cold=0;
string msg;
void create()
{
	set_name("葫芦", ({"hu lu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是慧净和尚用来装酒的葫芦。得把里面的酒倒掉(clear)才能装东西。
里面装着半壶米酒。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 10);
		set("no_store",1);
		set("no_pawn",1);
		set("no_sell",1);
		set("no_give",1);
	}

}

void init()
{
	add_action("do_clear","clear");
	add_action("do_catch","catch");
	add_action("do_gua","gua");
	add_action("do_jie","jie");
	if (present("hu lu",this_player()))
	{
		add_action("do_drop","drop");
	}
	add_action("do_za","za");
	
}

int do_clear(string arg)
{
	object ob=this_object();
	object me=this_player();
	if (query("max_liquid")>0)
	{
		set("max_liquid",0);
		message_vision("$N拔开塞子，把葫芦里的酒倒掉。\n", me);
		ob->set("long", "这是慧净和尚用来装酒的葫芦,现在已经空了。\n");
		return 1;
	}
	write("葫芦已经是空的了。\n");
	return 1;
}
int do_catch(string arg)
{
	object me=this_player();
	object ob=this_object();
	string a;
	object *inv;
    int i;
	inv = all_inventory(environment(me));
	if (me->query_temp("bingcan/gua"))
	{
		write("葫芦在你要上挂着呢，先解(jie)下来再说吧。\n");
		return 1;
	}
	for(i=0; i<sizeof(inv); i++)
	{ 
		if (inv[i]->query("id")=="bing can")
		{
			
			if(query("max_liquid")>0)
			{
				write("你听到嗤的一声,显是冰蚕遇到葫芦里的酒,已经化做一滩血水.\n");
				destruct(inv[i]);
				return 1;
			}
			write("你将葫芦口慢慢移向黄线绘成的圆圈,葫芦口一伸入圈内，那蚕儿嗤的一声，便钻入葫芦。\n");
			ob->set("long", "这是慧净和尚用来装酒的葫芦。里面装着一只"+HIW"冰蚕"NOR+"。\n");
			call_out("do_cansi",5,me);  //抓到冰蚕后，蚕开始吐丝      
			me->set_temp("bingcan/getcan",1);
			me->delete_temp("bingcan/findcan");
			destruct(inv[i]);
			call_out("gua_can",5,me);
			return 1;
	    }
	 }
	write("这里没有冰蚕,你抓什么?\n");
	return 1;
}

int do_gua(string arg)
{
	object me=this_player();
	if (arg=="hu lu" && present("hu lu",me))
	{
		
		if(!me->query_temp("bingcan/gua"))
		{
			if (me->query_temp("bingcan/getcan") )
				{
					write("你把葫芦挂在腰间。由于布不传冷，你感觉好多了。\n");
					if (!me->query_temp("bingcan/cansi") && !me->query_temp("bingcan/getsi"))
					{
						this_object()->set("long", "这是慧净和尚用来装酒的葫芦,上面结了一层霜。
此刻正挂在你的腰上，里面装着一只"+HIW"冰蚕"NOR+"。\n"+"你可以把它解(jie)下来\n");
					}
					
					me->set_temp("bingcan/gua",1);
					can_cold=0;                //挂在腰上，冰冻计数器清0
					return 1;
				}
				else{
				write("你把葫芦挂在腰间。\n");
					if (!me->query_temp("bingcan/cansi") && !me->query_temp("bingcan/getsi"))
					{
						this_object()->set("long", "这是慧净和尚用来装酒的葫芦,此刻正挂在你的腰上。\n"+"你可以把它解(jie)下来\n");
					}
				can_cold=0;		
				me->set_temp("bingcan/gua",1);
				return 1;
				}
			
		}
		write("葫芦不在你腰上挂着呢么？\n");
		return 1;
	}
	notify_fail("你要挂什么？\n");
}

int do_jie(string arg)
{
	object me=this_player();
	object ob;
	if (arg=="hu lu" && present("hu lu",me))
	{
		ob=present("hu lu",me);
		if (me->query_temp("bingcan/gua"))
		{
			write("你把葫芦从腰上解了下来。\n");
			if (!me->query_temp("bingcan/cansi") && !me->query_temp("bingcan/getsi"))
				{
					ob->set("long","这是慧净和尚用来装酒的葫芦，可以挂(gua)在腰间。\n");
				}
			me->delete_temp("bingcan/gua");
			if (me->query_temp("bingcan/getcan"))
			{				
				if (!me->query_temp("bingcan/cansi") && !me->query_temp("bingcan/getsi"))
				{
					ob->set("long", "这是慧净和尚用来装酒的葫芦,上面结了一层霜，里面装着一只"+HIW"冰蚕"NOR+"。\n");
				}
				remove_call_out("gua_can");
				call_out("gua_can",5,me);
				return 1;
					

			}
			return 1;
		}
		write("葫芦在你身上揣着呢，解什么解？\n");
		return 1;
	}
	return 0;
}

int gua_can()
{
	object me=this_player();
	object ob;
	if (!me->query_temp("bingcan/gua"))
	{
		ob=present("hu lu",me);
		write(HIB"你感觉葫芦冷得出奇，直比冰块更冷，你将葫芦从右手交到左手，又从左交到右，当真奇寒彻骨，实在拿捏不住。\n"NOR);
		ob->set_name(HIW"葫芦"NOR, ({"hu lu"}));
		ob->set("long", "这是慧净和尚用来装酒的葫芦,上面结了一层霜，里面装着一只"+HIW"冰蚕"NOR+"。\n");
		can_cold++;
		if (can_cold==3)
		{
			write("你实在受不了这刺骨寒冷，将葫芦扔到地上，不了葫芦早已冻得发脆，刚一落地就摔得粉碎，
你一楞神，冰蚕早已无影无踪。\n");
			destruct(ob);
			me->delete_temp("bingcan/getcan");
			me->delete_temp("bingcan/gua");
			return 1;
		}
		call_out("gua_can",5,me);
	}
	return 1;
}

int do_drop(string arg)
{
	object me=this_player();
	object ob;
	if (arg=="hu lu" && present("hu lu",me))
	{
		ob=present("hu lu",me);
		if (me->query_temp("bingcan/getcan") )
		{
			write("你将葫芦扔到地上，不了葫芦早已冻得发脆，刚一落地就摔得粉碎，
你一楞神，冰蚕早已无影无踪。\n");
			me->delete_temp("bingcan/getcan");
			me->delete_temp("bingcan/gua");
			me->delete_temp("bingcan/cansi"); //蚕丝计数器删除
			remove_call_out("do_cansi"); //蚕没了，吐丝结束
			destruct(ob);
			return 1;
		}
		write("你把葫芦扔到地上。\n");
		me->delete_temp("bingcan/gua");
		ob->move(environment(me));
		return 1;
		}
	return 1;
}

int do_cansi()
{
	object me=this_player();
	object ob=this_object();
	if (me->query_temp("bingcan/cansi")<=10)
	{	
		msg= "这是慧净和尚用来装酒的葫芦,上面结了一层霜，里面的"+HIW"冰蚕"NOR+"似乎包着一层薄丝。\n";
		ob->set("long",msg);
	}
	if (me->query_temp("bingcan/cansi")<=30 && me->query_temp("bingcan/cansi")>10 )
	{	
		msg="这是慧净和尚用来装酒的葫芦,上面结了一层霜，里面的"+HIW"冰蚕"NOR+"似乎包着一层厚丝。\n";
		ob->set("long", msg);
	}
	if (me->query_temp("bingcan/cansi")<=50 && me->query_temp("bingcan/cansi")>30)
	{
		msg="这是慧净和尚用来装酒的葫芦,上面结了一层霜，里面的"+HIW"冰蚕"NOR+"似乎已经变成了茧。\n";
		ob->set("long", msg);
	}
	if (me->query_temp("bingcan/cansi")==80 )
	{
		me->set_temp("bingcan/getsi",1);   //玩家是否可以得到蚕茧
		tell_object(me,HIR"你突然感觉寒气顿消，酒葫芦上的霜也消失殆尽，似乎冰蚕已经死了。快砸(za)开葫芦看看吧。\n"NOR);
		ob->set("long", "这是慧净和尚用来装酒的葫芦,上面结了一层霜，里面的"+HIW"冰蚕茧"NOR+"已经成形了。\n");
		remove_call_out("do_cansi");	
		me->delete_temp("bingcan/cansi"); //冰蚕已死，大功告成。
		me->delete_temp("bingcan/getcan");
		return 1;
	}
	me->add_temp("bingcan/cansi",1);
	call_out("do_cansi",1,me);
	return 1;
}

int do_za(string arg)
{
	object me=this_player();
	object ob=this_object();
	object ob1;
	if (arg=="hu lu" && present("hu lu",me))
	{
		if (me->query_temp("bingcan/getsi"))  
		{
			tell_object(me,HIR"葫芦被你轻轻一磕，立刻便碎成几块，你小心的把冰蚕茧捡起来，藏在怀里。\n"NOR);
			me->delete_temp("bingcan/getsi");    //玩家拿到冰蚕茧
			me->delete_temp("bingcan/gua");
			me->delete_temp("bingcan/cansi");
			ob1=new("/d/shaolin/obj/bingcanjian");
			ob1->move(me);
			ob=present("hu lu",me);
			destruct(ob);	
			return 1;
		}
		else
		{
			tell_object(me,HIW"葫芦被你轻轻一磕，立刻便碎成几块，冰蚕丝一遇阳光，立刻便化的无影无踪。\n"NOR);
			ob=present("hu lu",me);
			me->delete_temp("bingcan/getsi");    //玩家拿到冰蚕茧
			me->delete_temp("bingcan/gua");
			me->delete_temp("bingcan/cansi");
			destruct(ob);
			return 1;
		}
	}
	tell_object(me,"你要砸什么？\n");
	return 1;
}