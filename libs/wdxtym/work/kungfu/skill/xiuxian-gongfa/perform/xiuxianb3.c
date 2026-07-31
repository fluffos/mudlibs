#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

#define TIAN "「" HIY "仙法·暗灭双星" NOR "」"



////////////////////////////////////////
//1  判断内力
//2  判断音律修养
//3  判断佛学及道学修养
//4  判断江湖阅历
//5  判断先天臂力
//6  判断后天臂力及unarmed
//7  判断先天悟性
//8  判断后天悟性及literate
//9  判断先天根骨
//10 判断后天根骨及force
//11 判断先天身法
//12 判断后天身法及dodge
///////////////////////////////////////

string query_name() { return "仙法"ZJBR"暗灭双星"; }

string final(object me, object target, int damage);

int perform(object me, object target)
{
        int damage, damage1;
        int p;
        string msg, cl, wp;
        int ap, dp, dp1;
        int lvl;
        object weapon, cloth;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TIAN "只能对战斗中的对手使用。\n");

        if ((int)me->query("max_neili") < 10000)
                return notify_fail("你内力修为不够，难以施展" TIAN "。\n");

        if ((int)me->query("max_jingli") < 10000)
                return notify_fail("你精力修为不够，难以施展" TIAN "。\n");

        lvl = (int)me->query_skill("xiuxian-gongfa", 1);
        if (lvl < 100)
                return notify_fail("你修仙真法火候不够，难以施展" TIAN "。\n");

        if ((int)me->query("neili") < 10000)
                return notify_fail("你现在真气不够，难以施展" TIAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        message_sort(HIM "\n$N" HIM "口中默念：天干地支，百绝无常。如吾天昭，真煌无莽！"
                     "周围空间扭曲了起来。$n" HIM "大惊失色，仿佛已身在空间乱流之中！\n" NOR, me, target);


        ap = me->query_skill("force");

        damage = target->query_skill("force");

        if (me->query_temp("weapon"))
        {
				damage += me->query_temp("apply/damage");
        } else
        {
                damage += me->query_temp("apply/unarmed_damage");
        }

        dp = target->query_skill("dodge") + target->query_skill("xiuxian-gongfa", 1);

        // 第一招，判断对方内力
        message_sort(HIW "$N" HIW "双臂一震，一股浑厚至极的内劲汹涌澎湃，"
                     "带着排山倒海之势向$n" HIW "席卷而至。\n" NOR, me, target);

        damage1 = 0;

        if (ap * 10 / 3 + random(ap) > dp)
        {
                if (me->query("max_neili") > target->query("max_neili") * 25)
                {
                        msg = HIW "$n" HIW "举臂欲挡,然而$N" HIW "浑厚的内力无可抵御，"
                              "刹那间就将$n" HIW "全身骨头压碎。" NOR "( $n" RED "受伤过重，已"
                              "经有如风中残烛，随时都可能断气。" NOR ")\n";
                        damage1 = -1;
                        me->add("neili", -2000);
                } else
                {
                        target->receive_damage("qi", 100000-target->query("jianman"), me);
				      target->receive_wound("qi", 100000-target->query("jianman"), me);
                        p = (int)target->query("qi") * 250 / (int)target->query("max_qi");

                        msg = HIY "$n" HIY "思虑未定，$N" HIY "的内劲已破体而入，"
                              "$n" HIY "受此重击，喉口一甜，呕出数口" HIR "鲜血" HIY "。\n" NOR;
                        msg += "( $n" + eff_status_msg(p) + " )\n";

                        me->add("neili", -2000);
                }
        } else
        {
                msg = CYN "$n" CYN "知道$N这招无可抵挡，"
                       CYN "当即飞身跃起丈许，躲闪开来。\n" NOR;
                me->add("neili", -5000);
        }
        message_sort(msg, me, target);



        me->start_busy(3);
        me->add("neili", -1000 - random(1000));
        return 1;
}

string final(object me, object target, int ap)
{
        target->add_temp("apply/avoid_busy", -1000);
        target->add_temp("apply/reduce_busy", -1000);
        target->add_temp("apply/avoid_weak", -1000);
        target->add_temp("apply/avoid_locked", -1000);
        target->set_temp("no_perform", 1, target);
        remove_call_out("tian_end");
        call_out("tian_end", 10 + random(ap / 50), me, target);
        return HIY "$n" HIY "丝毫不懂此招奥妙，一个疏神，丹田已遭重创！\n" NOR +
               WHT "$n" WHT "感到自身的忽视虚弱，忽视忙乱、忽视绝招冷冻能力被封印。\n" NOR;
}

void tian_end(object me, object target)
{
        if( target && target->query_temp("no_perform") )
        {
                if (living(target))
                {
                        message_combatd(HIC "$N" HIC "深深吸入一口"
                                        "气，脸色由白转红，看起来好"
                                        "多了。\n" NOR, target);

                        tell_object(target, HIY "你感到被扰乱的真气"
                                            "慢慢平静了下来。\n" NOR);
                }
        target->add_temp("apply/avoid_busy", 1000);
        target->add_temp("apply/reduce_busy", 1000);
        target->add_temp("apply/avoid_weak", 1000);
        target->add_temp("apply/avoid_locked", 1000);
        tell_object(target, HIR "你的忽视虚弱，忽视忙乱、忽视绝招冷冻能力终于解除封印。\n" NOR);
                target->delete_temp("no_perform");
        }
        return;
}