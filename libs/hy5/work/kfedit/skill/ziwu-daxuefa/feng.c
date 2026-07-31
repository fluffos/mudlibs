#include <ansi.h>
#include <combat.h>

#define FENG "「" HIR "神笔封穴" NOR "」"

inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;
        string wn;

        int level;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(FENG "只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "dagger")
                return notify_fail("你所使用的武器不对，难以施展" FENG "。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");
        if (me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("你使用的内功必须是南海玄功。\n");
        skill = me->query_skill("ziwu-daxuefa", 1);

        if (me->query_skill("force",1) < 150)
                return notify_fail("你的内功的修为不够，难以施展" FENG "。\n");

        if (skill < 100)
                return notify_fail("你的子午打穴法修为有限，难以施展" FENG "。\n");

        if (me->query("neili") < 500)
                return notify_fail("你现在的真气不足，难以施展" FENG "。\n");

        if (me->query_skill_mapped("dagger") != "ziwu-daxuefa")
                return notify_fail("你没有激发子午打穴法，难以施展" FENG "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "飞身一跃而起，贴至$n" HIR "跟前，手中" +
              weapon->name() + HIR "大起大落，气势恢弘，幻出一道闪电"
              "直射$n" HIR "要穴！\n" NOR;
 
        ap = me->query_skill("dagger");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -100);
                damage = 500 + ap  + random(ap / 5);
 target->add("qi",-damage);
		target->add("eff_qi",-damage);
		target->apply_condition("no_exert",3);
		//target->start_busy(3);
                msg += HIR "$p" HIR "微微一楞，只觉胸口一麻，"
                                           "已被$N" HIR "点中要穴，整个上半身顿时"
                                           "瘫软无力，缓缓瘫倒。\n" NOR;


                me->start_busy(1);

        } else
        {
                msg += CYN "可是$p" CYN "的看破了$P" CYN
                       "的招式，巧妙的一一拆解，没露半点"
                       "破绽！\n" NOR;
                me->add("neili", -50);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
if (skill > 300 || !userp(me))
{
	
 wn = weapon->name();
                           
        msg = HIC "$N" HIC "怒啸一声，施展出绝招「" HIW "残月刺" HIC "」"
              "手中" + wn + HIC "划出一道弧形，将$n" HIC "笼罩。\n"NOR;

        message_vision(msg, me, target);

        level = me->query_skill("ziwu-daxuefa", 1);

        me->add("neili", -80);

        if (level + random(level) > target->query_skill("dodge"))
        {
		msg = HIY "$N" HIY "看不出$n" HIY "招式中的虚实，连忙"
                      "护住自己全身，一时竟无以应对！\n" NOR; 
                target->start_busy(5);
                me->start_busy(random(2));
	} else
        {
		msg = CYN "可是$N" CYN "镇定自若，小心拆招，没有被"
                      "$n" NOR + CYN "招式所困。\n" NOR;
                      
                me->start_busy(2);
	}
	message_combatd(msg, target, me);	
}	



        return 1;
}
