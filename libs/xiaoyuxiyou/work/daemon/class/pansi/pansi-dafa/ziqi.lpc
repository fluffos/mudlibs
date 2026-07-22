// drainerbolt.c
//2001,lestat
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg,succ_msg;
	int damage;
	
        if( me->query_level()<35 )
		return notify_fail("你的人物等级不够。\n");
	if((int)me->query_skill("spells") < 500 )
		return notify_fail("你的法术不够高！\n");
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )	
		return notify_fail("你要对谁施展氤氲紫气？\n");
	if((int)me->query("mana") < 500 )
		return notify_fail("你的法力不够！\n");
	if((int)me->query("sen") < 200 )
		return notify_fail("你的精神没有办法有效集中！\n");

	me->add("mana", -200);
	me->receive_damage("sen",100);

	if( random(me->query("max_mana")) < 20 ) 
	{
		write("你失败了。\n");
		return 1;
	}

	msg = "$N口中喃喃地念著咒文，左手一挥，手中聚起一团紫气射向$n！\n";
	succ_msg = "结果「嗤」地一声，紫气从$p身上透体而过，拖出一条长长的七彩光气，光气绕了回转过来又从$N顶门注入$P的体内！\n";
	damage = me->query_skill("spells")+me->query("mana");
	damage = damage/5+random(damage/5);
	me->set_temp("pfm_msg",1);
	me->set_temp("pfm_color",HIM);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,"头部",damage);
	me->set_temp("pfm_color",0);
	me->set_temp("pfm_msg",0);	
	if( damage<1 )
	{
		message_combatd(HIM"但是被$n"HIM"躲开了。\n"NOR,me,target);
		me->add("mana",-100);
	}
	me->start_busy(2);
	return 5;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：氤氲紫气
        法术所属：盘丝大法
        法术效果：给予对方带固定伤害的要害法术攻击
                  自身busy 2 秒
                  法术公共冷却5秒
        法术条件：
        	  人物等级35级
                  法力500点，消耗200点，失败则追加消耗100点
                  精神200点，消耗100点
                  法术有效等级500
                  
STR;
        me->start_more(str);
        return 1;
}
