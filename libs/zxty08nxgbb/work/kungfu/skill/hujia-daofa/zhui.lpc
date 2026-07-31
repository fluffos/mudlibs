// By KinGSo@舞林 2006年4月25日 早上

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

#define ZHUI "「" HIR "卸甲锥心势" NOR "」"



int perform(object me, object target)
{
	object weapon;
	int damage, p;
	string msg;
        int ap, dp;

       
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHUI "只能对战斗中的对手使用。\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对，难以施展" ZHUI "。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的内功火候不够，难以施展" ZHUI "。\n");

        if ((int)me->query_skill("hujia-daofa", 1) < 150)
                return notify_fail("你的胡家刀法还不到家，难以施展" ZHUI "。\n");

        if (me->query_skill_mapped("blade") != "hujia-daofa")
                return notify_fail("你没有激发胡家刀法，难以施展" ZHUI "。\n");

        if ((int)me->query("neili") < 800)
                return notify_fail("你的真气不够，难以施展" ZHUI "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "手中的" + weapon->name() +  HIR "一振，施出「卸"
              "甲锥心势」，顿时一股凌厉无比的无形刀气破空袭向$n" HIR "！\n"NOR;

        ap = me->query_skill("blade") + me->query_skill("force");
        dp = target->query_skill("force");

        if (ap / 3 + random(ap) > dp)
	{
		damage = ap *4 + random(ap * 8);
                me->add("neili", -150);
             

                if (damage > 6000) damage = 6000 + random(3000);  

                 target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/2, me);
                me->add("neili", -500);
                if (me->query("neili") < 0)
                      me->set("neili",0);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");


                  msg +=   HIR "只见$n" HIR "一声惨叫，整个人如遭电击，刀气穿心，口中鲜血狂喷而出！\n" NOR;
       msg += "( $n"+eff_status_msg(p)+" )\n"; 
             me->start_busy(2);


		me->start_busy(2);
	} else 
	{
		msg += CYN "可是$p" CYN "默运内力，硬是抵挡了$P"
                       CYN "的这记无形刀气。\n"NOR;
                me->add("neili", -50);
		me->start_busy(3);
	}
	message_vision(msg, me, target);
       me->start_perform(4,"「卸甲锥心势」");
	return 1;
}
