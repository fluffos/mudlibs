// wuzhishan.c,五指山
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	int damage;
	string msg,succ_msg;

        if( me->query_level()<40 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="盘丝洞" 
        && me->query("chushi/chushi_pansidong")!="yes")
                  return notify_fail("你不能使用这项技能！\n");
	if((int)me->query("mana") < 800 )
		return notify_fail("你的法力不够！\n");
	if((int)me->query("sen") < 500 )
		return notify_fail("你无法集中精力，别砸中自己了！\n");
	if( time()<me->query_temp("psd_wushi")+8 )
		return notify_fail("你不能频繁使用此法术。\n");
	if( me->query_skill("pansi-dafa",1)<400 )
		return notify_fail("你的盘丝大法修为太低。\n");
				
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )	
		return notify_fail("你要用五指山震谁？\n");

	me->add("mana", -300);
	me->receive_damage("sen", 200);

	if( random(me->query("max_mana")) < 30 ) 
	{
		write("好象没反应，再来一次吧！\n");
		return 1;
	}

	msg = "$N口中念了几句咒文，半空中出现一座五指山，呼！地一声向$n当头砸下！\n";
	succ_msg = "结果砸个正着，差点没把$n压扁！\n";
	damage = me->query_skill("pansi-dafa",1);
	me->add_temp("apply/attack",30);
	me->set_temp("pfm_msg",1);
	me->set_temp("pfm_color",HIC);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,damage);
	me->set_temp("pfm_color",0);
	me->set_temp("pfm_msg",0);
	me->add_temp("apply/attack",-30);
	me->set_temp("psd_wushi",time());
	if( damage<1 )
		message_combatd(HIC "但是$n"HIC"在千钧一发之际跳了开来。\n" NOR, me,target);
	else
	{
		if( COMBAT_D->query_message_type(me,target)==2 )
			message_vision(HIR"另外还造成了"+damage+"点气血损伤以及"+damage/2+"点精神损失。\n"NOR,me,target);
		target->receive_wound("kee",damage,me,TYPE_CAST);
		target->receive_wound("sen",damage/2,me,TYPE_CAST);
		COMBAT_D->report_status(target,1);
	}	
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：佛祖五指
        法术所属：盘丝大法
        法术效果：给予对方带固定伤害的法术攻击
                  命中则附加减少对方的气血与精神后限
                  冷却8秒
        法术条件：
                  盘丝洞弟子
        	  人物等级40级
                  法力800点，消耗300点
                  精神500点，消耗200点
                  盘丝大法400级
                  
STR;
        me->start_more(str);
        return 1;
}

