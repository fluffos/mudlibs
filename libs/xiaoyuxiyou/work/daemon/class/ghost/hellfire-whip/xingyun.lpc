//鬼火腥云
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_CLEAN_UP;

void remove_effect(object me, int p)
{
	if( me )
	{
		message_vision(HIB"$N"HIB"长吸一声，收去了全身缠绕的腥云鬼火。\n"NOR,me);
		me->add_temp("apply/re_spells_damage",-p);
		me->add_temp("apply/re_combat_damage",-p);	
		me->add_temp("apply/re_spells_effdamage",-p);	
		me->add_temp("apply/re_combat_effdamage",-p);	
		me->set_temp("hell_xingyun",time());	
		me->delete_temp("hell_XY");	
	}
}

int perform(object me, object target)
{
	int p,t;	
	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name") != "阎罗地府" )
        	return notify_fail("你是哪儿偷学来的武功，也想用「鬼火腥云」?\n");
	if((int)me->query("force") < 1000 )
        	return notify_fail("你的内力不足！\n");
	if((int)me->query("sen") < 100 )
        	return notify_fail("你的精神不足，没法子施用外功！\n");
	if((int)me->query_skill("hellfire-whip", 1) < 150)
        	return notify_fail("你的烈火鞭级别还不够，小心走火入魔！\n");               
	if (me->query_skill_mapped("force")!="tonsillit")
	        return notify_fail("鬼火腥云必须配合摄气诀才能使用。\n"); 
	if( time()-(int)me->query_temp("hell_xingyun") < 6 )
        	return notify_fail("绝招用多就不灵了！\n"); 
        if( me->query_temp("hell_XY") )
        	return notify_fail("你已经召唤了幽冥鬼火。\n");	
        message_vision(HIB"$N"HIB"默运神功，浑身鬼气暴涨，漫天飞舞,瞬间在周身裹成一团鬼火，背后好似隐现黄泉异象！\n"NOR,me);
        me->add("force",-200);
        me->receive_damage("sen",80,me);
	
	p = me->query_skill("tonsillit",1)/5;
	t = 30+me->query_skill("whip")/10;
	
	me->add_temp("apply/re_spells_damage",p);
	me->add_temp("apply/re_combat_damage",p);	
	me->add_temp("apply/re_spells_effdamage",p);	
	me->add_temp("apply/re_combat_effdamage",p);	
        me->set_temp("hell_XY",p);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, p:), t);
	return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        外功名称：鬼火腥云
        外功所属：烈 火 鞭
        外功效果：是自己在一定时间内反弹敌人的伤害
                  效果消失后冷却时间 6 秒
        外功条件：
        	  人物等级15级
        	  地府弟子
        	  内力1000点，消耗200点
        	  精神100点，消耗80点
                  烈 火 鞭150级
                  基本内功激发摄气诀
LONG;
me->start_more(str);
return 1;
}

void remove()
{
	int p,i;
	object me,*usr = users();
	if( i=sizeof(usr)>0 )
	{
		while(i--)
		{
			if( !usr[i] || !environment(usr[i])
			 || !objectp(usr[i]) )
				continue;
			if( usr[i]->query_temp("hell_XY") )
			{
				me = usr[i];
				p = me->query_temp("hell_XY"); 
				message_vision(HIB"$N"HIB"长吸一声，收去了全身缠绕的腥云鬼火。\n"NOR,me);
				me->add_temp("apply/re_spells_damage",-p);
				me->add_temp("apply/re_combat_damage",-p);	
				me->add_temp("apply/re_spells_effdamage",-p);	
				me->add_temp("apply/re_combat_effdamage",-p);	
				me->set_temp("hell_xingyun",time());
				me->delete_temp("hell_XY");
			}
		}
	}
} 