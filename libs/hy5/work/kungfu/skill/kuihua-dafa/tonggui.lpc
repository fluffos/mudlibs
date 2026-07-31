// gonggui.c  同归于尽

#include <ansi.h>
#define XI "「" HIW "无声无息" NOR "」"
#define HUI "「" HIW "毁天" HIR "灭地" NOR "」"

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int skill;
        string msg;
        int damage;
        int ap, dp, lvl,j;
         int attack_type;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("同归于尽只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("kuihua-dafa", 1) < 150 )
                return notify_fail("你的葵花大法不够娴熟，不会使用「同归于尽」。\n");
       if ((int)me->query_skill("kuihua-xinfa", 1) < 50)
               return notify_fail("你的葵花心法太低了。\n");
               
        skill = me->query_skill("kuihua-dafa", 1);
        lvl = me->query_skill("kuihua-dafa", 1);


        if( (int)me->query("neili") < 300  ) 
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("kui_tong") ) 
                return notify_fail("你已经在运功中了。\n");

if( me->query("eff_qi")<100|| !((int)(me->query("max_qi")/me->query("qi"))>=3.5))
{
        msg = HIR "$N" HIR "身子忽进忽退，身形诡秘异常，在$n"
              HIR "身边飘忽不定。\n" NOR;

        ap = me->query_skill("dodge");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                msg += HIR "结果$p" HIR "只能紧守门户，不敢妄自出击！\n" NOR;
                target->start_busy(7);

                me->start_busy(1);
        } else
        {
                msg += CYN "可是$p" CYN "看破了$P" CYN "的身法，并没"
                       "有受到任何影响。\n" NOR;
                me->start_busy(2);

        }
        message_vision(msg, me, target);
 msg = HIR "\n$N" HIR "尖啸一声，猛然进步欺前，一招竟直袭$n" HIR "要害，速度之快，令"
              "人见所未见，闻所未闻。\n" NOR;

        ap = me->query_skill("unarmed");
        dp = target->query_skill("force");

        if (ap / 2 + random(ap) > dp || random(3)==0)
        {
                ap = me->query_skill("kuihua-dafa", 1);
                me->start_busy(2);
                damage=me->query_skill("kuihua-dafa", 1);	
                damage = damage  + random(damage)+100;
                target->add("qi",-damage*2);
		target->add("eff_qi",-damage/2);
                msg +=HIR "这一招速度之快完全超出了$n" HIR "的想象，$n" HIR
                                                "慌忙回缩招架，但是此招之快，已无从躲闪，$n" HIR "尖叫"
                                                "一声，已然中招。\n" NOR;
               

        } else
                msg += HIM "$n" HIM "大吃一惊，连忙退后，居然"
                                "侥幸躲开着这一招！\n" NOR;

        me->add("neili",-200);
        me->start_busy(2);
      message_vision(msg, me, target);        

}
else
{
if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
        msg = HIY "$N发疯似的冲了上来" + HIR "唯我葵花" +HIY "，$n只觉得眼前一花，咽喉已被剑锋穿过！！！" ;
        msg +=  HIW"\n一股血箭喷涌而出．．$n的全身经脉尽断．．\n" NOR;

	message_vision(msg, me, target);

if (target->query("qi") > 30000)
{
target->add("qi",-29000);
target->add("eff_qi",-29000);
}else target->unconcious();
	COMBAT_D->report_status(target);
	} else {
                msg = HIY "$N发疯似的冲了上来" + HIR "唯我葵花" +HIY "，$n只觉得眼前一花！！！" ;
		msg += HIG"可是$p还是躲过了$P的最后一击！！\n" NOR;
		me->start_busy(3);
                message_vision(msg, me, target);
	}
	
        me->add_temp("apply/attack", (int)me->query("kuihua-dafa")/2);
        me->add_temp("apply/dodge", -(int)me->query_skill("kuihua-dafa",1)/2);
        me->add_temp("apply/damage",(int)me->query_skill("kuihua-dafa",1)/2);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, (int)me->query_skill("kuihua-dafa",1)/2, (int)me->query_skill("kuihua-dafa",1)/2:), 30);
        me->set_temp("kui_tong", 1);


        me->add("neili", -(int)me->query("neili"));
}
        return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
        me->add_temp("apply/attack", - (int)me->query("kuihua-dafa")/2);
        me->add_temp("apply/dodge", (int)me->query_skill("kuihua-dafa",1)/2);
        me->add_temp("apply/damage",-(int)me->query_skill("kuihua-dafa",1)/2);
        me->delete_temp("kui_tong");
        
}

