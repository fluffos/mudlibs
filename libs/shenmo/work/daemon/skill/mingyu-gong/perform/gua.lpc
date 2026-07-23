// gua.c 明玉功「冰河倒挂」
#include <ansi.h>
#include <combat.h>

#define GUA            "「" HIM "冰河倒挂" NOR "」"

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp, fp, pp;
        
        if (! target) target = offensive_target(me);
        if (! target || ! me->is_fighting(target))
                return notify_fail(GUA "只能在战斗中对对手使用。\n");
                
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对！\n");
                
        if ((int)me->query_skill("mingyu-gong", 1) < 300)
                return notify_fail("你明玉功修为不够，无法施展" GUA "。\n");
            if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("你的冰雪心法修为不够。\n");              
        if ((int)me->query_skill("sword", 1) < 300)
                return notify_fail("你剑法修为不够，无法施展" GUA "。\n");
                
        if ((int)me->query("neili") < 500)
                return notify_fail("你现在真气不够，无法施展" GUA "！\n");
                
        if (me->query_skill_mapped("sword") != "mingyu-gong")
                return notify_fail("你没有将明玉功运用于剑法，无法使用" GUA "。\n");
                
        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
               
        me->add("neili", -300);
        
        ap =  me->query_skill("sword");
        dp =  target->query_skill("dodge");
        fp = target->query_skill("force");
        pp = target->query_skill("parry");

        message_vision(HIW "\n$N" HIW "娇喝一声，手中" + weapon->name() + HIW "随即不停舞动，如巨浪般卷"
                        "出，正是明玉功绝技「" HIM "冰河倒挂" HIW "」\n，突然" + weapon->name() + HIW 
                        "幻出的冰河激射出四路袭向$n，势不可挡．\n" NOR, me, target);        
        msg = HIM "$N" HIM "将内力全灌入剑身，呼的一剑，当头直劈。\n" NOR;
        if (ap * 11 / 20 + random(ap) < fp)
                msg += CYN "$n" CYN "凭借自身高强的内功，硬是荡开此招。\n" NOR;
        else
        {
                damage = me->query_skill("sword");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$n" HIR "不知此招之强，招架之下竟被$N"
                                           HIR "这一剑震得口吐鲜血，连连倒退。\n" NOR;
        }
        msg += HIM "\n$N" HIM "圈转" + weapon->name() + HIM "，剑势灵动，招招直指要害，剑光如网，铺天盖地。\n" NOR;
        if (ap * 11 / 20 + random(ap) < dp)
                msg += CYN "$n" CYN "的身法却比剑势还快，从容的闪过剑招。\n" NOR;
        else
        {
                damage = me->query_skill("sword");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "此招来势当真快极，$n" HIR "哪里来得及闪"
                                           "避招架？只见$N" HIR "剑光闪过，$n"
                                           HIR "混身霎时鲜血淋漓！\n" NOR;

        }
        msg += HIM "\n$N" HIM "反手一剑，疾刺$p" HIM "后心，剑法之快，部位之准，令人防不胜防。\n" NOR;
        if (ap * 11 / 20 + random(ap) < pp)
                msg += CYN "$n" CYN "身在空中，不及变招，只能挥出一招，正击中$N"
                       CYN "剑上，略一借力，飘然避去。\n" NOR;
        else
        {
               damage = me->query_skill("sword");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "$n" HIR "身在空中，哪里来得及变招？只见$N"
                                           HIR "此剑掠过，$n" HIR "大声惨呼，鲜血四下飞溅！\n" NOR;
        }
        msg += HIM "\n$N" HIM "谷催十成功力，分身化影，犹如数个$N一起分袭击$n。\n" NOR;
        if (me->query_skill("martial-cognize", 1) * 2 / 3 + random(me->query_skill("martial-cognize", 1)) <
            target->query_skill("martial-cognize", 1))
                msg += CYN "$n" CYN "不愧武学精湛，立分虚实，$n"
                       CYN "全力攻向$N。\n" NOR;
        else
        {
                damage = me->query_skill("sword");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage);
                msg += HIR "$n" HIR "慌乱出招，却都只击到残影，"
                                           HIR "身上也同时多处中招．\n" NOR;

        }
        me->start_busy(3);
        message_combatd(msg, me, target);
        return 1;
}

