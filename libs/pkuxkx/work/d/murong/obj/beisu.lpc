/*
FILE:/d/obj/beisu.c
create by: bfmgqy
create date:2009-6-16
使用方法：
	use beisu
作用描述：
	1.悲酥清风，打开后10秒内关闭，按照打开-关闭时间有效，不关闭10秒后自动失效。
	2.物品不可保存,不可扔，不可拾取
	3.物品持有玩家在毒雾有效时间内所经过的房间，对房间内玩家有效。
	4.毒性持续到玩家退出。
	5.毒影响所有玩家包括自己，需要先闻解药才能使用。
	6.毒药消用完后瓶子自动消失。
悲苏状态: 
	没有中毒：0
	中毒：1
	解药持续期：2
*/

#include <ansi.h>

inherit ITEM;

int beisu_open(object ob);

void create()
{
	set_name("悲酥清风", ({"beisu","beisu qingfeng"}));
	if(clonep())	set_default_object(__FILE__);
	{
		set("long", "这是一瓶悲酥清风，超强迷药，闻到者浑身酸软，无法动弹。\n");
		set("unit","瓶");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_give", 1);

		set("use_count",10);
		set("is_beisu_open",0);
	}
	setup();
}

void init()
{
	add_action("do_beisu_open", "use");
	add_action("do_beisu_close", "feng");
}

int do_beisu_open(string arg)
{
	string item,amount;
	object ob,me;


	if(!arg) 
		return notify_fail("你要用什么?\n");

	me = this_player();
	ob = present(arg,me);

	if( !ob ) 
		return 0;
	if( ob != this_object() ) 
		return 0;

	if(me->is_busy())
		return notify_fail("你上一个动作没有完成。\n");
	
	if(ob->query("is_beisu_open"))
		return notify_fail("瓶子已经是打开着的了.\n");

	ob->set("is_beisu_open",1);
	if(ob->query("use_count")<1)
	{
		ob->set("is_beisu_open", 1);		
		return notify_fail("你打开了瓶子,什么效果也没有!\n");
	}
	
	tell_object(me, "你小心翼翼的拔开了瓶塞，一股清香飘散在空中。\n");
	message("vision",HIB"空气中飘着阵阵香气。\n"NOR, environment(me));
	remove_call_out("beisu_open");
	beisu_open(ob);		
	return 1;
}

int do_beisu_close(string arg)
{
	object ob;

	if(!arg) return notify_fail("什么?");

	ob = present( arg, this_player() );

	if( !ob ) return 0;
	if( ob != this_object() ) return 0;


	if(this_player()->is_busy())
		return notify_fail("你上一个动作没有完成。\n");

	if(!ob->query("is_beisu_open"))
		return notify_fail("你没打开瓶子啊.\n");

	tell_object(this_player(), "你迅速塞上了悲酥清风的瓶盖.\n");
	ob->set("is_beisu_open", 0);
	remove_call_out("beisu_open");
	return 1;
}

int beisu_open(object ob)
{
	int u_count;
	object m_player,m_room,*objs;
	
	if(!ob->query("is_beisu_open"))
		return notify_fail("我还在瓶子里呢.\n");

	if(interactive(m_player=environment(ob)))
		m_room=environment(m_player);
		
	objs = all_inventory(m_room);
	
	foreach(object p in objs)
	{
		if(!wizardp(p)&&interactive(p))
		{
			p->add_temp("beisu_dujia",1);
			if(p->query_temp("beisu_dujia")>5 && p->query_temp( "beisu_du" )<1)
			{
				tell_object( p, HIW"你只觉得浑身酸软，无法动弹!\n"NOR );
				message( "vision", HIY + p->name() + "中了悲酥清风，无法动弹\n"NOR, m_room, p );
				p->set_temp("beisu_du", 1);
				p->start_call_out(__FILE__, "beisu_busy", 1, p );
				p->start_busy(700); 
			} else if(p->query_temp( "beisu_du" )<2)
			{
				p->start_busy(7000000);
			}
		}
	}

	u_count = ob->query( "use_count" );

	if( u_count<1 )
	{
		message( "vision", HIY"香气已经消散了。\n"NOR, m_room );
		remove_call_out( "beisu_open" );
		destruct(this_object());
	} 
	else
	{
		ob->add( "use_count", -1 );
		remove_call_out( "beisu_open" );
		call_out( "beisu_open", 5, ob );
	}

	return 1;
}

int beisu_busy(object me)
{
	if(!me) return 0;
	if(interactive(me)&&(int)me->query_temp("beisu_du")==1)
	{
		me->start_busy(10);	
		me->start_call_out(__FILE__, "beisu_busy", 1, me);
	}	
	return 1;
}