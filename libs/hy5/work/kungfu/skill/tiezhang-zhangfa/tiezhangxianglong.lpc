// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#define ZHUI "「" HIW "穿心锥" NOR "」"
#define KAI "「" HIW "破甲推山" NOR "」"
#define CHU "「" HIM "孤雁出群" NOR "」"

int perform(object me, object target)
{
	string msg;
	int extra;
	int i,a,ap,dp;
	int skill;
	object weapon;
        int damage;

	if( !target ) target = offensive_target(me);
        skill=(int)me->query_skill("tiezhang-zhangfa", 1);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("铁掌降龙只能对战斗中的对手使用。\n");
	 
    if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用！\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「铁掌降龙」只能空手使用。\n");		

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 50 )
		return notify_fail("你的铁掌掌法不够娴熟，不能用铁掌降龙。\n");

	if( (int)me->query_skill("guiyuan-tunafa", 1) < 60 )
		return notify_fail("你的归元吐纳法不够娴熟，不能使用铁掌降龙。\n");

   if (me->query_skill_mapped("unarmed") != "tiezhang-zhangfa"
     ||me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("你没有把铁掌做为基本招架和备为掌法。\n");

	extra = me->query_skill("tiezhang-zhangfa",1) / 20;
	extra += me->query_skill("guiyuan-tunafa",1) /20;
 i = extra/4;
    if( (int)me->query("neili", 1) <  (80 * i) )
		return notify_fail("你现在内力不足，不能使用！\n");	
        me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 1900);
	msg = HIR  "$N运起［归元吐纳法］，同时使出［铁掌降龙］一阵一阵的掌力，如潮水般的击向$n！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIW "第一层掌力，．．．．\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 11) a=11;
        for(i=0;i<a;i++)
	{
	msg = HIC "$N身形突转，一掌又打了过来！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
i = extra/4;
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1900);
me->start_busy(3);
me->add("neili", - 30 * i);
if (skill>200 && me && target)
{
 msg = HIY "\n$N" HIY "一声冷笑，双掌一错，陡然施出一招"
              "「" HIW "穿心锥" HIY "」，幻出千百之手掌一齐"
              "插向$n" HIY "！" NOR;

if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                me->start_busy(1);
                damage = me->query_skill("tiezhang-zhangfa",1)+100;
                damage = damage  + random(damage);
         if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi",damage*2,me);
                target->receive_wound("qi",damage*2,me);
                msg +=HIR "\n结果$p" HIR "没能避开$P" HIR
                                          "变幻莫测的掌法，掌劲顿时透胸而过，"
                                          "口喷鲜血，几乎摔倒！\n" NOR;
        } else
        {
                me->start_busy(2);
                msg = CYN "\n可是$p" CYN "识破了$P"
                      CYN "这一招，斜斜一跃避开。\n" NOR;
        }
        message_combatd(msg, me, target);
	
}	

if (skill>300 && me && target)
{
        ap = me->query("combat_exp",1);
        dp = target->query("combat_exp",1);

        msg = HIC "\n$N" HIC "长啸一声，施出绝招「" HIW "开山破" HIC "」，一"
              "拳挥出，破空而响，直击$n" HIC "面门和胸口。\n" NOR;
        


if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                damage = (int)me->query_skill("tiezhang-zhangfa", 1)+100;
                damage += random(damage)+300;
         if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi",damage*2,me);
                target->receive_wound("qi",damage*2,me);
                msg +=HIR "\n $N" HIR "出手既快，方位又奇，$n"
                                          HIR "闪避不及，闷哼一声，已然中拳。\n" NOR;


	        me->start_busy(1);                                         
        } else
        {
                msg = CYN "$n" CYN "不慌不忙，以快打快，将$N"
                      CYN "这招化去。\n" NOR;


	        me->start_busy(2);
        }
        message_combatd(msg, me, target);
	
}	

if (skill>400 && me && target)
{

        ap = me->query("combat_exp",1);
        dp = target->query("combat_exp",1);

        msg = HIC "\n$N" HIC "腾空而起，施展出绝招「" HIM "孤雁出群" HIC "」，"
              "\n犹如一只大雁临空而下，双掌猛地拍向$n" HIC "。\n" NOR;


if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                damage = (int)me->query_skill("strike", 1)+(int)me->query_skill("tiezhang-zhangfa", 1);
                damage = damage+300+random(300);
         if (userp(target) && damage > target->query("qi",1)/2) damage=target->query("qi",1)/2;
                target->receive_damage("qi",damage*2,me);
                target->receive_wound("qi",damage*2,me);
                msg +=HIR "但见$N" HIR "双掌拍来，掌风作响，"
                                           "当真迅捷无比。$n" HIR "顿觉心惊胆战，"
                                           "毫无招架之力，微作迟疑间$N" HIR "\n这掌"
                                           "已正中$n" HIR "胸口，顿将$p震退数步。"
                                           " \n" NOR;
                target->apply_condition("tiezhang_yang",50);
target->apply_condition("tiezhang_yin",50);
                me->start_busy(1);

        } else
        {
                msg = CYN "$n" CYN "见$N" CYN "这掌拍来，内力"
                      "充盈，只得向后一纵，才躲过这一掌。\n" NOR;

                me->start_busy(2);

        }
        message_vision(msg, me, target);
}
	return 1;
}
