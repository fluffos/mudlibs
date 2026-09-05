/*
FILE:/d/obj/beisu_jieyao.c
create by: bfmgqy
create date: 2009-6-16

语法:
	1. use <解药> [数量] to <目标>	给目标玩家使用解药（解毒，并且使玩家1个condition内不会中毒
	2. use <解药>	给自己使用解药（1个condition内不会中毒）

	判断自己是否有解药
	判断解药是否已经用完
	判断是给自己闻还是给别的玩家闻
	判断自己是否busy，busy无法使用
	判断目标是否中毒busy
	中毒busy->解busy,解毒， call_out
*/

#include <ansi.h>

inherit ITEM;

int help_beisu_jieyao(object me);

void create()
{
	set_name("解药",({"jieyao"}));
	set_weight(1000);
	if(clonep())
		set_default_object(__FILE__);
	else {
		set("long","这是一瓶悲酥清风的解药，闻起来奇臭无比\n");
		set("unit", "瓶");
		set("value", 10);
		
		set("use_count", 5);
	}

	setup();
}

void init()
{
	add_action("use_jieyao", "use");
}

int use_jieyao(string arg)
{
	string s_obj,  s_target;
	int s_seq;
	object ob,target,room,me;


	if(!arg) help_beisu_jieyao(this_player());

	me = this_player();	
	ob = present( arg, me );
	s_target="";
	//判断是给自己闻还是给别的玩家闻
	if( !ob ) 
	{
		if( sscanf(arg, "%s to %s", s_obj, s_target)!=2 ) 
		{
			return help_beisu_jieyao(me);
		}
		ob = present( s_obj, me);
		if( !ob ) return 0;
	}	
	
	if( ob != this_object() ) return 0;
	room=environment(me);	
	if (s_target&&s_target!="")
		target=present(s_target, room);
	else
		target=me;


	if( !target )
		return notify_fail("你想让谁闻解药？\n");
	
	if( !interactive(target) )
		return notify_fail(target->name() + "不需要这玩意。\n");
	
	if( !living(target) )
		return notify_fail("对尸体使用解药有用么？？。\n");

	//判断自己是否busy，busy无法使用
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成。\n");

	//判断自己是否有解药
	if( ob->query("use_count")<1 )
	{
		tell_object( me, "你使用了解药，但是毫无效果，一气之下将瓶子打得粉碎。\n" );	
		destruct(ob);
	} else if( target->query_temp("beisu_du")&&target->is_busy() )
	{
		target->start_busy(0);
		target->start_call_out(__FILE__, "jie_out", 2, target);
		target->set_temp("beisu_du", 2);
		ob->add("use_count", -1);
		tell_object(target, "一阵臭气传来，让你无法忍受，浑身哆嗦。。\n");
		return 1;
	} else if( target->query_temp("beisu_du")<2 )
	{
		target->set_temp("beisu_du", 2);
		target->start_call_out(__FILE__, "jie_out", 2, target);
		ob->add("use_count", -1);
		tell_object(target, "一阵臭气传来，让你无法忍受，浑身哆嗦。。\n");
		return 1;			
	} else
	{
		return notify_fail(target->name() + "已经用过一次解药了。\n");
	}	
	return 1;	
}

int help_beisu_jieyao(object me)
{
	
	tell_object( me, "语法：use <解药>\n语法：use <解药> to 玩家\n" );
	return 1;
}

int jie_out(object me)
{
	if(!me)	return 0;
	if(interactive(me))
	{
		if(me->query_temp("beisu_du"))
		{
			me->delete_temp("beisu_du");
			tell_object( me, "清新空气扑面而来，你感到一阵舒爽。\n" );
		}
	}
}