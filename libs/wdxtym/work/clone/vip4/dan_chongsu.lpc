//dan_chongsu.c 经脉重塑丹

#include <ansi.h>

inherit ITEM;

int do_eat_2(string arg);

void create()
{
	set_name(HIR"经脉重塑丹" NOR, ({ "chongsu dan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一颗红红的丹药，使用后能够重设经脉强化的种类。\n");
		set("value", 10000);
		set("no_drop",1);
		set("no_sell",1);
		set("yuanbao", 500);
		set("only_do_effect", 1);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat_2","chongsujm");
}

int do_eat_2(string arg)
{
	object ob,me=this_player();		
	string msg, jingmai, dan, skill, *yin, *yang;
	int i;

	if(!arg||arg=="")
	{
		tell_object(me, ZJOBLONG + "请选择经脉："NOR+"\n"ZJOBACTS2+ZJMENUF(3,3,10,30)+
					CYN"阳跷脉"NOR":chongsujm 阳跷脉"ZJSEP+
					CYN"阴跷脉"NOR":chongsujm 阴跷脉\n");
		return 1;
	}

	yang = ({"sword","blade","whip","staff","throwing","unarmed","strike","cuff","finger","hand","leg"});
	yin = ({"force","dodge","parry"});

	if (sscanf(arg, "%s for %s", jingmai, skill) == 2)
	{
		if (jingmai !="阳跷脉" && jingmai !="阴跷脉") {
			tell_object(me, "经脉选择错误！\n");
			return 1;
		}
		if(jingmai == "阳跷脉")
		{
			if(me->query("meridian/ap")==skill)
			{
				tell_object(me, "你目前强化的正式这项技能，无需重塑经脉！\n");
				return 1;
			}
			else if(member_array(skill,yang)==-1)
			{
				tell_object(me, "错误的参数！\n");
				return 1;
			}
			else
				me->set("meridian/ap",skill);
		}
		else if(jingmai == "阴跷脉")
		{
			if(me->query("meridian/dp")==skill)
			{
				tell_object(me, "你目前强化的正式这项技能，无需重塑经脉！\n");
				return 1;
			}
			else if(member_array(skill,yin)==-1)
			{
				tell_object(me, "错误的参数！\n");
				return 1;
			}
			else
				me->set("meridian/dp",skill);
		}
	}
	else
	{
		msg = "请选择你要重新强化的技能类型：\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		if(arg == "阳跷脉")
			msg += 	"剑法:chongsujm "+arg+" for sword"ZJSEP
				"刀法:chongsujm "+arg+" for blade"ZJSEP
				"鞭法:chongsujm "+arg+" for whip"ZJSEP
				"杖法:chongsujm "+arg+" for staff"ZJSEP
				"暗器:chongsujm "+arg+" for throwing"ZJSEP
				"拳脚:chongsujm "+arg+" for unarmed"ZJSEP
				"掌法:chongsujm "+arg+" for strike"ZJSEP
				"拳法:chongsujm "+arg+" for cuff"ZJSEP
				"指法:chongsujm "+arg+" for finger"ZJSEP
				"手法:chongsujm "+arg+" for hand"ZJSEP
				"腿法:chongsujm "+arg+" for leg";
		else if(arg == "阴跷脉")
			msg += 	"轻功:chongsujm "+arg+" for dodge"ZJSEP
				"招架:chongsujm "+arg+" for parry"ZJSEP
				"内功:chongsujm "+arg+" for force";
		else
			msg = "你要重塑什么经脉？";
		tell_object(me, ZJOBLONG +msg+ "\n");
		return 1;
	}

	tell_object(me, "你一仰脖，吞下了一颗" + name() +"，只觉一股真气从丹田直冲而起，经由全身最终又回到丹田。"NOR"\n恭喜您：重塑经脉成功！\n");
	
	destruct(this_object());

	return 1;
}

int do_effect(object me)
{
	do_eat_2("");
	return 1;
}

int query_autoload() { return 1; }
