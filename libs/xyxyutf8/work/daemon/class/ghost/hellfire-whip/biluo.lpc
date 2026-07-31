// 碧落黄泉 biluo.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg,succ_msg;
	
	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");
		
        if( !target ) target = offensive_target(me);
	if( !target
 	 || !target->is_character()
 	 || target->is_corpse()
 	 || target==me
 	 || !me->is_fighting(target) )
                return notify_fail("你要对谁施展这一招"+HIG"「碧落黄泉」"+NOR"？\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
        if((int)me->query_skill("hellfire-whip", 1) <120)
                return notify_fail("你的烈火鞭级别还不够！\n");

        me->add("force", -30 );
        me->receive_damage("kee", 50);
	
	msg = MAG "$N"MAG"惨号一声，一口鲜血喷向半空，吃这主人心血一逼，手中$w"MAG"啸声大作，夹着阵阵鬼哭闪电般飞袭$n的胸口七处大穴！\n" NOR;
	succ_msg = HIR "结果长鞭在$n"HIR"胸口三进三出，带出一地鲜血！\n" NOR;
	me->set_temp("pfm_msg",1);
	damage=COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,"胸口",me->query_skill("whip")/5);
	me->set_temp("pfm_msg",0);	
	if( damage<1 )
		message_combatd(MAG "但是$n一声轻笑，身形摇晃，避了开去。\n" NOR,me,target);
	me->start_busy(2);	
        return 1;
}

int help(object me)
{
string str;
if(  !me )      return 0;
str = @LONG
        外功名称：碧落黄泉
        外功所属：烈 火 鞭
        外功效果：以鲜血提升自身攻击对敌进行一次带固定伤害的要害攻击
        	  自身busy 2 秒
        外功条件：
        	  人物等级15级
                  烈 火 鞭120级
                  内力500点，消耗30点
                  气血100点，消耗50点 
               
LONG;
me->start_more(str);
return 1;
}
      