// bite.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj,damage;
	string msg,succ_msg;
	
	success_adj = 20;
	damage_adj = 120;

	if( me->query_level()<40 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query("family/family_name")!="陷空山无底洞" )
        	return notify_fail("无底洞弟子才可以用！\n");
	if( me->query("mana")<500 )
		return notify_fail("你的法力不够！\n");
	if( (int)me->query("sen") < 200 )
		return notify_fail("你无法集中精力！\n");
	if( time()<me->query_temp("wdd_bite")+5 )
		return notify_fail("你不能频繁变化妖身。\n");
				
	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("闲的没事变什么老鼠？\n");


	me->add("mana", -100);
	me->receive_damage("sen",100);

	if( random(me->query("mana")) < 50 ) {
		write("你变的这么小,怎么咬人！\n");
		return 1;
	}

	msg = HIC "\n$N"HIC"口中喃喃自语，化作一只白毛玉鼠，扑向$n"HIC"！\n" NOR;
	succ_msg = HIR "\n结果$n"HIR"被咬了个正着！\n"NOR;
	
	me->set_temp("wdd_bite",time());
	me->add_temp("apply/spells_succ",success_adj);
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,damage_adj,"both");
	me->add_temp("apply/spells_succ",-success_adj);
	me->delete_temp("pfm_msg");
	if( damage<1 )
	{
		message_vision(HIC"$N"HIC"连忙一侧身闪在一旁。\n" NOR,me);
		me->start_busy(1);
	}
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：化鼠术
        法术所属：妖法
        法术效果：变化成白鼠使对方精神气血受打击
        	  失败则自身busy 1 秒
        	  冷却时间5秒
        法术条件：
                  无底洞弟子
        	  人物等级40级
                  精神200点，消耗100点
                  法力500点，消耗200点
                  
STR;
        me->start_more(str);
        return 1;
}