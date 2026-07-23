// binghuo.c 烈焰寒冰掌--
// looo/2001/6/23
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int damage, dp,skill;
skill = me->query_skill("bazhen-zhang",1);
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「绝命连击」只能在战斗中使用。\n");

        if( objectp( me->query_temp("weapon")) )
                return notify_fail("只有空手才能施展「绝命连击」。\n");

        if( (int)me->query_skill("bazhen-zhang", 1) < 150 )
                return notify_fail("你的这门掌功夫还不够娴熟，不会使用「绝命连击」。\n");

        if(me->query_skill("yunlong-shengong", 1) < 120)
                return notify_fail("以你现在的云龙心法还使不出「绝命连击」。\n");

        if (me->query_temp("weapon"))
                return notify_fail("你只能空手使用「绝命连击」。\n");

        if( (int)me->query("max_neili") < 800 )
                return notify_fail("你的内力修为太弱，不能使用「绝命连击」！\n");

        if( (int)me->query("neili") < 800 )
                return notify_fail("你的真气不够！\n");

   
                msg = HIR "\n$N" HIR "左手手心隐隐透红光，一股炽热掌气直袭" HIR "$n" HIR "胸口！\n"NOR;
                if (living(target))
                       dp = target->query_skill("parry") / 3;
                else   dp = 0;
                if (random(me->query_skill("parry")) > dp)
                {
                       me->start_busy(1);
                       target->start_busy(1);
                       me->add("neili", -300);
                       damage = (int)me->query_skill("bazhen-zhang", 1);
                       damage = (int)me->query_skill("force", 1) + damage;
                       damage = random(damage) + 300;
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIR "$n" HIR" 顿时觉得胸口如被火烧，一口真气难以继回，!!\n"NOR;

                       if(me->query_skill("bazhen-zhang", 1) > 150)
                              call_out("perform2", 0, me, target);
                }   else
                {
                       me->start_busy(3);
                       me->add("neili", -100);
                       msg += HIW"可是$p一个巧云翻身，远远的躲了开去。\n"NOR;
                }

        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target)
{
        string msg;
        int damage,dp,ap;
                int skill;
skill = me->query_skill("bazhen-zhang",1);
        if (!me || !target || environment(me) != environment(target)) return 0;
        if(!living(target))
          return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("你待要再出第二掌，却发现自己的内力不够了！\n");

        msg = HIB "\n接着" HIB "$N" HIB "你挥出右手，手心竟是暗隐寒劲，以巧妙角度向" HIB "$n" HIB "拍过去!\n"NOR;
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
              {

                me->start_busy(1);

                me->add("neili", -300);
                damage = (int)me->query_skill("bazhen-zhang", 1);
                damage = random(damage)+300;
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIW  "结果一掌击中，" HIW "$n" HIW "只觉得全身气脉通道如遭冻结，脸色一下变白！\n"NOR;

                }
        else {
           me->start_busy(3);
           me->add("neili", -100);
           msg += HIY "\n$p" HIY "眼看寒气逼人，暗生警觉，顺势跳了开去。\n" NOR;
           }
        message_vision(msg, me, target);

if (skill> 250)
{
     msg = HIR "$N" HIR "一声暴喝，手臂上青筋突起，使出「绝命一击」左手一晃，右手成爪，向$n" HIR
              "前胸迅疾抓到。\n" NOR;

        dp = target->query_skill("force", 1);
        if (dp < 1)  dp = 1;
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -150);
                damage = ap + (int)me->query_skill("force", 1);
                damage += random(damage / 2);
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIR "$n" HIR "闪避不及，前胸顿时被抓出"
                                           "五条血痕，不禁长声惨呼！\n" NOR;

                me->start_busy(2 + random(3));
        } else
        {
                me->add("neili", -50);
                damage = ap / 2 + random(ap / 2);
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIM "$n" HIM "不敢小觑此招，拼力拆解，"
                                           "但双臂仍被抓出了几条血印！\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
}

if (skill> 350)
{
      msg = HIY "最后只见$N" HIY "聚力于掌，平平推出，顿时掌风澎湃，掌力"
              "携着「雷霆万钧」之势猛贯向$n" HIY "而去！\n" NOR;

        if (random(me->query_skill("strike")) > target->query_skill("dodge") / 2)
        {
                me->start_busy(3);

                damage = me->query_skill("bazhen-zhang", 1);
                damage = damage * 3 + random(damage * 5);
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIR "结果只听$n" HIR "一声闷哼，$N"
                                           HIR "掌劲穿胸而过，“哇”的喷出一大"
                                           "口鲜血。\n" NOR;
                me->add("neili", -300);
        } else
        {
                me->start_busy(2);
                me->add("neili", -200);
                msg += CYN "可是$p" CYN "看破了$N" CYN
                       "的企图，躲开了这招杀着。\n" NOR;
        }
        message_combatd(msg, me, target);
}
        return 1;
}

